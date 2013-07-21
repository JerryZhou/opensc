#pragma once
//------------------------------------------------------------------------------
/**
    @class OSX::OSXEvent

    OSX implmentation of an event synchronization object.

    (C) 2013 Larry Weya
*/
#include "core/types.h"

//------------------------------------------------------------------------------
namespace OSX
{
class OSXEvent
{
public:
    /// constructor
    OSXEvent(bool manualReset=false);
    /// destructor
    ~OSXEvent();
    /// signal the event
    void Signal();
    /// reset the event (only if manual reset)
    void Reset();
    /// wait for the event to become signalled
    void Wait() const;
    /// wait for the event with timeout in millisecs
    bool WaitTimeout(int ms) const;
    /// check if event is signalled
    bool Peek() const;
private:
    mutable pthread_mutex_t mutex;
    mutable pthread_cond_t condition;
    bool isSignalled;
};

//------------------------------------------------------------------------------
/**
*/
inline
OSXEvent::OSXEvent(bool manualReset)
{
    pthread_mutex_init(&this->mutex, NULL);
    pthread_cond_init (&this->condition, NULL);
}

//------------------------------------------------------------------------------
/**
*/
inline
OSXEvent::~OSXEvent()
{
    pthread_cond_destroy(&this->condition);
    pthread_mutex_destroy(&this->mutex);
}

//------------------------------------------------------------------------------
/**
*/
inline void
OSXEvent::Signal()
{
    pthread_mutex_lock(&this->mutex);
    pthread_cond_signal(&this->condition);
    this->isSignalled = true;
    pthread_mutex_unlock(&this->mutex);
}

//------------------------------------------------------------------------------
/**
*/
inline void
OSXEvent::Reset()
{
    // signal any waiters
    this->Signal();
    pthread_mutex_lock(&this->mutex);
    this->isSignalled = false;
    pthread_mutex_unlock(&this->mutex);
}

//------------------------------------------------------------------------------
/**
*/
inline void
OSXEvent::Wait() const
{
    pthread_mutex_lock(&this->mutex);
    if(!this->isSignalled)
    {
        pthread_cond_wait(&this->condition, &this->mutex);
    }
    pthread_mutex_unlock(&this->mutex);
}

//------------------------------------------------------------------------------
/**
    Waits for the event to become signaled with a specified timeout
    in milli seconds. If the method times out it will return false,
    if the event becomes signalled within the timeout it will return 
    true.
*/
inline bool
OSXEvent::WaitTimeout(int timeoutInMilliSec) const
{
    /*pthread_mutex_lock(&this->mutex);
    if(!this->isSignalled)
    {
        timespec tm;
        tm.tv_sec = 0;
        tm.tv_nsec = timeoutInMilliSec/1000;
        pthread_cond_timedwait(&this->condition, &this->mutex);
    }
    pthread_mutex_unlock(&this->mutex);*/
    n_error("OSXEvent::WaitTimeout called");
    return false;
}

//------------------------------------------------------------------------------
/**
    This checks if the event is signalled and returnes immediately.
*/
inline bool
OSXEvent::Peek() const
{
    return this->isSignalled;
}

} // namespace OSX
//------------------------------------------------------------------------------

