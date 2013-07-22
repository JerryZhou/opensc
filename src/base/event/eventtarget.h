#ifndef _JB__EVENTTARGET_H_
#define _JB__EVENTTARGET_H_

#include "stdneb.h"
#include "base/target.h"

namespace Base{
//---------------------------------------------------------------------------------
class Event;

/// class EventTarget
class EventTarget : public Base::Target{
    __DeclareClass(EventTarget);
public:
    EventTarget();
    virtual ~EventTarget();

    virtual void OnEvent(Ptr<Event> &evt);
};
}// end of Base

#endif
