//------------------------------------------------------------------------------
//  oglmemoryvertexbufferloader.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglmemoryshaderloader.h"
#include "coregraphics/ogl/gldebug.h"
#include "coregraphics/ogl/oglvertexbuffer.h"
#include "coregraphics/renderdevice.h"

namespace OGL
{
__ImplementClass(OGL::OGLMemoryShaderLoader, 'GMSL', Resources::ResourceLoader);

using namespace Resources;
using namespace CoreGraphics;
using namespace OGL;

//------------------------------------------------------------------------------
/**
    Compile a shader of the given type from the provided source
*/
void
OGLMemoryShaderLoader::CompileShader(const GLuint shader, const char* shaderSrc)
{
    GLDEBUG(glShaderSource(shader, 1, &shaderSrc, NULL));
    
    GLDEBUG(glCompileShader(shader));
    
    GLint status;
    GLDEBUG(glGetShaderiv(shader, GL_COMPILE_STATUS, &status));
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        GLDEBUG(glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength));
        
        // TODO: consider uing Util::String to manage memory
        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        GLDEBUG(glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog));
        
        n_error("Compile failure in shader:\n%s\n", strInfoLog);
        delete[] strInfoLog;
    }
}

//------------------------------------------------------------------------------
/**
    Compile a glsl program from a vertex and fragment shaders

    TODO: provide an array of shaders to compile e.g. geometry, multiple shaders
*/
void
OGLMemoryShaderLoader::CompileProgram(const GLuint program, const GLuint vertexShader, const GLuint fragmentShader)
{
    GLDEBUG(glAttachShader(program, vertexShader));
    GLDEBUG(glAttachShader(program, fragmentShader));
    
    //glBindFragDataLocation(program, 0, "outColor");
    GLDEBUG(glLinkProgram(program));
    
    GLint status;
    GLDEBUG(glGetProgramiv(program, GL_LINK_STATUS, &status));
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        GLDEBUG(glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength));
        
        GLchar *strInfoLog = new GLchar[infoLogLength + 1];
        GLDEBUG(glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog));
        n_error("Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
    }
    
    GLDEBUG(glDetachShader(program, vertexShader));
    GLDEBUG(glDetachShader(program, fragmentShader));
}

//------------------------------------------------------------------------------
/**
*/
void
OGLMemoryShaderLoader::SetVertexShaderSrc(const char* source)
{
    this->vertexShaderSrc = source;
}

//------------------------------------------------------------------------------
/**
*/

void
OGLMemoryShaderLoader::SetFragmentShaderSrc(const char* source)
{
    this->fragmentShaderSrc = source;
}

//------------------------------------------------------------------------------
/**
    This will create a OGL vertex buffer and vertex declaration object
    from the data provided in the Setup() method and setup our resource
    object (which must be a OGLVertexBuffer object).
*/
bool
OGLMemoryShaderLoader::OnLoadRequested()
{
    n_assert(this->GetState() == Resource::Initial);
    n_assert(this->resource.isvalid());
    n_assert(!this->resource->IsAsyncEnabled());
    n_assert(this->vertexShaderSrc.IsValid());
    n_assert(this->fragmentShaderSrc.IsValid());

    // create vertex shader
    GLDEBUG(GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER));
    OGLMemoryShaderLoader::CompileShader(vertexShader, this->vertexShaderSrc.AsCharPtr());
    
    // create fragment shaders
    GLDEBUG(GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER));
    OGLMemoryShaderLoader::CompileShader(fragmentShader, this->fragmentShaderSrc.AsCharPtr());
    
    // create program
    GLDEBUG(GLuint glslProgram = glCreateProgram());
    
    /// bind attributes
    GLDEBUG(glBindAttribLocation(glslProgram, OGLVertexComponent::PositionAttr, VertexComponent::SemanticNameToString(VertexComponent::Position).AsCharPtr()));
    GLDEBUG(glBindAttribLocation(glslProgram, OGLVertexComponent::NormalAttr, VertexComponent::SemanticNameToString(VertexComponent::Normal).AsCharPtr()));
    GLDEBUG(glBindAttribLocation(glslProgram, OGLVertexComponent::TangentAttr, VertexComponent::SemanticNameToString(VertexComponent::Tangent).AsCharPtr()));
    GLDEBUG(glBindAttribLocation(glslProgram, OGLVertexComponent::BinormalAttr, VertexComponent::SemanticNameToString(VertexComponent::Binormal).AsCharPtr()));
    Util::String texCoordAttrName = VertexComponent::SemanticNameToString(VertexComponent::TexCoord);
    texCoordAttrName.AppendInt(0);
    GLDEBUG(glBindAttribLocation(glslProgram,
                                 OGLVertexComponent::SemanticNameToAttributeIndex(VertexComponent::TexCoord, 0),
                                 texCoordAttrName.AsCharPtr()));
    GLDEBUG(glBindAttribLocation(glslProgram, OGLVertexComponent::ColorAttr, VertexComponent::SemanticNameToString(VertexComponent::Color).AsCharPtr()));
    
    // compile program
    OGLMemoryShaderLoader::CompileProgram(glslProgram, vertexShader, fragmentShader);

    // setup our resource object
    const Ptr<OGLShader>& res = this->resource.downcast<OGLShader>();
    n_assert(!res->IsLoaded());
    res->SetGLSLProgram(glslProgram);
    
    // delete shaders
    GLDEBUG(glDeleteShader(vertexShader));
    GLDEBUG(glDeleteShader(fragmentShader));

    // invalidate setup data (because we don't own our data)
    this->vertexShaderSrc.Clear();
    this->fragmentShaderSrc.Clear();

    this->SetState(Resource::Loaded);
    return true;
}

} // namespace OGL
