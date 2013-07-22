#include "base/event/eventdelegate.h"

using namespace Base;
using namespace Core;

TEST(EventDelegate, constructor){
    EventDelegate delegate;
}

TEST(EventDelegate, constructor_target_handle){
    Ptr<EventTarget> target = EventTarget::Create();
    EventDelegate delegate(target, jevent_selector(EventTarget::OnEvent));
    EXPECT_EQ(delegate.Target(), target);
    EXPECT_EQ(delegate.Handle(), jevent_selector(EventTarget::OnEvent));
}

TEST(EventDelegate, constructor_copy){
    Ptr<EventTarget> target = EventTarget::Create();
    EventDelegate delegate(target, jevent_selector(EventTarget::OnEvent));
    EventDelegate delegatecopy(delegate);
    EXPECT_EQ(delegate, delegatecopy);

    EXPECT_EQ(delegatecopy.Target(), target);
    EXPECT_EQ(delegatecopy.Handle(), jevent_selector(EventTarget::OnEvent));
}

TEST(EventDelegate, constructor_assign){
    Ptr<EventTarget> target = EventTarget::Create();
    EventDelegate delegate(target, jevent_selector(EventTarget::OnEvent));

    EventDelegate delegatecopy;
    EXPECT_TRUE(delegatecopy.Target() == NULL);
    EXPECT_TRUE(delegatecopy.Handle() == NULL);

    delegatecopy = delegate;
    EXPECT_EQ(delegate, delegatecopy);

    EXPECT_EQ(delegatecopy.Target(), target);
    EXPECT_EQ(delegatecopy.Handle(), jevent_selector(EventTarget::OnEvent));
}

TEST(EventDelegate, invoke){
    Ptr<EventTarget> target = EventTarget::Create();
    Ptr<Event> evt;

    EventDelegate delegate(target, jevent_selector(EventTarget::OnEvent));
    delegate.Invoke(evt);

    EventDelegate delegatecopy;
    delegatecopy.Invoke(evt);
}
