#include "stdinc.h"
#include "base/log.h"

TEST(Log, loglevels){
    LOGV("this is verbose log");
    LOGI("this is info log");
    LOGW("this is warn log");
    LOGD("this is debug log");
    LOGE("this is error log");
    LOGF("this is fatal log");
}

