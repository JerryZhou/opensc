#ifndef __WEAKPTR_H_
#define __WEAKPTR_H_

#include "stdinc.h"
#include "interlocked.h"

namespace Base{
/*
 * The WeakPtr is implements by holder stuctor, all weakptr share a same holder,
 * There is only one holder binded to one object. when the object have been died,
 * clear the holder the same time.
 *
 * Author: jerryzhou@outlook.com
 * */

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
    	Base::AutoLock autoLock(dmutex);
        ptr = p;
    }

    /// add ref
    void addRef() {
        Base::Interlocked::increment(refCounted);
    }

    /// imp after
    void release();

    /// current ref
    int refCnt() const {
        return refCounted;
    }

    /// support the thread safe op
    void lock()const{
    	dmutex.lock();
    }

    /// thread safe op
    void unlock()const{
    	dmutex.unlock();
    }

    /// used for auto lock
    const Base::ThreadMutex &mutex(){
    	return this->dmutex;
    }

    /// data members
    T* ptr;
    Base::ThreadMutex dmutex;
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
    typedef std::map<TPtr, HPtr> HolderContainer;
    typedef std::vector<HPtr> HolderFreeList;
    typedef typename HolderContainer::iterator HolderContainerIte;

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
    	HolderContainerIte ite = holderMap.begin();
        while (ite != holderMap.end()) {
            delete ite->second;
            ite->second = NULL;
            ++ite;
        }

        while (holders.size() > 0) {
            HPtr h = holders.back();
            delete h;
            h = NULL;
            holders.pop_back();
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
        Base::AutoLock locks(mutex);

        HolderContainerIte ite = holderMap.find(p);
        if (ite == holderMap.end()) {
            HPtr h = allocHPtr();
            h->setT(p);
            holderMap[p] = h;
            return h;
        } else {
            return ite->second;
        }
    }

    /// release the holder ptr
    bool destroyHolder(const TPtr p) {
        Base::AutoLock locks(mutex);

        HolderContainerIte ite = holderMap.find(p);
        if (ite != holderMap.end()) {
            freeHPtr(ite->second);
            holderMap.erase(ite);
            return true;
        }
        return false;
    }

    /// alloc the holder ptr
    HPtr allocHPtr() {
        Base::AutoLock locks(mutex);

        HPtr h = NULL;
        if (holders.size() > 0) {
            for (int i=holders.size()-1; i>=0; --i) {
                if(holders.at(i)->refCnt() == 0) {
                    h = holders.at(i);
                    //holders.remove(i);
                    remove(holders, i);
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
        Base::AutoLock locks(mutex);

        if(!h) return;
        h->setT(NULL);
        holders.push_back(h);

        shrinkageFreeList();
    }

    /// helper for vector
    void remove(HolderFreeList &list, int idx){
    	if(idx != (int)list.size()-1){
    		list[idx] = list.back();
    	}
    	list.pop_back();
    }

    /// shrink the holder free container
    void shrinkageFreeList() {
        Base::AutoLock locks(mutex);

        if (holders.size() > freeListCapacity) {
            bool expandFreeListCapacity = true;
            for (int i=holders.size()-1; i>=0; --i) {
                if(holders.at(i)->refCnt() == 0) {
                    expandFreeListCapacity = false;
                    delete holders.at(i);
                    //holders.remove(i);
                    remove(holders, i);
                }
            }

            if (expandFreeListCapacity) {
                freeListCapacity = 2 * freeListCapacity;
            } else {
                freeListCapacity = J_Max<size_t>(holders.size(), 1000);
            }
        }
    }

    /// shrink the hoder container
    void shrinkageContainer() {
        Base::AutoLock locks(mutex);

        if (holderMap.count() > containerCapacity) {
            bool expandCapactiy = true;

            HolderContainerIte ite = holderMap.begin();
            while (ite != holderMap.end()) {
                if (ite->second->refCnt() == 0) {
                    expandCapactiy = false;
                    HolderContainerIte eraseIte = ite++;
                    eraseIte->second->setT(NULL);
                    holders.push_back(eraseIte->second);
                    holderMap.erase(eraseIte);
                } else {
                    ++ite;
                }
            }

            if (expandCapactiy) {
                containerCapacity = containerCapacity * 2;
            } else {
                containerCapacity = J_Max<size_t>(holderMap.count(), 1000);
            }
        }
    }

    /// data members
    HolderContainer holderMap;
    HolderFreeList holders;
    typename HolderFreeList::size_type freeListCapacity;
    typename HolderFreeList::size_type containerCapacity;
    Base::ThreadMutex mutex;
};

/// release the holder
template<typename T>
void THolder<T>::release() {
    if(Base::Interlocked::decrement(refCounted) == 0) {
        THolderCenter<T>::Instance()->recycleHolder(this);
    }
}

/// weakptr imp
template<typename T, typename TBase = T>
class WeakPtr {
public:
	/// default destructor
    WeakPtr()
	: holderPtr(NULL) {
        ;
    }

    /// constructor from object ptr
    WeakPtr(const T* ptr)
    : holderPtr(NULL) {
        if (ptr) {
            holderPtr = THolderCenter<TBase>::Instance()->requestHolder((T*)(ptr));
            // We Can set a max holder num
            if (holderPtr) {
                holderPtr->addRef();
            }
        }
    }

    /// copy constructor
    WeakPtr(const WeakPtr& other)
    : holderPtr(NULL) {
        *this = other;
    }

    /// assign constructor
    WeakPtr& operator = (const WeakPtr& other) {
        if (&other != this) {
            release();
            // just add ref to valid object
            if(other.holderPtr && other.holderPtr->ptr) {
                this->holderPtr = other.holderPtr;
                this->holderPtr->addRef();
            }

        }
        return *this;
    }

    /// default destructor
    ~WeakPtr() {
        release();
    }
//
//    /// op the target
//    inline T* operator->() const {
//    	if (holderPtr) { return static_cast<T*>(holderPtr->ptr); }
//    	return NULL;
//    }
//
//    /// op the target
//    inline T& operator*() const {
//    	if (holderPtr) { return *(static_cast<T*>(holderPtr->ptr)); }
//    	return *static_cast<T*>(NULL);
//    }
//
//    /// op the target
//    inline operator T*() const {
//    	if (holderPtr) { return static_cast<T*>(holderPtr->ptr); }
//    	return NULL;
//    }

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
    THolder<TBase>* holderPtr;
};
}// end of Base
#endif
