#pragma once
//------------------------------------------------------------------------------
/**
    @class Win360::Win360Timer
    
    OSX implementation of the Time::Timer class. Uses 
    the QueryPerformanceCounter() functions.

    @todo solve multiprocessor issues of QueryPerformanceCounter()
    (different processors may return different PerformanceFrequency
    values, thus, threads should be prevented from switching between
    processors with thread affinities).
    
    (C) 2013 Larry Weya
*/
#include "core/types.h"
#include "timing/time.h"

//------------------------------------------------------------------------------
namespace OSX
{
class OSXTimer
{
public:
    /// constructor
    OSXTimer();
    /// start/continue the timer
    void Start();
    /// stop the timer
    void Stop();
    /// reset the timer
    void Reset();
    /// return true if currently running
    bool Running() const;
    /// get current time in seconds
    Timing::Time GetTime() const;
    /// get current time in ticks
    Timing::Tick GetTicks() const;

private:
    /// return internal time as 64 bit integer
    __int64_t InternalTime() const;

    bool running;
    __int64_t diffTime;  // accumulated time when the timer was not running
    __int64_t stopTime;  // when was the timer last stopped?
};

} // namespace OSX
//------------------------------------------------------------------------------
   