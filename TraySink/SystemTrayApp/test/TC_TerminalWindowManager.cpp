#include "stdafx.h"

#include "TestEnvironment.h"
#include "TC_TerminalWindowManager.h"

TC_TerminalWindowManager::TC_TerminalWindowManager(){}
TC_TerminalWindowManager::~TC_TerminalWindowManager(){}

void TC_TerminalWindowManager::preprocessing()
{
	log0("TITLE", "TerminalWindowManager");
	log0("DESC", "Handel terminal with console");
	log0("PREP", "1) Create console window, title: ConsoleSysTray_test");
	log0("TEST", "Manual user input testing");
	log0("POST", "1) Kill console window");

	std::system("start cmd /k title ConsoleTerminalManager_test");
}

void TC_TerminalWindowManager::testprocessing()
{
	TerminalWindowManager myWinManager;
	myWinManager.mainLoop(NULL);
	std::system("taskkill /FI \"WINDOWTITLE eq ConsoleTerminalManager_test\"");
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
	# Bad Cases
hide 20
add ConsoleWindowClass Title with space 2
quit
*/