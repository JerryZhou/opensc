#ifndef __JB_EVENT_H_
#define __JB_EVENT_H_

#include "stdinc.h"
#include "base/event/eventtarget.h"

namespace Base{

/// event
class Event{
public:
    /// default constructor
    Event()
    : id(0)
    , param(NULL) {
    }
    /// default destructor
    virtual ~Event(){
    }

public:
    /// data members
    int id; // event id
    void* param;// event params
};// end of Event

/// event id from 0
typedef int EventId;
/// event handler
typedef void (Base::EventTarget::*JSEL_EventHandler)(Base::Event*);
/// selector, from object-c
#define jevent_selector(_SELECTOR) (Base::JSEL_EventHandler)(&_SELECTOR)

}// end of Base
#endif
