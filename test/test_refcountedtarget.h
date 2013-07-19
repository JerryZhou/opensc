#include "base/refcountedtarget.h"

using namespace Base;

TEST(RefcountedTarget, constructor){
    RefcountedTarget target;
    EXPECT_EQ(target.retainCount(), 1);
}
