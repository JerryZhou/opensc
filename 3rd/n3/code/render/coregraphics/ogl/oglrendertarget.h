#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLRenderTarget
  
    OGL implementation of RenderTarget.
    
    (C) 2013 Larry Weya
*/    
#include "coregraphics/base/rendertargetbase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLRenderTarget : public Base::RenderTargetBase
{
    __DeclareClass(OGLRenderTarget);
public:
    /// constructor
    OGLRenderTarget();
    /// destructor
    virtual ~OGLRenderTarget();
    
    /// setup the render target object
    void Setup();
    /// discard the render target object
    void Discard();
    /// begin a render pass
    void BeginPass();
    /// end current render pass
    void EndPass();
    /// generate mipmap levels
    void GenerateMipLevels();

protected:
    friend class OGLRenderDevice;
};

} // namespace Direct3D9
//------------------------------------------------------------------------------
