#ifndef __EVENTJNI_H_
#define __EVENTJNI_H_ 

#include "stdinc.h"

//----------------------------------------------------------------------------------
void setup_event_jni(JNIEnv *env);

int post_event_from_java(JNIEnv *env, int evt, jobjectArray args);

int add_event_from_jni(int evt);

int remove_event_from_jni(int evt);

#endif
