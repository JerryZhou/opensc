//------------------------------------------------------------------------------
//  zipstresstestapplication.cc
//  (C) 2008 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "io/iointerface.h"
#include "coregraphics/memoryvertexbufferloader.h"
#include "coregraphics/memoryindexbufferloader.h"
#include "coregraphics/memorymeshloader.h"
#include "coregraphics/streammeshloader.h"
#include "coregraphics/streamtextureloader.h"
#include "coregraphics/ogl/oglmemoryshaderloader.h"
#include "coregraphics/shadersemantics.h"
#include "mygameapplication.h"

namespace App
{
using namespace IO;
using namespace Util;
using namespace CoreGraphics;
using namespace Debug;
using namespace Http;
using namespace Resources;
    
//------------------------------------------------------------------------------
/**
 */
void CreateMesh()
{
    // create vertices
    float vertices[] = {
        //-----position--------|-------color------|
        -2.0f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // BL
        -0.2f, -1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // BR
        -0.2f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, // TR
        -2.0f,  1.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f// TL
    };
    
    // create indices
    ushort indices[] = {
        0, 1, 2,
        0, 2, 3
    };
    
    // create vertex components
    Array<VertexComponent> vertexComponents;
    vertexComponents.Append(VertexComponent(VertexComponent::Position, 0, VertexComponent::Float4, 0));
    vertexComponents.Append(VertexComponent(VertexComponent::Color, 0, VertexComponent::Float3, 0));
    //vertexComponents.Append(VertexComponent(VertexComponent::TexCoord, 0, VertexComponent::Float2, 1));
    //vertexComponents.Append(VertexComponent(VertexComponent::TexCoord, 1, VertexComponent::Float2, 1));
    
    /// create vertex buffer
    Ptr<VertexBuffer> vb = VertexBuffer::Create();
    Ptr<MemoryVertexBufferLoader> mvbLoader = MemoryVertexBufferLoader::Create();
    mvbLoader->Setup(vertexComponents, 4, vertices, sizeof(vertices), VertexBuffer::UsageImmutable, VertexBuffer::AccessNone);
    vb->SetLoader(mvbLoader.upcast<ResourceLoader>());
    vb->SetAsyncEnabled(false);
    vb->Load();
    if (!vb->IsLoaded())
    {
        n_error("Failed to load vertex buffer!");
    }
    
    // create index buffer
    Ptr<IndexBuffer> ib = IndexBuffer::Create();
    Ptr<MemoryIndexBufferLoader> mibLoader = MemoryIndexBufferLoader::Create();
    mibLoader->Setup(IndexType::Index16, 6, indices, sizeof(indices), IndexBuffer::UsageImmutable, IndexBuffer::AccessNone);
    ib->SetLoader(mibLoader.upcast<ResourceLoader>());
    ib->SetAsyncEnabled(false);
    ib->Load();
    if (!ib->IsLoaded())
    {
        n_error("Failed to load vertex buffer!");
    }
    
    // create primitive group(s)
    Array<PrimitiveGroup> primitiveGroups;
    PrimitiveGroup primitiveGroup0;
    primitiveGroup0.SetBaseIndex(0);
    primitiveGroup0.SetBaseVertex(0);
    primitiveGroup0.SetNumIndices(6);
    primitiveGroup0.SetNumVertices(4);
    primitiveGroup0.SetPrimitiveTopology(PrimitiveTopology::TriangleList);
    primitiveGroup0.SetBoundingBox(Math::bbox());
    primitiveGroups.Append(primitiveGroup0);
    
    //create mesh loader
    Ptr<MemoryMeshLoader> memoryMeshLoader = MemoryMeshLoader::Create();
    memoryMeshLoader->SetVertexBuffer(vb);
    memoryMeshLoader->SetIndexBuffer(ib);
    memoryMeshLoader->SetPrimitiveGroups(primitiveGroups);
}
    
//------------------------------------------------------------------------------
/**
*/
bool
MyGameApplication::Open()
{
    n_assert(!this->IsOpen());
    if (ConsoleApplication::Open())
    {        
        // setup asynchronous IO
        this->ioInterface = IoInterface::Create();
        this->ioInterface->Open();
        if (IoServer::Instance()->FileExists("home:export_osx.zip"))
        {
            // main thread
            this->ioServer->MountArchive("home:export_osx");
            
            // io thread
            /*Ptr<IO::MountArchive> mountArchiveMsg = IO::MountArchive::Create();
            mountArchiveMsg->SetURI("home:export_win32");
            this->ioInterface->Send(mountArchiveMsg.upcast<Messaging::Message>());*/
        }
        
        this->httpInterface = HttpInterface::Create();
        this->httpInterface->Open();
        
        // debug server instance requires by render device
        // setup core runtime, debug server and a http server proxy
        this->debugHandler = DebugHandler::Create();
        this->debugHandler->Open();
        
        // create window
        this->displayDevice = DisplayDevice::Create();
        this->displayDevice->Open();
        
        // render device
        this->renderDevice = RenderDevice::Create();
        this->renderDevice->Open();
        
        //vertex layout server
        this->vertexLayoutServer = VertexLayoutServer::Create();
        this->vertexLayoutServer->Open();
        
        // transform device
        this->transformDevice = TransformDevice::Create();
        this->transformDevice->Open();
        
        //create mesh
        this->mesh = Mesh::Create();
        this->mesh->SetResourceId(ResourceId("meshes:examples/tiger_s_0.nvx2"));
        //this->mesh->SetResourceId(ResourceId("meshes:examples/sphere_s_0.nvx2"));
        Ptr<StreamMeshLoader> streamMeshLoader = StreamMeshLoader::Create();
        this->mesh->SetLoader(streamMeshLoader.upcast<ResourceLoader>());
        this->mesh->SetAsyncEnabled(false);
        this->mesh->Load();
        if (!this->mesh->IsLoaded())
        {
            n_error("Failed to load mesh!");
        }
        this->mesh->SetLoader(0);
        
        // set diffmap 0 semantic
        this->diffMap0Semantic = ShaderVariable::Semantic(NEBULA3_SEMANTIC_DIFFMAP0);
        
        // setup texture
        this->diffMap0Texture = Texture::Create();
        this->diffMap0Texture->SetResourceId(ResourceId("tex:examples/tiger.dds"));
        //this->diffMap0Texture->SetResourceId(ResourceId("tex:system/uv-map_seam.dds"));
        Ptr<StreamTextureLoader> streamTextureLoader = StreamTextureLoader::Create();
        this->diffMap0Texture->SetLoader(streamTextureLoader.upcast<ResourceLoader>());
        this->diffMap0Texture->SetAsyncEnabled(false);
        this->diffMap0Texture->Load();
        if (!this->diffMap0Texture->IsLoaded())
        {
            n_error("Failed to load texture!");
        }
        this->diffMap0Texture->SetLoader(0);
        
        // setup shader
        Ptr<OGL::OGLMemoryShaderLoader> memShdLoader = OGL::OGLMemoryShaderLoader::Create();
        memShdLoader->SetVertexShaderSrc("#version 150\n\
                                         uniform mat4 ModelViewProjection;\
                                         uniform mat4 Model;\
                                         uniform mat4 View;\
                                         uniform mat4 Projection;\
                                         in vec4 Position;\
                                         in vec3 Color;\
                                         out vec3 vsColor;\
                                         in vec2 TexCoord0;\
                                         out vec2 outTexCoord0;\
                                         void main()\
                                         {\
                                             vsColor = Color;\
                                             outTexCoord0 = TexCoord0;\
                                             gl_Position = Projection * View * Model * Position;\n\
                                         }");
        memShdLoader->SetFragmentShaderSrc("#version 150\n\
                                           uniform sampler2D DiffMap0;\
                                           in vec3 vsColor;\
                                           out vec4 outColor;\
                                           in vec2 outTexCoord0;\
                                           void main()\
                                           {\
                                               outColor = texture( DiffMap0, outTexCoord0 ).rgba;\
                                           }");
        
        this->shader = Shader::Create();
        this->shader->SetLoader(memShdLoader.upcast<ResourceLoader>());
        this->shader->SetAsyncEnabled(false);
        this->shader->Load();
        if (!this->shader->IsLoaded())
        {
            n_error("Failed to load shader!");
        }
        this->shader->SetLoader(0);
        
        this->shaderInstance = this->shader->CreateShaderInstance();
        
        return true;   
    }
    return false;
}
    
//------------------------------------------------------------------------------
/**
 */
void
MyGameApplication::Close()
{
    this->shader->DiscardShaderInstance(this->shaderInstance);
    this->shaderInstance = 0;
    
    this->shader->Unload();
    this->shader = 0;
    
    this->diffMap0Texture->Unload();
    this->diffMap0Texture = 0;
    
    this->mesh->Unload();
    this->mesh = 0;
    
    this->transformDevice->Close();
    this->transformDevice = 0;
    
    this->vertexLayoutServer->Close();
    this->vertexLayoutServer = 0;
    
    this->renderDevice->Close();
    this->renderDevice = 0;
    
    this->displayDevice->Close();
    this->displayDevice = 0;
    
    this->debugHandler->Close();
    this->debugHandler = 0;
    
    this->httpInterface->Close();
    this->httpInterface = 0;
    
    this->ioInterface->Close();
    this->ioInterface = 0;
    
    ConsoleApplication::Close();
}

//------------------------------------------------------------------------------
/**
*/
void
MyGameApplication::Run()
{
    n_assert(this->isOpen);
    //while (!this->IsQuitRequested())
    while(!glfwWindowShouldClose(this->displayDevice->GetWindow()))
    {
        // process window messages
        this->displayDevice->ProcessWindowMessages();
        
        // start rendering
        if (this->renderDevice->BeginFrame())
        {
            this->renderDevice->BeginPass(renderDevice->GetDefaultRenderTarget(), this->shaderInstance);
            
            // Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
            Math::matrix44 proj = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
            // Camera matrix
            Math::matrix44 view = glm::lookAt(
                                              glm::vec3(5.0f, 2.0f, 5.0f), // Camera is at (0,2,5), in World Space
                                              glm::vec3(0,0,0), // and looks at the origin
                                              glm::vec3(0,1,0)  // Head is up (set to 0,-1,0 to look upside-down)
                                              );
            // Model matrix : an identity matrix (model will be at the origin)
            Math::matrix44 model      = glm::mat4(1.0f);  // Changes for each model !
            
            // set view matrices
            this->transformDevice->SetProjTransform(proj);
            this->transformDevice->SetViewTransform(view);
            /*this->transformDevice->SetFocalLength(this->camera->GetCameraSettings().GetFocalLength());*/
            
            // apply transforms
            this->transformDevice->ApplyViewSettings();
            
            this->transformDevice->SetModelTransform(model);
            
            // for each model apply model transforms
            this->transformDevice->ApplyModelTransforms(this->shaderInstance);
            
            // apply texture
            const Ptr<ShaderVariable>& diffuseMap0Var = this->shaderInstance->GetVariableBySemantic(this->diffMap0Semantic);
            diffuseMap0Var->SetTexture(this->diffMap0Texture);
            
            // apply mesh
            this->mesh->ApplyPrimitives(0);
            this->renderDevice->Draw();
            
            this->renderDevice->EndPass();
            this->renderDevice->EndFrame();
            this->renderDevice->Present();
        }
    }
}

} // namespace App