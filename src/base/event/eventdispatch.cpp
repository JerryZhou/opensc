#include "eventdispatch.h"

using namespace Threading;
using namespace Util;

namespace Base{

/// default constructor
EventDispatch::EventDispatch(){
}

/// default destructor
EventDispatch::~EventDispatch(){
}

/// dispatch event
void EventDispatch::Dispatch(Ptr<Event> &evt){
	DelegateList target;
	// find target
	do{
		AutoLock lock(mutex);

		IndexT idx = this->delegatesMap.FindIndex(&(evt->GetId()));
		if(ite != InvalidIndex){
			target = this->delegatesMap.ValueAtIndex(idx);
		}
	}while(false);

	// disptach to target
	DelegateList toRemoved;
	if(!target.IsEmpty()) do{
		EventDelegate& ref = target.Back();
		if(!ref.invoke(evt)){
			toRemoved.Append(ref);
		}
		target.EraseIndexSwap(target.Size() - 1);
	}while(!target.IsEmpty());

	// remmove invalid delegates
	if(!toRemoved.IsEmpty()) do{
		EventDelegate& ref = toRemoved.Back();
		removeEventDelegate(evt->id, ref);
        toRemoved.EraseIndexSwap(toRemoved.Size() - 1);
	}while(!toRemoved.IsEmpty());
}

/// add delegate
void EventDispatch::AddEventDelegate(const EventId &id, Base::EventTarget* target, JSEL_EventHandler jevent){
	AddEventDelegate(id, EventDelegate(target, jevent));
}

/// add delegate
void EventDispatch::AddEventDelegate(const EventId &id, const EventDelegate& ref){
	AutoLock lock(m_mutex);

	IndexT idx = this->delegatesMap.FindIndex(&id);
	if(idx != InvalidIndex){
		DelegateList& list = this->delegatesMap.ValueAtIndex(idx);
		list.Append(ref);
	}else{
        DelegateList list;
        list.Append(ref);
		m_delegatesMap.Add(&id, list);
		// add event
		// TODO: add event from other source, like from system input event
	}
}

/// remove delegate
void EventDispatch::RemoveEventDelegate(const EventId &id, Base::EventTarget* target, JSEL_EventHandler jevent){
	RemoveEventDelegate(id, EventDelegate(target, jevent));
}

/// remove delegate
void EventDispatch::RemoveEventDelegate(const EventId &id, const EventDelegate& ref){
	AutoLock lock(this->mutex);

	IndexT idx = this->delegatesMap.FindIndex(&id);
	if(idx != InvalidIndex){
		DelegateList& list = this->delegatesMap.ValueAtIndex(idx);
		// we have override operator == for EventDelegate
        IndexT refIdx = list.FindIndex(ref);
        if(refIdx != InvalidIndex){
            list.EraseIndexSwap(refIdx);
        }
		// remove event
		// TOOD: when list.empty() , remove from other source
	}
}

/// global dispatch
J_GLOBAL_INSTANCE(EventDispatch, eventDispatch);

}
