#include "eventdelegate.h"

namespace Base{
/// default constructor
EventDelegate::EventDelegate()
: m_target(NULL)
, m_handle(NULL){

}

/// construtor from target and handle
EventDelegate::EventDelegate(Base::EventTarget* target, JSEL_EventHandler handle)
: m_target(target), m_handle(handle){
}

/// copy constructor
EventDelegate::EventDelegate(const EventDelegate& other)
: m_target(NULL)
, m_handle(NULL){
	*this = other;
}

/// assignment constructor
EventDelegate& EventDelegate::operator = (const EventDelegate& other){
	// if other is same as this
	IF_DO(*this == other, return *this);

	// release old target
	m_target = other.m_target;
	// take the same handle address
	m_handle = other.m_handle;
}

/// override operator ==
bool EventDelegate::operator == (const EventDelegate& other) const{
	// if other is same as this
	IF_DO(this == &other, return true);
	IF_DO(this->m_target.rawPtr() == other.m_target.rawPtr()
			&& this->m_handle == other.m_handle, return true);

	return false;
}

/// default destructor
EventDelegate::~EventDelegate(){
	m_target = NULL;
}

/// invoke the target event handle
/// @param return true when the delegate is valid
/// @param return false when the delegate is invalid
bool EventDelegate::invoke(Event* evt){
	if(m_target.lock() && m_handle != NULL){
		(m_target->*(m_handle))(evt);
		m_target.unlock();
		return true;
	}
	return false;
}

/// get the selector of event
JSEL_EventHandler EventDelegate::handle() const{
    return m_handle;
}

/// get the target
Base::EventTarget* EventDelegate::target() const{
    return m_target;
}

}// end of Base
