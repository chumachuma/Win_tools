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

void BadTest()
{
	printC ("create console window, title: ConsoleSysTray_test", BLUE);
	std::system("start cmd /k title ConsoleSysTray_test");

	WindowManager wMan (4);

	printC ("displayBuffer: empty", BLUE);
	wMan.displayBuffer();
	
	printC ("add ConsoleSysTray_test, position=1", BLUE);
	wMan.attachConsoleWithTitle("ConsoleSysTray_test", 1);//TODO test remove isSet

	printC ("displayBuffer: 1 -> ConsoleSysTray_test -> VISIBLE", BLUE);
	wMan.displayBuffer();

	printC ("hide ConsoleSysTray_test", BLUE);
	wMan.hideWindow(1);

	printC ("displayBuffer: 1 -> ConsoleSysTray_test -> HIDDEN", BLUE);
	wMan.displayBuffer();

	printC ("show ConsoleSysTray_test", BLUE);
	wMan.showWindow(1);

	printC ("hide ConsoleSysTray_test", BLUE);
	wMan.hideWindow(1);
	printC ("delete ConsoleSysTray_test, window is shown, and not removed", BLUE);
	wMan.removeWindow(1);

	printC ("displayBuffer: empty", BLUE);
	wMan.displayBuffer();
}

int _tmain(int argc, char* argv[])
{
	
	//BadTest();

	//showWindows();
	
	TerminalWindowManager myWinManager;
	myWinManager.mainLoop(NULL);
	_beginthread( myWinManager.mainLoop, 0, NULL );

	SelfClassWindow myWinClass;
	myWinClass.selfCreateWindow();
	SystemTrayHandler myWinTray ( FindWindow ("ConsoleWindowClass", NULL), myWinClass.getHandler() );
	myWinClass.mainLoop();

	return 0;
}

