#pragma once
//------------------------------------------------------------------------------
/**
 @class OGL::OGLShaderVariable
 
 Open GL implementation of ShaderVariable.
 
 (C) 2013 Larry Weya
 */
#include "coregraphics/base/shadervariablebase.h"
#include "coregraphics/texture.h"
#include "math/matrix44.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLShaderVariable : public Base::ShaderVariableBase
{
    __DeclareClass(OGLShaderVariable);
public:
    /// constructor
    OGLShaderVariable();
    /// destructor
    virtual ~OGLShaderVariable();
    
    /// set int value
    void SetInt(int value);
    /// set int array values
    void SetIntArray(const int* values, SizeT count);
    /// set float value
    void SetFloat(float value);
    /// set float array values
    void SetFloatArray(const float* values, SizeT count);
    /// set vector value
    void SetFloat4(const Math::float4& value);
    /// set vector array values
    void SetFloat4Array(const Math::float4* values, SizeT count);
    /// set matrix value
    void SetMatrix(const Math::matrix44& value);
    /// set matrix array values
    void SetMatrixArray(const Math::matrix44* values, SizeT count);
    /// set bool value
    void SetBool(bool value);
    /// set bool array values
    void SetBoolArray(const bool* values, SizeT count);
    /// set texture value
    void SetTexture(const Ptr<CoreGraphics::Texture>& value);
    
private:
    friend class OGLShaderInstance;
    
    /// setup from glsl program
    void Setup(GLuint program, GLint attribIndex, const char* name, GLenum attrType);
    
    GLuint glslProgram;
    GLint attribIndex;
};

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetInt(int value)
{
    glUniform1i(this->attribIndex, value);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetIntArray(const int* values, SizeT count)
{
    glUniform1iv(this->attribIndex, count, values);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetFloat(float value)
{
    glUniform1f(this->attribIndex, value);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetFloatArray(const float* values, SizeT count)
{
    glUniform1fv(this->attribIndex, count, values);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetFloat4(const Math::float4& value)
{
    glUniform4f(this->attribIndex, value.vec[0], value.vec[0], value.vec[0], value.vec[0]);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetFloat4Array(const Math::float4* values, SizeT count)
{
    n_error("OGLShaderVariable::SetFloat4Array called\n");
    glUniform4fv(this->attribIndex, count, &values->vec[0]);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetMatrix(const Math::matrix44& value)
{
    glUniformMatrix4fv(this->attribIndex, 1, GL_FALSE, &value.mx[0][0]);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetMatrixArray(const Math::matrix44* values, SizeT count)
{
    n_error("OGLShaderVariable::SetMatrixArray called\n");
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetBool(bool value)
{
    glUniform1i(this->attribIndex, value);
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLShaderVariable::SetBoolArray(const bool* values, SizeT count)
{
    const int MaxNumBools = 128;
    n_assert(count < MaxNumBools);
    int tmp[MaxNumBools];
    IndexT i;
    for (i = 0; i < count; i++)
    {
        tmp[i] = (int)values[i];
    }
    glUniform1iv(this->attribIndex, count, tmp);
}
    
} // namespace OGL
//------------------------------------------------------------------------------
