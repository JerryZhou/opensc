cmake_minimum_required (VERSION 2.8)

set(N3_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)

include_directories(${N3_DIR}/code/extlibs)

set(N3_FOUNDATION_SRC_DIR ${N3_DIR}/code/foundation)
include_directories(${N3_FOUNDATION_SRC_DIR})

set(N3_FOUNDATION_APP_SRCS
  ${N3_FOUNDATION_SRC_DIR}/app/application.h
  ${N3_FOUNDATION_SRC_DIR}/app/application.cc
  ${N3_FOUNDATION_SRC_DIR}/app/consoleapplication.h
  ${N3_FOUNDATION_SRC_DIR}/app/consoleapplication.cc
)
source_group(app FILES ${N3_FOUNDATION_APP_SRCS})

set(N3_FOUNDATION_CORE_SRCS
  ${N3_FOUNDATION_SRC_DIR}/core/coreserver.cc
  ${N3_FOUNDATION_SRC_DIR}/core/debug.cc
  ${N3_FOUNDATION_SRC_DIR}/core/exithandler.cc
  ${N3_FOUNDATION_SRC_DIR}/core/factory.cc
  ${N3_FOUNDATION_SRC_DIR}/core/refcounted.cc
  ${N3_FOUNDATION_SRC_DIR}/core/refcountedlist.cc
  ${N3_FOUNDATION_SRC_DIR}/core/rtti.cc
)
source_group(core FILES ${N3_FOUNDATION_CORE_SRCS})

set(N3_FOUNDATION_CORE_DEBUG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/core/debug/corepagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/core/debug/corepagehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/core/debug/stringatompagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/core/debug/stringatompagehandler.cc
)
source_group(core\\debug FILES ${N3_FOUNDATION_CORE_DEBUG_SRCS})

if(APPLE)
  set(N3_FOUNDATION_CORE_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/core/osx/osxsingleton.h
    ${N3_FOUNDATION_SRC_DIR}/core/osx/osxsysfunc.h
    ${N3_FOUNDATION_SRC_DIR}/core/osx/osxsysfunc.cc
    ${N3_FOUNDATION_SRC_DIR}/core/osx/precompiled.h
  )
  source_group(core\\osx FILES ${N3_FOUNDATION_CORE_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_CORE_SRCS
  ${N3_FOUNDATION_CORE_SRCS}
  ${N3_FOUNDATION_CORE_DEBUG_SRCS}
  ${N3_FOUNDATION_CORE_PLATFORM_SRCS}
)

set(N3_FOUNDATION_DEBUG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/debug/debugcounter.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debugcounter.cc
  ${N3_FOUNDATION_SRC_DIR}/debug/debugfloat.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debughandler.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debughandler.cc
  ${N3_FOUNDATION_SRC_DIR}/debug/debuginterface.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debuginterface.cc
  ${N3_FOUNDATION_SRC_DIR}/debug/debugpagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debugpagehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/debug/debugserver.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debugserver.cc
  ${N3_FOUNDATION_SRC_DIR}/debug/debugtimer.h
  ${N3_FOUNDATION_SRC_DIR}/debug/debugtimer.cc
  ${N3_FOUNDATION_SRC_DIR}/debug/minidump.h
)
source_group(debug FILES ${N3_FOUNDATION_DEBUG_SRCS})

if(APPLE)
  set(N3_FOUNDATION_DEBUG_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/debug/osx/osxminidump.h
    ${N3_FOUNDATION_SRC_DIR}/debug/osx/osxminidump.cc
  )
  source_group(debug\\osx FILES ${N3_FOUNDATION_DEBUG_PLATFORM_SRCS})
elseif(WIN32)
  set(N3_FOUNDATION_DEBUG_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/debug/win32/win32minidump.h
    ${N3_FOUNDATION_SRC_DIR}/debug/win32/win32minidump.cc
  )
  source_group(debug\\win32 FILES ${N3_FOUNDATION_DEBUG_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_DEBUG_SRCS
  ${N3_FOUNDATION_DEBUG_SRCS}
  ${N3_FOUNDATION_DEBUG_PLATFORM_SRCS}
)

set(N3_FOUNDATION_FRAMESYNC_SRCS
  ${N3_FOUNDATION_SRC_DIR}/framesync/framesynchandlerthread.h
  ${N3_FOUNDATION_SRC_DIR}/framesync/framesynchandlerthread.cc
  ${N3_FOUNDATION_SRC_DIR}/framesync/framesyncshareddata.h
  ${N3_FOUNDATION_SRC_DIR}/framesync/framesyncshareddata.cc
  ${N3_FOUNDATION_SRC_DIR}/framesync/framesynctimer.h
  ${N3_FOUNDATION_SRC_DIR}/framesync/framesynctimer.cc
)
source_group(framesync FILES ${N3_FOUNDATION_FRAMESYNC_SRCS})

set(N3_FOUNDATION_HTTP_SRCS
  ${N3_FOUNDATION_SRC_DIR}/http/defaulthttprequesthandler.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpclient.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpclientregistry.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpinterface.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpmessagehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpnzstream.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpprotocol.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httprequest.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httprequesthandler.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httprequestreader.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httprequestwriter.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpresponsereader.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpresponsewriter.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpserver.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpserverproxy.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpstatus.cc
  ${N3_FOUNDATION_SRC_DIR}/http/httpstream.cc
)
source_group(http FILES ${N3_FOUNDATION_HTTP_SRCS})

set(N3_FOUNDATION_HTTP_DEBUG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/http/debug/helloworldrequesthandler.h
  ${N3_FOUNDATION_SRC_DIR}/http/debug/helloworldrequesthandler.cc
  ${N3_FOUNDATION_SRC_DIR}/http/debug/svgtestpagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/http/debug/svgtestpagehandler.cc
)
source_group(http\\debug FILES ${N3_FOUNDATION_HTTP_DEBUG_SRCS})

set(N3_FOUNDATION_HTTP_HTML_SRCS
  ${N3_FOUNDATION_SRC_DIR}/http/html/htmlelement.h
  ${N3_FOUNDATION_SRC_DIR}/http/html/htmlelement.cc
  ${N3_FOUNDATION_SRC_DIR}/http/html/htmlpagewriter.h
  ${N3_FOUNDATION_SRC_DIR}/http/html/htmlpagewriter.cc
)
source_group(http\\html FILES ${N3_FOUNDATION_HTTP_HTML_SRCS})

set(N3_FOUNDATION_HTTP_SVG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/http/svg/svglinechartwriter.h
  ${N3_FOUNDATION_SRC_DIR}/http/svg/svglinechartwriter.cc
  ${N3_FOUNDATION_SRC_DIR}/http/svg/svgpagewriter.h
  ${N3_FOUNDATION_SRC_DIR}/http/svg/svgpagewriter.cc
)
source_group(http\\svg FILES ${N3_FOUNDATION_HTTP_SVG_SRCS})

set(N3_FOUNDATION_HTTP_SRCS
  ${N3_FOUNDATION_HTTP_SRCS}
  ${N3_FOUNDATION_HTTP_DEBUG_SRCS}
  ${N3_FOUNDATION_HTTP_HTML_SRCS}
  ${N3_FOUNDATION_HTTP_SVG_SRCS}
)

set(N3_FOUNDATION_INTERFACE_SRCS
  ${N3_FOUNDATION_SRC_DIR}/interface/interfacebase.h
  ${N3_FOUNDATION_SRC_DIR}/interface/interfacebase.cc
  ${N3_FOUNDATION_SRC_DIR}/interface/interfacehandlerbase.h
  ${N3_FOUNDATION_SRC_DIR}/interface/interfacehandlerbase.cc
)
source_group(interface FILES ${N3_FOUNDATION_INTERFACE_SRCS})

set(N3_FOUNDATION_IO_SRCS
  ${N3_FOUNDATION_SRC_DIR}/io/assign.h
  ${N3_FOUNDATION_SRC_DIR}/io/assignregistry.h
  ${N3_FOUNDATION_SRC_DIR}/io/assignregistry.cc
  ${N3_FOUNDATION_SRC_DIR}/io/binaryreader.h
  ${N3_FOUNDATION_SRC_DIR}/io/binaryreader.cc
  ${N3_FOUNDATION_SRC_DIR}/io/binarywriter.h
  ${N3_FOUNDATION_SRC_DIR}/io/binarywriter.cc
  ${N3_FOUNDATION_SRC_DIR}/io/bxmlreader.h
  ${N3_FOUNDATION_SRC_DIR}/io/bxmlreader.cc
  ${N3_FOUNDATION_SRC_DIR}/io/console.h
  ${N3_FOUNDATION_SRC_DIR}/io/console.cc
  ${N3_FOUNDATION_SRC_DIR}/io/consolehandler.h
  ${N3_FOUNDATION_SRC_DIR}/io/consolehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/io/excelxmlreader.h
  ${N3_FOUNDATION_SRC_DIR}/io/excelxmlreader.cc
  ${N3_FOUNDATION_SRC_DIR}/io/filestream.h
  ${N3_FOUNDATION_SRC_DIR}/io/filestream.cc
  ${N3_FOUNDATION_SRC_DIR}/io/filetime.h
  ${N3_FOUNDATION_SRC_DIR}/io/fswrapper.h
  ${N3_FOUNDATION_SRC_DIR}/io/gamecontentserver.h
  ${N3_FOUNDATION_SRC_DIR}/io/gamecontentserver.cc
  ${N3_FOUNDATION_SRC_DIR}/io/historyconsolehandler.h
  ${N3_FOUNDATION_SRC_DIR}/io/historyconsolehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/io/iointerface.h
  ${N3_FOUNDATION_SRC_DIR}/io/iointerface.cc
  ${N3_FOUNDATION_SRC_DIR}/io/iointerfacehandler.h
  ${N3_FOUNDATION_SRC_DIR}/io/iointerfacehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/io/iointerfaceprotocol.h
  ${N3_FOUNDATION_SRC_DIR}/io/iointerfaceprotocol.cc
  ${N3_FOUNDATION_SRC_DIR}/io/ioserver.h
  ${N3_FOUNDATION_SRC_DIR}/io/ioserver.cc
  ${N3_FOUNDATION_SRC_DIR}/io/logfileconsolehandler.h
  ${N3_FOUNDATION_SRC_DIR}/io/logfileconsolehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/io/mediatype.h
  ${N3_FOUNDATION_SRC_DIR}/io/memorystream.h
  ${N3_FOUNDATION_SRC_DIR}/io/memorystream.cc
  ${N3_FOUNDATION_SRC_DIR}/io/schemeregistry.h
  ${N3_FOUNDATION_SRC_DIR}/io/schemeregistry.cc
  ${N3_FOUNDATION_SRC_DIR}/io/stream.h
  ${N3_FOUNDATION_SRC_DIR}/io/stream.cc
  ${N3_FOUNDATION_SRC_DIR}/io/streamreader.h
  ${N3_FOUNDATION_SRC_DIR}/io/streamreader.cc
  ${N3_FOUNDATION_SRC_DIR}/io/streamwriter.h
  ${N3_FOUNDATION_SRC_DIR}/io/streamwriter.cc
  ${N3_FOUNDATION_SRC_DIR}/io/textreader.h
  ${N3_FOUNDATION_SRC_DIR}/io/textreader.cc
  ${N3_FOUNDATION_SRC_DIR}/io/textwriter.h
  ${N3_FOUNDATION_SRC_DIR}/io/textwriter.cc
  ${N3_FOUNDATION_SRC_DIR}/io/uri.h
  ${N3_FOUNDATION_SRC_DIR}/io/uri.cc
  ${N3_FOUNDATION_SRC_DIR}/io/xmlreader.h
  ${N3_FOUNDATION_SRC_DIR}/io/xmlreader.cc
  ${N3_FOUNDATION_SRC_DIR}/io/xmlwriter.h
  ${N3_FOUNDATION_SRC_DIR}/io/xmlwriter.cc
)
source_group(io FILES ${N3_FOUNDATION_IO_SRCS})

set(N3_FOUNDATION_IO_ARCHFS_SRCS
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archive.h
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archive.cc
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archivebase.h
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archivebase.cc
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archivefilesystem.h
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archivefilesystem.cc
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archivefilesystembase.h
  ${N3_FOUNDATION_SRC_DIR}/io/archfs/archivefilesystembase.cc
)
source_group(io\\archfs FILES ${N3_FOUNDATION_IO_ARCHFS_SRCS})

set(N3_FOUNDATION_IO_BASE_SRCS
  ${N3_FOUNDATION_SRC_DIR}/io/base/gamecontentserverbase.h
  ${N3_FOUNDATION_SRC_DIR}/io/base/gamecontentserverbase.cc
)
source_group(io\\base FILES ${N3_FOUNDATION_IO_BASE_SRCS})

set(N3_FOUNDATION_IO_DEBUG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/io/debug/consolepagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/io/debug/consolepagehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/io/debug/iopagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/io/debug/iopagehandler.cc
)
source_group(io\\debug FILES ${N3_FOUNDATION_IO_DEBUG_SRCS})

if(APPLE)
  set(N3_FOUNDATION_IO_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/io/osx/osxconsolehandler.h
    ${N3_FOUNDATION_SRC_DIR}/io/osx/osxconsolehandler.cc
    ${N3_FOUNDATION_SRC_DIR}/io/osx/osxfiletime.h
    ${N3_FOUNDATION_SRC_DIR}/io/osx/osxfswrapper.h
    ${N3_FOUNDATION_SRC_DIR}/io/osx/osxfswrapper.cc
  )
  source_group(io\\osx FILES ${N3_FOUNDATION_IO_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_IO_UTIL_SRCS
  ${N3_FOUNDATION_SRC_DIR}/io/util/bxmlfilestructs.h
  ${N3_FOUNDATION_SRC_DIR}/io/util/bxmlloaderutil.h
  ${N3_FOUNDATION_SRC_DIR}/io/util/bxmlloaderutil.cc
)
source_group(io\\util FILES ${N3_FOUNDATION_IO_UTIL_SRCS})

set(N3_FOUNDATION_IO_ZIPFS_SRCS
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/ziparchive.h
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/ziparchive.cc
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipdirentry.h
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipdirentry.cc
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipfileentry.h
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipfileentry.cc
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipfilestream.h
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipfilestream.cc
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipfilesystem.h
  ${N3_FOUNDATION_SRC_DIR}/io/zipfs/zipfilesystem.cc
)
source_group(io\\zipfs FILES ${N3_FOUNDATION_IO_ZIPFS_SRCS})

set(N3_FOUNDATION_IO_SRCS
  ${N3_FOUNDATION_IO_SRCS}
  ${N3_FOUNDATION_IO_ARCHFS_SRCS}
  ${N3_FOUNDATION_IO_BASE_SRCS}
  ${N3_FOUNDATION_IO_DEBUG_SRCS}
  ${N3_FOUNDATION_IO_PLATFORM_SRCS}
  ${N3_FOUNDATION_IO_UTIL_SRCS}
  ${N3_FOUNDATION_IO_ZIPFS_SRCS}
)

set(N3_FOUNDATION_JOBS_SRCS
  ${N3_FOUNDATION_SRC_DIR}/jobs/job.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/job.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobdatadesc.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobfunccontext.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobfuncdesc.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobport.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobport.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobsystem.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobsystem.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/jobuniformdesc.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/stdjob.h
)
source_group(jobs FILES ${N3_FOUNDATION_JOBS_SRCS})

set(N3_FOUNDATION_JOBS_BASE_SRCS
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobbase.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobbase.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobfuncdescbase.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobportbase.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobportbase.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobsystembase.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/base/jobsystembase.cc
)
source_group(jobs\\base FILES ${N3_FOUNDATION_JOBS_BASE_SRCS})

set(N3_FOUNDATION_JOBS_SERIAL_SRCS
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjob.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjob.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjobfuncdesc.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjobport.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjobport.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjobsystem.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/serial/serialjobsystem.cc
)
source_group(jobs\\base FILES ${N3_FOUNDATION_JOBS_SERIAL_SRCS})

set(N3_FOUNDATION_JOBS_TP_SRCS
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjob.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjob.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobcommand.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobfuncdesc.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobport.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobport.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobslice.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobslice.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobsystem.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobsystem.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobthreadpool.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpjobthreadpool.cc
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpworkerthread.h
  ${N3_FOUNDATION_SRC_DIR}/jobs/tp/tpworkerthread.cc
)
source_group(jobs\\base FILES ${N3_FOUNDATION_JOBS_SERIAL_SRCS})

set(N3_FOUNDATION_JOBS_SRCS
  ${N3_FOUNDATION_JOBS_SRCS}
  ${N3_FOUNDATION_JOBS_BASE_SRCS}
  ${N3_FOUNDATION_JOBS_SERIAL_SRCS}
#  ${N3_FOUNDATION_JOBS_TP_SRCS}
)

set(N3_FOUNDATION_MATH_SRCS
  ${N3_FOUNDATION_SRC_DIR}/math/angularpfeedbackloop.h
  ${N3_FOUNDATION_SRC_DIR}/math/bbox.h
  ${N3_FOUNDATION_SRC_DIR}/math/bbox.cc
  ${N3_FOUNDATION_SRC_DIR}/math/clipstatus.h
  ${N3_FOUNDATION_SRC_DIR}/math/extrapolator.h
  ${N3_FOUNDATION_SRC_DIR}/math/float2.h
  ${N3_FOUNDATION_SRC_DIR}/math/float4.h
  ${N3_FOUNDATION_SRC_DIR}/math/frustum.h
  ${N3_FOUNDATION_SRC_DIR}/math/line.h
  ${N3_FOUNDATION_SRC_DIR}/math/line.cc
  ${N3_FOUNDATION_SRC_DIR}/math/matrix44.h
  ${N3_FOUNDATION_SRC_DIR}/math/noise.h
  ${N3_FOUNDATION_SRC_DIR}/math/pfeedbackloop.h
  ${N3_FOUNDATION_SRC_DIR}/math/pidfeedbackloop.h
  ${N3_FOUNDATION_SRC_DIR}/math/plane.h
  ${N3_FOUNDATION_SRC_DIR}/math/point.h
  ${N3_FOUNDATION_SRC_DIR}/math/polar.h
  ${N3_FOUNDATION_SRC_DIR}/math/quaternion.h
  ${N3_FOUNDATION_SRC_DIR}/math/rectangle.h
  ${N3_FOUNDATION_SRC_DIR}/math/scalar.h
  ${N3_FOUNDATION_SRC_DIR}/math/sphere_.h
  ${N3_FOUNDATION_SRC_DIR}/math/sphere_.cc
  ${N3_FOUNDATION_SRC_DIR}/math/transform44.h
  ${N3_FOUNDATION_SRC_DIR}/math/vector.h
)
source_group(math FILES ${N3_FOUNDATION_MATH_SRCS})

set(N3_FOUNDATION_MATH_GLMATH_SRCS
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_float4.h
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_float4.cc
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_matrix44.h
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_matrix44.cc
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_plane.h
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_plane.cc
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_point.h
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_quaternion.h
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_quaternion.cc
  ${N3_FOUNDATION_SRC_DIR}/math/glmath/glm_vector.h
)
source_group(math\\glmath FILES ${N3_FOUNDATION_MATH_GLMATH_SRCS})

if(APPLE)
  set(N3_FOUNDATION_MATH_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/math/osx/osxscalar.h
  )
  source_group(math\\osx FILES ${N3_FOUNDATION_MATH_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_MATH_SRCS
  ${N3_FOUNDATION_MATH_SRCS}
  ${N3_FOUNDATION_MATH_GLMATH_SRCS}
  ${N3_FOUNDATION_MATH_PLATFORM_SRCS}
)

set(N3_FOUNDATION_MEMORY_SRCS
  ${N3_FOUNDATION_SRC_DIR}/memory/heap.h
  ${N3_FOUNDATION_SRC_DIR}/memory/memory.h
  ${N3_FOUNDATION_SRC_DIR}/memory/memorypool.h
  ${N3_FOUNDATION_SRC_DIR}/memory/debug/memorypagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/memory/debug/memorypagehandler.cc
  ${N3_FOUNDATION_SRC_DIR}/memory/poolarrayallocator.h
  ${N3_FOUNDATION_SRC_DIR}/memory/poolarrayallocator.cc
)
source_group(memory FILES ${N3_FOUNDATION_MEMORY_SRCS})

set(N3_FOUNDATION_MEMORY_DEBUG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/memory/debug/memorypagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/memory/debug/memorypagehandler.cc
)
source_group(memory\\debug FILES ${N3_FOUNDATION_MEMORY_DEBUG_SRCS})

if(APPLE)
  set(N3_FOUNDATION_MEMORY_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxheap.h
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxheap.cc
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxmemory.h
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxmemory.cc
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxmemoryconfig.h
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxmemoryconfig.cc
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxmemorypool.h
    ${N3_FOUNDATION_SRC_DIR}/memory/osx/osxmemorypool.cc
  )
  source_group(memory\\osx FILES ${N3_FOUNDATION_MEMORY_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_MEMORY_SRCS
  ${N3_FOUNDATION_MEMORY_SRCS}
  ${N3_FOUNDATION_MEMORY_DEBUG_SRCS}
  ${N3_FOUNDATION_MEMORY_PLATFORM_SRCS}
)

set(N3_FOUNDATION_MESSAGING_SRCS
  ${N3_FOUNDATION_SRC_DIR}/messaging/asyncport.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/asyncport.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/batchmessage.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/batchmessage.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/blockinghandlerthread.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/blockinghandlerthread.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/delegatetable.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/delegatetable.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/dispatcher.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/dispatcher.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/handler.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/handler.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/handlerthreadbase.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/handlerthreadbase.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/id.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/message.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/message.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/messagereader.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/messagereader.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/messagewriter.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/messagewriter.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/port.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/port.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/runthroughhandlerthread.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/runthroughhandlerthread.cc
  ${N3_FOUNDATION_SRC_DIR}/messaging/staticmessagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/messaging/staticmessagehandler.cc
)
source_group(messaging FILES ${N3_FOUNDATION_MESSAGING_SRCS})

set(N3_FOUNDATION_NET_SRCS
  ${N3_FOUNDATION_SRC_DIR}/net/debugmessage.h
  ${N3_FOUNDATION_SRC_DIR}/net/debugpacket.h
  ${N3_FOUNDATION_SRC_DIR}/net/debugpacket.cc
  ${N3_FOUNDATION_SRC_DIR}/net/messageclient.h
  ${N3_FOUNDATION_SRC_DIR}/net/messageclient.cc
  ${N3_FOUNDATION_SRC_DIR}/net/messageclientconnection.h
  ${N3_FOUNDATION_SRC_DIR}/net/messageclientconnection.cc
  ${N3_FOUNDATION_SRC_DIR}/net/tcpclient.h
  ${N3_FOUNDATION_SRC_DIR}/net/tcpclient.cc
  ${N3_FOUNDATION_SRC_DIR}/net/tcpclientconnection.h
  ${N3_FOUNDATION_SRC_DIR}/net/tcpclientconnection.cc
  ${N3_FOUNDATION_SRC_DIR}/net/tcpmessagecodec.h
  ${N3_FOUNDATION_SRC_DIR}/net/tcpmessagecodec.cc
  ${N3_FOUNDATION_SRC_DIR}/net/tcpserver.h
  ${N3_FOUNDATION_SRC_DIR}/net/tcpserver.cc
)
source_group(net FILES ${N3_FOUNDATION_NET_SRCS})

if(UNIX)
  set(N3_FOUNDATION_NET_POSIX_SRCS
    ${N3_FOUNDATION_SRC_DIR}/net/posix/posixipaddress.cc
    ${N3_FOUNDATION_SRC_DIR}/net/posix/posixsocket.cc
  )
  source_group(net\\posix FILES ${N3_FOUNDATION_NET_POSIX_SRCS})
endif()

set(N3_FOUNDATION_NET_SOCKET_SRCS
  ${N3_FOUNDATION_SRC_DIR}/net/socket/ipaddress.h
  ${N3_FOUNDATION_SRC_DIR}/net/socket/socket.h
  ${N3_FOUNDATION_SRC_DIR}/net/socket/socket.cc
)
source_group(net\\socket FILES ${N3_FOUNDATION_NET_SOCKET_SRCS})

if(APPLE)
  set(N3_FOUNDATION_NET_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/net/tcp/stdtcpclient.h
    ${N3_FOUNDATION_SRC_DIR}/net/tcp/stdtcpclient.cc
    ${N3_FOUNDATION_SRC_DIR}/net/tcp/stdtcpclientconnection.h
    ${N3_FOUNDATION_SRC_DIR}/net/tcp/stdtcpclientconnection.cc
    ${N3_FOUNDATION_SRC_DIR}/net/tcp/stdtcpserver.h
    ${N3_FOUNDATION_SRC_DIR}/net/tcp/stdtcpserver.cc
  )
  source_group(net\\tcp FILES ${N3_FOUNDATION_NET_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_NET_SRCS
  ${N3_FOUNDATION_NET_SRCS}
  ${N3_FOUNDATION_NET_POSIX_SRCS}
  ${N3_FOUNDATION_NET_SOCKET_SRCS}
  ${N3_FOUNDATION_NET_PLATFORM_SRCS}
)

set(N3_FOUNDATION_SYSTEM_SRCS
  ${N3_FOUNDATION_SRC_DIR}/system/appentry.h
  ${N3_FOUNDATION_SRC_DIR}/system/byteorder.h
  ${N3_FOUNDATION_SRC_DIR}/system/cpu.h
  ${N3_FOUNDATION_SRC_DIR}/system/systeminfo.h
)
source_group(system FILES ${N3_FOUNDATION_SYSTEM_SRCS})

set(N3_FOUNDATION_SYSTEM_BASE_SRCS
  ${N3_FOUNDATION_SRC_DIR}/system/base/systeminfobase.h
  ${N3_FOUNDATION_SRC_DIR}/system/base/systeminfobase.cc
)
source_group(system\\base FILES ${N3_FOUNDATION_SYSTEM_BASE_SRCS})

if(APPLE)
  set(N3_FOUNDATION_SYSTEM_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/system/osx/osxcpu.h
    ${N3_FOUNDATION_SRC_DIR}/system/osx/osxsysteminfo.h
    ${N3_FOUNDATION_SRC_DIR}/system/osx/osxsysteminfo.cc
  )
  source_group(system\\osx FILES ${N3_FOUNDATION_SYSTEM_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_SYSTEM_SRCS
  ${N3_FOUNDATION_SYSTEM_SRCS}
  ${N3_FOUNDATION_SYSTEM_BASE_SRCS}
  ${N3_FOUNDATION_SYSTEM_PLATFORM_SRCS}
)

set(N3_FOUNDATION_THREADING_SRCS
  ${N3_FOUNDATION_SRC_DIR}/threading/barrier.h
  ${N3_FOUNDATION_SRC_DIR}/threading/criticalsection.h
  ${N3_FOUNDATION_SRC_DIR}/threading/event.h
  ${N3_FOUNDATION_SRC_DIR}/threading/interlocked.h
  ${N3_FOUNDATION_SRC_DIR}/threading/objectref.h
  ${N3_FOUNDATION_SRC_DIR}/threading/objectref.cc
  ${N3_FOUNDATION_SRC_DIR}/threading/thread.cc
  ${N3_FOUNDATION_SRC_DIR}/threading/safeflag.h
  ${N3_FOUNDATION_SRC_DIR}/threading/safepriorityqueue.h
  ${N3_FOUNDATION_SRC_DIR}/threading/safequeue.h
  ${N3_FOUNDATION_SRC_DIR}/threading/thread.h
  ${N3_FOUNDATION_SRC_DIR}/threading/thread.cc
  ${N3_FOUNDATION_SRC_DIR}/threading/threadbarrier.h
  ${N3_FOUNDATION_SRC_DIR}/threading/threadid.h
)
source_group(threading FILES ${N3_FOUNDATION_THREADING_SRCS})

set(N3_FOUNDATION_THREADING_DEBUG_SRCS
  ${N3_FOUNDATION_SRC_DIR}/threading/debug/threadpagehandler.h
  ${N3_FOUNDATION_SRC_DIR}/threading/debug/threadpagehandler.cc
)
source_group(threading\\debug FILES ${N3_FOUNDATION_THREADING_DEBUG_SRCS})

if(APPLE)
  set(N3_FOUNDATION_THREADING_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxbarrier.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxcriticalsection.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxevent.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxinterlocked.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxthread.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxthread.cc
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxthreadbarrier.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxthreadid.h
    ${N3_FOUNDATION_SRC_DIR}/threading/osx/osxthreadlocalptr.h
  )
  source_group(threading\\osx FILES ${N3_FOUNDATION_THREADING_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_THREADING_SRCS
  ${N3_FOUNDATION_THREADING_SRCS}
  ${N3_FOUNDATION_THREADING_DEBUG_SRCS}
  ${N3_FOUNDATION_THREADING_PLATFORM_SRCS}
)

set(N3_FOUNDATION_TIMING_SRCS
  ${N3_FOUNDATION_SRC_DIR}/timing/calendartime.h
  ${N3_FOUNDATION_SRC_DIR}/timing/time.h
  ${N3_FOUNDATION_SRC_DIR}/timing/timer.h
)
source_group(timing FILES ${N3_FOUNDATION_TIMING_SRCS})

set(N3_FOUNDATION_TIMING_BASE_SRCS
  ${N3_FOUNDATION_SRC_DIR}/timing/base/calendartimebase.h
  ${N3_FOUNDATION_SRC_DIR}/timing/base/calendartimebase.cc
)
source_group(timing\\base FILES ${N3_FOUNDATION_TIMING_BASE_SRCS})

if(APPLE)
  set(N3_FOUNDATION_TIMING_PLATORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/timing/osx/osxcalendartime.h
    ${N3_FOUNDATION_SRC_DIR}/timing/osx/osxcalendartime.cc
    ${N3_FOUNDATION_SRC_DIR}/timing/osx/osxtimer.h
    ${N3_FOUNDATION_SRC_DIR}/timing/osx/osxtimer.cc
  )
  source_group(timing\\base FILES ${N3_FOUNDATION_TIMING_PLATORM_SRCS})
endif()

set(N3_FOUNDATION_TIMING_SRCS
  ${N3_FOUNDATION_TIMING_SRCS}
  ${N3_FOUNDATION_TIMING_BASE_SRCS}
  ${N3_FOUNDATION_TIMING_PLATORM_SRCS}
)

set(N3_FOUNDATION_UTIL_SRCS
  ${N3_FOUNDATION_SRC_DIR}/util/array.h
  ${N3_FOUNDATION_SRC_DIR}/util/bitfield.h
  ${N3_FOUNDATION_SRC_DIR}/util/blob.h
  ${N3_FOUNDATION_SRC_DIR}/util/blob.cc
  ${N3_FOUNDATION_SRC_DIR}/util/commandlineargs.h
  ${N3_FOUNDATION_SRC_DIR}/util/commandlineargs.cc
  ${N3_FOUNDATION_SRC_DIR}/util/crc.h
  ${N3_FOUNDATION_SRC_DIR}/util/crc.cc
  ${N3_FOUNDATION_SRC_DIR}/util/delegate.h
  ${N3_FOUNDATION_SRC_DIR}/util/dictionary.h
  ${N3_FOUNDATION_SRC_DIR}/util/fixedarray.h
  ${N3_FOUNDATION_SRC_DIR}/util/fixedtable.h
  ${N3_FOUNDATION_SRC_DIR}/util/fourcc.h
  ${N3_FOUNDATION_SRC_DIR}/util/globalstringatomtable.h
  ${N3_FOUNDATION_SRC_DIR}/util/globalstringatomtable.cc
  ${N3_FOUNDATION_SRC_DIR}/util/guid.h
  ${N3_FOUNDATION_SRC_DIR}/util/hashtable.h
  ${N3_FOUNDATION_SRC_DIR}/util/keyvaluepair.h
  ${N3_FOUNDATION_SRC_DIR}/util/list.h
  ${N3_FOUNDATION_SRC_DIR}/util/localstringatomtable.h
  ${N3_FOUNDATION_SRC_DIR}/util/localstringatomtable.cc
  ${N3_FOUNDATION_SRC_DIR}/util/priorityarray.h
  ${N3_FOUNDATION_SRC_DIR}/util/quadtree.h
  ${N3_FOUNDATION_SRC_DIR}/util/queue.h
  ${N3_FOUNDATION_SRC_DIR}/util/randomnumbertable.h
  ${N3_FOUNDATION_SRC_DIR}/util/randomnumbertable.cc
  ${N3_FOUNDATION_SRC_DIR}/util/ringbuffer.h
  ${N3_FOUNDATION_SRC_DIR}/util/round.h
  ${N3_FOUNDATION_SRC_DIR}/util/runlengthcodec.h
  ${N3_FOUNDATION_SRC_DIR}/util/runlengthcodec.cc
  ${N3_FOUNDATION_SRC_DIR}/util/simpletree.h
  ${N3_FOUNDATION_SRC_DIR}/util/sparsetable.h
  ${N3_FOUNDATION_SRC_DIR}/util/stack.h
  ${N3_FOUNDATION_SRC_DIR}/util/string.h
  ${N3_FOUNDATION_SRC_DIR}/util/string.cc
  ${N3_FOUNDATION_SRC_DIR}/util/stringatom.h
  ${N3_FOUNDATION_SRC_DIR}/util/stringatom.cc
  ${N3_FOUNDATION_SRC_DIR}/util/stringatomtablebase.h
  ${N3_FOUNDATION_SRC_DIR}/util/stringatomtablebase.cc
  ${N3_FOUNDATION_SRC_DIR}/util/stringbuffer.h
  ${N3_FOUNDATION_SRC_DIR}/util/stringbuffer.cc
  ${N3_FOUNDATION_SRC_DIR}/util/typepunning.h
  ${N3_FOUNDATION_SRC_DIR}/util/variant.h
)
source_group(util FILES ${N3_FOUNDATION_UTIL_SRCS})

if(APPLE)
  set(N3_FOUNDATION_UTIL_PLATFORM_SRCS
    ${N3_FOUNDATION_SRC_DIR}/util/osx/osxguid.h
    ${N3_FOUNDATION_SRC_DIR}/util/osx/osxguid.cc
  )
  source_group(util\\osx FILES ${N3_FOUNDATION_UTIL_PLATFORM_SRCS})
endif()

set(N3_FOUNDATION_UTIL_SRCS
  ${N3_FOUNDATION_UTIL_SRCS}
  ${N3_FOUNDATION_UTIL_PLATFORM_SRCS}
)

set(N3_FOUNDATION_SRCS_MAIN
  ${N3_FOUNDATION_SRC_DIR}/foundation.h
  ${N3_FOUNDATION_SRC_DIR}/stdneb.h
  ${N3_FOUNDATION_SRC_DIR}/stdneb.cc
)
source_group("" FILES ${N3_FOUNDATION_SRCS_MAIN})

#set(COMPILE_DEFINITIONS NEBULA3_USE_SERIAL_JOBSYSTEM=1)

add_library(foundation STATIC
  ${N3_FOUNDATION_APP_SRCS}
  ${N3_FOUNDATION_CORE_SRCS}
  ${N3_FOUNDATION_DEBUG_SRCS}
  ${N3_FOUNDATION_SRCS}
  ${N3_FOUNDATION_PLATFORM_SRCS}
  ${N3_FOUNDATION_FRAMESYNC_SRCS}
  ${N3_FOUNDATION_HTTP_SRCS}
  ${N3_FOUNDATION_INTERFACE_SRCS}
  ${N3_FOUNDATION_IO_SRCS}
  ${N3_FOUNDATION_JOBS_SRCS}
  ${N3_FOUNDATION_MATH_SRCS}
  ${N3_FOUNDATION_MEMORY_SRCS}
  ${N3_FOUNDATION_MESSAGING_SRCS}
  ${N3_FOUNDATION_MEMORY_SRCS}
  ${N3_FOUNDATION_NET_SRCS}
  ${N3_FOUNDATION_SYSTEM_SRCS}
  ${N3_FOUNDATION_THREADING_SRCS}
  ${N3_FOUNDATION_TIMING_SRCS}
  ${N3_FOUNDATION_UTIL_SRCS}
  ${N3_FOUNDATION_SRCS_MAIN}
)
target_link_libraries(foundation zlib)
#set_target_properties(foundation PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
