#ifndef __JB_PTR_H_
#define __JB_PTR_H_ 
#include "stdinc.h"

namespace Base{
template<typename TYPE>
class Ptr{
public:
    /// default constructor
    Ptr()
    : ptr(NULL){
    }
    /// default destructor
    ~Ptr(){
	J_SafeRelease(this->ptr);
    }
    /// construct from raw pointer
    Ptr(T* t)
    : ptr(NULL){
	*this = t;
    }
    /// copy constructor
    Ptr(const Ptr& other)
    : ptr(NULL){
	*this = other;
    }

    /// assign constructor from raw pointer
    Ptr& operator= (T* t){
	IF_DO(t == this->ptr, return *this);
	J_SafeRelease(this->ptr);
	this->ptr = t;
	J_SafeRetain(this->ptr);
	return *this;
    }

    /// assign constructor
    Ptr& operator= (const Ptr& other){
	IF_DO(this == &other, return *this);
	return *this = other.ptr;
    }
	
    /// equality operator
    bool operator==(const Ptr<TYPE>& rhs) const{
	return this->ptr == rhs.ptr;
    }
    /// inequality operator
    bool operator!=(const Ptr<TYPE>& rhs) const{
	return this->ptr != rhs.ptr;
    }
    /// shortcut equality operator
    bool operator==(const TYPE* rhs) const{
	return this->ptr == rhs;
    }
    /// shortcut inequality operator
    bool operator!=(const TYPE* rhs) const{
	return this->ptr != rhs;
    }

    /// safe -> operator
    TYPE* operator->() const{
	J_ASSERT2(this->ptr, "Null Pointer access in Ptr::operator->()");
	return this->ptr;
    }

    /// safe dereference operator
    TYPE& operator*() const{
	J_ASSERT2(this->ptr, "Null Pointer access in Ptr::operator->()");
	return *this->ptr;
    }
    /// safe pointer cast operator
    operator TYPE*() const{
	J_ASSERT2(this->ptr, "Null Pointer access in Ptr::operator->()");
	return this->ptr;
    }

    /// type-safe downcast operator to other smart pointer
    template<class DERIVED> const Ptr<DERIVED>& downcast() const{
#if ( OPENSC_DEBUG == 1)
	// if DERIVED is not a derived class of TYPE, compiler complains here
	//     // compile-time inheritance-test
	OPENSC_UNUSED_ATT const DERIVED *derived = static_cast<const DERIVED*>(this->ptr);
#endif
	return *reinterpret_cast<const Ptr<DERIVED>*>(this);
		     
    }

    /// type-safe upcast operator to other smart pointer
    template<class BASE> const Ptr<BASE>& upcast() const{
#if (OPENSC_DEBUG == 1)
	// if BASE is not a base-class of TYPE, compiler complains here
	// compile-time inheritance-test
	OPENSC_UNUSED_ATTR const BASE *base = this->ptr;
#endif
	return *reinterpret_cast<const Ptr<BASE>*>(this);
    }

    /// unsafe(!) cast to anything, unless classes have no inheritance-relationship,
    /// call upcast/downcast instead, they are type-safe
    template<class OTHERTYPE> const Ptr<OTHERTYPE>& cast() const{
	// note: this is an unsafe cast
	return *reinterpret_cast<const Ptr<OTHERTYPE>*>(this);
    }

    /// check if pointer is valid
    bool isvalid() const{
	return (0 != this->ptr);
    }
    /// return direct pointer (asserts if null pointer)
    TYPE* get() const{
	J_ASSERT2(this->ptr, "NULL pointer access in Ptr::get()!");
	return this->ptr;
    }
    /// return direct pointer (returns null pointer)
    TYPE* get_unsafe() const{
	return this->ptr;
    }

private:
    /// data members
    TYPE* ptr;
};// end of Ptr
}// end of Base
#endif
