#ifndef __INTERLOCKED_H_
#define __INTERLOCKED_H_

namespace Base {
class Interlocked {
public:
	/// interlocked increment, return result
	static int Increment(int volatile& var);
	/// interlocked decrement, return result
	static int Decrement(int volatile& var);
	/// interlocked add
	static int Add(int volatile& var, int a);
	/// interlocked exchange
	static int Exchange(int volatile* dest, int value);
	/// interlocked compare-exchange
	static int CompareExchange(int volatile* dest, int e, int comparand);
};

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::Increment(int volatile& var) {
	return __sync_fetch_and_add(&var, 1);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::Decrement(int volatile& var) {
	return __sync_fetch_and_add(&var, -1);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::Add(int volatile& var, int a) {
	return __sync_fetch_and_add(&var, a);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::Exchange(int volatile* dest, int value) {
	return __sync_lock_test_and_set(dest, value);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::CompareExchange(int volatile* dest, int e,
		int comparand) {
	return __sync_bool_compare_and_swap(dest, e, comparand);
}
}// end of Base
#endif
