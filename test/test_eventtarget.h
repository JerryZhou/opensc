#include "base/event/eventtarget.h"

using namespace Base;

TEST(EventTarget, constructor){
    Ptr<EventTarget> target = EventTarget::Create();
}

TEST(EventTarget, selector){
    Ptr<EventTarget> target = EventTarget::Create();
    Ptr<Event> evt = Event::Create();
    
    JSEL_EventHandler h = jevent_selector(EventTarget::OnEvent);
    EventTarget *pTarget = target;
    (pTarget->*(h))(evt);
}

