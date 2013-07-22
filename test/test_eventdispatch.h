#include "base/event/eventdispatch.h"
#include "base/event/eventtarget.h"

using namespace Base;
TEST(EventDispatch, constructor){
    EventDispatch dispatch;
}

TEST(EventDispatch, instance){
    EXPECT_TRUE(eventDispatch() != NULL);
}

/// test target
class __test_EventTarget : public EventTarget{
    __DeclareClass(__test_EventTarget);
public:
    __test_EventTarget()
    :m_count(0){
    }

    void handleEvent(Base::Event *evt){
	m_count++;
    }

    void hOnEvent(Base::Event *evt){
	m_count++;
	m_count++;
    }

public:
    int m_count;
};
__ImplementClass(__test_EventTarget, '_ett', EventTarget);

TEST(EventDispatch, addEventDelegate){
    Ptr<EventTarget> target = EventTarget::Create();
    eventDispatch()->AddEventDelegate(Event::Id, target, jevent_selector(EventTarget::OnEvent));
}

TEST(EventDispatch, removeEventDelegate){
    Ptr<__test_EventTarget> evtTarget = __test_EventTarget::Create();

    eventDispatch()->RemoveEventDelegate(Event::Id, evtTarget,
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->RemoveEventDelegate(Event::Id, evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->RemoveEventDelegate(Event::Id, evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));
}

TEST(EventDispatch, dispatch){
    Ptr<__test_EventTarget> evtTarget = __test_EventTarget::Create();
    Ptr<Event> evt = Event::Create();
    
    eventDispatch()->AddEventDelegate(Event::Id, evtTarget,
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->AddEventDelegate(Event::Id, evtTarget, 
	    jevent_selector(__test_EventTarget::hOnEvent));

    EXPECT_EQ(evtTarget->m_count, 0);

    eventDispatch()->Dispatch(evt);

    EXPECT_EQ(evtTarget->m_count, 3);

    eventDispatch()->RemoveEventDelegate(Event::Id, evtTarget, 
	    jevent_selector(__test_EventTarget::hOnEvent));

    eventDispatch()->Dispatch(evt);

    EXPECT_EQ(evtTarget->m_count, 4);

    eventDispatch()->RemoveEventDelegate(Event::Id, evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->Dispatch(evt);

    EXPECT_EQ(evtTarget->m_count, 4);
}
