cmake_minimum_required (VERSION 2.8)
project (Tests)

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")
message("CMAKE_BUILD_TYPE is ${CMAKE_BUILD_TYPE}")
message("CMAKE_SOURCE_DIR is ${CMAKE_SOURCE_DIR}")

if(APPLE)
  set(PLATFORM_DIR "osx")
endif(APPLE)

include_directories(${CMAKE_SOURCE_DIR}/code/foundation)
include_directories(${CMAKE_SOURCE_DIR}/code/extlibs)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

set(N3_TESTS_SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${N3_FOUNDATION_SRC_DIR})

set(N3_TESTBASE_SRCS
  ${N3_TESTS_SRC_DIR}/testbase/stackdebug.h
  ${N3_TESTS_SRC_DIR}/testbase/stackdebug.cc
  ${N3_TESTS_SRC_DIR}/testbase/testcase.h
  ${N3_TESTS_SRC_DIR}/testbase/testcase.cc
  ${N3_TESTS_SRC_DIR}/testbase/testrunner.h
  ${N3_TESTS_SRC_DIR}/testbase/testrunner.cc
)
# uncomment to hide the Header Files and Source Files directories
#source_group("" FILES ${N3_TESTBASE_SRCS})

add_library(testbase ${N3_TESTBASE_SRCS})
set_target_properties(testbase PROPERTIES FOLDER tests)

#
# Foundation Tests
#
set(N3_TESTFOUNDATION_SRCS
  ${N3_TESTS_SRC_DIR}/testfoundation/float4test.h
  ${N3_TESTS_SRC_DIR}/testfoundation/float4test.cc
  ${N3_TESTS_SRC_DIR}/testfoundation/httpclienttest.h
  ${N3_TESTS_SRC_DIR}/testfoundation/httpclienttest.cc
  ${N3_TESTS_SRC_DIR}/testfoundation/main.cc
)
# uncomment to hide the Header Files and Source Files directories
#source_group("" FILES ${N3_TESTFOUNDATION_SRCS})

add_executable(testfoundation ${N3_TESTFOUNDATION_SRCS})
target_link_libraries(testfoundation
  foundation
  zlib
  testbase
)
set_target_properties(testfoundation PROPERTIES FOLDER tests)
set_target_properties(testfoundation PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PLATFORM_DIR})

#
# Math Tests
#
set(N3_MATHTEST_SRCS
  ${N3_TESTS_SRC_DIR}/mathtest/float4test.h
  ${N3_TESTS_SRC_DIR}/mathtest/float4test.cc
  ${N3_TESTS_SRC_DIR}/mathtest/main.cc
  ${N3_TESTS_SRC_DIR}/mathtest/mathtestutil.h
  ${N3_TESTS_SRC_DIR}/mathtest/matrix44test.h
  ${N3_TESTS_SRC_DIR}/mathtest/matrix44test.cc
  ${N3_TESTS_SRC_DIR}/mathtest/planetest.h
  ${N3_TESTS_SRC_DIR}/mathtest/planetest.cc
  ${N3_TESTS_SRC_DIR}/mathtest/pointtest.h
  ${N3_TESTS_SRC_DIR}/mathtest/pointtest.cc
  ${N3_TESTS_SRC_DIR}/mathtest/quaterniontest.h
  ${N3_TESTS_SRC_DIR}/mathtest/quaterniontest.cc
  ${N3_TESTS_SRC_DIR}/mathtest/scalartest.h
  ${N3_TESTS_SRC_DIR}/mathtest/scalartest.cc
  ${N3_TESTS_SRC_DIR}/mathtest/stackalignment.h
  ${N3_TESTS_SRC_DIR}/mathtest/vectortest.h
  ${N3_TESTS_SRC_DIR}/mathtest/vectortest.cc
)
# uncomment to hide the Header Files and Source Files directories
#source_group("" FILES ${N3_MATHTEST_SRCS})

#add_executable(mathtest ${N3_MATHTEST_SRCS})
#target_link_libraries(mathtest
#  foundation
#  zlib
#  testbase
#)
#set_target_properties(mathtest PROPERTIES FOLDER tests)
#set_target_properties(mathtest PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${PLATFORM_DIR})