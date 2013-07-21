#pragma once
//------------------------------------------------------------------------------
/**
    @class OGL::OGLRenderDevice
  
    Implements a RenderDevice on top of OpenGL.
    
    (C) 2013 Larry Weya
*/

//#ifdef __cplusplus
//extern "C"
//{
    
void logGLError(GLenum err, uint16_t line_no, const char* filename, const char* func);

//}
//#endif //__cplusplus
#ifdef NEBULA3_DEBUG2
#define GLDEBUG(x) \
x; \
{ \
GLenum e; \
while( (e=glGetError()) != GL_NO_ERROR) \
{ \
logGLError(e, __LINE__, __FILE__, #x); \
} \
};
#else
#define GLDEBUG(x) \
x;
#endif