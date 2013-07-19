#ifndef __MACRODEF_H_
#define __MACRODEF_H_

#include "interlocked.h"
#include "mutex.h"

#define IF_DO(con, doit ) do { if(con) { doit; } }while(false)
#define IF_DO_THEN_DO(con, doit, thendoit ) do { if(con) { doit; } else { thendoit; } }while(false)

#define J_ASSERT(con) assert(con)

/**
 * clamp the v to [min, max]
 * */
inline int clamp(int v, int min, int max) {
	IF_DO(v > max, return max);
	IF_DO(v < min, return min);
	return v;
}

/**
 * max the value
 * */
template<typename T>
inline const T& J_Max(const T &a, const T &b){
	IF_DO(a > b, return a);
	return b;
}

/**
 * get array size
 * */
#ifndef __countof
#define __countof(array) (sizeof(array)/sizeof(array[0]))
#endif

/**
 * global instance :
 * */
template<typename T>
class InstanceHolder {
public:
	typedef T* InstancePtr;
	InstanceHolder(InstancePtr& ref) :
			instance(ref) {
		;
	}
	~InstanceHolder() {
		delete instance;
		instance = NULL;
	}
	InstancePtr &instance;
};

/// declare macro
#define J_GLOBAL_INSTANCE_DECLARE(type, name) type* name()
#define J_GLOBAL_INSTANCE(type, name) \
	type* name(){ \
		static type* instance = NULL;\
		if(instance == NULL){\
			instance = new type();\
			if(instance){\
				static InstanceHolder<type> holder(instance); \
			}\
		}\
		return instance;\
	}

#endif