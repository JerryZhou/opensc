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
public:
    __test_EventTarget()
    :m_count(0){
    }

    void handleEvent(Base::Event *evt){
	m_count++;
    }

    virtual void onEvent(Base::Event *evt){
	m_count++;
	m_count++;
    }

public:
    int m_count;
};

TEST(EventDispatch, addEventDelegate){
    EventTarget target;
    eventDispatch()->addEventDelegate(0, &target, jevent_selector(EventTarget::onEvent));
}

TEST(EventDispatch, removeEventDelegate){
    __test_EventTarget evtTarget;

    eventDispatch()->removeEventDelegate(0, &evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->addEventDelegate(0, &evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->removeEventDelegate(0, &evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));
}

TEST(EventDispatch, dispatch){
    __test_EventTarget evtTarget;
    eventDispatch()->addEventDelegate(0, &evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->addEventDelegate(0, &evtTarget, 
	    jevent_selector(EventTarget::onEvent));

    EXPECT_EQ(evtTarget.m_count, 0);

    eventDispatch()->dispatch(NULL);

    EXPECT_EQ(evtTarget.m_count, 3);

    eventDispatch()->removeEventDelegate(0, &evtTarget, 
	    jevent_selector(EventTarget::onEvent));

    eventDispatch()->dispatch(NULL);

    EXPECT_EQ(evtTarget.m_count, 4);

    eventDispatch()->removeEventDelegate(0, &evtTarget, 
	    jevent_selector(__test_EventTarget::handleEvent));

    eventDispatch()->dispatch(NULL);

    EXPECT_EQ(evtTarget.m_count, 4);
}
