#pragma once
#ifndef TERMINAL_WINDOW_MANAGER_H
	#define TERMINAL_WINDOW_MANAGER_H

class TerminalWindowManager
{
public:
	TerminalWindowManager();
	~TerminalWindowManager();
	static void mainLoop(void *arg); //Required for threading
	
protected:
	static string inputCommand;
	static bool continueMainLooop;
	static void RunCases (istream& stream);
};

#endif