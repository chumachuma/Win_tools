#include <shellapi.h>
#include "stdafx.h"

using namespace std;
#include "ShowOpenWindows.h"
#include "WindowManager.h"
#include "printC.h"
#include "TerminalWindowManager.h"

string TerminalWindowManager::inputCommand = "";
bool TerminalWindowManager::continueMainLooop = true;

TerminalWindowManager::TerminalWindowManager ()
{
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
		RunCases(cin);
	}
	while (continueMainLooop);
}

void TerminalWindowManager::RunCases(istream& stream)
{
}