#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLMemoryShaderLoader
    
    Initialize an OGLShader from data in memory on the Open GL
    platform.
    
    (C) 2013 Larry Weya
*/
#include "resources/resourceloader.h"
#include "coregraphics/shader.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLMemoryShaderLoader : public Resources::ResourceLoader
{
    __DeclareClass(OGLMemoryShaderLoader);
public:
    /// called by resource when a load is requested
    virtual bool OnLoadRequested();
    
    /// get vertex shader source
    Util::String GetVertexShaderSrc() const;
    /// set vertex shader source
    void SetVertexShaderSrc(const char* source);
    /// get fragment shader source
    Util::String GetFragmentShaderSrc() const;
    /// set fragment shader source
    void SetFragmentShaderSrc(const char* source);
private:
    static void CompileShader(const GLuint shader, const char* shaderSrc);
    static void CompileProgram(const GLuint program, const GLuint vertexShader, const GLuint fragmentShader);
    
    Util::String vertexShaderSrc;
    Util::String fragmentShaderSrc;
};

//------------------------------------------------------------------------------
/**
*/
inline Util::String
OGLMemoryShaderLoader::GetVertexShaderSrc() const
{
    n_assert(this->vertexShaderSrc.IsValid());
    return this->vertexShaderSrc;
}

//------------------------------------------------------------------------------
/**
*/
inline Util::String
OGLMemoryShaderLoader::GetFragmentShaderSrc() const
{
    n_assert(this->fragmentShaderSrc.IsValid());
    return this->fragmentShaderSrc;
}

} // namespace OGL
//------------------------------------------------------------------------------
