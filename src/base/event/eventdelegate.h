#ifndef __JB_EVENTDELEGATE_H_
#define __JB_EVENTDELEGATE_H_
#include "stdinc.h"
#include "base/event/event.h"

namespace Base{

///---------------------------------------------------------------------------------
/// declares
class EventTarget;

///---------------------------------------------------------------------------------
/// event delegate: weak reference
class EventDelegate{
public:
	/// default constructor
	EventDelegate();
	/// construtor from target and handle
	EventDelegate(Base::EventTarget* t, JSEL_EventHandler h);

	/// copy constructor
	EventDelegate(const EventDelegate& other);
	/// assignment constructor
	EventDelegate& operator = (const EventDelegate& other);
	/// override operator ==
	bool operator == (const EventDelegate& other) const;

	/// default destructor
	virtual ~EventDelegate();

	/// invoke the target event handle
	/// @param return true when the delegate is valid
	/// @param return false when the delegate is invalid
	bool Invoke(Event* evt);

	/// get the selector of event
	JSEL_EventHandler Handle() const;
	/// get the target
	Base::EventTarget* Target() const;

protected:
	/// data members
	Base::TargetPtr<Base::EventTarget> target;
	JSEL_EventHandler handle;
};// end of EventDelegate

}// end of Base

#endif
