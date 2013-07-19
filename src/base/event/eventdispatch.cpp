#include "eventdispatch.h"
///#include "eventjni.h"

namespace Base{

/// default constructor
EventDispatch::EventDispatch(){
}

/// default destructor
EventDispatch::~EventDispatch(){
}

/// dispatch event
void EventDispatch::dispatch(Event* evt){
	DelegateList target;
	// find target
	do{
		AutoLock lock(m_mutex);
		DelegateMapIte ite = m_delegatesMap.find(evt->id);
		if(ite != m_delegatesMap.end()){
			target = (*ite).second;
		}
	}while(false);

	// disptach to target
	DelegateList toRemoved;
	if(!target.empty()) do{
		EventDelegate& ref = target.front();
		if(!ref.invoke(evt)){
			toRemoved.push_back(ref);
		}
		target.pop_front();
	}while(!target.empty());

	// remmove invalid delegates
	if(!toRemoved.empty()) do{
		EventDelegate& ref = toRemoved.front();
		removeEventDelegate(evt->id, ref);
	}while(false);
}

/// add delegate
void EventDispatch::addEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent){
	addEventDelegate(id, EventDelegate(target, jevent));
}

/// add delegate
void EventDispatch::addEventDelegate(EventId id, const EventDelegate& ref){
	AutoLock lock(m_mutex);

	DelegateMapIte ite = m_delegatesMap.find(id);
	if(ite != m_delegatesMap.end()){
		DelegateList& list = (*ite).second;
		list.push_back(ref);
	}else{
		m_delegatesMap[id].push_back(ref);
		// add event
		// add_event_from_jni(id);
	}
}

/// remove delegate
void EventDispatch::removeEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent){
	removeEventDelegate(id, EventDelegate(target, jevent));
}

/// remove delegate
void EventDispatch::removeEventDelegate(EventId id, const EventDelegate& ref){
	AutoLock lock(m_mutex);

	DelegateMapIte ite = m_delegatesMap.find(id);
	if(ite != m_delegatesMap.end()){
		DelegateList& list = (*ite).second;
		// we have override operator == for EventDelegate
		list.remove(ref);
		// remove event
		//if(list.empty()){
		//	remove_event_from_jni(id);
		//}
	}
}

/// global dispatch
J_GLOBAL_INSTANCE(EventDispatch, eventDispatch);

}
