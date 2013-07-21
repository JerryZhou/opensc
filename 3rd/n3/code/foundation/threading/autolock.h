#pragma once
//------------------------------------------------------------------------------
/**
    @class Threading::AutoLock

    (C) 2013 JerryZhou@outlook.com
*/

#include "core/types.h"
#include "threading/criticalsection.h"

//------------------------------------------------------------------------------
namespace Threading
{
class AutoLock
{
public:
    /// constructor
    AutoLock(const Threading::CriticalSection& ref)
    : mutex(ref){
	mutex.Enter();
    }
    /// destructor
    ~AutoLock(){
	mutex.Leave();
    }

private:
    const Threading::CriticalSection &mutex;
};
}
