cmake_minimum_required (VERSION 2.8)
project (OpenSC)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")

include_directories(${CMAKE_SOURCE_DIR}/3rd/n3/code/extlibs/glfw/include)

add_subdirectory(src/)
add_subdirectory(test/)
add_subdirectory(3rd/n3/)
