#include "eventdelegate.h"

namespace Base{
/// default constructor
EventDelegate::EventDelegate()
: target(NULL)
, handle(NULL){

}

/// construtor from target and handle
EventDelegate::EventDelegate(Base::EventTarget* h, JSEL_EventHandler h)
: target(t), handle(h){
}

/// copy constructor
EventDelegate::EventDelegate(const EventDelegate& other)
: target(NULL)
, handle(NULL){
	*this = other;
}

/// assignment constructor
EventDelegate& EventDelegate::operator = (const EventDelegate& other){
	// if other is same as this
	IF_DO(*this == other, return *this);

	// release old target
	this->target = other.target;
	// take the same handle address
	this->handle = other.handle;
}

/// override operator ==
bool EventDelegate::operator == (const EventDelegate& other) const{
	// if other is same as this
	IF_DO(this == &other, return true);
	IF_DO(this->target == other.target
			&& this->handle == other.handle, return true);

	return false;
}

/// default destructor
EventDelegate::~EventDelegate(){
	this->target = NULL;
}

/// invoke the target event handle
/// @param return true when the delegate is valid
/// @param return false when the delegate is invalid
bool EventDelegate::Invoke(Event* evt){
	if(this->target.lock() && this->handle != NULL){
		(this->target->*(this->handle))(evt);
		this->target.unlock();
		return true;
	}
	return false;
}

/// get the selector of event
JSEL_EventHandler EventDelegate::Handle() const{
    return this->handle;
}

/// get the target
Base::EventTarget* EventDelegate::Target() const{
    return this->target;
}

}// end of Base
