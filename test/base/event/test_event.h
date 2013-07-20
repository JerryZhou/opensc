#include "base/event/event.h"

TEST(Event, constructor){
    Event evt;
    EXPECT_TRUE(evt.id == 0);
    EXPECT_TRUE(evt.param == NULL);
}
