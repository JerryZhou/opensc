//------------------------------------------------------------------------------
//  osxminidump.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "debug/minidump.h"

namespace OSX
{
using namespace Util;

//------------------------------------------------------------------------------
/**
    This static method registers our own exception handler with Windows.
*/
void
OSXMiniDump::Setup()
{
    
}

//------------------------------------------------------------------------------
/**
    This method is called by n_assert() and n_error() to write out
    a minidump file.
*/
bool
OSXMiniDump::WriteMiniDump()
{
    return true;
}

} // namespace Debug
