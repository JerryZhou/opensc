//------------------------------------------------------------------------------
//  oglshader.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglshader.h"
#include "coregraphics/shaderinstance.h"
#include "coregraphics/shader.h"

namespace OGL
{
__ImplementClass(OGL::OGLShader, 'GLSD', Base::ShaderBase);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
*/
OGLShader::OGLShader() :
    glslProgram(0)
{
    // empty
}

//------------------------------------------------------------------------------
/**
*/
OGLShader::~OGLShader()
{
    if (this->IsLoaded())
    {
        this->Unload();
    }
}

//------------------------------------------------------------------------------
/**
*/
void
OGLShader::Unload()
{
    if (0 != this->glslProgram)
    {
        glDeleteProgram(this->glslProgram);
        this->glslProgram = 0;
    }
    ShaderBase::Unload();
}

} // namespace OGL