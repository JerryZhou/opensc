#include "base/event/event.h"
#include "messaging/message.h"

using namespace Base;
using namespace Core;
using namespace Messaging;

TEST(Event, constructor){
    Ptr<Event> evt = Event::Create();
    EXPECT_TRUE(evt->GetId() == Event::Id);
}
