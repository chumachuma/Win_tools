#include "stdafx.h"

#include "TestEnvironment.h"
#include "TC_SystemTray.h"

TC_SystemTray::TC_SystemTray(){}
TC_SystemTray::~TC_SystemTray(){}

void TC_SystemTray::preprocessing()
{
	log0("TITLE", "SystemTray");
	log0("DESC", "Creates system Tray icon that hides and shows main console window");
	log0("PREP", "");
	log0("TEST", "Create window to handle WINDOWS MESSAGES");
	log0("TEST", "Create tray icon (Notify icon)");
	log0("POST", "");
}

void TC_SystemTray::testprocessing()
{
	SelfClassWindow myWinClass;
	myWinClass.selfCreateWindow();
	SystemTrayHandler myWinTray ( FindWindow ("ConsoleWindowClass", NULL), myWinClass.getHandler() );
	myWinClass.mainLoop();
}

void TC_SystemTray::postprocessing()
{
}