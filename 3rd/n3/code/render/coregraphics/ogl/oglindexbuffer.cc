//------------------------------------------------------------------------------
//  d3d9indexbuffer.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglindexbuffer.h"

namespace OGL
{
__ImplementClass(OGL::OGLIndexBuffer, 'D9IB', Base::IndexBufferBase);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
OGLIndexBuffer::OGLIndexBuffer() :
    glIndexBuffer(0),
    mapCount(0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
OGLIndexBuffer::~OGLIndexBuffer()
{
    n_assert(0 == this->glIndexBuffer);
    n_assert(0 == this->mapCount);
}

//------------------------------------------------------------------------------
/**
*/
void
OGLIndexBuffer::Unload()
{
    n_assert(0 == this->mapCount);
    if (0 != this->glIndexBuffer)
    {
        glDeleteBuffers(1, &this->glIndexBuffer);
        this->glIndexBuffer = 0;
    }
    IndexBufferBase::Unload();
}

//------------------------------------------------------------------------------
/**
*/
void*
OGLIndexBuffer::Map(MapType mapType)
{
    n_assert(0 != this->glIndexBuffer);
    void* ptr = 0;
    // TODO: map buffer
    n_error("OGLIndexBuffer::Map called\n");
    this->mapCount++;
    return ptr;
}

//------------------------------------------------------------------------------
/**
*/
void
OGLIndexBuffer::Unmap()
{
    n_assert(0 != this->glIndexBuffer);
    n_assert(this->mapCount > 0);
    // TODO: unmap buffer
    n_error("OGLIndexBuffer::Map called\n");
    this->mapCount--;
}

} // namespace OGL
