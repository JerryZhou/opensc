cmake_minimum_required(VERSION 2.8)

project(tinyxml)

set(TINY_XML_SRCS
  ${CMAKE_CURRENT_SOURCE_DIR}/tinystr.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tinystr.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tinyxml.h
  ${CMAKE_CURRENT_SOURCE_DIR}/tinyxml.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tinyxmlerror.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/tinyxmlparser.cc
)

include_directories(${CMAKE_SOURCE_DIR}/code/foundation)
include_directories(${CMAKE_SOURCE_DIR}/code/extlibs)
add_library(tinyxml STATIC ${TINY_XML_SRCS})
set_target_properties(tinyxml PROPERTIES FOLDER extlibs)