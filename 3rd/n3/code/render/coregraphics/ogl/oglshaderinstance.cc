//------------------------------------------------------------------------------
//  d3d9shaderinstance.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglshaderinstance.h"
#include "coregraphics/ogl/gldebug.h"
#include "coregraphics/renderdevice.h"
#include "coregraphics/shader.h"
#include "coregraphics/shadervariable.h"
#include "coregraphics/shadervariation.h"

namespace OGL
{
__ImplementClass(OGL::OGLShaderInstance, 'GLSI', Base::ShaderInstanceBase);

using namespace Util;
using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
 */
OGLShaderInstance::OGLShaderInstance() :
    glslProgram(0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
 */
OGLShaderInstance::~OGLShaderInstance()
{
    n_assert(0 == this->glslProgram);
}

//------------------------------------------------------------------------------
/**
 This method is called by Shader::CreateInstance() to setup the
 new shader instance.
 */
void
OGLShaderInstance::Setup(const Ptr<Shader>& origShader)
{
    n_assert(origShader.isvalid());
    n_assert(0 == this->glslProgram);
    
    const Ptr<OGLShader>& oglShader = origShader.upcast<OGLShader>();
    this->glslProgram = oglShader->GetGLSLProgram();
    
    // call parent class
    ShaderInstanceBase::Setup(origShader);
    
    GLint params;
    GLDEBUG(glGetProgramiv(this->glslProgram, GL_ACTIVE_UNIFORMS, &params));
    GLchar attrName[100];
    GLsizei attrLen;
    GLint attrSize;
    GLenum attrType;
    
    // setup shader variables
    SizeT paramIndex;
    for(paramIndex = 0; paramIndex < params; paramIndex++)
    {
        GLDEBUG(glGetActiveUniform(this->glslProgram, paramIndex, 100, &attrLen, &attrSize, &attrType, attrName));
        n_dbgout("Name: %s, len: %d, size: %d, type: %d\n", attrName, attrLen, attrSize, attrType);
        Ptr<ShaderVariable> shaderVariable = ShaderVariable::Create();
        
        /// get attribute index
        GLDEBUG(GLuint attrIndex = glGetUniformLocation(this->glslProgram, attrName));
        ///
        shaderVariable->Setup(this->glslProgram, attrIndex, attrName, attrType);
        this->variables.Append(shaderVariable);
        this->variablesByName.Add(shaderVariable->GetName(), shaderVariable);
        this->variablesBySemantic.Add(shaderVariable->GetSemantic(), shaderVariable);
    }
    
    // setup a default variation
    Ptr<ShaderVariation> shaderVariation = ShaderVariation::Create();
    //shaderVariation->Setup(this->d3d9Effect, hTechnique);
    this->variations.Add(shaderVariation->GetFeatureMask(), shaderVariation);
    
    n_assert(this->variations.Size() > 0);
    
    // select a proper default active variation
    this->SelectActiveVariation(this->variations.KeyAtIndex(0));
}

//------------------------------------------------------------------------------
/**
 */
void
OGLShaderInstance::Cleanup()
{
    n_assert(0 != this->glslProgram);
    // TODO: is it possible for the parent shader ro get deleted before its children?
    this->glslProgram = 0;
    ShaderInstanceBase::Cleanup();
}

//------------------------------------------------------------------------------
/**
 */
bool
OGLShaderInstance::SelectActiveVariation(ShaderFeature::Mask featureMask)
{
    if (ShaderInstanceBase::SelectActiveVariation(featureMask))
    {
        n_dbgout("OGLShaderInstance::SelectActiveVariation called\n");
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------
/**
 */
SizeT
OGLShaderInstance::Begin()
{
    n_assert(0 != this->glslProgram);
    ShaderInstanceBase::Begin();
    GLDEBUG(glUseProgram(this->glslProgram));
    return 1;
}

//------------------------------------------------------------------------------
/**
 */
void
OGLShaderInstance::End()
{
    ShaderInstanceBase::End();
    GLDEBUG(glUseProgram(0))
}
    
} // namespace OGL