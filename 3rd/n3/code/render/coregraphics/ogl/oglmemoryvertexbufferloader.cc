//------------------------------------------------------------------------------
//  d3d9memoryvertexbufferloader.cc
//  (C) 2007 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "coregraphics/ogl/oglmemoryvertexbufferloader.h"
#include "coregraphics/ogl/gldebug.h"
#include "coregraphics/vertexlayoutserver.h"
#include "coregraphics/renderdevice.h"
#include "coregraphics/vertexbuffer.h"

namespace OGL
{
__ImplementClass(OGL::OGLMemoryVertexBufferLoader, 'GMVL', Base::MemoryVertexBufferLoaderBase);

using namespace Resources;
using namespace CoreGraphics;

//------------------------------------------------------------------------------
/**
    This will create a OGL vertex buffer and vertex declaration object
    from the data provided in the Setup() method and setup our resource
    object (which must be a OGLVertexBuffer object).
*/
bool
OGLMemoryVertexBufferLoader::OnLoadRequested()
{
    n_assert(this->GetState() == Resource::Initial);
    n_assert(this->resource.isvalid());
    n_assert(!this->resource->IsAsyncEnabled());
    n_assert(this->numVertices > 0);
    if (VertexBuffer::UsageImmutable == this->usage)
    {
        n_assert(0 != this->vertexDataPtr);
        n_assert(0 < this->vertexDataSize);
    }

    // first setup the vertex layout
    Ptr<VertexLayout> vertexLayout = VertexLayoutServer::Instance()->CreateSharedVertexLayout(this->vertexComponents);
    if (0 != this->vertexDataPtr)
    {
        n_assert((this->numVertices * vertexLayout->GetVertexByteSize()) == this->vertexDataSize);
    }

    // create an Open GL vertex buffer object
    GLuint vertexArray, vertexBuffer;
    
    GLDEBUG(glGenBuffers(1, &vertexBuffer));
    GLDEBUG(glGenVertexArrays(1, &vertexArray));
    
    ///GLenum usage =  OGLTypes::AsOGLUsage(this->usage, this->access);
    
    // setup initial data if provided
    if (0 != this->vertexDataPtr)
    {
        //vertex buffer
        GLDEBUG(glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer));
        // @todo: set usage hint appropriately
        GLDEBUG(glBufferData(GL_ARRAY_BUFFER, this->vertexDataSize, this->vertexDataPtr, GL_STATIC_DRAW));
    }

    // setup our resource object
    const Ptr<VertexBuffer>& res = this->resource.downcast<VertexBuffer>();
    n_assert(!res->IsLoaded());
	res->SetUsage(this->usage);
	res->SetAccess(this->access);
    res->SetVertexLayout(vertexLayout);
    res->SetNumVertices(this->numVertices);
    res->SetGLVertexBuffer(vertexBuffer);
    res->SetGLVertexArray(vertexArray);
    
    // TODO: ubind vertex array and buffer

    // invalidate setup data (because we don't own our data)
    this->vertexDataPtr = 0;
    this->vertexDataSize = 0;

    this->SetState(Resource::Loaded);
    return true;
}

} // namespace OGL
