#ifndef __MUTEX_H_
#define __MUTEX_H_

#include <pthread.h>

namespace Base {
//--------------------------------------------------------------------------
// pthread mutex lock: recursive lock, reentrant thread mutex
//--------------------------------------------------------------------------
class ThreadMutex {
public:
	ThreadMutex() {
		pthread_mutexattr_t    attr;
		pthread_mutexattr_init(&attr);
		pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
		pthread_mutex_init(&mutex, &attr);
		pthread_mutexattr_destroy(&attr);
	}
	~ThreadMutex() {
		pthread_mutex_destroy(&mutex);
	}

	void lock() const {
		pthread_mutex_lock((pthread_mutex_t*) (&mutex));
	}

	void unlock() const {
		pthread_mutex_unlock((pthread_mutex_t*) (&mutex));
	}

private:
	pthread_mutex_t mutex;
};

//--------------------------------------------------------------------------
// auto mutex lock
//--------------------------------------------------------------------------
class AutoLock {
public:
	AutoLock(const ThreadMutex &mux) :
			mutex(mux) {
		mutex.lock();
	}
	~AutoLock() {
		mutex.unlock();
	}

private:
	const ThreadMutex& mutex;
};
}
#endif

