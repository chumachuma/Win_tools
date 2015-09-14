#include "stdafx.h"

using namespace std;
#include "WindowManager.h"
#include "printC.h"

WindowRegistry::WindowRegistry (unsigned short numOfWindows): numOfWindows(numOfWindows)
{
	//wReg = new vector<WindowState>;
	StateColor[HIDDEN] = DARKAQUA;
	StateColor[VISIBLE] = DARKGREEN;
	StateColor[NONE] = DARKWHITE;
	wReg.resize(numOfWindows);
	for (unsigned short i=0; i<numOfWindows; i++)
		wReg[i].position = i;
}
WindowRegistry::~WindowRegistry ()
{
	//delete wReg; wReg = NULL;
}

void WindowRegistry::attachReg(HWND *hWnd, unsigned short position)
{
	wReg[position].setWindow(hWnd, position);
}

void WindowRegistry::removeReg(unsigned short position)
{
	wReg[position].setWindow(NULL, position);
}

void WindowRegistry::hide(unsigned short position)
{
	wReg[position].state = HIDDEN;
}

void WindowRegistry::show(unsigned short position)
{
	wReg[position].state = VISIBLE;
}

void WindowRegistry::getRegistry ()
{
	printC( "NUM \t state \t windowClass \t windowTitle", DARKYELLOW);
	for (unsigned short i=0; i<numOfWindows; i++) //Slooooow
	{
		char* pCharProcess = new char[wReg[i].getState().length() +1];
		strcpy( pCharProcess, wReg[i].getState().c_str() );
		printC( pCharProcess, StateColor[wReg[i].state] );
		delete[] pCharProcess;
	}
}

bool WindowRegistry::isSet (unsigned short position)
{
	return wReg[position].state != NONE;
}

