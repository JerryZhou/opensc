#include "eventjni.h"
#include "event.h"
#include "eventdispatch.h"

USING_NS_CC;
//---------------------------------------------------------------------------------
struct JniEventContext{
	JniMethodInfo  addEventMethodId;
	JniMethodInfo  removeEventMethodId;

	void setup(JNIEnv *env){
		if(! JniHelper::getStaticMethodInfo(addEventMethodId, "com/duowan/pad/cocos2dx/YYCocos2dRoom", "addEvent", "(I)V")){
			LOGE("can not find class com/duowan/pad/cocos2dx/YYCocos2dRoom::addEvent");
		}

		if(! JniHelper::getStaticMethodInfo(addEventMethodId, "com/duowan/pad/cocos2dx/YYCocos2dRoom", "removeEvent", "(I)V")){
			LOGE("can not find class com/duowan/pad/cocos2dx/YYCocos2dRoom::removeEvent");
		}
	}

	void addEvent(int id){
		if(addEventMethodId.classID && addEventMethodId.methodID){
			addEventMethodId.env->CallStaticVoidMethod(addEventMethodId.classID, addEventMethodId.methodID, id);
		}
	}

	void removeEvent(int id){
		if(removeEventMethodId.classID && removeEventMethodId.methodID){
			removeEventMethodId.env->CallStaticVoidMethod(removeEventMethodId.classID, removeEventMethodId.methodID, id);
		}
	}
};
static JniEventContext eventContext = {0};
static volatile bool baseStart = false;
void setup_event_jni(JNIEnv *env){
	IF_DO(baseStart, return);
	baseStart = true;
	eventContext.setup(env);
}

//----------------------------------------------------------------------------------
int post_event_from_java(JNIEnv *env, int evtId, jobjectArray args){
	Base::Event evt;
	evt.id = evtId;
	evt.env = env;
	evt.args = args;
	evt.param = NULL;
	Base::eventDispatch()->dispatch(&evt);
	return 0;
}

//----------------------------------------------------------------------------------
int add_event_from_jni(int evt){
	eventContext.addEvent(evt);
}

//----------------------------------------------------------------------------------
int remove_event_from_jni(int evt){
	eventContext.removeEvent(evt);
}

