#ifndef __TARGET_H_
#define __TARGET_H_
#include "weakptr.h"

namespace Base{
class Target{
public:
    /// default constructor
    Target();
    /// default destructor
    virtual ~Target();

};// end of Target

template<typename T>
class TargetPtr : public WeakPtr<Base::Target, Base::Target>{
public:
    /// default destructor
    TargetPtr(){
    }

    /// constructor from object ptr
    TargetPtr(const T* ptr)
    : WeakPtr<Base::Target, Base::Target>(ptr){

    }

    /// op the target
    inline T* operator->() const {
    	if (holderPtr) { return static_cast<T*>(holderPtr->ptr); }
    	return NULL;
    }

    /// op the target
    inline T& operator*() const {
    	if (holderPtr) { return *(static_cast<T*>(holderPtr->ptr)); }
    	return *static_cast<T*>(NULL);
    }

    /// op the target
    inline operator T*() const {
    	if (holderPtr) { return static_cast<T*>(holderPtr->ptr); }
    	return NULL;
    }
    
    /// op raw ptr
    inline T* rawPtr() const{
	return (T*)(*this);
    }
    
};// end of TargetPtr

}// end of Base
#endif
