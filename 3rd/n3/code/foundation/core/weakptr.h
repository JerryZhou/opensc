#ifndef __WEAKPTR_H_
#define __WEAKPTR_H_

#include "core/types.h"
#include "core/ptr.h"
#include "util/array.h"
#include "util/dictionary.h"
#include "threading/interlocked.h"
#include "threading/criticalsection.h"
#include "threading/autolock.h"
#include "math/scalar.h"

/// declare macro
#define J_GLOBAL_INSTANCE_DECLARE(type, name) type* name()
#define J_GLOBAL_INSTANCE(type, name) \
        type* name(){ \
                static type* instance = NULL;\
                if(instance == NULL){\
                        instance = new type();\
                        if(instance){\
                                static Core::InstanceHolder<type> holder(instance); \
                        }\
                }\
                return instance;\
        }

namespace Core{
/// delcare
class RefCounted;

/*
 * The WeakPtr is implements by holder stuctor, all weakptr share a same holder,
 * There is only one holder binded to one object. when the object have been died,
 * clear the holder the same time.
 *
 * Author: jerryzhou@outlook.com
 * */
/// holder instance
template<typename T>
class InstanceHolder {
public:
    typedef T* InstancePtr;
    InstanceHolder(InstancePtr& ref) :
		    instance(ref) {
	    ;
    }
    ~InstanceHolder() {
	    delete instance;
	    instance = NULL;
    }
    InstancePtr &instance;
};

//---------------------------------------------------------------------------------
template<typename T>
class THolder
{
    /// disable the copy and assign construtor
    THolder(const THolder& other);
    THolder& operator = (const THolder& other);

public:
    /// constructor
    THolder(T* p = NULL)
		: ptr(NULL) , refCounted(0) {
        setT(p);
    }

    /// destructor
    ~THolder() {
        setT(NULL);
    }

    /// target object
    void setT(T* p) {
    	this->criticalSection.Enter();
        ptr = p;
    	this->criticalSection.Leave();
    }

    /// add ref
    void addRef() {
        Threading::Interlocked::Increment(refCounted);
    }

    /// imp after
    void release();

    /// current ref
    int refCnt() const {
        return refCounted;
    }

    /// support the thread safe op
    void lock()const{
    	this->criticalSection.Enter();
    }

    /// thread safe op
    void unlock()const{
    	this->criticalSection.Leave();
    }

    /// used for auto lock
    const Threading::CriticalSection &mutex(){
    	return this->criticalSection;
    }

    /// data members
    T* ptr;
    Threading::CriticalSection criticalSection;
    volatile int refCounted;
};

//---------------------------------------------------------------------------------
template<typename T>
class THolderCenter
{
public:
    /// types def
    typedef T* TPtr;
    typedef THolder<T>* HPtr;
    typedef Util::Dictionary<TPtr, HPtr> HolderContainer;
    typedef Util::Array<HPtr> HolderFreeList;

    /// Instance of holder center
    static J_GLOBAL_INSTANCE(THolderCenter<T>, Instance);

    /// holder center
    THolderCenter()
        : freeListCapacity(1000)
        , containerCapacity(1000) {
        ;
    }

    /// default destructor
    ~THolderCenter() {
	// clear container
	for(IndexT i = 0; i < holderMap.Size(); ++i){
	    HPtr& hPtr = holderMap.ValueAtIndex(i);
	    delete hPtr;
	    hPtr = NULL;
	}

	// clear freelist
	for(IndexT i = 0; i < holders.Size(); ++i){
	    HPtr& hPtr = holders[i];
	    delete hPtr;
	    hPtr = NULL;
	}
    }

    // in this the holder refcounted must be 0
    // but may be a null holder,
    // we can delete the holder at this place
    void recycleHolder(HPtr h) {
        if (h->ptr) {
            destroyHolder(h->ptr);
        }
    }

    /// get the holder ptr
    HPtr requestHolder(const TPtr p) {
        Threading::AutoLock locks(mutex);

	IndexT idx = holderMap.FindIndex(p);
	if (idx != InvalidIndex){
	    return holderMap.ValueAtIndex(idx);
	} else {
	    HPtr h = allocHPtr();
	    h->setT(p);
	    holderMap[p] = h;
	    return h;
	}
    }

    /// release the holder ptr
    bool destroyHolder(const TPtr p) {
        Threading::AutoLock locks(mutex);

	IndexT idx = holderMap.FindIndex(p);
	if (idx != InvalidIndex){
	    freeHPtr(holderMap.ValueAtIndex(idx));
	    holderMap.EraseAtIndex(idx);
	    return true;
	}
	return false;
    }

    /// alloc the holder ptr
    HPtr allocHPtr() {
        Threading::AutoLock locks(mutex);

        HPtr h = NULL;
        if (holders.Size() > 0) {
            for (int i=holders.Size()-1; i>=0; --i) {
                if(holders[i]->refCnt() == 0) {
                    h = holders[i];
		    holders.EraseIndexSwap(i);
                    break;
                }
            }
        }

        if(!h) {
            h = new THolder<T>();
        }

        return h;
    }

    /// free holder ptr
    void freeHPtr(HPtr h) {
        Threading::AutoLock locks(mutex);

        if(!h) return;
        h->setT(NULL);
        holders.Append(h);

        shrinkageFreeList();
    }

    /// shrink the holder free container
    void shrinkageFreeList() {
        Threading::AutoLock locks(mutex);

        if (holders.Size() > freeListCapacity) {
            bool expandFreeListCapacity = true;
            for (int i=holders.Size()-1; i>=0; --i) {
                if(holders[i]->refCnt() == 0) {
                    expandFreeListCapacity = false;
                    delete holders[i];
		    holders.EraseIndexSwap(i);
                }
            }

            if (expandFreeListCapacity) {
                freeListCapacity = 2 * freeListCapacity;
            } else {
                freeListCapacity = Math::n_max((int)holders.Size(), 1000);
            }
        }
    }

    /// shrink the hoder container
    void shrinkageContainer() {
        Threading::AutoLock locks(mutex);

        if (holderMap.Size() > containerCapacity) {
            bool expandCapactiy = true;
	    
	    // for each in holder map
	    Util::Array<TPtr> tptrs = n_new(Util::Array<TPtr>); 
	    for(IndexT i = 0; i< holderMap.Size(); ++i){
		HPtr hptr = holderMap.ValueAtIndex(i);
		if ( hptr->refCnt() == 0) {
                    expandCapactiy = false;
		    hptr->setT(NULL);
		    tptrs.Append( holderMap.KeyAtIndex(i) );
		    holders.Append(hptr);
		}
	    }
	    // clear holder map
	    for(IndexT i = 0; i< tptrs.Size(); ++i){
		holderMap.Erase(tptrs[i]);
	    }

	    // control the capactity
            if (expandCapactiy) {
                containerCapacity = containerCapacity * 2;
            } else {
                containerCapacity = Math::n_max((int)holderMap.Size(), 1000);
            }
        }
    }

    /// data members
    HolderContainer holderMap;
    HolderFreeList holders;
    SizeT freeListCapacity;
    SizeT containerCapacity;
    Threading::CriticalSection mutex;
};

/// release the holder
template<typename T>
void THolder<T>::release() {
    if(Threading::Interlocked::Decrement(refCounted) == 0) {
        THolderCenter<T>::Instance()->recycleHolder(this);
    }
}

/// weakptr imp
template<typename TYPE, typename TBASE = Core::RefCounted>
class WeakPtr {
public:
    /// default destructor
    WeakPtr()
	: holderPtr(NULL) {
        ;
    }

    /// constructor from object ptr
    WeakPtr(const TYPE* ptr)
    : holderPtr(NULL) {
	*this = ptr;
    }

    /// constructor from Ptr<> pointer
    WeakPtr(const Ptr<TYPE>& p)
    : holderPtr(NULL){
	*this = (TYPE*)(p);
    }

    /// copy constructor
    WeakPtr(const WeakPtr& other)
    : holderPtr(NULL) {
        *this = other;
    }

    /// default destructor
    ~WeakPtr() {
        release();
    }

    /// assignment operator from C++ pointer
    WeakPtr& operator = (const TYPE* ptr){
	if( (TYPE*)(this) == ptr) {
	    return *this;
	}

	release();
	if (ptr) {
            holderPtr = THolderCenter<TBASE>::Instance()->requestHolder((TYPE*)(ptr));
            // We Can set a max holder num
            if (holderPtr) {
                holderPtr->addRef();
            }
        }
	return *this;
    }

    /// assignment operator from Ptr<>
    WeakPtr& operator = (const Ptr<TYPE> rhs){
	return *this = (TYPE*)(rhs);
    }

    /// assign constructor
    WeakPtr& operator = (const WeakPtr& other) {
        if (&other != this) {
	    if(other.holderPtr == this->holderPtr){
		return *this;
	    }

            release();
            // just add ref to valid object
            if(other.holderPtr && other.holderPtr->ptr) {
                this->holderPtr = other.holderPtr;
                this->holderPtr->addRef();
            }

        }
        return *this;
    }

    /// safe -> operator
    TYPE* operator->() const{
	return (TYPE*)(holderPtr ? holderPtr->ptr : NULL);
    }
    /// safe dereference operator
    TYPE& operator*() const{
	return *((TYPE*)(holderPtr ? holderPtr->ptr: NULL));
    }
    /// safe pointer cast operator
    operator TYPE*() const{
	return (TYPE*)(holderPtr ? holderPtr->ptr : NULL);
    }
    /// check if pointer is valid
    bool isvalid() const{
	return (holderPtr && holderPtr->ptr);
    }
    /// return direct pointer (asserts if null pointer)
    TYPE* get() const{
	return (TYPE*)(holderPtr ? holderPtr->ptr : NULL);
    }
    /// return direct pointer (returns null pointer)
    TYPE* get_unsafe() const{
	return (TYPE*)(holderPtr ? holderPtr->ptr : NULL);
    }
    /// op the target
    inline void release() {
        if (holderPtr) {
            holderPtr->release();
            holderPtr = NULL;
        }
    }

    /// if you need thread safe, should lock first
    inline bool isNull()const {
        return !holderPtr || !(holderPtr->ptr);
    }

    /// override operator bool()
    inline operator bool() {
        return !isNull();
    }

    /// thread lock
    inline bool lock() const{
    	if(holderPtr){
    		holderPtr->lock();
    		return true;
    	}
    	return false;
    }

    /// thread unlock
    inline bool unlock() const{
    	if(holderPtr){
    		holderPtr->unlock();
    		return true;
    	}
    	return false;
    }

protected:
    THolder<TBASE>* holderPtr;
};

}// end of Base
#endif
