#ifndef __INTERLOCKED_H_
#define __INTERLOCKED_H_

namespace Base {
class Interlocked {
public:
	/// interlocked increment, return result
	static int increment(int volatile& var);
	/// interlocked decrement, return result
	static int decrement(int volatile& var);
	/// interlocked add
	static int add(int volatile& var, int a);
	/// interlocked exchange
	static int exchange(int volatile* dest, int value);
	/// interlocked compare-exchange
	static int compareExchange(int volatile* dest, int e, int comparand);
};

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::increment(int volatile& var) {
	return __sync_fetch_and_add(&var, 1);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::decrement(int volatile& var) {
	return __sync_fetch_and_add(&var, -1);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::add(int volatile& var, int a) {
	return __sync_fetch_and_add(&var, a);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::exchange(int volatile* dest, int value) {
	return __sync_lock_test_and_set(dest, value);
}

//------------------------------------------------------------------------------
/**
 */
inline int Interlocked::compareExchange(int volatile* dest, int e,
		int comparand) {
	return __sync_bool_compare_and_swap(dest, e, comparand);
}
}// end of Base
#endif
