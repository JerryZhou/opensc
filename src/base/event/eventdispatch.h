#ifndef __JB_EVENTDISPATCH_H_
#define __JB_EVENTDISPATCH_H_  

#include "stdinc.h"
#include "base/event/eventdelegate.h"

namespace Base{

/// event
class EventDispatch {
public:
	/// type binding
 	typedef std::list<Base::EventDelegate> DelegateList;
 	typedef DelegateList::iterator DelegateIte;
 	typedef DelegateList::const_iterator DelegateConstIte;

 	typedef std::map<EventId, DelegateList > DelegateMap;
 	typedef DelegateMap::iterator DelegateMapIte;
 	typedef DelegateMap::const_iterator DelegateMapConstIte;

	/// default constructor
 	EventDispatch();
 	/// default destructor
 	virtual ~EventDispatch();

 	/// dispatch event
 	void Dispatch(Event* event);

 	/// add event delegate, have not check the unique
 	void AddEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent);
 	void AddEventDelegate(EventId id, const EventDelegate& ref);

 	/// remove event delegate
 	void RemoveEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent);
 	void RemoveEventDelegate(EventId id, const EventDelegate& ref);

protected:
 	/// data members
 	ThreadMutex mutex;
 	DelegateMap delegatesMap;
};// end of EventDispatch

J_GLOBAL_INSTANCE_DECLARE(EventDispatch, eventDispatch);

}// end of Base
#endif
