#pragma once
//------------------------------------------------------------------------------
/**
    @class OSX::OSXThreadBarrier
    
    Block until all thread have arrived at the barrier.
    
    (C) 2009 Radon Labs GmbH
*/
#include "core/types.h"
#include "threading/criticalsection.h"

//------------------------------------------------------------------------------
namespace OSX
{
class OSXThreadBarrier
{
public:
    /// constructor
    OSXThreadBarrier();
    /// destructor
    ~OSXThreadBarrier();
    /// setup the object with the number of threads
    void Setup(SizeT numThreads);
    /// return true if the object has been setup
    bool IsValid() const;
    /// enter thread barrier, return false if not all threads have arrived yet
    bool Arrive();
    /// call after Arrive() returns false to wait for other threads
    void Wait();
    /// call after Arrive() returns true to resume all threads
    void SignalContinue();

private:
    Threading::CriticalSection critSect;
    long numThreads;
    volatile long outstandingThreads;
    pthread_mutex_t mutex;
    pthread_cond_t condition;
    bool isValid;
};

//------------------------------------------------------------------------------
/**
*/
inline
OSXThreadBarrier::OSXThreadBarrier() :
    numThreads(0),
    outstandingThreads(0),
    isValid(false)
{
    /* Initialize mutex and condition variable objects */
    int res = pthread_mutex_init(&this->mutex, NULL);
    n_assert(0 == res);
    res = pthread_cond_init (&this->condition, NULL);
    n_assert(0 == res);    
}

//------------------------------------------------------------------------------
/**
*/
inline
OSXThreadBarrier::~OSXThreadBarrier()
{
    int res = pthread_mutex_destroy(&this->mutex);
    n_assert(0 == res);
    res = pthread_cond_destroy(&this->condition);
    n_assert(0 == res);
}

//------------------------------------------------------------------------------
/**
*/
inline void
OSXThreadBarrier::Setup(SizeT num)
{
    n_assert(!this->isValid);
    this->numThreads = num;
    this->outstandingThreads = num;
    this->isValid = true;
}

//------------------------------------------------------------------------------
/**
*/
inline bool
OSXThreadBarrier::IsValid() const
{
    return this->isValid;
}

//------------------------------------------------------------------------------
/**
    Notify arrival at thread-sync point, return false if not all threads
    have arrived yet, and true if all threads have arrived. If the
    method returns false, you should immediately call Wait(), if the
    method returns true, the caller has a chance to perform some actions
    which should happen before threads continue, and then call the
    SignalContinue() method.
*/
inline bool
OSXThreadBarrier::Arrive()
{
    this->critSect.Enter();
    n_assert(this->outstandingThreads > 0);
    this->outstandingThreads--;
    return (0 == this->outstandingThreads);
}

//------------------------------------------------------------------------------
/**
    This method should be called when Arrive() returns false. It will
    put the thread to sleep because not all threads have arrived yet.
    When the method returns, all threads have arrived at the sync point.

    NOTE: sometimes both the render and the main thread arrive here
    with the outstandingThreads member set to 1 (from two) causing
    both thread to be waiting idefinitely.
*/
inline void
OSXThreadBarrier::Wait()
{
    this->critSect.Leave();
    
    pthread_mutex_lock(&this->mutex);
    pthread_cond_wait(&this->condition, &this->mutex);
    pthread_mutex_unlock(&this->mutex);
}

//------------------------------------------------------------------------------
/**
    This method should be called after Arrive() returns true. This means
    that all threads have arrived at the sync point and execution of all
    threads may resume.
*/
inline void
OSXThreadBarrier::SignalContinue()
{
    this->outstandingThreads = this->numThreads;
    this->critSect.Leave();
    
    // let sleeping threads not lie
    pthread_cond_broadcast(&this->condition);
}

} // namespace OSX
//------------------------------------------------------------------------------
    