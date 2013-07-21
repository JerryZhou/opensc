#pragma once
//------------------------------------------------------------------------------
/**
 @class OGL::OGLShaderInstance
 
 Open GL implementation of CoreGraphics::ShaderInstance.
 
 @todo lost/reset device handling
 
 (C) 2007 Radon Labs GmbH
 */
#include "coregraphics/base/shaderinstancebase.h"
#include "coregraphics/shaderfeature.h"

namespace Base
{
    class ShaderBase;
}

//------------------------------------------------------------------------------
namespace OGL
{
    class OGLShaderInstance : public Base::ShaderInstanceBase
    {
        __DeclareClass(OGLShaderInstance);
    public:
        /// constructor
        OGLShaderInstance();
        /// destructor
        virtual ~OGLShaderInstance();
        /// get glsl program
        GLuint GetGLSLProgram() const;
        
        /// select active variation by feature mask
        bool SelectActiveVariation(CoreGraphics::ShaderFeature::Mask featureMask);
        /// begin rendering through the currently selected variation, returns no. passes
        SizeT Begin();
        /// end rendering through variation
        void End();
        
    protected:
        friend class Base::ShaderBase;
        friend class OGLShader;
        
        /// setup the shader instance from its original shader object
        virtual void Setup(const Ptr<CoreGraphics::Shader>& origShader);
        /// cleanup the shader instance
        virtual void Cleanup();
        
        GLuint glslProgram; // points to the same program as the parent shader
    };
    
    //------------------------------------------------------------------------------
    /**
     */
    inline GLuint
    OGLShaderInstance::GetGLSLProgram() const
    {
        n_assert(0 != this->glslProgram);
        return this->glslProgram;
    }
    
} // namespace OGL
//------------------------------------------------------------------------------

