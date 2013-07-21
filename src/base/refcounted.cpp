#include "refcounted.h"

namespace Base{

/// default constructor
Refcounted::Refcounted()
: refcounted(0){
}

/// default destructor
Refcounted::~Refcounted(){
    J_ASSERT2(this->refcounted == 0, 
	    "Refcounted::~Refcounted() refcounted %d != 0", this->refcounted);
}

/// reference counting, increment
void Refcounted::Release(void){
	if(Base::Interlocked::Decrement(this->refcounted) == 0){
		delete this;
	}
}

/// reference counting, decrement
void Refcounted::Retain(void){
	Base::Interlocked::Increment(this->refcounted);
}

/// current reference count
int Refcounted::RetainCount(void){
	return this->refcounted;
}

}
