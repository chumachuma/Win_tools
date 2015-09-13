#pragma once
#ifndef TERMINAL_WINDOW_MANAGER_H
	#define TERMINAL_WINDOW_MANAGER_H

#include "WindowManager.h"

typedef void(*StringFunc)(std::istream& stream);

class TerminalWindowManager
{
public:
	TerminalWindowManager();
	~TerminalWindowManager();
	static void mainLoop(void *arg); // static and argument required for threading
	
protected:
	static std::string inputCommand;
	static bool continueMainLooop;
	static WindowManager wMan;

	static std::map<std::string, StringFunc> string2FuncMap;

	static void endLoop (std::istream& stream);
	static void showOpenWindows (std::istream& stream);
	static void attachWindow (std::istream& stream);
	static void detachWindow (std::istream& stream);
	static void showWindow (std::istream& stream);
	static void hideWindow (std::istream& stream);
	static void displayWindows (std::istream& stream);
	// TODO add console window?
	// TODO Colors?
	// BUGS wrong input (BUFFER OVERFLOW!)
	// Add help command
};

#endif