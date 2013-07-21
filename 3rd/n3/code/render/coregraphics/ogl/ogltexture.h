#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLTexture
    
    OGL implementation of Texture class
    
    (C) 2013 Larry Weya
*/
#include "coregraphics/base/texturebase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLTexture : public Base::TextureBase
{
    __DeclareClass(OGLTexture);
public:
    /// constructor
    OGLTexture();
    /// destructor
    virtual ~OGLTexture();

    /// unload the resource, or cancel the pending load
    virtual void Unload();
    /// map a texture mip level for CPU access
    bool Map(IndexT mipLevel, MapType mapType, MapInfo& outMapInfo);
    /// unmap texture after CPU access
    void Unmap(IndexT mipLevel);
    /// map a cube map face for CPU access
    bool MapCubeFace(CubeFace face, IndexT mipLevel, MapType mapType, MapInfo& outMapInfo);
    /// unmap cube map face after CPU access
    void UnmapCubeFace(CubeFace face, IndexT mipLevel);
    ///
    void SetupFromOGLTexture(GLint tex2D, const bool setLoaded);
    ///
    GLint GetGLTexture() const;

protected:
    GLint texture;
};

//------------------------------------------------------------------------------
/**
 */
inline GLint
OGLTexture::GetGLTexture() const
{
    return this->texture;
}
} // namespace OGL
//------------------------------------------------------------------------------
    