//------------------------------------------------------------------------------
//  win32displaydevice.cc
//  (C) 2006 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/ogldisplaydevice.h"

namespace OGL
{
__ImplementClass(OGL::OGLDisplayDevice, 'OGLD', Base::DisplayDeviceBase);
__ImplementSingleton(OGL::OGLDisplayDevice);

using namespace CoreGraphics;
using namespace Math;

//------------------------------------------------------------------------------
/**
 */
OGLDisplayDevice::OGLDisplayDevice() :
    window(0)
{
    __ConstructSingleton;
    glfwSetErrorCallback(OGLDisplayDevice::ErrorCallback);
    
    // initialise glfw
    if (!glfwInit())
        n_error("Error initialising glfw\n");
}

//------------------------------------------------------------------------------
/**
 */
OGLDisplayDevice::~OGLDisplayDevice()
{
    if (this->IsOpen())
    {
        this->Close();
    }
    
    glfwTerminate();
    __DestructSingleton;
}

//------------------------------------------------------------------------------
/**
 */
bool
OGLDisplayDevice::Open()
{
    n_assert(!this->IsOpen());
    if (DisplayDeviceBase::Open())
    {
        bool success = this->OpenWindow();
        return success;
    }
    return false;
}

//------------------------------------------------------------------------------
/**
 */
void
OGLDisplayDevice::Close()
{
    n_assert(this->IsOpen());
    this->CloseWindow();
    DisplayDeviceBase::Close();
}

//------------------------------------------------------------------------------
/**
 Polls for and processes window messages. Call this message once per
 frame in your render loop. If the user clicks the window close
 button, or hits Alt-F4, a CloseRequested input event will be sent.
 */
void
OGLDisplayDevice::ProcessWindowMessages()
{
    n_assert(this->IsOpen());
    
    // it may happen that the WinProc has already closed our window!
    if (0 != this->window)
    {
        // TODO: how about non-realtime windows that would be better off with a glfwWaitEvents()
        glfwPollEvents();
    }
}

//------------------------------------------------------------------------------
/**
 Open the application window.
 */
bool
OGLDisplayDevice::OpenWindow()
{
    n_assert(0 == this->window);
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
            
    // TODO: initialize application icon
    
    // TODO: check if fullscreen
    //DisplayMode adjMode = this->ComputeAdjustedWindowRect();
    
    // open window
    this->window = glfwCreateWindow(1024, 768, "Nebula 3 - Window", NULL, NULL);// lParam
    n_assert(0 != this->window);
    
    // TODO: check always-on-top
    
    return true;
}

//------------------------------------------------------------------------------
/**
 Close the application window.
 */
void
OGLDisplayDevice::CloseWindow()
{
    // close the window (if not already happened), the window may
    // have been closed externally by Alt-F4 (for instance)
    if (0 != this->window)
    {
        glfwDestroyWindow(this->window);
        this->window = 0;
    }
}
    
//------------------------------------------------------------------------------
/**
 Close the application window.
 */
void
OGLDisplayDevice::ErrorCallback(int error, const char* description)
{
    n_error("OGLDisplayDevice::Error %s", description);
}
    
} // namespace CoreGraphics