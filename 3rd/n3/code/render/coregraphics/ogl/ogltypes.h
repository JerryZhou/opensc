#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLTypes
    
    Provides static helper functions to convert from and to OpenGL
    data types and enumerations.
    
    (C) 2013 Larry Weya
*/
#include "core/types.h"
#include "coregraphics/pixelformat.h"
#include "coregraphics/vertexcomponent.h"
#include "coregraphics/primitivetopology.h"
#include "coregraphics/antialiasquality.h"
#include "coregraphics/imagefileformat.h"
#include "coregraphics/indextype.h"
#include "coregraphics/base/resourcebase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLTypes
{
public:
    /// convert primitive topology to OpenGL primitive
    static GLenum AsOGLPrimitiveType(CoreGraphics::PrimitiveTopology::Code t);
    /// convert index type to OpenGL index type
    static GLenum IndexTypeAsOGLType(CoreGraphics::IndexType::Code indexType);
    /// Convert the N3 format to a GLenum
    static GLenum FormatToGLenum(const CoreGraphics::VertexComponent::Format f);
    /// determine the number of components from the format
    static GLint NumComponentsFromFormat(const CoreGraphics::VertexComponent::Format f);
    /// return true if the data of the specified format needs to be normalized
    static GLboolean ShouldNormalize(const CoreGraphics::VertexComponent::Format f);
};

} // namespace OGL
//------------------------------------------------------------------------------
