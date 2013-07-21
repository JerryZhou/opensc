#include "base/refcounted.h"

using namespace Base;

TEST(Refcounted, constructor){
    Refcounted target;
    EXPECT_EQ(target.RetainCount(), 0);
}
