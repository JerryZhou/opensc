//------------------------------------------------------------------------------
//  oglstreamtextureloader.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglstreamtextureloader.h"
#include "coregraphics/texture.h"
#include "coregraphics/renderdevice.h"
#include "io/ioserver.h"
#include "SOIL.h"

namespace OGL
{
__ImplementClass(OGL::OGLStreamTextureLoader, 'GLTL', Resources::StreamResourceLoader);

using namespace CoreGraphics;
using namespace Resources;
using namespace IO;

//------------------------------------------------------------------------------
/**
 This method actually setups the Texture object from the data in the stream.
 */
bool
OGLStreamTextureLoader::SetupResourceFromStream(const Ptr<Stream>& stream)
{
    n_assert(stream.isvalid());
    n_assert(stream->CanBeMapped());

    n_assert(this->resource->IsA(Texture::RTTI));
    const Ptr<Texture>& res = this->resource.downcast<Texture>();
    n_assert(!res->IsLoaded());
    
    stream->SetAccessMode(Stream::ReadAccess);
    if (stream->Open())
    {
        unsigned char* srcData = (unsigned char*)stream->Map();
        Stream::Size srcDataSize = stream->GetSize();
        
        GLint texture = SOIL_load_OGL_texture_from_memory(srcData, srcDataSize, SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
                                          SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT | SOIL_FLAG_TEXTURE_REPEATS);
        n_dbgout("SOIL_last_result: %s\n", SOIL_last_result());
        n_assert(texture != 0);
        
        // @todo: handle 1D, 3D etc. textures
        res->SetupFromOGLTexture(texture, true);
        
        stream->Unmap();
        stream->Close();
        return true;
    }
    return false;
}
    
} // namespace OGL