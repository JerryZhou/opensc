//------------------------------------------------------------------------------
//  osxysteminfo.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "system/osx/osxsysteminfo.h"

namespace OSX
{

//------------------------------------------------------------------------------
/**
*/
OSXSystemInfo::OSXSystemInfo()
{
    int nm[2];
    size_t len = 4;
    uint32_t data;
    char machine_arch[10];
    const char* x86_64 = "x86_64";
    const char* x86_32 = "x86";
    
    this->platform = OSX;
    
    // get page size
    nm[0] = CTL_HW; nm[1] = HW_PAGESIZE;
    sysctl(nm, 2, &data, &len, NULL, 0);
    this->pageSize = data;
    
    // get num cpus
    sysctlbyname("hw.logicalcpu", &data, &len, NULL, 0);
    this->numCpuCores = data;
    
    // get machine architecture
    nm[1] = HW_MACHINE; len = 10;
    sysctl(nm, 2, &machine_arch, &len, NULL, 0);
    if(strcmp(machine_arch, x86_64) == 0)
    {
        this->cpuType = X86_64;
    }
    else if(strcmp(machine_arch, x86_32) == 0)
    {
        this->cpuType = X86_32;
    }
    else
    {
        this->cpuType = UnknownCpuType;
    }
}

} // namespace OSX