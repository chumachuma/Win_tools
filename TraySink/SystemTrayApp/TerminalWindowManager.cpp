#include <shellapi.h>
#include "stdafx.h"

using namespace std;
#include "ShowOpenWindows.h"
#include "printC.h"
#include "TerminalWindowManager.h"

string TerminalWindowManager::inputCommand = "";
bool TerminalWindowManager::continueMainLooop = true;
std::map<std::string, StringFunc> TerminalWindowManager::string2FuncMap;
WindowManager TerminalWindowManager::wMan(16);

TerminalWindowManager::TerminalWindowManager ()
{
	string2FuncMap["quit"] = &endLoop;
	string2FuncMap["info"] = &showOpenWindows;
	string2FuncMap["add"] = &attachWindow;
	string2FuncMap["remove"] = &detachWindow;
	string2FuncMap["show"] = &showWindow;
	string2FuncMap["hide"] = &hideWindow;
	string2FuncMap["buffer"] = &displayWindows;
}
TerminalWindowManager::~TerminalWindowManager ()
{
}

void TerminalWindowManager::mainLoop ( void *arg )
{
	do
	{
		cout << ">> ";
		cin >> inputCommand;
		string2FuncMap[inputCommand](cin);
		cin.clear();
	}
	while (continueMainLooop);
}

void TerminalWindowManager::endLoop (istream& stream)
{
	continueMainLooop = false;
}

void TerminalWindowManager::showOpenWindows (istream& stream)
{
	showWindows();
}

void TerminalWindowManager::attachWindow (istream& stream)
{
	string wClass;
	string wTitle;
	unsigned short position;
	stream >> wClass;
	stream >> wTitle;
	stream >> position;
	wMan.attachWindow ( wClass.c_str(), wTitle.c_str(), position );
}

void TerminalWindowManager::detachWindow (istream& stream)
{
	unsigned short position;
	stream >> position;
	wMan.removeWindow( position );
}

void TerminalWindowManager::showWindow (istream& stream)
{
	unsigned short position;
	stream >> position;
	wMan.showWindow( position );
}

void TerminalWindowManager::hideWindow (istream& stream)
{
	unsigned short position;
	stream >> position;
	wMan.hideWindow( position );
}

void TerminalWindowManager::displayWindows (istream& stream)
{
	wMan.displayBuffer();
}
