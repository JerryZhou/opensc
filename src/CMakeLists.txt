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
    ${J_SRC_DIR}/base/markflag.h
    ${J_SRC_DIR}/base/markflag.cpp
    ${J_SRC_DIR}/base/manager.h
    ${J_SRC_DIR}/base/manager.cpp
)
source_group(base FILES ${J_BASE_SRCS})

set(J_BASE_FSM_SRCS
    ${J_SRC_DIR}/base/fsm/fsm.h
    ${J_SRC_DIR}/base/fsm/fsm.cpp
    ${J_SRC_DIR}/base/fsm/fsmaction.h
    ${J_SRC_DIR}/base/fsm/fsmaction.cpp
    ${J_SRC_DIR}/base/fsm/fsmcondition.h
    ${J_SRC_DIR}/base/fsm/fsmcondition.cpp
    ${J_SRC_DIR}/base/fsm/fsmcontext.h
    ${J_SRC_DIR}/base/fsm/fsmcontext.cpp
    ${J_SRC_DIR}/base/fsm/fsmevent.h
    ${J_SRC_DIR}/base/fsm/fsmevent.cpp
    ${J_SRC_DIR}/base/fsm/fsmtransition.h
    ${J_SRC_DIR}/base/fsm/fsmtransition.cpp
)
source_group(base\\fsm FILES ${J_BASE_FSM_SRCS})


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
    ${J_SRC_DIR}/component/unit/unit.h
    ${J_SRC_DIR}/component/unit/unit.cpp
    ${J_SRC_DIR}/component/unit/unitmanager.h
    ${J_SRC_DIR}/component/unit/unitmanager.cpp
)
source_group(component\\unit FILES ${J_COMPONENT_ENTITY_SRCS})

set(J_COMPONENT_TEMPLATE_SRCS
    ${J_SRC_DIR}/component/template/templaterecord.h
    ${J_SRC_DIR}/component/template/templaterecord.cpp
    ${J_SRC_DIR}/component/template/templatecontainer.h
    ${J_SRC_DIR}/component/template/templatecontainer.cpp
    ${J_SRC_DIR}/component/template/templateenum.h
    ${J_SRC_DIR}/component/template/templateenum.cpp
    ${J_SRC_DIR}/component/template/templateclass.h
    ${J_SRC_DIR}/component/template/templateclass.cpp
    ${J_SRC_DIR}/component/template/templateinit.h
    ${J_SRC_DIR}/component/template/templateinit.cpp
    ${J_SRC_DIR}/component/template/templateloader.h
    ${J_SRC_DIR}/component/template/templateloader.cpp
    ${J_SRC_DIR}/component/template/templatemanager.h
    ${J_SRC_DIR}/component/template/templatemanager.cpp
)
source_group(component\\template FILES ${J_COMPONENT_TEMPLATE_SRCS})

set(J_COMPONENT_TEMPLATE_RECORD_SRCS
    ${J_SRC_DIR}/component/template/record/recordenum.h
    ${J_SRC_DIR}/component/template/record/recordflag.h
    ${J_SRC_DIR}/component/template/record/recordclass.h
    ${J_SRC_DIR}/component/template/record/recordstruct.h
)
source_group(component\\template\\record FILES ${J_COMPONENT_TEMPLATE_RECORD_SRCS})

file(GLOB J_SIMULATION_SRCS_H "${J_SRC_DIR}/simulation/*.h")
file(GLOB J_SIMULATION_SRCS_CPP "${J_SRC_DIR}/simulation/*.cpp")
LIST(APPEND J_SIMULATION_SYSTEM_SRCS 
    ${J_SIMULATION_SRCS_H} 
    ${J_SIMULATION_SRCS_CPP})
source_group(simulation FILES ${J_SIMULATION_SRCS})


file(GLOB J_SIMULATION_SYSTEM_SRCS_H "${J_SRC_DIR}/simulation/system/*.h")
file(GLOB J_SIMULATION_SYSTEM_SRCS_CPP "${J_SRC_DIR}/simulation/system/*.cpp")
LIST(APPEND J_SIMULATION_SYSTEM_SRCS 
    ${J_SIMULATION_SYSTEM_SRCS_H} 
    ${J_SIMULATION_SYSTEM_SRCS_CPP})
source_group(simulation\\system FILES ${J_SIMULATION_SYSTEM_SRCS})

#aux_source_directory($(J_SRC_DIR}/network J_NETWORK_SRCS)
#message(${J_NETWORK_SRCS})
#source_group(network FILES ${J_NETWORK_SRCS})

# static library
add_library(opensc STATIC
    ${J_BASE_SRCS}
    ${J_BASE_FSM_SRCS}
    ${J_BASE_EVENT_SRCS}
    ${J_COMPONENT_ENTITY_SRCS}
    ${J_COMPONENT_TEMPLATE_SRCS}
    ${J_COMPONENT_TEMPLATE_RECORD_SRCS}
    ${J_SIMULATION_SRCS}
    ${J_SIMULATION_SYSTEM_SRCS}
)

# out put library
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/../bin)
