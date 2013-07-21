//------------------------------------------------------------------------------
//  oglshadervariable.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglshadervariable.h"
#include "coregraphics/ogl/gldebug.h"

namespace OGL
{
__ImplementClass(OGL::OGLShaderVariable, 'GLSV', Base::ShaderVariableBase);

using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
 */
OGLShaderVariable::OGLShaderVariable() :
    glslProgram(0),
    attribIndex(-1)
{
    // empty
}

//------------------------------------------------------------------------------
/**
 */
OGLShaderVariable::~OGLShaderVariable()
{
    this->glslProgram = 0;
    this->attribIndex = -1;
}

//------------------------------------------------------------------------------
/**
 */
void
OGLShaderVariable::Setup(GLuint program, GLint attribIndex, const char* name, GLenum attrType)
{
    n_assert(0 != program);
    n_assert(-1 != attribIndex);
    n_assert(0 == this->glslProgram);
    n_assert(-1 == this->attribIndex);
    
    this->glslProgram = program;
    this->attribIndex = attribIndex;
    this->SetName(Name(name));
    
    // use name as our semantic as glsl has no concept of semantics
    this->SetSemantic(Semantic(name));
    
    // @todo: crack the data type
    switch (attrType)
    {
        case GL_FLOAT:
            this->SetType(FloatType);
            break;
        case GL_FLOAT_MAT4:
            this->SetType(MatrixType);
        case GL_SAMPLER_2D:
            this->SetType(TextureType);
            break;
        default:
            this->SetType(UnknownType);
            break;
    }
}

//------------------------------------------------------------------------------
/**
 */
void
OGLShaderVariable::SetTexture(const Ptr<CoreGraphics::Texture>& value)
{
    GLDEBUG(glUniform1i(this->attribIndex, 0))// bind to texture unit 0
    GLDEBUG(glActiveTexture(GL_TEXTURE0)) // activate texture unit 0
    GLDEBUG(glBindTexture(GL_TEXTURE_2D, value->GetGLTexture())) // send texture to bound unit
}
    
} // namespace OGL