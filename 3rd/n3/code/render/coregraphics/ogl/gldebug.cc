//------------------------------------------------------------------------------
//  glerror.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/gldebug.h"
#include "core/debug.h"
#include "util/string.h"

void logGLError(GLenum err, uint16_t line_no, const char* filename, const char* func)
{
    Util::String errorMsg;
    switch(err) {
        case GL_INVALID_OPERATION:      errorMsg="INVALID_OPERATION";      break;
        case GL_INVALID_ENUM:           errorMsg="INVALID_ENUM";           break;
        case GL_INVALID_VALUE:          errorMsg="INVALID_VALUE";          break;
        case GL_OUT_OF_MEMORY:          errorMsg="OUT_OF_MEMORY";          break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:  errorMsg="INVALID_FRAMEBUFFER_OPERATION";  break;
    }
    n_dbgout("Error at line number %d, in file %s. glGetError() returned %s for call %s\n", line_no, filename, errorMsg.AsCharPtr(), func );
}