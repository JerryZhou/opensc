#pragma once
//------------------------------------------------------------------------------
/** 
    @class OGL::OGLVertexBuffer
  
    OpenGL implementation of VertexBuffer.
    
    (C) 2013 Larry Weya
*/    
#include "coregraphics/base/vertexbufferbase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLVertexBuffer : public Base::VertexBufferBase
{
    __DeclareClass(OGLVertexBuffer);
public:
    /// constructor
    OGLVertexBuffer();
    /// destructor
    virtual ~OGLVertexBuffer();
    
    /// load the resource
    virtual Resource::State Load();
    /// unload the resource, or cancel the pending load
    virtual void Unload();
    /// map the vertices for CPU access
    void* Map(MapType mapType);
    /// unmap the resource
    void Unmap();

    /// set gl vertex buffer
    void SetGLVertexBuffer(GLuint buffer);
    /// get pointer to GL vertex buffer object
    GLuint GetGLVertexBuffer() const;
    
    /// set gl vertex array
    void SetGLVertexArray(GLuint glBuffer);
    /// get pointer to GL vertex buffer object
    GLuint GetGLVertexArray() const;

private:
    GLuint glVertexBuffer;
    GLuint glVertexArray;
    int mapCount;
};

//------------------------------------------------------------------------------
/**
*/
inline void
OGLVertexBuffer::SetGLVertexBuffer(GLuint buffer)
{
    n_assert(0 != buffer);
    n_assert(0 == this->glVertexBuffer);
    this->glVertexBuffer = buffer;
}

//------------------------------------------------------------------------------
/**
*/
inline GLuint
OGLVertexBuffer::GetGLVertexBuffer() const
{
    n_assert(0 != this->glVertexBuffer);
    n_assert(0 == this->mapCount);
    return this->glVertexBuffer;
}
    
//------------------------------------------------------------------------------
/**
 */
inline void
OGLVertexBuffer::SetGLVertexArray(GLuint vertexArray)
{
    n_assert(0 != vertexArray);
    n_assert(0 == this->glVertexArray);
    this->glVertexArray = vertexArray;
}

//------------------------------------------------------------------------------
/**
 */
inline GLuint
OGLVertexBuffer::GetGLVertexArray() const
{
    n_assert(0 != this->glVertexArray);
    return this->glVertexArray;
}

} // namespace OGL
//------------------------------------------------------------------------------

