cmake_minimum_required (VERSION 2.8)

# includes
include_directories(${CMAKE_SOURCE_DIR}/3rd/n3/code/extlibs)
include_directories(${CMAKE_SOURCE_DIR}/3rd/n3/code/foundation)
include_directories(${CMAKE_SOURCE_DIR}/include)

# libs
link_directories(${CMAKE_SOURCE_DIR}/3rd/n3/lib)

# srcs
set(J_SRC_DIR ${CMAKE_SOURCE_DIR}/src)
include_directories(${J_SRC_DIR})

set(J_BASE_SRCS
    ${J_SRC_DIR}/base/log.h
    ${J_SRC_DIR}/base/log.cpp
    ${J_SRC_DIR}/base/target.h
    ${J_SRC_DIR}/base/target.cpp
    ${J_SRC_DIR}/base/event/event.h
    ${J_SRC_DIR}/base/event/event.cpp
    ${J_SRC_DIR}/base/event/eventtarget.h
    ${J_SRC_DIR}/base/event/eventtarget.cpp
    ${J_SRC_DIR}/base/event/eventdelegate.h
    ${J_SRC_DIR}/base/event/eventdelegate.cpp
)
source_group(base FILES ${J_BASE_SRCS})

# static library
add_library(opensc STATIC
    ${J_BASE_SRCS}
)

# out put library
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
