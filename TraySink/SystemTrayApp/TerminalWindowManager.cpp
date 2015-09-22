#include <shellapi.h>
#include "stdafx.h"

using namespace std;
#include "ShowOpenWindows.h"
#include "printC.h"
#include "TerminalWindowManager.h"

string TerminalWindowManager::inputCommand = "";
bool TerminalWindowManager::continueMainLooop = true;
std::map<std::string, StringFunc> TerminalWindowManager::string2FuncMap;
unsigned short TerminalWindowManager::winRegSize = 16; // TODO change this so it can be run with command argument
WindowManager TerminalWindowManager::wMan(16);

TerminalWindowManager::TerminalWindowManager (unsigned short& _winRegSize)
{
	//winRegSize = _winRegSize;
	//wMan = WindowManager(winRegSize);
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
		string optionString;
		getline(cin, optionString);
		istringstream optionsStream( optionString );
		optionsStream >> inputCommand;
		string2FuncMap[inputCommand](optionsStream);
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

void TerminalWindowManager::attachWindow (istream& stream) //Very bad code, should create a class for each parser?
{
	string wClass;
	string wTitle;
	unsigned short position;
	stream >> wClass;
	
	string auxTitle;
	stream >> wTitle;
	stream >> auxTitle;
	while ( !isdigit(auxTitle[0]) )
	{
		wTitle += " ";
		wTitle += auxTitle;
		stream >> auxTitle;
	}
	std::istringstream argS( auxTitle );
	argS >> position;
	if (position < winRegSize)
		wMan.attachWindow ( wClass.c_str(), wTitle.c_str(), position );
	else
		printC("Specified position out of range", RED);
}

void TerminalWindowManager::detachWindow (istream& stream)
{
	unsigned short position;
	stream >> position;
	if (position < winRegSize)
		wMan.removeWindow( position );
	else
		printC("Specified position out of range", RED);
}

void TerminalWindowManager::showWindow (istream& stream)
{
	unsigned short position;
	stream >> position;
	if (position < winRegSize)
		wMan.showWindow( position );
	else
		printC("Specified position out of range", RED);
}

void TerminalWindowManager::hideWindow (istream& stream)
{
	unsigned short position;
	stream >> position;
	if (position < winRegSize)
		wMan.hideWindow( position );
	else
		printC("Specified position out of range", RED);
}

void TerminalWindowManager::displayWindows (istream& stream)
{
	wMan.displayBuffer();
}
