#pragma once
//------------------------------------------------------------------------------
/**
 @class OGL::OGLStreamMeshLoader
 
 Setup a Mesh object from a stream. Supports the following file formats:
 
 - nvx2 (Nebula2 binary mesh file format)
 - nvx3 (Nebula3 binary mesh file format)
 - n3d3 (Nebula3 ascii mesh file format)
 
 @todo: document file formats
 
 (C) 2013 Larry Weya
 */
#include "resources/streamresourceloader.h"
#include "coregraphics/base/resourcebase.h"

//------------------------------------------------------------------------------
namespace OGL
{
class OGLStreamMeshLoader : public Resources::StreamResourceLoader
{
    __DeclareClass(OGLStreamMeshLoader);
public:
    /// constructor
    OGLStreamMeshLoader();
    /// set the intended resource usage (default is UsageImmutable)
    void SetUsage(Base::ResourceBase::Usage usage);
    /// get resource usage
    Base::ResourceBase::Usage GetUsage() const;
    /// set the intended resource access (default is AccessNone)
    void SetAccess(Base::ResourceBase::Access access);
    /// get the resource access
    Base::ResourceBase::Access GetAccess() const;
    
private:
    /// setup mesh from generic stream, branches to specialized loader methods
    virtual bool SetupResourceFromStream(const Ptr<IO::Stream>& stream);
#if NEBULA3_LEGACY_SUPPORT
    /// setup mesh from nvx2 file in memory
    bool SetupMeshFromNvx2(const Ptr<IO::Stream>& stream);
#endif
    /// setup mesh from nvx3 file in memory
    bool SetupMeshFromNvx3(const Ptr<IO::Stream>& stream);
    /// setup mesh from n3d3 file in memory
    bool SetupMeshFromN3d3(const Ptr<IO::Stream>& stream);
    
protected:
    Base::ResourceBase::Usage usage;
    Base::ResourceBase::Access access;
};

//------------------------------------------------------------------------------
/**
 */
inline void
OGLStreamMeshLoader::SetUsage(Base::ResourceBase::Usage usage_)
{
    this->usage = usage_;
}

//------------------------------------------------------------------------------
/**
 */
inline Base::ResourceBase::Usage
OGLStreamMeshLoader::GetUsage() const
{
    return this->usage;
}

//------------------------------------------------------------------------------
/**
 */
inline void
OGLStreamMeshLoader::SetAccess(Base::ResourceBase::Access access_)
{
    this->access = access_;
}

//------------------------------------------------------------------------------
/**
 */
inline Base::ResourceBase::Access
OGLStreamMeshLoader::GetAccess() const
{
    return this->access;
}
    
} // namespace OGL
//------------------------------------------------------------------------------
