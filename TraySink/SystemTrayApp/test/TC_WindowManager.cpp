#include "stdafx.h"

#include "TestEnvironment.h"
#include "TC_WindowManager.h"

TC_WindowManager::TC_WindowManager(){}
TC_WindowManager::~TC_WindowManager(){}

void TC_WindowManager::preprocessing()
{
	log0("TITLE", "WindowManager");
	log0("DESC", "This class manages and tracks the visibility of windows added");
	log0("PREP", "1) Initialize Window Manager with buffer of 4 windows");
	log0("PREP", "2) Create console window, title: ConsoleSysTray_test");
	log0("TEST", "1) Compare all elements are retrieved");
	log0("POST", "1) Remove Window Manager");
	log0("POST", "2) Kill console window");

	wMan = new WindowManager(4);
	std::system("start cmd /k title ConsoleSysTray_test");
}

void TC_WindowManager::testprocessing()
{
	logD ("displayBuffer: empty");
	wMan->displayBuffer();
	
	logD ("add ConsoleSysTray_test, position=1");
	wMan->attachConsoleWithTitle("ConsoleSysTray_test", 1);//TODO test remove isSet

	logD ("displayBuffer: 1 -> ConsoleSysTray_test -> VISIBLE");
	wMan->displayBuffer();

	logD ("hide ConsoleSysTray_test");
	wMan->hideWindow(1);

	logD ("displayBuffer: 1 -> ConsoleSysTray_test -> HIDDEN");
	wMan->displayBuffer();

	logD ("show ConsoleSysTray_test");
	wMan->showWindow(1);

	logD ("hide ConsoleSysTray_test");
	wMan->hideWindow(1);
	logD ("delete ConsoleSysTray_test, window is shown, and not removed");
	wMan->removeWindow(1);

	logD ("displayBuffer: empty");
	wMan->displayBuffer();

}

void TC_WindowManager::postprocessing()
{
	delete wMan;
	wMan = 0;
	std::system("taskkill /FI \"WINDOWTITLE eq ConsoleSysTray_test\"");//need to add system32 to environment
}