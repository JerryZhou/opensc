#pragma once
//------------------------------------------------------------------------------
/** 
    @class OGL::OGLVertexComponent
  
    OpenGL implementation of VertexComponent.
    
    (C) 2013 Larry Weya
*/    
#include "coregraphics/base/vertexcomponentbase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLVertexComponent : public Base::VertexComponentBase
{
public:
    /// vertex attribute indexes to bind
    enum AttributeIndex
    {
        PositionAttr = 0,
        NormalAttr,
        TangentAttr,
        BinormalAttr,
        TexCoord0Attr,
        TexCoord1Attr,
        TexCoord2Attr,
        TexCoord3Attr,
        TexCoord4Attr,
        TexCoord5Attr,
        TexCoord6Attr,
        TexCoord7Attr,
        ColorAttr,
        SkinWeightsAttr,
        SkinJIndicesAttr,
        
        Invalid,
    };
    
    /// default constructor
    OGLVertexComponent() { };
    /// constructor
    OGLVertexComponent(SemanticName semName_, IndexT semIndex_, Format format_, IndexT streamIndex_=0) : VertexComponentBase(semName_, semIndex_, format_, streamIndex_) { };
    
    /// Get the shader attribute index for the component ate index
    static AttributeIndex SemanticNameToAttributeIndex(SemanticName n, IndexT semIndex = 0);
};
    
//------------------------------------------------------------------------------
/**
 * Returns the attribute index for the semantic
 */
inline OGLVertexComponent::AttributeIndex
OGLVertexComponent::SemanticNameToAttributeIndex(SemanticName n, IndexT semIndex)
{
    switch (n)
    {
        case SemanticName::Position:      return PositionAttr;
        case SemanticName::Normal:        return NormalAttr;
        case SemanticName::Tangent:       return TangentAttr;
        case SemanticName::Binormal:      return BinormalAttr;
        case SemanticName::TexCoord:
            switch(semIndex)
            {
                case 0: return TexCoord0Attr;
                case 1: return TexCoord1Attr;
                case 2: return TexCoord2Attr;
                case 3: return TexCoord3Attr;
                case 4: return TexCoord4Attr;
                case 5: return TexCoord5Attr;
                case 6: return TexCoord6Attr;
                case 7: return TexCoord7Attr;
            }
        case SemanticName::Color:         return ColorAttr;
        case SemanticName::SkinWeights:   return SkinWeightsAttr;
        case SemanticName::SkinJIndices:  return SkinJIndicesAttr;
        default:
            n_error("OGLVertexBuffer::SemanticNameToAttributeIndex(): invalid SemanticName code!");
            return Invalid;
    }
}

} // namespace OGL
//------------------------------------------------------------------------------

