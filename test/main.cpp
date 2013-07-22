#include "stdneb.h"
#include "openscapplication.h"
#include "base/log.h"

ImplementNebulaApplication();

using namespace Util;
using namespace App;

//------------------------------------------------------------------------------
/**
 * */
void
NebulaMain(const CommandLineArgs& args){
    OpenSCApplication app;
    app.SetCompanyName("Huncent");
    app.SetAppID("OpenSC");
    app.SetCmdLineArgs(args);
    if(app.Open()){
	app.Run();
	app.Close();
    }
    app.Exit();
}
