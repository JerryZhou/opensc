#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLDisplayDevice
    
    OpenGL implementation of DisplayDevice class. Manages the application
    window.
    
    (C) 2013 Larry Weya
*/
#include "coregraphics/base/displaydevicebase.h"

//------------------------------------------------------------------------------
namespace App { class MyGameApplication; }
namespace OGL
{
class OGLDisplayDevice : public Base::DisplayDeviceBase
{
    __DeclareClass(OGLDisplayDevice);
    __DeclareSingleton(OGLDisplayDevice);
    
public:
    /// constructor
    OGLDisplayDevice();
    /// destructor
    virtual ~OGLDisplayDevice();

    /// open the display
    virtual bool Open();
    /// close the display
    virtual void Close();
    /// open the window
    virtual bool OpenWindow();
    /// close the window
    virtual void CloseWindow();
    /// process window system messages, call this method once per frame
    virtual void ProcessWindowMessages();
    
    /// get the application window
    GLFWwindow* GetWindow() const;

protected:
    GLFWwindow* window;

private:
    static void ErrorCallback(int error, const char* description);
};
    //------------------------------------------------------------------------------
/**
*/
inline GLFWwindow*
OGLDisplayDevice::GetWindow() const
{
    return this->window;
}

} // namespace OGL
//------------------------------------------------------------------------------

    