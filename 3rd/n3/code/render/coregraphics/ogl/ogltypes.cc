//------------------------------------------------------------------------------
//  ogltypes.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/ogltypes.h"

namespace OGL
{
using namespace Base;
using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
GLenum
OGLTypes::AsOGLPrimitiveType(PrimitiveTopology::Code t)
{
    switch (t)
    {
        case PrimitiveTopology::PointList:      return GL_POINTS;
        case PrimitiveTopology::LineList:       return GL_LINES;
        case PrimitiveTopology::LineStrip:      return GL_LINE_STRIP;
        case PrimitiveTopology::TriangleList:   return GL_TRIANGLES;
        case PrimitiveTopology::TriangleStrip:  return GL_TRIANGLE_STRIP;
        default:
            n_error("OGLTypes::AsOGLPrimitiveType(): unsupported topology '%s'!",
                PrimitiveTopology::ToString(t).AsCharPtr());
            return GL_TRIANGLES;
    }
}

//------------------------------------------------------------------------------
/**
*/
GLenum
OGLTypes::IndexTypeAsOGLType(IndexType::Code indexType)
{
    return (IndexType::Index16 == indexType) ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT;
}
    
//------------------------------------------------------------------------------
/**
 * Returns GLenum for the specified format
 */
GLenum
OGLTypes::FormatToGLenum(const VertexComponent::Format f)
{
    switch (f) {
        case VertexComponent::Float:
        case VertexComponent::Float2:
        case VertexComponent::Float3:
        case VertexComponent::Float4:
            return GL_FLOAT;
        case VertexComponent::UByte4:
        case VertexComponent::UByte4N:
            return GL_UNSIGNED_BYTE;
        case VertexComponent::Short2:
        case VertexComponent::Short4:
        case VertexComponent::Short2N:
        case VertexComponent::Short4N:
            return GL_SHORT;
        default:
            n_error("OGLVertexBuffer::FormatToGLenum(): invalid Format!");
            return -1;
    }
}

//------------------------------------------------------------------------------
/**
 * Returns GLenum for the specified format
 */
GLint
OGLTypes::NumComponentsFromFormat(const VertexComponent::Format f)
{
    switch (f) {
        case VertexComponent::Float:
            return 1;
        case VertexComponent::Float2:
        case VertexComponent::Short2:
        case VertexComponent::Short2N:
            return 2;
        case VertexComponent::Float3:
            return 3;
        case VertexComponent::Float4:
        case VertexComponent::Short4:
        case VertexComponent::Short4N:
        case VertexComponent::UByte4:
        case VertexComponent::UByte4N:
            return 4;
        default:
            n_error("OGLVertexBuffer::NumComponentsFromFormat(): invalid Format!");
            return -1;
    }
}

//------------------------------------------------------------------------------
/**
 * Returns true if the data should be normalized
 */
GLboolean
OGLTypes::ShouldNormalize(const VertexComponent::Format f)
{
    switch (f) {
        case VertexComponent::Short2:
        case VertexComponent::Short4:
        case VertexComponent::UByte4:
            return GL_TRUE;
        case VertexComponent::Float:
        case VertexComponent::Float2:
        case VertexComponent::Float3:
        case VertexComponent::Float4:
        case VertexComponent::Short4N:
        case VertexComponent::UByte4N:
            return GL_FALSE;
        default:
            n_error("OGLVertexBuffer::ShouldBeNormalized(): invalid Format!");
            return GL_FALSE;
    }
}

} // namespace OGL
