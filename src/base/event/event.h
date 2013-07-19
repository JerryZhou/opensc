#ifndef __JB_EVENT_H_
#define __JB_EVENT_H_

#include "stdinc.h"
#include "base/event/eventtarget.h"

namespace Base{

/// event
class Event{
public:
	virtual ~Event(){
	}

public:
	int id; // event id
	void* param;// event params
	//JNIEnv *env; // jni env
	//jobjectArray args; // java event array, do not save
};// end of Event

typedef int EventId;
typedef void (Base::EventTarget::*JSEL_EventHandler)(Base::Event*);
#define jevent_selector(_SELECTOR) (Base::JSEL_EventHandler)(&_SELECTOR)

}// end of Base
#endif
