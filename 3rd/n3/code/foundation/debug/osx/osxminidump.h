#pragma once
#ifndef OSX_OSXMINIDUMP_H
#define OSX_OSXMINIDUMP_H
//------------------------------------------------------------------------------
/**
    @class Win32::Win32MiniDump
  
    Win32 implementation of MiniDump.
    
    (C) 2007 Radon Labs GmbH
*/
#include "core/types.h"
#include "util/string.h"

//------------------------------------------------------------------------------
namespace OSX
{
class OSXMiniDump
{
public:
    /// setup the the Win32 exception callback hook
    static void Setup();
    /// write a mini dump
    static bool WriteMiniDump();

private:
};
 
} // namespace OSX
//------------------------------------------------------------------------------
#endif
