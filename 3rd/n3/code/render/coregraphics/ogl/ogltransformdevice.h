#pragma once
//------------------------------------------------------------------------------
/**
 @class OGL::OGLTransformDevice
 
 Open GL version of TransformDevice.
 
 (C) 2013 Larry Weya
 */
#include "coregraphics/base/transformdevicebase.h"
#include "coregraphics/shadervariable.h"
#include "core/singleton.h"

//------------------------------------------------------------------------------
namespace OGL
{
    class OGLTransformDevice : public Base::TransformDeviceBase
    {
        __DeclareClass(OGLTransformDevice);
        __DeclareSingleton(OGLTransformDevice);
    public:
        /// constructor
        OGLTransformDevice();
        /// destructor
        virtual ~OGLTransformDevice();
        
        /// updates shared shader variables dependent on view matrix
        void ApplyViewSettings();
        /// apply any model transform needed, implementation is platform dependend
        void ApplyModelTransforms(const Ptr<CoreGraphics::ShaderInstance>& shdInst);
        
    private:
        CoreGraphics::ShaderVariable::Semantic mvpSemantic;
        CoreGraphics::ShaderVariable::Semantic modelSemantic;
        CoreGraphics::ShaderVariable::Semantic modelViewSemantic;
        CoreGraphics::ShaderVariable::Semantic viewSemantic;
        CoreGraphics::ShaderVariable::Semantic invViewSemantic;
        CoreGraphics::ShaderVariable::Semantic invModelViewSemantic;
        CoreGraphics::ShaderVariable::Semantic viewProjSemantic;
        CoreGraphics::ShaderVariable::Semantic eyePosSemantic;
        CoreGraphics::ShaderVariable::Semantic halfPixelSizeSemantic;
        CoreGraphics::ShaderVariable::Semantic projectionSemantic;
        CoreGraphics::ShaderVariable::Semantic invProjectionSemantic;
    };
    
} // namespace OGL
//------------------------------------------------------------------------------
