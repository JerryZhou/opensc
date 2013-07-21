#pragma once
//------------------------------------------------------------------------------
/**
    @file core/config.h

    OpenSC compiler specific defines and configuration.
    
    (C) JerryZhou@outlook.com
*/

// setup platform identification macros
#ifdef __XBOX360__
#undef __XBOX360__
#endif
#ifdef _XBOX
#define __XBOX360__ (1)
#endif

#ifdef __WIN32__
#undef __WIN32__
#endif
#ifdef WIN32
#define __WIN32__ (1)
#endif

#ifdef __PS3__
#undef __PS3__
#endif
#ifdef __CELLOS_LV2__
#define __PS3__ (1)
#endif

#ifdef __OSX__
#undef __OSX__
#endif
#ifdef __APPLE__
#define __OSX__ (1)
#endif

//------------------------------------------------------------------------------
/**
    Nebula3 configuration.
*/

#if defined(_DEBUG) || !defined(NDEBUG)
#define OPENSC_DEBUG (1)
#endif

/// max size of a data slice is 16 kByte - 1 byte
/// this needs to be in a header, which is accessable from SPU too,
/// thats why its here
static const int JobMaxSliceSize = 0x3FFF;

#if __WII__
#define __WII_PROFILING__ (0)
#endif

#if PUBLIC_BUILD
#define __J_NO_ASSERT__ (0)    // DON'T SET THIS TO (1) - PUBLIC_BUILD SHOULD STILL DISPLAY ASSERTS!
#else
#define __J_NO_ASSERT__ (0)
#endif

// define whether a platform comes with archive support built into the OS
#if __PS3__
#define J_NATIVE_ARCHIVE_SUPPORT (1)
#else
#define J_NATIVE_ARCHIVE_SUPPORT (0)
#endif

// enable/disable Nebula3 memory stats
#if OPENSC_DEBUG
#define J_MEMORY_STATS (1)
#define J_MEMORY_ADVANCED_DEBUGGING (0)
#else
#define J_MEMORY_STATS (0) // not useable on xbox360 in release mode cause of HeapWalk
#define J_MEMORY_ADVANCED_DEBUGGING (0)
#endif

// enable/disable memory pool allocation for refcounted object
// FIXME -> memory pool is disabled for all platforms, cause it causes crashes (reproducable on xbox360)
#if (__WII__ || __MAYA__ || __WIN32__ || __PS3__)
#define J_OBJECTS_USE_MEMORYPOOL (0)
#else
#define J_OBJECTS_USE_MEMORYPOOL (0)
#endif

// Enable/disable serial job system (ONLY SET FOR DEBUGGING!)
// You'll also need to fix the foundation_*.epk file to use the jobs/serial source files
// instead of jobs/tp!
// On the Wii, the serial job system is always active.
#define J_USE_SERIAL_JOBSYSTEM (0)

// enable/disable thread-local StringAtom tables
#if (__WII__)
#define J_ENABLE_THREADLOCAL_STRINGATOM_TABLES (0)
#else
#define J_ENABLE_THREADLOCAL_STRINGATOM_TABLES (1)
#endif

// enable/disable growth of StringAtom buffer
#define J_ENABLE_GLOBAL_STRINGBUFFER_GROWTH (1)

// size of of a chunk of the global string buffer for StringAtoms
#define J_GLOBAL_STRINGBUFFER_CHUNKSIZE (32 * 1024)

// enable/disable Nebula3 animation system log messages
#define J_ANIMATIONSYSTEM_VERBOSELOG (0)
#define J_ANIMATIONSYSTEM_FRAMEDUMP (0)

// override SQLite filesystem functions with Nebula functions?
// only useful on consoles
// win32 doesn't work without !!!
#if __WIN32__
#define J_OVERRIDE_SQLITE_FILEFUNCTIONS (1)
#else
#define J_OVERRIDE_SQLITE_FILEFUNCTIONS (1)
#endif

// enable/disable bounds checking in the container util classes
#if OPENSC_DEBUG
#define J_BOUNDSCHECKS (1)
#else
#define J_BOUNDSCHECKS (1)
#endif
         
// enable/disable the builtin HTTP server
#if PUBLIC_BUILD || __WII_PROFILING__
#define __J_HTTP__ (0)
#else
#define __J_HTTP__ (1)
#endif

// enable/disable the transparent web filesystem
#if __WIN32__ || __OSX__
#define __J_FILESYSTEM__ (1)
#else
#define __J_HTTP_FILESYSTEM__ (0)
#endif

// enable/disable profiling (see Debug::DebugTimer, Debug::DebugCounter)
#if PUBLIC_BUILD
#define J_ENABLE_PROFILING (0)
#elif __J_HTTP__
// profiling needs http
#define J_ENABLE_PROFILING (1)
#else 
#define J_ENABLE_PROFILING (0)
#endif

// max length of a path name
#define J_MAXPATH (512)

// enable/disable support for Nebula2 file formats and concepts
#define J_LEGACY_SUPPORT (1)

// enable/disable mini dumps
#define J_ENABLE_MINIDUMPS (1)

// enable/disable debug messages in fmod coreaudio
#define J_FMOD_COREAUDIO_VERBOSE_ENABLED  (0)

// enable fmod profiling feature
#define J_FMOD_ENABLE_PROFILING (0)

// OpenSC's main window class
#define J_WINDOW_CLASS "OpenSC::MainWindow"

// number of lines in the IO::HistoryConsoleHandler ring buffer
#if __WII__
#define J_CONSOLE_HISTORY_SIZE (64)
#else
#define J_CONSOLE_HISTORY_SIZE (256)
#endif

// maximum number of local players for local coop games
#define J_MAX_LOCAL_PLAYERS (4)

// use raknet on xbox360 platform?
#define XBOX360_USE_RAKNET    (0)

// enable legacy support for database vectors (vector3/vector4 stuff)
#define J_DATABASE_LEGACY_VECTORS (1)

// enable legacy support for 3-component vectors in XML files
#define J_XMLREADER_LEGACY_VECTORS (1)

// enable/disable scriping (NOTE: scripting support has been moved into an Addon)
#if __WII__
#define __J_SCRIPTING__ (0)
#else
#define __J_SCRIPTING__ (1)
#endif

// define the standard IO scheme for the platform
#if __WII__
#define DEFAULT_IO_SCHEME "arc"
#else
#define DEFAULT_IO_SCHEME "file"
#endif

// default resource names
#if __WIN32__ 
#define J_PLACEHOLDER_TEXTURENAME "systex:system/placeholder.dds"
#define J_PLACEHOLDER_MESHNAME  "sysmsh:system/placeholder_s_0.nvx2"
#define J_DEFAULT_FRAMESHADER_NAME "dx9default"
#define J_TEXTURE_EXTENSION ".dds"
#define J_MESH_EXTENSION ".nvx2"
#elif __XBOX360__
#define J_PLACEHOLDER_TEXTURENAME "systex:system/placeholder.ntx"
#define J_PLACEHOLDER_MESHNAME  "sysmsh:system/placeholder_s_0.nvx2"
#define J_DEFAULT_FRAMESHADER_NAME "dx9default"
#define J_TEXTURE_EXTENSION ".ntx"
#define J_MESH_EXTENSION ".nvx2"
#elif __WII__
#define J_PLACEHOLDER_TEXTURENAME "systex:system/placeholder.tpl"
#define J_PLACEHOLDER_MESHNAME  "sysmsh:system/placeholder_s_0.nvx2"
#define J_DEFAULT_FRAMESHADER_NAME "wiidefault"
#define J_TEXTURE_EXTENSION ".tpl"
#define J_MESH_EXTENSION ".nwdl"
#elif __PS3__
#define J_PLACEHOLDER_TEXTURENAME "systex:system/placeholder.gtf"
#define J_PLACEHOLDER_MESHNAME  "sysmsh:system/placeholder_s_0.nvx2"
#define J_DEFAULT_FRAMESHADER_NAME "default"
#define J_TEXTURE_EXTENSION ".gtf"
#define J_MESH_EXTENSION ".nvx2"
#elif __OSX__
#define J_PLACEHOLDER_TEXTURENAME "systex:system/placeholder.dds"
#define J_PLACEHOLDER_MESHNAME  "sysmsh:system/placeholder_s_0.nvx2"
#define J_DEFAULT_FRAMESHADER_NAME "dx9default"
#define J_TEXTURE_EXTENSION ".dds"
#define J_MESH_EXTENSION ".nvx2"
#endif

// VisualStudio settings
#ifdef _MSC_VER
#define __VC__ (1)
#endif
#ifdef __VC__
#pragma warning( disable : 4251 )       // class XX needs DLL interface to be used...
#pragma warning( disable : 4355 )       // initialization list uses 'this' 
#pragma warning( disable : 4275 )       // base class has not dll interface...
#pragma warning( disable : 4786 )       // symbol truncated to 255 characters
#pragma warning( disable : 4530 )       // C++ exception handler used, but unwind semantics not enabled
#pragma warning( disable : 4995 )       // _OLD_IOSTREAMS_ARE_DEPRECATED
#pragma warning( disable : 4996 )       // _CRT_INSECURE_DEPRECATE, VS8: old string routines are deprecated
#pragma warning( disable : 4512 )       // 'class' : assignment operator could not be generated
#pragma warning( disable : 4610 )       // object 'class' can never be instantiated - user-defined constructor required
#pragma warning( disable : 4510 )       // 'class' : default constructor could not be generated
#endif

// CodeWarrior settings
#ifdef __MWERKS__
#pragma warning off (10216)     // illegal empty declaration used ( ; ; )
#pragma warning off (10317)     
#pragma warning off (10342)     // ...not inlined
#pragma warning off (10182)     // arg not used in function 
#pragma warning off (10358)     // illegal or unsupported __attribute__
#endif

// GCC settings
#if defined __GNUC__
#define __cdecl
#define __forceinline inline
#endif

#if !defined(__GNUC__) && !defined(__WII__)
#define  __attribute__(x)  /**/
#endif

// PS3 settings
#if __PS3__
// __attribute__((always_inline)) caused  DATA_HTAB_MISS PPU exception in matrix-math-test
// matrixtest::Run() needed 51616 byte from the stack, only in Run(), without always_inline
// it was only 9344 byte 
#endif

#if __WII__
#define __cdecl
#define __forceinline inline __attribute__((always_inline))

// BP: FP_CONTRACT is off by default on the wii
#pragma STDC FP_CONTRACT ON
#endif

// define max texture space for resource streaming
#if __WIN32__
// 512 MB
#define __maxTextureBytes__ (524288000)
#else
// 256 MB
#define __maxTextureBytes__ (268435456)
#endif

//------------------------------------------------------------------------------
