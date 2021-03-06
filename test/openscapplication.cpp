//------------------------------------------------------------------------------
//  openscapplication.cc
//  (C) JerryZhou@outlook.com 
//------------------------------------------------------------------------------
#include "gtest/gtest.h"
#include "stdneb.h"
#include "io/iointerface.h"
#include "openscapplication.h"
#include "base/log.h"
#include "component/template/templateenum.h"
#include "component/template/templateloader.h"
#include "component/template/templatecontainer.h"

using ::testing::EmptyTestEventListener;
using ::testing::InitGoogleTest;
using ::testing::Test;
using ::testing::TestCase;
using ::testing::TestEventListeners;
using ::testing::TestInfo;
using ::testing::TestPartResult;
using ::testing::UnitTest;

using namespace Util;
using namespace IO;
using namespace Component;
using namespace Record;

#include "test_event.h"
#include "test_eventdelegate.h"
#include "test_eventdispatch.h"
#include "test_eventtarget.h"
#include "test_templateenum.h"
#include "test_templateclass.h"
#include "test_templaterecord.h"
#include "test_templateloader.h"
#include "test_log.h"
#include "test_macrodef.h"
#include "test_target.h"

namespace App
{
using namespace IO;
using namespace Component;
using namespace Record;

//------------------------------------------------------------------------------
/**
*/
bool
OpenSCApplication::Open() {
    n_assert(!this->IsOpen());
    if (ConsoleApplication::Open()) {
        // setup asynchronous IO
        this->ioInterface = IoInterface::Create();
        this->ioInterface->Open();
	return true;
    }
    return false;
}


//------------------------------------------------------------------------------
/**
 */
void
OpenSCApplication::Close() {

    this->ioInterface->Close();
    this->ioInterface = 0;

    ConsoleApplication::Close();
}

//------------------------------------------------------------------------------
/**
*/
void
OpenSCApplication::Run() {
    n_assert(this->isOpen);
    // setup the component
    Component::SetupEnums();
    Component::TemplateLoader::SetupLoader();
    
    int argc = 0;
    char *argv[] = {
        (char*)(""),
    };
    InitGoogleTest(&argc, argv);
    (void)(RUN_ALL_TESTS());
}

}// end of App

