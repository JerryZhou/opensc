cmake_minimum_required (VERSION 2.8)

set(N3_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)

include_directories(${N3_DIR}/code)
include_directories(${N3_DIR}/code/extlibs)
include_directories(${N3_DIR}/code/addons)
include_directories(${N3_DIR}/code/addons/network)
include_directories(${N3_DIR}/code/addons/posteffect)
include_directories(${N3_DIR}/code/addons/ode)
include_directories(${N3_DIR}/code/foundation)
include_directories(${N3_DIR}/code/render)
include_directories(${N3_DIR}/code/application)
include_directories(${N3_DIR}/code/application/basegamefeature)
#include_directories(${N3_DIR}/code/application/graphicsfeature)
#include_directories(${N3_DIR}/code/application/physicsfeature)
#include_directories(${N3_DIR}/code/application/networkfeature)
#include_directories(${N3_DIR}/code/application/stateobjectfeature)

set(N3_APPLICATION_SRC_DIR ${N3_DIR}/code/application)

set(N3_APPLICATION_SRC_MAIN 
    ${N3_APPLICATION_SRC_DIR}/application.h
    ${N3_APPLICATION_SRC_DIR}/stdneb.h
    ${N3_APPLICATION_SRC_DIR}/stdneb.cc
)
source_group("" FILES ${N3_APPLICATION_SRC_MAIN})

set(N3_APPLICATION_APPGAME_SRCS
    ${N3_APPLICATION_SRC_DIR}/appgame/appconfig.h
    ${N3_APPLICATION_SRC_DIR}/appgame/gameapplication.h
    ${N3_APPLICATION_SRC_DIR}/appgame/gameapplication.cc
    ${N3_APPLICATION_SRC_DIR}/appgame/statehandler.h
    ${N3_APPLICATION_SRC_DIR}/appgame/statehandler.cc
)
source_group(appgame FILES ${N3_APPLICATION_APPGAME_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegamefeatureunit.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegamefeatureunit.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegameprotocol.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegameprotocol.h
) 
source_group(basegamefeature FILES ${N3_APPLICATION_BASEGAMEFEATURE_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_BASEGAMEATTR_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegameattr/basegameattributes.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegameattr/basegameattributes.cc
) 
source_group(basegamefeature\\basegameattr FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_BASEGAMEATTR_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_BASEGAMETIMING_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/gametimesource.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/gametimesource.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/inputtimesource.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/inputtimesource.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/systemtimesource.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/systemtimesource.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/timemanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/timemanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/timesource.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/basegametiming/timesource.cc
) 
source_group(basegamefeature\\basegametiming FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_BASEGAMETIMING_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_DEBUG_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/debug/objectinspectorhandler.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/debug/objectinspectorhandler.cc
) 
source_group(basegamefeature\\debug FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_DEBUG_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_LOADER_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/entityloader.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/entityloader.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/entityloaderbase.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/entityloaderbase.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/environmentloader.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/environmentloader.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/levelloader.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/levelloader.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/loaderserver.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/loaderserver.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/userprofile.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/loader/userprofile.cc
) 
source_group(basegamefeature\\loader FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_LOADER_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_MANAGERS_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/animeventmanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/animeventmanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/categorymanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/categorymanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/entitymanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/entitymanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/enventitymanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/enventitymanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/envquerymanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/envquerymanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/factorymanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/factorymanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/focusmanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/focusmanager.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/globalattrsmanager.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/managers/globalattrsmanager.cc
) 
source_group(basegamefeature\\managers FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_MANAGERS_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_PROPERTIES_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/properties/timeproperty.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/properties/timeproperty.cc
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/properties/transformableproperty.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/properties/transformableproperty.cc
) 
source_group(basegamefeature\\propertyies FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_PROPERTIES_SRCS})

set(N3_APPLICATION_BASEGAMEFEATURE_STATEHANDLERS_SRCS
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/statehandlers/gamestatehandler.h
    ${N3_APPLICATION_SRC_DIR}/basegamefeature/statehandlers/gamestatehandler.cc
) 
source_group(basegamefeature\\statehandlers FILES 
    ${N3_APPLICATION_BASEGAMEFEATURE_STATEHANDLERS_SRCS})

set(N3_APPLICATION_COMMANDHANDLERS_SRCS
    ${N3_APPLICATION_SRC_DIR}/commandhandlers/createentitycommand.h
    ${N3_APPLICATION_SRC_DIR}/commandhandlers/createentitycommand.cc
) 
source_group(commandhandlers FILES ${N3_APPLICATION_COMMANDHANDLERS_SRCS})

set(N3_APPLICATION_GAME_SRCS
    ${N3_APPLICATION_SRC_DIR}/game/entity.h
    ${N3_APPLICATION_SRC_DIR}/game/entity.cc
    ${N3_APPLICATION_SRC_DIR}/game/featureunit.h
    ${N3_APPLICATION_SRC_DIR}/game/featureunit.cc
    ${N3_APPLICATION_SRC_DIR}/game/gameserver.h
    ${N3_APPLICATION_SRC_DIR}/game/gameserver.cc
    ${N3_APPLICATION_SRC_DIR}/game/manager.h
    ${N3_APPLICATION_SRC_DIR}/game/manager.cc
    ${N3_APPLICATION_SRC_DIR}/game/property.h
    ${N3_APPLICATION_SRC_DIR}/game/property.cc
) 
source_group(game FILES ${N3_APPLICATION_GAME_SRCS})

#set(N3_APPLICATION_GRAPHICSFEATURE_SRCS
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsfeatureunit.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsfeatureunit.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsfeatureprotocol.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsfeatureprotocol.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsfeatureproperties.h
#) 
#source_group(graphicsfeature FILES ${N3_APPLICATION_GRAPHICSFEATURE_SRCS})

#set(N3_APPLICATION_GRAPHICSFEATURE_GRAPHICSATTR_SRCS
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsattr/graphicsattributes.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsattr/graphicsattributes.cc
#) 
#source_group(graphicsfeature\\graphicsattr FILES 
#    ${N3_APPLICATION_GRAPHICSFEATURE_GRAPHICSATTR_SRCS})
#
#set(N3_APPLICATION_GRAPHICSFEATURE_GRAPHICSUTIL_SRCS
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsutil/lightflickerutil.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsutil/lightflickerutil.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsutil/segmentedgfxutil.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/graphicsutil/segmentedgfxutil.cc
#) 
#source_group(graphicsfeature\\graphicsutil FILES 
#    ${N3_APPLICATION_GRAPHICSFEATURE_GRAPHICSUTIL_SRCS})
#
#set(N3_APPLICATION_GRAPHICSFEATURE_MANAGERS_SRCS
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/managers/attachmentmanager.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/managers/attachmentmanager.cc
#) 
#source_group(graphicsfeature\\managers FILES 
#    ${N3_APPLICATION_GRAPHICSFEATURE_MANAGERS_SRCS})
#
#set(N3_APPLICATION_GRAPHICSFEATURE_PROPERTIES_SRCS
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/actorgraphicsproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/actorgraphicsproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/ambiencebubbleproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/ambiencebubbleproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/animationcontrolproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/animationcontrolproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/cameraproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/cameraproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/chasecameraproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/chasecameraproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/cutscenecameraproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/cutscenecameraproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/environmentgraphicsproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/environmentgraphicsproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/graphicsproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/graphicsproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/inputproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/inputproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/lightproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/lightproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/mayacameraproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/mayacameraproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/pathanimproperty.h
#    ${N3_APPLICATION_SRC_DIR}/graphicsfeature/properties/pathanimproperty.cc
#) 
#source_group(graphicsfeature\\properties FILES 
#    ${N3_APPLICATION_GRAPHICSFEATURE_PROPERTIES_SRCS})
#
#set(N3_APPLICATION_PHYSICSFEATURE_SRCS
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsprotocol.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsprotocol.cc
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsfeatureunit.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsfeatureunit.cc
#) 
#source_group(physicsfeature FILES ${N3_APPLICATION_PHYSICSFEATURE_SRCS})
#
#set(N3_APPLICATION_PHYSICSFEATURE_SRCS
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsprotocol.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsprotocol.cc
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsfeatureunit.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsfeatureunit.cc
#) 
#source_group(physicsfeature FILES ${N3_APPLICATION_PHYSICSFEATURE_SRCS})
#
#set(N3_APPLICATION_PHYSICSFEATURE_PHYSICSATTR_SRCS
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsattr/physicsattributes.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/physicsattr/physicsattributes.cc
#) 
#source_group(physicsfeature\\physicsattr FILES 
#    ${N3_APPLICATION_PHYSICSFEATURE_PHYSICSATTR_SRCS})
#
#set(N3_APPLICATION_PHYSICSFEATURE_PROPERTIES_SRCS
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/actorphysicsproperty.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/actorphysicsproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/environmentcollideproperty.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/environmentcollideproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/mousegripperproperty.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/mousegripperproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/physicsproperty.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/physicsproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/triggerproperty.h
#    ${N3_APPLICATION_SRC_DIR}/physicsfeature/properties/triggerproperty.cc
#) 
#source_group(physicsfeature\\properties FILES 
#    ${N3_APPLICATION_PHYSICSFEATURE_PROPERTIES_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actionreader.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actionreader.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scriptfeatureunit.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scriptfeatureunit.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scriptprotocol.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scriptprotocol.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scripttable.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scripttable.cc
#) 
#source_group(scriptfeature FILES ${N3_APPLICATION_SCRIPTFEATURE_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_ACTIONS_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/action.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/action.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/actionlist.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/actionlist.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/ifthenelseaction.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/ifthenelseaction.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/sequenceaction.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/sequenceaction.cc
#) 
#source_group(scriptfeature\\actions FILES ${N3_APPLICATION_SCRIPTFEATURE_ACTIONS_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_ACTIONS_BEHAVIOUR_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/behaviour/fsmaction.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/actions/behaviour/fsmaction.cc
#) 
#source_group(scriptfeature\\actions\\behaviour FILES 
#    ${N3_APPLICATION_SCRIPTFEATURE_ACTIONS_BEHAVIOUR_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_CONDITIONS_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/and.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/and.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/condition.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/condition.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/not.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/not.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/operator.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/or.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/or.cc
#) 
#source_group(scriptfeature\\conditions FILES 
#    ${N3_APPLICATION_SCRIPTFEATURE_CONDITIONS_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_CONDITIONS_BEHAVIOUR_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/behaviour/fsmcondition.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/conditions/behaviour/fsmcondition.cc
#) 
#source_group(scriptfeature\\conditions\\behaviour FILES 
#    ${N3_APPLICATION_SCRIPTFEATURE_CONDITIONS_BEHAVIOUR_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_DIALOG_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/dialog/dialog.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/dialog/dialog.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/dialog/dialogdesc.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/dialog/dialogdesc.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/dialog/dialogtake.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/dialog/dialogtake.cc
#) 
#source_group(scriptfeature\\dialog FILES 
#    ${N3_APPLICATION_SCRIPTFEATURE_DIALOG_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_FSM_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/behaviourproperty.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/behaviourproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/state.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/state.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/statemachine.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/statemachine.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/transition.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/fsm/transition.cc
#) 
#source_group(scriptfeature\\fsm FILES ${N3_APPLICATION_SCRIPTFEATURE_FSM_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_LOG_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/log/infolog.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/log/infolog.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/log/infologfilter.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/log/infologfilter.cc
#) 
#source_group(scriptfeature\\log FILES ${N3_APPLICATION_SCRIPTFEATURE_LOG_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_MANAGERS_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/dialogmanager.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/dialogmanager.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/logmanager.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/logmanager.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/questmanager.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/questmanager.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/scriptmanager.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/scriptmanager.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/scripttemplatemanager.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/scripttemplatemanager.cc
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/substitutionmanager.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/managers/substitutionmanager.cc
#) 
#source_group(scriptfeature\\managers FILES ${N3_APPLICATION_SCRIPTFEATURE_MANAGERS_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_QUEST_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/quest/task.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/quest/task.cc
#) 
#source_group(scriptfeature\\quest FILES ${N3_APPLICATION_SCRIPTFEATURE_QUEST_SRCS})
#
#set(N3_APPLICATION_SCRIPTFEATURE_SCRIPTATTR_SRCS
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scriptattr/scriptattributes.h
#    ${N3_APPLICATION_SRC_DIR}/scriptfeature/scriptattr/scriptattributes.cc
#) 
#source_group(scriptfeature\\scriptattr FILES ${N3_APPLICATION_SCRIPTFEATURE_SCRIPTATTR_SRCS})
#
#set(N3_APPLICATION_STATEOBJECTFEATURE_SRCS
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/stateobjectfeatureunit.h
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/stateobjectprotocol.h
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/stateobjectprotocol.cc
#) 
#source_group(stateobjectfeature FILES ${N3_APPLICATION_STATEOBJECTFEATURE_SRCS})
#
#set(N3_APPLICATION_STATEOBJECTFEATURE_PROPERTIES_SRCS
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/properties/stategraphicsproperty.h
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/properties/stategraphicsproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/properties/stateproperty.h
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/properties/stateproperty.cc
#    ${N3_APPLICATION_SRC_DIR}/stateobjectfeature/properties/stateinfo.h
#) 
#source_group(stateobjectfeature\\properties FILES 
#    ${N3_APPLICATION_STATEOBJECTFEATURE_PROPERTIES_SRCS})

add_library(application STATIC
    ${N3_APPLICATION_SRCS_MAIN}

    ${N3_APPLICATION_APPGAME_SRCS}

    ${N3_APPLICATION_BASEGAMEFEATURE_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_BASEGAMEATTR_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_BASEGAMETIMING_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_DEBUG_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_LOADER_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_MANAGERS_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_PROPERTIES_SRCS}
    ${N3_APPLICATION_BASEGAMEFEATURE_STATEHANDLERS_SRCS}

    ${N3_APPLICATION_COMMANDHANDLERS_SRCS}

    ${N3_APPLICATION_GAME_SRCS}

#    ${N3_APPLICATION_GRAPHICSFEATURE_SRCS}
#    ${N3_APPLICATION_GRAPHICSFEATURE_GRAPHICSATTR_SRCS}
#    ${N3_APPLICATION_GRAPHICSFEATURE_GRAPHICSUTIL_SRCS}
#    ${N3_APPLICATION_GRAPHICSFEATURE_MANAGERS_SRCS}
#    ${N3_APPLICATION_GRAPHICSFEATURE_PROPERTIES_SRCS}
#
#    ${N3_APPLICATION_PHYSICSFEATURE_SRCS}
#    ${N3_APPLICATION_PHYSICSFEATURE_PHYSICSATTR_SRCS}
#    ${N3_APPLICATION_PHYSICSFEATURE_PROPERTIES_SRCS}
#
#    ${N3_APPLICATION_SCRIPTFEATURE_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_ACTIONS_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_ACTIONS_BEHAVIOUR_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_CONDITIONS_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_CONDITIONS_BEHAVIOUR_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_DIALOG_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_FSM_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_LOG_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_MANAGERS_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_QUEST_SRCS}
#    ${N3_APPLICATION_SCRIPTFEATURE_SCRIPTATTR_SRCS}
#
#    ${N3_APPLICATION_STATEOBJECTFEATURE_SRCS}
#    ${N3_APPLICATION_STATEOBJECTFEATURE_PROPERTIES_SRCS}
)

target_link_libraries(application foundation render)
