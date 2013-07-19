#include <stdlib.h>
#include <stdio.h>
#include "gtest/gtest.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

#include "test_log.h"
#include "test_mutex.h"
#include "test_target.h"
#include "test_refcountedtarget.h"

int main(int argc, char* argv[]){
    InitGoogleTest(&argc, argv);

    int ret_val = RUN_ALL_TESTS();
    
    return ret_val;
}
