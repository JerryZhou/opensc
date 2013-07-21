#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLShader
    
    OGL implementation of Shader.
    
    (C) 2013 Larry Weya
*/
#include "coregraphics/base/shaderbase.h"
#include "coregraphics/shaderinstance.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLShader : public Base::ShaderBase
{
    __DeclareClass(OGLShader);
public:
    /// constructor
    OGLShader();
    /// destructor
    virtual ~OGLShader();
   
    /// unload the resource, or cancel the pending load
    virtual void Unload();
    /// get glsl program
    GLuint GetGLSLProgram() const;

private:
    friend class OGLMemoryShaderLoader;

    /// set glgl program object
    void SetGLSLProgram(GLuint program);

    GLuint glslProgram;
};

//------------------------------------------------------------------------------
/**
*/
inline void
OGLShader::SetGLSLProgram(GLuint program)
{
    n_assert(0 != program);
    n_assert(0 == this->glslProgram);
    this->glslProgram = program;
}

//------------------------------------------------------------------------------
/**
*/
inline GLuint
OGLShader::GetGLSLProgram() const
{
    n_assert(0 != this->glslProgram);
    return this->glslProgram;
}

} // namespace OGL
//------------------------------------------------------------------------------

    