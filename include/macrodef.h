#ifndef __MACRODEF_H_
#define __MACRODEF_H_

#define OPENSC_DEBUG (1)

#define OPENSC_UNUSED_ATTR

#define IF_DO(con, doit ) do { if(con) { doit; } }while(false)
#define IF_DO_THEN_DO(con, doit, thendoit ) do { if(con) { doit; } else { thendoit; } }while(false)

#define J_ASSERT(con) assert(con)

#define J_ASSERT2(con, ...) do {\
    if(!(con)) { \
	Base::__sc_log_print(Base::SC_LOG_FATAL, JE_LOG_TAG, __VA_ARGS__); \
	assert(false); \
    } }while(false)

#define J_SafeRelease(t) do { if(t) { t->Release(); t = NULL; } }while(false)

#define J_SafeRetain(t) do { if(t) { t->Retain(); } }while(false)

#define J_Name(TYPE) #TYPE
#define J_DeclareName(TYPE) Util::StringAtom name;

/**
 * pow of num
 **/
template<typename TYPE>
inline int J_PowOf(TYPE v){
    int x=0;
    while(v>1) {
        v>>=1;
        x++;
    }
    return x;
}

/**
 * clamp the v to [min, max]
 * */
inline int J_Clamp(int v, int min, int max) {
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

#endif
