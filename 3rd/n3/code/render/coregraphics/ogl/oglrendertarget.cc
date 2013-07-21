//------------------------------------------------------------------------------
//  d3d9rendertarget.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/config.h"
#include "coregraphics/rendertarget.h"
#include "coregraphics/ogl/oglrenderdevice.h"
#include "coregraphics/displaydevice.h"

namespace OGL
{
__ImplementClass(OGL::OGLRenderTarget, 'GLRT', Base::RenderTargetBase);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
OGLRenderTarget::OGLRenderTarget()
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
OGLRenderTarget::~OGLRenderTarget()
{
    n_assert(!this->isValid);
}

//------------------------------------------------------------------------------
/**
*/
void
OGLRenderTarget::Setup()
{    
    // call parent class
    RenderTargetBase::Setup();
    
    // if we're the default render target, query display device
    // for setup parameters
    if (this->isDefaultRenderTarget)
    {
        // NOTE: the default render target will never be anti-aliased!
        // this assumes a render pipeline where the actual rendering goes
        // into an offscreen render target and is then resolved to the back buffer
        //DisplayDevice* displayDevice = DisplayDevice::Instance();
        this->SetWidth(1024);//displayDevice->GetDisplayMode().GetWidth());
        this->SetHeight(768);//displayDevice->GetDisplayMode().GetHeight());
        this->SetAntiAliasQuality(AntiAliasQuality::None);
        this->SetColorBufferFormat(PixelFormat::X8R8G8B8);//displayDevice->GetDisplayMode().GetPixelFormat());
    }
}

//------------------------------------------------------------------------------
/**
*/
void
OGLRenderTarget::Discard()
{
    RenderTargetBase::Discard();
}

//------------------------------------------------------------------------------
/**
*/
void
OGLRenderTarget::BeginPass()
{
    RenderTargetBase::BeginPass();
}

//------------------------------------------------------------------------------
/**
*/
void
OGLRenderTarget::EndPass()
{
    RenderTargetBase::EndPass();
}

//------------------------------------------------------------------------------
/**
*/
void
OGLRenderTarget::GenerateMipLevels()
{
    n_error("OGLRenderTarget::GenerateMipLevels called\n");
}

} // namespace OGL
