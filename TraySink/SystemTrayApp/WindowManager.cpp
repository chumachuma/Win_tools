#include "stdafx.h"
#include "printC.h"

using namespace std;
#include "WindowManager.h"

WindowManager::WindowManager (unsigned short numOfWindows): numOfWindows(numOfWindows)
{
	hWnd.resize(numOfWindows);
	selfWnd = FindWindow ("ConsoleWindowClass", NULL);
	wReg = new WindowRegistry(numOfWindows);
}

WindowManager::~WindowManager ()
{
	// Show all windows
	for (int i=0; i<numOfWindows; i++)
		showWindow(i);

	//delete [] hWnd;	hWnd = NULL;
	delete wReg; wReg = NULL;
}

void WindowManager::attachWindow (const char* WindowClass, const char* WindowTitle, unsigned short position)
{
	if (position < numOfWindows)
	{
		if (wReg->isSet(position))//(hWnd[0] != NULL) // Replace Window if it already exists // Use registry to check
			removeWindow(position);
		hWnd[position] = FindWindow (WindowClass, WindowTitle);
		wReg->attachReg(&hWnd[position], position);
	}
	else
		cerr << "Position to attach windows out of range:" << position <<endl;
}

void WindowManager::attachConsoleWithTitle (const char* WindowTitle, unsigned short position)
{
	attachWindow("ConsoleWindowClass", WindowTitle, position);
}

void WindowManager::removeWindow (unsigned short position) // There cannot be hidden windows
{
	showWindow(position);
	//delete hWnd[position]; hWnd[position] = NULL; //Not needed
	wReg->removeReg(position);
}

void WindowManager::hideWindow (unsigned short position)
{
	ShowWindow(hWnd[position], 0);
	wReg->hide(position);
}

void WindowManager::showWindow (unsigned short position)
{
	ShowWindow(hWnd[position], 1);
	wReg->show(position);
}

void WindowManager::displayBuffer ()
{
	wReg->getRegistry();
}