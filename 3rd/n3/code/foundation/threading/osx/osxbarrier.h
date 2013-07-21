#pragma once

//------------------------------------------------------------------------------
/**
    @class Darwin::DarwinBarrier
    
    Implements the 2 macros ReadWriteBarrier and MemoryBarrier.
    
    ReadWriteBarrier prevents the compiler from re-ordering memory
    accesses accross the barrier.

    MemoryBarrier prevents the CPU from reordering memory access across
    the barrier (all memory access will be finished before the barrier
    is crossed).
    
    (C) 2007 Radon Labs GmbH
*/
#include "core/types.h"
#include <libkern/OSAtomic.h>

//------------------------------------------------------------------------------
#define ReadWriteBarrier OSMemoryBarrier
#define MemoryBarrier OSMemoryBarrier
//------------------------------------------------------------------------------