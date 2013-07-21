#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLIndexBuffer
  
    OpenGL implementation of index buffer.
    
    (C) 2013 Larry Weya
*/
#include "coregraphics/base/indexbufferbase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLIndexBuffer : public Base::IndexBufferBase
{
    __DeclareClass(OGLIndexBuffer);
public:
    /// constructor
    OGLIndexBuffer();
    /// destructor
    virtual ~OGLIndexBuffer();
    
    /// unload the resource, or cancel the pending load
    virtual void Unload();
    /// map index buffer for CPU access
    void* Map(MapType mapType);
    /// unmap the resource
    void Unmap();

    /// set GL index buffer pointer
    void SetGLIndexBuffer(GLuint ptr);
    /// get GL index buffer pointer
    GLuint GetGLIndexBuffer() const;

private:
    GLuint glIndexBuffer;
    int mapCount;
};

//------------------------------------------------------------------------------
/**
*/
inline void
OGLIndexBuffer::SetGLIndexBuffer(GLuint buffer)
{
    n_assert(0 != buffer);
    n_assert(0 == this->glIndexBuffer);
    this->glIndexBuffer = buffer;
}

//------------------------------------------------------------------------------
/**
*/
inline GLuint
OGLIndexBuffer::GetGLIndexBuffer() const
{
    n_assert(0 != this->glIndexBuffer);
    n_assert(0 == this->mapCount);
    return this->glIndexBuffer;
}

} // namespace OGL
//------------------------------------------------------------------------------
