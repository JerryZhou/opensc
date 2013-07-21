//------------------------------------------------------------------------------
//  audiotest.cc
//  (C) 2008 Radon Labs GmbH
//------------------------------------------------------------------------------
#include "stdneb.h"
#include "mygameapplication.h"

ImplementNebulaApplication();

using namespace Util;
using namespace App;

//------------------------------------------------------------------------------
/**
*/
void
NebulaMain(const CommandLineArgs& args)
{
    MyGameApplication app;
    app.SetCompanyName("Twisted Logic");
    app.SetAppID("MyGameAPp");
    app.SetCmdLineArgs(args);
    if (app.Open())
    {
        app.Run();
        app.Close();
    }    
    app.Exit();
}
