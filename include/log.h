#ifndef __LOG_H_
#define __LOG_H_
#include "stdinc.h"

#define  JE_LOG_TAG "cocos2d-x"

#ifndef LOGD
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG, JE_LOG_TAG, __VA_ARGS__)
#endif

#ifndef LOGE
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, JE_LOG_TAG, __VA_ARGS__)
#endif

#endif
