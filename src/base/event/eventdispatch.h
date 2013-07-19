#ifndef __EVENTDISPATCH_H_
#define __EVENTDISPATCH_H_  

#include "stdinc.h"
#include "base/event/eventdelegate.h"

namespace Base{

/// event
class EventDispatch {
public:
	/// type binding
 	typedef std::list<EventDelegate> DelegateList;
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
 	void dispatch(Event* event);

 	/// add event delegate, have not check the unique
 	void addEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent);
 	void addEventDelegate(EventId id, const EventDelegate& ref);

 	/// remove event delegate
 	void removeEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent);
 	void removeEventDelegate(EventId id, const EventDelegate& ref);

protected:
 	/// data members
 	ThreadMutex m_mutex;
 	DelegateMap m_delegatesMap;
};// end of EventDispatch

J_GLOBAL_INSTANCE_DECLARE(EventDispatch, eventDispatch);

}// end of Base
#endif
