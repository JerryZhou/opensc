//------------------------------------------------------------------------------
//  oglvertexbuffer.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglvertexbuffer.h"
#include "coregraphics/ogl/gldebug.h"
#include "coregraphics/ogl/ogltypes.h"

namespace OGL
{
__ImplementClass(OGL::OGLVertexBuffer, 'GLVB', Base::VertexBufferBase);

using namespace CoreGraphics;
using namespace Resources;

//------------------------------------------------------------------------------
/**
*/
OGLVertexBuffer::OGLVertexBuffer() :
    glVertexBuffer(0),
    glVertexArray(0),
    mapCount(0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
OGLVertexBuffer::~OGLVertexBuffer()
{
    n_assert(0 == this->glVertexBuffer);
    n_assert(0 == this->mapCount);
}
    
//------------------------------------------------------------------------------
/**
 */
Resource::State
OGLVertexBuffer::Load()
{
    /// run load to allow setting vertex array and buffer
    State loadState = VertexBufferBase::Load();
    
    n_assert(this->glVertexArray != 0);
    
    // vertex array to allow binding attributes
    GLDEBUG(glBindVertexArray(this->glVertexArray));
    
    /// enable each component within vertex array
    GLsizei stride = this->vertexLayout->GetVertexByteSize();
    IndexT compIndex;
    for(compIndex = 0; compIndex < this->vertexLayout->GetNumComponents(); compIndex++)
    {
        const VertexComponent& comp = this->vertexLayout->GetComponentAt(compIndex);
        VertexComponent::SemanticName sem = comp.GetSemanticName();
        n_dbgout("Semantic: %d, Name: %s, Sem Index: %d\n", sem, VertexComponent::SemanticNameToString(sem).AsCharPtr(), comp.GetSemanticIndex());
        
        OGLVertexComponent::AttributeIndex attrIndex = OGLVertexComponent::SemanticNameToAttributeIndex(sem, comp.GetSemanticIndex());
        n_dbgout("Attribute Index: %d\n", attrIndex);
        
        const VertexComponent::Format format = comp.GetFormat();
        
        GLint numComps = OGLTypes::NumComponentsFromFormat(format);
        GLenum dataType = OGLTypes::FormatToGLenum(format);
        GLboolean normalized = OGLTypes::ShouldNormalize(format);
        IndexT byteOffset = comp.GetByteOffset();
        
        /// setup vertex attributes
        GLDEBUG(glEnableVertexAttribArray(attrIndex));
        GLDEBUG(glVertexAttribPointer(attrIndex, numComps, dataType, normalized, stride, (void*)byteOffset));
    }
    
    // unbind vertex array
    GLDEBUG(glBindVertexArray(0));
    
    return loadState;
}

//------------------------------------------------------------------------------
/**
*/
void
OGLVertexBuffer::Unload()
{
    n_assert(0 == this->mapCount);
    if (0 != this->glVertexBuffer)
    {
        glDeleteBuffers(1, &this->glVertexBuffer);
        this->glVertexBuffer = 0;
    }
    if (0 != this->glVertexArray)
    {
        glDeleteVertexArrays(1, &this->glVertexArray);
        this->glVertexArray = 0;
    }
    VertexBufferBase::Unload();
}

//------------------------------------------------------------------------------
/**
*/
void*
OGLVertexBuffer::Map(MapType mapType)
{
    n_assert(0 != this->glVertexBuffer);
    
    void* ptr = 0;
    /// TODO: Map buffer
    n_error("OGLVertexBuffer::Map called\n");
    return ptr;
}

//------------------------------------------------------------------------------
/**
*/
void
OGLVertexBuffer::Unmap()
{
    n_assert(0 != this->glVertexBuffer);
    n_assert(this->mapCount > 0);
    /// TODO: Map buffer
    n_error("OGLVertexBuffer::Unmap called\n");
    this->mapCount--;
}

} // namespace OGL
