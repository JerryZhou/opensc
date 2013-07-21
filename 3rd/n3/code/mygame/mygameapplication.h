#pragma once
//------------------------------------------------------------------------------
/**
    @class DevTestApplication
    
    App to test OSX port interation.
    
    (C) 2013 Larry Weya
*/
#include "io/iointerface.h"
#include "debug/debughandler.h"
#include "http/httpinterface.h"
#include "coregraphics/displaydevice.h"
#include "coregraphics/transformdevice.h"
#include "coregraphics/mesh.h"
#include "coregraphics/shader.h"
#include "coregraphics/shaderinstance.h"
#include "coregraphics/renderdevice.h"
#include "coregraphics/vertexlayoutserver.h"
#include "app/consoleapplication.h"

//------------------------------------------------------------------------------
namespace App
{
class MyGameApplication : public ConsoleApplication
{
public:
    /// open the application
    virtual bool Open();
    /// run the application
    virtual void Run();
    /// close the application
    virtual void Close();
    
    /// check if quit was requested
    bool IsQuitRequested() const;
    /// request quit
    void SetQuitRequested();
    
protected:
    Ptr<IO::IoInterface> ioInterface;
    Ptr<Debug::DebugHandler> debugHandler;
    Ptr<CoreGraphics::DisplayDevice> displayDevice;
    Ptr<CoreGraphics::RenderDevice> renderDevice;
    Ptr<CoreGraphics::VertexLayoutServer> vertexLayoutServer;
    Ptr<Http::HttpInterface> httpInterface;
    Ptr<CoreGraphics::TransformDevice> transformDevice;
    Ptr<CoreGraphics::Mesh> mesh;
    Ptr<CoreGraphics::Shader> shader;
    Ptr<CoreGraphics::ShaderInstance> shaderInstance;
    Ptr<CoreGraphics::Texture> diffMap0Texture;
    CoreGraphics::ShaderVariable::Semantic diffMap0Semantic;
    IndexT streamIndex;
    IndexT offsetVertexIndex;
    bool quitRequested;
}; 

//------------------------------------------------------------------------------
/**
 */
inline bool
MyGameApplication::IsQuitRequested() const
{
    return this->quitRequested;
}

//------------------------------------------------------------------------------
/**
 */
inline void
MyGameApplication::SetQuitRequested()
{
    this->quitRequested = true;
}
} // namespace App
//------------------------------------------------------------------------------
