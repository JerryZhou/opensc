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

#include "test_macrodef.h"
#include "test_mutex.h"
#include "test_target.h"

#include "base/test_log.h"
#include "base/test_refcountedtarget.h"
#include "base/event/test_event.h"
#include "base/event/test_eventtarget.h"
#include "base/event/test_eventdelegate.h"
#include "base/event/test_eventdispatch.h"

int main(int argc, char* argv[]){
    InitGoogleTest(&argc, argv);

    int ret_val = RUN_ALL_TESTS();
    
    return ret_val;
}
