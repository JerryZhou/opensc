//------------------------------------------------------------------------------
//  oglrenderdevice.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/config.h"
#include "coregraphics/ogl/oglrenderdevice.h"
#include "coregraphics/ogl/gldebug.h"
#include "coregraphics/displaydevice.h"
#include "coregraphics/vertexbuffer.h"
#include "coregraphics/indexbuffer.h"
#include "coregraphics/ogl/ogltypes.h"

namespace OGL
{
__ImplementClass(OGL::OGLRenderDevice, 'GLRD', Base::RenderDeviceBase);
__ImplementSingleton(OGL::OGLRenderDevice);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
OGLRenderDevice::OGLRenderDevice()
{
    __ConstructSingleton;
}

//------------------------------------------------------------------------------
/**
*/
OGLRenderDevice::~OGLRenderDevice()
{
    if (this->IsOpen())
    {
        this->Close();
    }
    __DestructSingleton;
}

//------------------------------------------------------------------------------
/**
    Test if the right OpenGL version is available by trying to open
    OpenGL.
*/
bool
OGLRenderDevice::CanCreate()
{
    n_error("OGLRenderDevice::CanCreate() called");
    return false;
}

//------------------------------------------------------------------------------
/**
    Open the render device. When successful, the RenderEvent::DeviceOpen
    will be sent to all registered event handlers after the Direct3D
    device has been opened.
*/
bool
OGLRenderDevice::Open()
{
    n_assert(!this->IsOpen());
    bool success = false;
    
    // attach context
    glfwMakeContextCurrent(DisplayDevice::Instance()->GetWindow());
    
    glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
    success = RenderDeviceBase::Open();
    return success;
}

//------------------------------------------------------------------------------
/**
    Close the render device. The RenderEvent::DeviceClose will be sent to
    all registered event handlers.
*/
void
OGLRenderDevice::Close()
{
    n_assert(this->IsOpen());
    RenderDeviceBase::Close();
    
    /// detach context
    //glfwMakeContextCurrent(NULL);
}

//------------------------------------------------------------------------------
/**
    Initialize the Direct3D device with initial device state.
*/
void
OGLRenderDevice::SetInitialDeviceState()
{
    n_error("OGLRenderDevice::SetInitialDeviceState called\n");
    //glViewport()
}

//------------------------------------------------------------------------------
/**
    Begin a complete frame. Call this once per frame before any rendering 
    happens. If rendering is not possible for some reason (e.g. a lost
    device) the method will return false. This method may also send
    the DeviceLost and DeviceRestored RenderEvents to attached event
    handlers.
*/
bool
OGLRenderDevice::BeginFrame()
{
    n_assert(this->IsOpen());
    if (RenderDeviceBase::BeginFrame())
    {
        // TODO: move this to render target
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
/**
    End a complete frame. Call this once per frame after rendering
    has happened and before Present(), and only if BeginFrame() returns true.
*/
void
OGLRenderDevice::EndFrame()
{
    RenderDeviceBase::EndFrame();
}

//------------------------------------------------------------------------------
/**
    End the current rendering pass. This will flush all texture stages
    in order to keep the d3d9 resource reference counts consistent without too
    much hassle.
*/
void
OGLRenderDevice::EndPass()
{
    RenderDeviceBase::EndPass();
}

//------------------------------------------------------------------------------
/**
    NOTE: Present() should be called as late as possible after EndFrame()
    to improve parallelism between the GPU and the CPU.
*/
void
OGLRenderDevice::Present()
{
    RenderDeviceBase::Present();

    glfwSwapBuffers(DisplayDevice::Instance()->GetWindow());

    // sync cpu thread with gpu
    //this->SyncGPU();
}

//------------------------------------------------------------------------------
/**
    Sets the vertex buffer to use for the next Draw().
*/
void
OGLRenderDevice::SetStreamSource(IndexT streamIndex, const Ptr<VertexBuffer>& vb, IndexT offsetVertexIndex)
{
    n_assert((streamIndex >= 0) && (streamIndex < MaxNumVertexStreams));
    //n_assert(this->inBeginPass);
    n_assert(this->IsOpen());    
    n_assert(vb.isvalid());
    if ((this->streamVertexBuffers[streamIndex] != vb) || (this->streamVertexOffsets[streamIndex] != offsetVertexIndex))
    {
        GLDEBUG(glBindVertexArray(vb->GetGLVertexArray()));
    }
    RenderDeviceBase::SetStreamSource(streamIndex, vb, offsetVertexIndex);
}

//------------------------------------------------------------------------------
/**
    Sets the vertex layout for the next Draw()
*/
void
OGLRenderDevice::SetVertexLayout(const Ptr<VertexLayout>& vl)
{
    //n_assert(this->inBeginPass);
    n_assert(this->IsOpen());    
    n_assert(vl.isvalid());

    if (this->vertexLayout != vl)
    {
        //n_error("OGLRenderDevice::SetVertexLayout called\n");
    }
    RenderDeviceBase::SetVertexLayout(vl);
}

//------------------------------------------------------------------------------
/**
    Sets the index buffer to use for the next Draw().
*/
void
OGLRenderDevice::SetIndexBuffer(const Ptr<IndexBuffer>& ib)
{
    //n_assert(this->inBeginPass);
    n_assert(this->IsOpen());
    n_assert(ib.isvalid());

    if (this->indexBuffer != ib)
    {
        GLDEBUG(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib->GetGLIndexBuffer()));
    }
    RenderDeviceBase::SetIndexBuffer(ib);
}

//------------------------------------------------------------------------------
/**
    Draw the current primitive group. Requires a vertex buffer, an
    optional index buffer and a primitive group to be set through the
    respective methods. To use non-indexed rendering, set the number
    of indices in the primitive group to 0.
*/
void
OGLRenderDevice::Draw()
{
    //n_assert(this->inBeginPass);
    n_assert(this->IsOpen());

    // TODO: determine OGL primitive type
    GLenum primitiveType = OGLTypes::AsOGLPrimitiveType(this->primitiveGroup.GetPrimitiveTopology());
    
    SizeT numIndices = this->primitiveGroup.GetNumIndices();
    this->primitiveGroup.GetPrimitiveTopology();
    if (numIndices > 0)
    {
        n_assert(this->indexBuffer.isvalid());
        GLDEBUG(glDrawElements(
                               primitiveType,
                               numIndices,
                               OGLTypes::IndexTypeAsOGLType(this->indexBuffer->GetIndexType()),
                               (void*)(sizeof(GLshort)*0)));
    }
    else
    {
        n_error("OGLRenderDevice::Draw called on a primitive group without indices\n");
        GLDEBUG(glDrawArrays(GL_TRIANGLES, 0, 6));
    }
    // update debug stats
    //_incr_counter(RenderDeviceNumPrimitives, this->primitiveGroup.GetNumPrimitives());
    _incr_counter(RenderDeviceNumDrawCalls, 1);
}

//------------------------------------------------------------------------------
/**
    Draw N instances of the current primitive group. Requires the following
    setup:
        
        - vertex stream 0: vertex buffer with instancing data, one vertex per instance
        - vertex stream 1: vertex buffer with instance geometry data
        - index buffer: index buffer for geometry data
        - primitive group: the primitive group which describes one instance
        - vertex declaration: describes a combined vertex from stream 0 and stream 1
*/
void
OGLRenderDevice::DrawIndexedInstanced(SizeT numInstances)
{
    n_assert(this->inBeginPass);
    n_assert(numInstances > 0);
    n_assert(this->IsOpen());

    n_error("OGLRenderDevice::DrawIndexedInstanced called\n");

    // update debug stats
    _incr_counter(RenderDeviceNumPrimitives, this->primitiveGroup.GetNumPrimitives() * numInstances);
    _incr_counter(RenderDeviceNumDrawCalls, 1);
}

//------------------------------------------------------------------------------
/**
    Save the backbuffer to the provided stream.
*/
ImageFileFormat::Code
OGLRenderDevice::SaveScreenshot(ImageFileFormat::Code fmt, const Ptr<IO::Stream>& outStream)
{
    n_assert(!this->inBeginFrame);
    
    n_error("OGLRenderDevice::SaveScreenshot called\n");
    
    return fmt;
}

//------------------------------------------------------------------------------
/**
*/
void 
OGLRenderDevice::SyncGPU()
{
    n_error("OGLRenderDevice::SyncGPU called\n");
}
} // namespace CoreGraphics
