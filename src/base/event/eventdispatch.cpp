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
void EventDispatch::Dispatch(Event* evt){
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
void EventDispatch::AddEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent){
	AddEventDelegate(id, EventDelegate(target, jevent));
}

/// add delegate
void EventDispatch::AddEventDelegate(EventId id, const EventDelegate& ref){
	AutoLock lock(m_mutex);

	DelegateMapIte ite = m_delegatesMap.find(id);
	if(ite != m_delegatesMap.end()){
		DelegateList& list = (*ite).second;
		list.push_back(ref);
	}else{
		m_delegatesMap[id].push_back(ref);
		// add event
		// TODO: add event from other source, like from system input event
	}
}

/// remove delegate
void EventDispatch::RemoveEventDelegate(EventId id, Base::EventTarget* target, JSEL_EventHandler jevent){
	RemoveEventDelegate(id, EventDelegate(target, jevent));
}

/// remove delegate
void EventDispatch::RemoveEventDelegate(EventId id, const EventDelegate& ref){
	AutoLock lock(m_mutex);

	DelegateMapIte ite = m_delegatesMap.find(id);
	if(ite != m_delegatesMap.end()){
		DelegateList& list = (*ite).second;
		// we have override operator == for EventDelegate
		list.remove(ref);
		// remove event
		// TOOD: when list.empty() , remove from other source
	}
}

/// global dispatch
J_GLOBAL_INSTANCE(EventDispatch, eventDispatch);

}
