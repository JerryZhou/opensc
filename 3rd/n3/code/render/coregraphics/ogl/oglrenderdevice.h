#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLRenderDevice
  
    Implements a RenderDevice on top of OpenGL.
    
    (C) 2013 Larry Weya
*/    
#include "coregraphics/base/renderdevicebase.h"
#include "coregraphics/pixelformat.h"
#include "coregraphics/imagefileformat.h"

//------------------------------------------------------------------------------
namespace OGL
{

#define NEBULA3_USE_FLOAT_DEPTHBUFFER 0

class OGLRenderDevice : public Base::RenderDeviceBase
{
    __DeclareClass(OGLRenderDevice);
    __DeclareSingleton(OGLRenderDevice);
public:
    /// constructor
    OGLRenderDevice();
    /// destructor
    virtual ~OGLRenderDevice();

    /// test if a compatible render device can be created on this machine
    static bool CanCreate();

    /// open the device
    bool Open();
    /// close the device
    void Close();

    /// begin complete frame
    bool BeginFrame();
    /// set the current vertex stream source
    void SetStreamSource(IndexT streamIndex, const Ptr<CoreGraphics::VertexBuffer>& vb, IndexT offsetVertexIndex);
    /// set current vertex layout
    void SetVertexLayout(const Ptr<CoreGraphics::VertexLayout>& vl);
    /// set current index buffer
    void SetIndexBuffer(const Ptr<CoreGraphics::IndexBuffer>& ib);
    /// draw current primitives
    void Draw();
    /// draw indexed, instanced primitives (see method header for details)
    void DrawIndexedInstanced(SizeT numInstances);
    /// end current pass
    void EndPass();
    /// end complete frame
    void EndFrame();
    /// present the rendered scene
    void Present();
    /// save a screenshot to the provided stream
    CoreGraphics::ImageFileFormat::Code SaveScreenshot(CoreGraphics::ImageFileFormat::Code fmt, const Ptr<IO::Stream>& outStream);
    /// get the current pass or batch shader
    const Ptr<CoreGraphics::ShaderInstance>& CurrentShaderInstance() const;

private:
    ///
    void SetInitialDeviceState();
    ///
    void SyncGPU();
};
    
//------------------------------------------------------------------------------
/**
 * Return the current bound shader instance for use by the transfom device
 */
inline const Ptr<CoreGraphics::ShaderInstance>&
OGLRenderDevice::CurrentShaderInstance() const
{
    n_assert(this->passShader.isvalid() || this->batchShader.isvalid());
    n_assert(this->inBeginPass || this->inBeginBatch);
    
    if(this->inBeginBatch)
    {
        return this->batchShader;
    }
    else
    {
        return this->passShader;
    }
}

} // namespace OGL
//------------------------------------------------------------------------------
