//------------------------------------------------------------------------------
//  openscapplication.cc
//  (C) JerryZhou@outlook.com 
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "io/iointerface.h"
#include "openscapplication.h"


namespace App
{
    using namespace IO;

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

    int argc = 0;
    char *argv[] = {""};
    InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
}

}// end of App

