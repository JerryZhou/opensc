//------------------------------------------------------------------------------
//  osxfswrapper.cc
//  (C) 2010 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "osxfswrapper.h"
#include "core/sysfunc.h"
#include <pwd.h>
#include <uuid/uuid.h>
#include <libproc.h>
#include <unistd.h>
#include <errno.h>


namespace OSX
{
using namespace Util;
using namespace Core;
using namespace IO;
    
//------------------------------------------------------------------------------
/**
*/
OSXFSWrapper::Handle
OSXFSWrapper::OpenFile(const String& path, Stream::AccessMode accessMode, Stream::AccessPattern accessPattern)
{
    FILE* f = fopen(path.AsCharPtr(), "rb");
    n_assert(f != 0);
    return f;
}
    
//------------------------------------------------------------------------------
/**
*/
void
OSXFSWrapper::CloseFile(Handle handle)
{
    int result = fclose(handle);
    n_assert(result == 0);
}
    
//------------------------------------------------------------------------------
/**
*/
void
OSXFSWrapper::Write(Handle handle, const void* buf, Stream::Size numBytes)
{
    n_error("OSXFSWrapper::Write(): IMPLEMENT ME!\n");
}
    
//------------------------------------------------------------------------------
/**
*/
Stream::Size
OSXFSWrapper::Read(Handle handle, void* buf, Stream::Size numBytes)
{
    int numItemsRead = fread(buf, numBytes, 1, handle);
    int result = ferror(handle);
    n_assert(result == 0);
    return numBytes * numItemsRead;
}
    
//------------------------------------------------------------------------------
/**
*/
void
OSXFSWrapper::Seek(Handle handle, Stream::Offset offset, Stream::SeekOrigin orig)
{
    // @todo: determine whence from orig
    int result = fseek(handle, offset, orig);
    n_assert(result != -1);
}
    
//------------------------------------------------------------------------------
/**
*/
Stream::Position
OSXFSWrapper::Tell(Handle handle)
{
    return ftell(handle);
}
    
//------------------------------------------------------------------------------
/**
*/
void
OSXFSWrapper::Flush(Handle handle)
{
    n_error("OSXFSWrapper::Flush(): IMPLEMENT ME!\n");
}
    
//------------------------------------------------------------------------------
/**
*/
bool
OSXFSWrapper::Eof(Handle handle)
{
    return feof(handle) != 0;
}
    
//------------------------------------------------------------------------------
/**
*/
Stream::Size
OSXFSWrapper::GetFileSize(Handle handle)
{
    // @todo: implement using OSXFSWrapper functions
    int result = fseek(handle, 0L, SEEK_END);
    return ftell(handle);
}
    
//------------------------------------------------------------------------------
/**
*/
void
OSXFSWrapper::SetReadOnly(const String& path, bool readOnly)
{
    n_error("OSXFSWrapper::SetReadOnly(): IMPLEMENT ME!\n");
}

//------------------------------------------------------------------------------
/**
*/
bool
OSXFSWrapper::IsReadOnly(const String& path)
{
    n_error("OSXFSWrapper::IsReadOnly(): IMPLEMENT ME!\n");
    return false;
}
    
//------------------------------------------------------------------------------
/**
 */
bool
OSXFSWrapper::DeleteFile(const String& path)
{
    n_error("OSXFSWrapper::DeleteFile(): IMPLEMENT ME!\n");
    return false;
}
    
//------------------------------------------------------------------------------
/**
*/
bool
OSXFSWrapper::DeleteDirectory(const String& path)
{
    n_error("OSXFSWrapper::DeleteDirectory(): IMPLEMENT ME!\n");
    return false;
}
    
//------------------------------------------------------------------------------
/**
*/
bool
OSXFSWrapper::FileExists(const String& path)
{
    return access(path.AsCharPtr(), F_OK) != -1;
}
    
//------------------------------------------------------------------------------
/**
*/
bool
OSXFSWrapper::DirectoryExists(const String& path)
{
    n_error("OSXFSWrapper::DirectoryExists(): IMPLEMENT ME!\n");
    return false;
}
    
//------------------------------------------------------------------------------
/**
*/
void
OSXFSWrapper::SetFileWriteTime(const String& path, FileTime fileTime)
{
    n_error("OSXFSWrapper::SetFileWriteTime() not implemented!");
}
    
//------------------------------------------------------------------------------
/**
*/
FileTime
OSXFSWrapper::GetFileWriteTime(const String& path)
{
    n_error("OSXFSWrapper::GetFileWriteTime() not implemented!");
    return FileTime();
}
    
//------------------------------------------------------------------------------
/**
*/
bool
OSXFSWrapper::CreateDirectory(const String& path)
{
    n_error("OSXFSWrapper::CreateDirectory(): NOT IMPLEMENTED!");
    return false;
}
    
//------------------------------------------------------------------------------
/**
*/
Array<String>
OSXFSWrapper::ListFiles(const String& path, const String& pattern)
{
    n_error("OSXFSWrapper::ListFiles(): NOT IMPLEMENTED!");
    return Array<String>();
}
    
//------------------------------------------------------------------------------
/**
 */
Array<String>
OSXFSWrapper::ListDirectories(const String& path, const String& pattern)
{
    n_error("OSXFSWrapper::ListDirectories(): NOT IMPLEMENTED!");
    return Array<String>();
}
    
//------------------------------------------------------------------------------
/**
 */
String
OSXFSWrapper::GetUserDirectory()
{
    struct passwd* pwd = getpwuid(getuid());
    return pwd->pw_dir;
}
    
//------------------------------------------------------------------------------
/**
 */
String
OSXFSWrapper::GetAppDataDirectory()
{  
    //n_error("OSXFSWrapper::GetAppDataDirectory(): NOT IMPLEMENTED!");
    return "";
}
    
//------------------------------------------------------------------------------
/**
 */
String 
OSXFSWrapper::GetProgramsDirectory()
{  
    //n_error("OSXFSWrapper::GetProgramsDirectory(): NOT IMPLEMENTED!");
    return "";
}
    
//------------------------------------------------------------------------------
/**
 */
String
OSXFSWrapper::GetTempDirectory()
{  
    //n_error("OSXFSWrapper::GetTempDirectory(): NOT IMPLEMENTED!");
    return "";
}
    
//------------------------------------------------------------------------------
/**
 */
String
OSXFSWrapper::GetBinDirectory()
{    
    String result = OSXFSWrapper::GetPathToExecutable();
    result = result.ExtractDirName();
    result.TrimRight("/");
    return String("file:///") + result;
}
    
//------------------------------------------------------------------------------
/**
 */
String
OSXFSWrapper::GetHomeDirectory()
{
    String homePath = OSXFSWrapper::GetPathToExecutable();
    // remove /app from nebula3/bin/osx/app
    homePath = homePath.ExtractDirName();
    // remove /osx from nebula3/bin/osx/
    homePath = homePath.ExtractDirName();
    // remove /bin from nebula3/bin/
    homePath = homePath.ExtractDirName();
    homePath.TrimRight("/");
    return String("file:///") + homePath;
}
    
//------------------------------------------------------------------------------
/**
 */
bool
OSXFSWrapper::IsDeviceName(const Util::String& str)
{
    if (str == "OSX") return true;
    else return false;
}
    
//------------------------------------------------------------------------------
/**
 */
const char*
OSXFSWrapper::ConvertPath(const Util::String& str)
{
    const char* ptr = str.AsCharPtr();
    n_assert((ptr[0] == 'O') && (ptr[1] == 'S') && (ptr[2] == 'X') && (ptr[3] == ':'));
    return &(ptr[4]);
}
    
Util::String
OSXFSWrapper::GetPathToExecutable()
{
    pid_t pid;
    char pathbuf[PROC_PIDPATHINFO_MAXSIZE];
    int res;
    
    pid = getpid();
    res = proc_pidpath (pid, pathbuf, sizeof(pathbuf));
    if(res <= 0)
    {
        n_error("OSXFSWrapper::GetPathToExecutable() %s", strerror(errno));
    }
    return String(pathbuf);
}

} // namespace OSX