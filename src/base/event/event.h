#ifndef __JB_EVENT_H_
#define __JB_EVENT_H_

#include "stdneb.h"
#include "base/event/eventtarget.h"
#include "messaging/message.h"

namespace Base{

/// event
class Event : public Messaging::Message{
    __DeclareClass(Event);
    __DeclareMsgId;
public:
    /// default constructor
    Event();
    /// default destructor
    virtual ~Event();

public:
};// end of Event

/// event id
typedef Messaging::Id EventId;
/// event handler
typedef void (Base::EventTarget::*JSEL_EventHandler)(Ptr<Base::Event> &evt);
/// selector, from object-c
#define jevent_selector(_SELECTOR) (Base::JSEL_EventHandler)(&_SELECTOR)

}// end of Base
#endif
