#ifndef __JB_EVENTDISPATCH_H_
#define __JB_EVENTDISPATCH_H_  

#include "stdinc.h"
#include "base/event/eventdelegate.h"
#include "util/array.h"
#include "util/dictionary.h"

namespace Base{

/// event
class EventDispatch {
public:
	/// type binding
 	typedef Util::Array<Base::EventDelegate> DelegateList;
 	typedef Util::Dictionary<EventId*, DelegateList > DelegateMap;

	/// default constructor
 	EventDispatch();
 	/// default destructor
 	virtual ~EventDispatch();

 	/// dispatch event
 	void Dispatch(Ptr<Event> &event);

 	/// add event delegate, have not check the unique
 	void AddEventDelegate(const EventId &id, 
		Base::EventTarget* target, JSEL_EventHandler jevent);
 	void AddEventDelegate(const EventId &id, const EventDelegate& ref);

 	/// remove event delegate
 	void RemoveEventDelegate(const EventId &id, 
		Base::EventTarget* target, JSEL_EventHandler jevent);
 	void RemoveEventDelegate(const EventId &id, const EventDelegate& ref);

protected:
 	/// data members
	Threading::CriticalSection mutex;
 	DelegateMap delegatesMap;
};// end of EventDispatch

J_GLOBAL_INSTANCE_DECLARE(EventDispatch, eventDispatch);

}// end of Base
#endif
