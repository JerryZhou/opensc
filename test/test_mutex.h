#include "mutex.h"

TEST(Mutex, lockAndUnlock){
    Base::ThreadMutex mutex;
    mutex.lock();
    mutex.unlock();
}

TEST(AutoLock, autoLock){
    Base::ThreadMutex mutex;
    {
	Base::AutoLock lock(mutex);
    }
}

TEST(AutoLock, autoLock_Tiwce){
    Base::ThreadMutex mutex;
    {
	Base::AutoLock lock(mutex);
	Base::AutoLock lock2(mutex);
    }
}
