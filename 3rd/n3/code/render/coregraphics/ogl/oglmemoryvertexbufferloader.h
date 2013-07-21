#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLMemoryVertexBufferLoader
    
    Initialize an OGLVertexBuffer from data in memory on the Open GL
    platform. This resource loader only creates static VertexBuffers which are 
    initialized once and are not accessible by the CPU.
    
    (C) 2013 Larry Weya
*/
#include "coregraphics/base/memoryvertexbufferloaderbase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLMemoryVertexBufferLoader : public Base::MemoryVertexBufferLoaderBase
{
    __DeclareClass(OGLMemoryVertexBufferLoader);
public:
    /// called by resource when a load is requested
    virtual bool OnLoadRequested();
};

} // namespace OGL
//------------------------------------------------------------------------------
