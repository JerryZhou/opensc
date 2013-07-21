//------------------------------------------------------------------------------
//  OGLStreamMeshLoader.cc
//  (C) 2013 Larry Weya
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglstreammeshloader.h"
#include "coregraphics/mesh.h"
#include "coregraphics/legacy/nvx2streamreader.h"

namespace OGL
{
__ImplementClass(OGL::OGLStreamMeshLoader, 'GLML', Resources::StreamResourceLoader);

using namespace IO;
using namespace CoreGraphics;
using namespace Util;

//------------------------------------------------------------------------------
/**
 */
OGLStreamMeshLoader::OGLStreamMeshLoader() :
    usage(Base::ResourceBase::UsageImmutable),
    access(Base::ResourceBase::AccessNone)
{
    // empty
}

//------------------------------------------------------------------------------
/**
 */
bool
OGLStreamMeshLoader::SetupResourceFromStream(const Ptr<Stream>& stream)
{
    n_assert(stream.isvalid());
    n_assert(this->resource.isvalid());
    String resIdExt = this->resource->GetResourceId().AsString().GetFileExtension();
#if NEBULA3_LEGACY_SUPPORT
    if (resIdExt == "nvx2")
    {
        return this->SetupMeshFromNvx2(stream);
    }
    else
#endif
        if (resIdExt == "nvx3")
        {
            return this->SetupMeshFromNvx3(stream);
        }
        else if (resIdExt == "n3d3")
        {
            return this->SetupMeshFromN3d3(stream);
        }
        else
        {
            n_error("D3D9StreamMeshLoader::SetupMeshFromStream(): unrecognized file extension in '%s'\n", this->resource->GetResourceId().Value());
            return false;
        }
}

//------------------------------------------------------------------------------
/**
 Setup the mesh resource from legacy nvx2 file (Nebula2 binary mesh format).
 */
#if NEBULA3_LEGACY_SUPPORT
bool
OGLStreamMeshLoader::SetupMeshFromNvx2(const Ptr<Stream>& stream)
{
    n_assert(stream.isvalid());
    Ptr<Legacy::Nvx2StreamReader> nvx2Reader = Legacy::Nvx2StreamReader::Create();
    nvx2Reader->SetStream(stream);
    nvx2Reader->SetUsage(this->usage);
    nvx2Reader->SetAccess(this->access);
    if (nvx2Reader->Open())
    {
        const Ptr<Mesh>& res = this->resource.downcast<Mesh>();
        n_assert(!res->IsLoaded());
        res->SetVertexBuffer(nvx2Reader->GetVertexBuffer().downcast<CoreGraphics::VertexBuffer>());
        res->SetIndexBuffer(nvx2Reader->GetIndexBuffer().downcast<CoreGraphics::IndexBuffer>());
        res->SetPrimitiveGroups(nvx2Reader->GetPrimitiveGroups());
        nvx2Reader->Close();
        return true;
    }
    return false;
}
#endif

//------------------------------------------------------------------------------
/**
 Setup the mesh resource from a nvx3 file (Nebula3's
 native binary mesh file format).
 */
bool
OGLStreamMeshLoader::SetupMeshFromNvx3(const Ptr<Stream>& stream)
{
    // FIXME!
    n_error("OGLStreamMeshLoader::SetupMeshFromNvx3() not yet implemented");
    return false;
}

//------------------------------------------------------------------------------
/**
 Setup the mesh resource from a n3d3 file (Nebula3's
 native ascii mesh file format).
 */
bool
OGLStreamMeshLoader::SetupMeshFromN3d3(const Ptr<Stream>& stream)
{
    // FIXME!
    n_error("OGLStreamMeshLoader::SetupMeshFromN3d3() not yet implemented");
    return false;
}
    
} // namespace OGL
