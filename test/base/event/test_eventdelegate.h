#include "base/event/eventdelegate.h"

using namespace Base;

TEST(EventDelegate, constructor){
    EventDelegate delegate;
}

TEST(EventDelegate, constructor_target_handle){
    EventTarget target;
    EventDelegate delegate(&target, jevent_selector(EventTarget::onEvent));
    EXPECT_EQ(delegate.target(), &target);
    EXPECT_EQ(delegate.handle(), jevent_selector(EventTarget::onEvent));
}

TEST(EventDelegate, constructor_copy){
    EventTarget target;
    EventDelegate delegate(&target, jevent_selector(EventTarget::onEvent));
    EventDelegate delegatecopy(delegate);
    EXPECT_EQ(delegate, delegatecopy);

    EXPECT_EQ(delegatecopy.target(), &target);
    EXPECT_EQ(delegatecopy.handle(), jevent_selector(EventTarget::onEvent));
}

TEST(EventDelegate, constructor_assign){
    EventTarget target;
    EventDelegate delegate(&target, jevent_selector(EventTarget::onEvent));

    EventDelegate delegatecopy;
    EXPECT_TRUE(delegatecopy.target() == NULL);
    EXPECT_TRUE(delegatecopy.handle() == NULL);

    delegatecopy = delegate;
    EXPECT_EQ(delegate, delegatecopy);

    EXPECT_EQ(delegatecopy.target(), &target);
    EXPECT_EQ(delegatecopy.handle(), jevent_selector(EventTarget::onEvent));
}

TEST(EventDelegate, invoke){
    EventTarget target;

    EventDelegate delegate(&target, jevent_selector(EventTarget::onEvent));
    delegate.invoke(NULL);

    EventDelegate delegatecopy;
    delegatecopy.invoke(NULL);
}
