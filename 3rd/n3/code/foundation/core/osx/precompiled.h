#pragma once
//------------------------------------------------------------------------------
/**
    @file core/osx/precompiled.h
 
    Contains precompiled headers on the OSX platform.
 
    (C) 2010 Radon Labs GmbH
*/

// crt headers
// GNU/C runtime
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <pthread.h>
#include <malloc/malloc.h>
#include <uuid/uuid.h>
// added by larry for system info functions
#include <sys/sysctl.h>

// C++ runtime
#include <algorithm>

#define GLFW_INCLUDE_GLCOREARB (1)
#include <GLFW/glfw3.h>

// NOTE: no headers here which depend on ObjC!