#include "base/event/eventtarget.h"

using namespace Base;

TEST(EventTarget, constructor){
    EventTarget target;
    TargetPtr<EventTarget> eventTargetPtr = &target; 
}

TEST(EventTarget, selector){
    EventTarget target;
    JSEL_EventHandler h = jevent_selector(EventTarget::OnEvent);
    EventTarget *pTarget = &target;
    (pTarget->*(h))(NULL);
}

