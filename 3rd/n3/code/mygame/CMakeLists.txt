cmake_minimum_required (VERSION 2.8)
project (MyGameApp)

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
message("CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")

include_directories(${N3_DIR}/code/foundation)
include_directories(${N3_DIR}/code/render)
include_directories(${N3_DIR}/code/extlibs)

if(APPLE)
  # opengl
  find_package(OpenGL REQUIRED)
  include_directories(${OPENGL_INCLUDE_DIR})
  # cocoa and IO Kit
  find_library(COCOA_LIBRARY Cocoa)
  find_library(IOKIT_LIBRARY IOKit)
  set(EXTRA_LIBS
    glfw
    ${OPENGL_LIBRARIES}
    ${COCOA_LIBRARY}
    ${IOKIT_LIBRARY}
  )
  set(PLATFORM_OUTPUT_DIR "osx")
endif(APPLE)

set(MY_GAME_SRCS
  mygameapplication.h
  mygameapplication.cc
  mygame.cc
)

add_executable(mygame ${MY_GAME_SRCS})
target_link_libraries(mygame foundation render zlib tinyxml SOIL ${EXTRA_LIBS})
#set_target_properties(mygame PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${N3_DIR}/bin/${PLATFORM_DIR})
set_target_properties(mygame PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${N3_DIR}/bin/${PLATFORM_OUTPUT_DIR})
set_target_properties(mygame PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${N3_DIR}/bin/${PLATFORM_OUTPUT_DIR})
set_target_properties(mygame PROPERTIES DEBUG_POSTFIX "_d")
