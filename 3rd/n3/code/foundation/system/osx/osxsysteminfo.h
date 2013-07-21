#pragma once
//------------------------------------------------------------------------------
/**
    @class OSX::OSXSystemInfo
    
    Provide information about the system we're running on.
    
    (C) 2013 Larry Weya
*/
#include "system/base/systeminfobase.h"

//------------------------------------------------------------------------------
namespace OSX
{
class OSXSystemInfo : public Base::SystemInfoBase
{
public:
    /// constructor
    OSXSystemInfo();
};

} // namespace OSX
//------------------------------------------------------------------------------
