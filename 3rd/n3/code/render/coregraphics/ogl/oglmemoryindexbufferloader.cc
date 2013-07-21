//------------------------------------------------------------------------------
//  d3d9memoryindexbufferloader.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglmemoryindexbufferloader.h"
#include "coregraphics/indexbuffer.h"
#include "coregraphics/renderdevice.h"

namespace OGL
{
__ImplementClass(OGL::OGLMemoryIndexBufferLoader, 'DMIL', Base::MemoryIndexBufferLoaderBase);

using namespace Resources;
using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
 This will create a D3D9 IndexBuffer using the data provided by our
 Setup() method and set our resource object (which must be a
 D3D9IndexBuffer object).
 */
bool
OGLMemoryIndexBufferLoader::OnLoadRequested()
{
    n_assert(this->GetState() == Resource::Initial);
    n_assert(this->resource.isvalid());
    n_assert(!this->resource->IsAsyncEnabled());
    n_assert(this->indexType != IndexType::None);
    n_assert(this->numIndices > 0);
    if (IndexBuffer::UsageImmutable == this->usage)
    {
        n_assert(this->indexDataSize == (this->numIndices * IndexType::SizeOf(this->indexType)));
        n_assert(0 != this->indexDataPtr);
        n_assert(0 < this->indexDataSize);
    }
    
    // create an index buffer object
    GLuint indexBuffer;
    glGenBuffers(1, &indexBuffer);
    
    /// TODO: glGetErrors
    n_assert(0 != indexBuffer);
    
    // setup initial data if provided
    if (0 != this->indexDataPtr)
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->indexDataSize, this->indexDataPtr, GL_STATIC_DRAW);
    }
    
    // setup our IndexBuffer resource
    const Ptr<IndexBuffer>& res = this->resource.downcast<IndexBuffer>();
    n_assert(!res->IsLoaded());
    res->SetUsage(this->usage);
    res->SetAccess(this->access);
    res->SetIndexType(this->indexType);
    res->SetNumIndices(this->numIndices);
    res->SetGLIndexBuffer(indexBuffer);
    
    // invalidate setup data (because we don't own our data)
    this->indexDataPtr = 0;
    this->indexDataSize = 0;
    
    this->SetState(Resource::Loaded);
    return true;
}
} // namespace OGL
