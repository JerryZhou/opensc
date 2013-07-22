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
)
source_group(base FILES ${J_BASE_SRCS})

set(J_BASE_EVENT_SRCS
    ${J_SRC_DIR}/base/event/event.h
    ${J_SRC_DIR}/base/event/event.cpp
    ${J_SRC_DIR}/base/event/eventtarget.h
    ${J_SRC_DIR}/base/event/eventtarget.cpp
    ${J_SRC_DIR}/base/event/eventdelegate.h
    ${J_SRC_DIR}/base/event/eventdelegate.cpp
    ${J_SRC_DIR}/base/event/eventdispatch.h
    ${J_SRC_DIR}/base/event/eventdispatch.cpp
)
source_group(base\\event FILES ${J_BASE_EVENT_SRCS})

set(J_COMPONENT_ENTITY_SRCS
    ${J_SRC_DIR}/component/entity/entity.h
    ${J_SRC_DIR}/component/entity/entity.cpp
)
source_group(component\\entity FILES ${J_COMPONENT_ENTITY_SRCS})

set(J_COMPONENT_TEMPLATE_SRCS
    ${J_SRC_DIR}/component/template/templaterecord.h
    ${J_SRC_DIR}/component/template/templaterecord.cpp
    ${J_SRC_DIR}/component/template/templatecontainer.h
    ${J_SRC_DIR}/component/template/templatecontainer.cpp
    ${J_SRC_DIR}/component/template/templateenum.h
    ${J_SRC_DIR}/component/template/templateenum.cpp
)
source_group(component\\template FILES ${J_COMPONENT_TEMPLATE_SRCS})

set(J_COMPONENT_TEMPLATE_RECORD_SRCS
    ${J_SRC_DIR}/component/template/record/recordenum.h
    ${J_SRC_DIR}/component/template/record/recordflag.h
)
source_group(component\\template\\record FILES ${J_COMPONENT_TEMPLATE_RECORD_SRCS})

# static library
add_library(opensc STATIC
    ${J_BASE_SRCS}
    ${J_BASE_EVENT_SRCS}
    ${J_COMPONENT_ENTITY_SRCS}
    ${J_COMPONENT_TEMPLATE_SRCS}
    ${J_COMPONENT_TEMPLATE_RECORD_SRCS}
)

# out put library
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
