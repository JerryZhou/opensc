cmake_minimum_required (VERSION 2.8)
project (Nebula3)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# no harm in adding the include dir in all platforms
set(N3_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${N3_DIR}/code/extlibs/glfw/include)

add_subdirectory(code/foundation)
add_subdirectory(code/render)
#add_subdirectory(code/application)
add_subdirectory(code/extlibs/zlib)
add_subdirectory(code/extlibs/glfw)
add_subdirectory(code/extlibs/tinyxml)
add_subdirectory(code/extlibs/SOIL)
add_subdirectory(code/tests)
add_subdirectory(code/mygame)
