//------------------------------------------------------------------------------
//  ogltexture.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/ogltexture.h"
#include "coregraphics/ogl/gldebug.h"
#include "coregraphics/ogl/ogltypes.h"

namespace OGL
{
__ImplementClass(OGL::OGLTexture, 'GLTX', Base::TextureBase);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
OGLTexture::OGLTexture()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
OGLTexture::~OGLTexture()
{
}

//------------------------------------------------------------------------------
/**
*/
void
OGLTexture::Unload()
{
    TextureBase::Unload();
}

//------------------------------------------------------------------------------
/**
*/
bool
OGLTexture::Map(IndexT mipLevel, MapType mapType, MapInfo& outMapInfo)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
void
OGLTexture::Unmap(IndexT mipLevel)
{
}

//------------------------------------------------------------------------------
/**
*/
bool
OGLTexture::MapCubeFace(CubeFace face, IndexT mipLevel, MapType mapType, MapInfo& outMapInfo)
{
    return false;
}

//------------------------------------------------------------------------------
/**
*/
void
OGLTexture::UnmapCubeFace(CubeFace face, IndexT mipLevel)
{
}
    
//------------------------------------------------------------------------------
/**
 Helper method to setup the texture object from an OpenGL 2D texture.
 */
void
OGLTexture::SetupFromOGLTexture(GLint tex2D, const bool setLoaded)
{
    n_assert(0 != tex2D);
    
    GLint miplevel = 0;
    GLenum target = GL_TEXTURE_2D;
    GLint width;
    GLint height;
    
    this->texture = tex2D;
    
    // @todo: add GLDEBUG calls after reactoring its location
    GLDEBUG(glBindTexture(target, tex2D))
    GLDEBUG(glGetTexLevelParameteriv(target, miplevel, GL_TEXTURE_WIDTH, &width))
    GLDEBUG(glGetTexLevelParameteriv(target, miplevel, GL_TEXTURE_HEIGHT, &height))
    
    this->SetType(Type::Texture2D);
    this->SetWidth(width);
    this->SetHeight(height);
    this->SetDepth(1);
    //this->SetNumMipLevels(tex2D->GetLevelCount());
    //this->SetPixelFormat(D3D9Types::AsNebulaPixelFormat(desc.Format));
    if (setLoaded)
    {
        this->SetState(Resource::Loaded);
    }
}

} // namespace OGL