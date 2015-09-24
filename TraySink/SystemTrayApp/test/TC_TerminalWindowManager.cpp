#include "stdafx.h"

#include "TestEnvironment.h"
#include "TC_TerminalWindowManager.h"

TC_TerminalWindowManager::TC_TerminalWindowManager(){}
TC_TerminalWindowManager::~TC_TerminalWindowManager(){}

void TC_TerminalWindowManager::preprocessing()
{
	log0("TITLE", "TerminalWindowManager");
	log0("DESC", "Handel terminal with console");
	log0("PREP", "1) Create console window, title: ConsoleSysTray_test\r\n");
	log0("PREP", "2) Create console window, title: Console with Spaces");
	log0("TEST", "Manual user input testing");
	log0("POST", "1) Kill the two console window");

	std::system("start cmd /k title ConsoleTerminalManager_test");
	std::system("start cmd /k title Console with Spaces");
}

void TC_TerminalWindowManager::testprocessing()
{
	unsigned short argUS = 16;
	TerminalWindowManager myWinManager(argUS);
	myWinManager.mainLoop(NULL);
	std::system("taskkill /FI \"WINDOWTITLE eq ConsoleTerminalManager_test\"");
	std::system("taskkill /FI \"WINDOWTITLE eq Console with Spaces\"");
}

void TC_TerminalWindowManager::postprocessing()
{
}

/*TEST
help
info
buffer
add ConsoleWindowClass ConsoleTerminalManager_test 1
hide 1
buffer
show 1
remove 1
buffer
pin 1
unpin 1
add ConsoleWindowClass Console with Spaces 2
buffer
hide 2
	
	# Bad Cases
hide 20
quit
*/