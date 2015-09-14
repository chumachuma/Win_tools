#pragma once
#ifndef WINDOW_MANAGER_H
	#define WINDOW_MANAGER_H

#include "printC.h"

enum State {
	HIDDEN = 0, 
	VISIBLE = 1,
	NONE
};


class WindowState
{
public:
	WindowState ();
	virtual ~WindowState ();
	void setWindow (HWND *hWnd, unsigned short position);
	void updateTitle ();
	void updateClass ();
	std::string getState ();

	unsigned short position;
	std::string  windowClass;
	std::string windowTitle; // Updatable outside of WindowManager!
	State state;

protected:
	HWND* hWnd;
};


class WindowRegistry
{
public:
	WindowRegistry (unsigned short numOfWindows=16);
	virtual ~WindowRegistry ();
	void attachReg (HWND *hWnd, unsigned short position);
	void removeReg (unsigned short position);
	void hide (unsigned short position);
	void show (unsigned short position);
	void getRegistry ();
	bool isSet (unsigned short position);

protected:
	std::vector<WindowState> wReg;
	unsigned short numOfWindows;
	std::map<State, Color> StateColor;
};


class WindowManager
{
public:
	WindowManager (unsigned short numOfWindows=16);
	~WindowManager ();
	void displayBuffer ();
	void attachWindow (const char* WindowClass=NULL, const char* WindowTitle=NULL, unsigned short position=0);
	void attachConsoleWithTitle (const char* WindowTitle=NULL, unsigned short position=0);
	void removeWindow (unsigned short position=0);
	void hideWindow (unsigned short position=0);
	void showWindow (unsigned short position=0);

protected:
	std::vector<HWND> hWnd;
	unsigned short numOfWindows;
	HWND selfWnd;
	WindowRegistry* wReg;
};

#endif