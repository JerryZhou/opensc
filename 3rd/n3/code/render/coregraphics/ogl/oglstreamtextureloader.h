#pragma once
//------------------------------------------------------------------------------
/**
 @class OGL::OGLStreamTextureLoader
 
 OpenGL implementation of StreamTextureLoader.
 
 (C) 2013 Larry Weya
 */
#include "resources/streamresourceloader.h"

//------------------------------------------------------------------------------
namespace OGL
{
    class OGLStreamTextureLoader : public Resources::StreamResourceLoader
    {
        __DeclareClass(OGLStreamTextureLoader);
    private:
        /// setup the texture from a Nebula3 stream
        virtual bool SetupResourceFromStream(const Ptr<IO::Stream>& stream);
    };
    
} // namespace OGL
//------------------------------------------------------------------------------
