#define _AFXDLL
//#include "AFXWIN.H"

#pragma once
#ifndef SYSTEM_TRAY_HANDLER_H
	#define SYSTEM_TRAY_HANDLER_H

class SelfClassWindow
{
public:
	SelfClassWindow ();
	void selfCreateWindow ();
	void mainLoop ();
	HWND getHandler ();

protected:
	WNDCLASSEX wincl;
	HWND myhWnd;
	MSG messages;
};


class SystemTrayHandler
{
public:
	SystemTrayHandler (HWND hWnd, HWND hiddenhWnd);
	~SystemTrayHandler ();
	static void swtich(); //Static So CALLBACK can use it
protected:
	static void hide();
	static void show();

	NOTIFYICONDATA Tray;
	//Can't make clicks on console
	WNDCLASSEX wincl;
	static HWND hWnd;
	static bool isVisible;
	HWND hiddenhWnd;
};

//Procedure
LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT unit, WPARAM wParam, LPARAM lParam);

//DECLARE_MESSAGE_MAP();

#endif