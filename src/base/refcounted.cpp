#include "refcountedtarget.h"

namespace Base{

/// default constructor
RefcountedTarget::RefcountedTarget()
: m_refcounted(1){

}

/// default destructor
RefcountedTarget::~RefcountedTarget(){

}

/// reference counting, increment
void RefcountedTarget::release(void){
	if(Base::Interlocked::decrement(m_refcounted) == 0){
		delete this;
	}
}

/// reference counting, decrement
void RefcountedTarget::retain(void){
	Base::Interlocked::increment(m_refcounted);
}

/// current reference count
int RefcountedTarget::retainCount(void){
	return m_refcounted;
}

}
