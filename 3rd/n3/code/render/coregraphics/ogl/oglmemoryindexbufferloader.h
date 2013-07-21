#pragma once
//------------------------------------------------------------------------------
/**
 @class OGL::OGLMemoryIndexBufferLoader
 
 Initialize an Open GL index buffer from data in memory for the Open GL
 platform. This resource loader only creates static IndexBuffers which are
 initialized once and are not accessible by the CPU.
 
 (C) 2013 Larry Weya
 */
#include "coregraphics/base/memoryindexbufferloaderbase.h"

//------------------------------------------------------------------------------
namespace OGL
{
    class OGLMemoryIndexBufferLoader : public Base::MemoryIndexBufferLoaderBase
    {
        __DeclareClass(OGLMemoryIndexBufferLoader);
    public:
        /// called by resource when a load is requested
        virtual bool OnLoadRequested();
    };
    
} // namespace OGL
//------------------------------------------------------------------------------
