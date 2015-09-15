#pragma once
#ifndef TERMINAL_WINDOW_MANAGER_H
	#define TERMINAL_WINDOW_MANAGER_H

#include "WindowManager.h"

typedef void(*StringFunc)(std::istream& stream);

class TerminalWindowManager
{
public:
	TerminalWindowManager(unsigned short& _winRegSize);
	~TerminalWindowManager();
	static void mainLoop(void *arg); // static and argument required for threading
	
protected:
	static std::string inputCommand;
	static bool continueMainLooop;
	static WindowManager wMan;
	static unsigned short winRegSize;

	static std::map<std::string, StringFunc> string2FuncMap;

	static void endLoop (std::istream& stream);
	static void showOpenWindows (std::istream& stream);
	static void attachWindow (std::istream& stream);
	static void detachWindow (std::istream& stream);
	static void showWindow (std::istream& stream);
	static void hideWindow (std::istream& stream);
	static void displayWindows (std::istream& stream);
	static void help (std::istream& stream); //TODO not implemented
	// TODO BUGS wrong input (BUFFER OVERFLOW!)
};

#endif