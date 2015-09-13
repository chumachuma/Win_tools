// SystemTrayApp.cpp : Defines the entry point for the console application.
//

#include <shellapi.h>
#include "stdafx.h"
//#include "resource.h" //TEMP

using namespace std;
#include <process.h>
#include "SystemTrayHandler.h"
#include "ShowOpenWindows.h"
#include "WindowManager.h"
#include "TerminalWindowManager.h"
#include "printC.h"

int _tmain(int argc, char* argv[])
{	
	TerminalWindowManager myWinManager;
	myWinManager.mainLoop(NULL);
	_beginthread( myWinManager.mainLoop, 0, NULL );

	SelfClassWindow myWinClass;
	myWinClass.selfCreateWindow();
	SystemTrayHandler myWinTray ( FindWindow ("ConsoleWindowClass", NULL), myWinClass.getHandler() );
	myWinClass.mainLoop();

	return 0;
}

