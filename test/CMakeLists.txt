cmake_minimum_required (VERSION 2.8)

# includes
include_directories(${CMAKE_SOURCE_DIR}/3rd/googletest/include)
include_directories(${CMAKE_SOURCE_DIR}/3rd/n3/code/extlibs)
include_directories(${CMAKE_SOURCE_DIR}/3rd/n3/code/foundation)
include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/src)

# libs
link_directories(${CMAKE_SOURCE_DIR}/3rd/n3/lib
    ${CMAKE_SOURCE_DIR}/3rd/googletest/lib
)

# srcs
set(J_T_SRC_DIR ${CMAKE_SOURCE_DIR}/test)
include_directories(${J_T_SRC_DIR})

set(J_BASE_SRCS
    ${J_T_SRC_DIR}/main.cpp
    ${J_T_SRC_DIR}/openscapplication.h
    ${J_T_SRC_DIR}/openscapplication.cpp
    ${J_T_SRC_DIR}/test_log.h
    ${J_T_SRC_DIR}/test_macrodef.h
    ${J_T_SRC_DIR}/test_event.h
    ${J_T_SRC_DIR}/test_eventdelegate.h
    ${J_T_SRC_DIR}/test_eventdispatch.h
    ${J_T_SRC_DIR}/test_eventtarget.h
    ${J_T_SRC_DIR}/test_target.h
    ${J_T_SRC_DIR}/test_templateclass.h
    ${J_T_SRC_DIR}/test_templateenum.h
    ${J_T_SRC_DIR}/test_templaterecord.h
    ${J_T_SRC_DIR}/test_templateloader.h
)
source_group(src FILES ${J_BASE_SRCS})

# static library
add_executable(jtest 
    ${J_BASE_SRCS}
)
target_link_libraries(jtest 
    opensc 
    foundation
    zlib
    tinyxml
    ${CMAKE_SOURCE_DIR}/3rd/googletest/lib/gtest_main.a 
)

# out put library
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
