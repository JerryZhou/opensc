cmake_minimum_required (VERSION 2.8)

set(N3_RENDER_SRC_DIR ${N3_DIR}/code/render)
include_directories(${N3_RENDER_SRC_DIR})

include_directories(${N3_DIR}/code/foundation)
include_directories(${N3_DIR}/code/extlibs)
include_directories(${N3_DIR}/code/extlibs/SOIL)

set(N3_RENDER_COREGRAPHICS_SRCS
  ${N3_RENDER_SRC_DIR}/coregraphics/displaydevice.h
  ${N3_RENDER_SRC_DIR}/coregraphics/displaydevice.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/indexbuffer.h
  ${N3_RENDER_SRC_DIR}/coregraphics/indexbuffer.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/memoryindexbufferloader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/memoryindexbufferloader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/memorymeshloader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/memorymeshloader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/memoryvertexbufferloader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/memoryvertexbufferloader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/mesh.h
  ${N3_RENDER_SRC_DIR}/coregraphics/mesh.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/multiplerendertarget.h
  ${N3_RENDER_SRC_DIR}/coregraphics/multiplerendertarget.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/primitivetopology.h
  ${N3_RENDER_SRC_DIR}/coregraphics/primitivetopology.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/renderdevice.h
  ${N3_RENDER_SRC_DIR}/coregraphics/renderdevice.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/rendertarget.h
  ${N3_RENDER_SRC_DIR}/coregraphics/rendertarget.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shaderfeature.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shaderfeature.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shaderinstance.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shaderinstance.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shadersemantics.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shaderserver.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shaderserver.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shadervariable.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shadervariable.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shadervariableinstance.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shadervariableinstance.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/shadervariation.h
  ${N3_RENDER_SRC_DIR}/coregraphics/shadervariation.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/streammeshloader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/streammeshloader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/streamshaderloader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/streamshaderloader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/streamtextureloader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/streamtextureloader.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/texture.h
  ${N3_RENDER_SRC_DIR}/coregraphics/texture.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/transformdevice.h
  ${N3_RENDER_SRC_DIR}/coregraphics/transformdevice.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexbuffer.h
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexbuffer.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexcomponent.h
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexlayout.h
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexlayout.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexlayoutserver.h
  ${N3_RENDER_SRC_DIR}/coregraphics/vertexlayoutserver.cc
)
source_group(coregraphics FILES ${N3_RENDER_COREGRAPHICS_SRCS})

set(N3_RENDER_COREGRAPHICS_BASE_SRCS
  ${N3_RENDER_SRC_DIR}/coregraphics/base/displaydevicebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/displaydevicebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/indexbufferbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/indexbufferbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/meshbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/meshbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/memoryindexbufferloaderbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/memoryindexbufferloaderbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/memoryvertexbufferloaderbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/memoryvertexbufferloaderbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/multiplerendertargetbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/multiplerendertargetbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/renderdevicebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/renderdevicebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/rendertargetbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/rendertargetbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/resourcebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/resourcebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shaderbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shaderbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shaderinstancebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shaderinstancebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shaderserverbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shaderserverbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shadervariablebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shadervariablebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shadervariableinstancebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shadervariableinstancebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shadervariationbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/shadervariationbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/texturebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/texturebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/transformdevicebase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/transformdevicebase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexbufferbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexbufferbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexcomponentbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexlayoutbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexlayoutbase.cc
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexlayoutserverbase.h
  ${N3_RENDER_SRC_DIR}/coregraphics/base/vertexlayoutserverbase.cc
)
source_group(coregraphics\\base FILES ${N3_RENDER_COREGRAPHICS_BASE_SRCS})

set(N3_RENDER_COREGRAPHICS_LEGACY_SRCS
  ${N3_RENDER_SRC_DIR}/coregraphics/legacy/nvx2streamreader.h
  ${N3_RENDER_SRC_DIR}/coregraphics/legacy/nvx2streamreader.cc
)
source_group(coregraphics\\legacy FILES ${N3_RENDER_COREGRAPHICS_LEGACY_SRCS})

if(APPLE)
  include_directories(${CMAKE_SOURCE_DIR}/code/extlibs/glfw/include)
  set(N3_RENDER_COREGRAPHICS_PLATFORM_SRCS
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/gldebug.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/gldebug.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogldisplaydevice.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogldisplaydevice.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglindexbuffer.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglindexbuffer.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglmemoryindexbufferloader.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglmemoryindexbufferloader.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglmemoryshaderloader.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglmemoryshaderloader.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglmemoryvertexbufferloader.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglmemoryvertexbufferloader.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglrenderdevice.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglrenderdevice.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglrendertarget.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglrendertarget.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglvertexbuffer.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglvertexbuffer.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglshader.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglshader.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglshaderinstance.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglshaderinstance.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglshadervariable.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglshadervariable.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglstreammeshloader.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglstreammeshloader.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglstreamtextureloader.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglstreamtextureloader.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogltransformdevice.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogltransformdevice.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogltexture.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogltexture.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogltypes.h
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/ogltypes.cc
    ${N3_RENDER_SRC_DIR}/coregraphics/ogl/oglvertexcomponent.h
  )
  source_group(coregraphics\\ogl FILES ${N3_RENDER_COREGRAPHICS_PLATFORM_SRCS})
endif()

set(N3_RENDER_RESOURCES_SRCS
  ${N3_RENDER_SRC_DIR}/resources/resource.h
  ${N3_RENDER_SRC_DIR}/resources/resource.cc
  ${N3_RENDER_SRC_DIR}/resources/resourceloader.h
  ${N3_RENDER_SRC_DIR}/resources/resourceloader.cc
  ${N3_RENDER_SRC_DIR}/resources/resourcemanager.h
  ${N3_RENDER_SRC_DIR}/resources/resourcemanager.cc
  ${N3_RENDER_SRC_DIR}/resources/streamresourceloader.h
  ${N3_RENDER_SRC_DIR}/resources/streamresourceloader.cc
)
source_group(resources FILES ${N3_RENDER_RESOURCES_SRCS})

set(N3_RENDER_COREGRAPHICS_SRCS
  ${N3_RENDER_COREGRAPHICS_SRCS}
  ${N3_RENDER_COREGRAPHICS_BASE_SRCS}
  ${N3_RENDER_COREGRAPHICS_LEGACY_SRCS}
  ${N3_RENDER_COREGRAPHICS_PLATFORM_SRCS}
)

set(N3_RENDER_SRCS_MAIN
#  ${N3_RENDER_SRC_DIR}/render_classregistry.h
  ${N3_RENDER_SRC_DIR}/stdneb.h
  ${N3_RENDER_SRC_DIR}/stdneb.cc
)
source_group("" FILES ${N3_RENDER_SRCS_MAIN})

add_library(render STATIC
  ${N3_RENDER_COREGRAPHICS_SRCS}
  ${N3_RENDER_RESOURCES_SRCS}
  ${N3_RENDER_SRCS_MAIN}
)

#target_link_libraries(foundation zlib)
#set_target_properties(render PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
