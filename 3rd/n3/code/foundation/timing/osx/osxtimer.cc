//------------------------------------------------------------------------------
//  win360timer.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "timing/osx/osxtimer.h"

namespace OSX
{

//------------------------------------------------------------------------------
/**
*/
OSXTimer::OSXTimer() :
    running(false),
    diffTime(0),
    stopTime(0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
    Start the timer. This will update the diffTime member to reflect
    the accumulated time when the timer was not running (basically the
    difference between this timer's time and the real system time).
*/
void
OSXTimer::Start()
{
    n_assert(!this->running);
    
    // query the current real time and update the diffTime member
    // to take the "lost" time into account since the timer was stopped
    __int64_t curRealTime;
    //QueryPerformanceCounter((LARGE_INTEGER*) &curRealTime);
    curRealTime = 0;
    this->diffTime += curRealTime - this->stopTime;
    this->stopTime = 0;
    this->running = true;
}

//------------------------------------------------------------------------------
/**
    Stop the timer. This will record the current realtime, so that
    the next Start() can measure the time lost between Stop() and Start()
    which must be taken into account to keep track of the difference between
    this timer's time and realtime.
*/
void
OSXTimer::Stop()
{
    n_assert(this->running);
    //QueryPerformanceCounter((LARGE_INTEGER*) &this->stopTime);
    this->stopTime = 0;
    this->running = false;
}

//------------------------------------------------------------------------------
/**
    Reset the timer so that will start counting at zero again.
*/
void
OSXTimer::Reset()
{
    bool wasRunning = this->running;
    if (wasRunning)
    {
        this->Stop();
    }
    this->stopTime = 0;
    this->diffTime = 0;
    if (wasRunning)
    {
        this->Start();
    }
}

//------------------------------------------------------------------------------
/**
    Returns true if the timer is currently running.
*/
bool
OSXTimer::Running() const
{
    return this->running;
}

//------------------------------------------------------------------------------
/**
    This returns the internal local time as large integer.
*/
__int64_t
OSXTimer::InternalTime() const
{
    // get the current real time
    __int64_t time;
    if (this->running)
    {
        // we are running, query current time
        //QueryPerformanceCounter((LARGE_INTEGER*) &time);
      time = 0;
    }
    else
    {
        // we are stopped, use time at last stop
        time = this->stopTime;
    }
 
    // convert to local time
    time -= this->diffTime;

    return time;
}

//------------------------------------------------------------------------------
/**
    This returns the timer's current time in seconds.
*/
Timing::Time
OSXTimer::GetTime() const
{
    // get the current real time
    __int64_t time = this->InternalTime();

    // query the performance frequency
    __int64_t freq;
    //QueryPerformanceFrequency((LARGE_INTEGER*) &freq);
    freq = 0;
 
    // convert to seconds
    Timing::Time seconds = ((Timing::Time)time) / ((Timing::Time)freq);
    return seconds;
}

//------------------------------------------------------------------------------
/**
    This returns the timer's current time in "ticks". A tick is defined
    as one millisecond (1/1000 seconds).
*/
Timing::Tick
OSXTimer::GetTicks() const
{
    // get the current real time
    __int64_t time = this->InternalTime();

    // query the performance frequency
    __int64_t freq;
    //QueryPerformanceFrequency((LARGE_INTEGER*) &freq);
    freq = 0;

    __int64_t ticks64 = time / (freq / 1000);
    return (Timing::Tick) ticks64;
}

} // namespace OSX
