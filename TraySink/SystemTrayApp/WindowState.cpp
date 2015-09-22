#include "stdafx.h"

using namespace std;
#include "WindowManager.h"

WindowState::WindowState ()
{
	windowClass = "";
	windowTitle = "";
	state = NONE;
	hWnd = NULL;
}
WindowState::~WindowState ()
{
	//delete windowClass; windowClass = NULL;
	//delete windowTitle; windowTitle = NULL;
}

void WindowState::setWindow (HWND *hWnd, unsigned short position)
{
	this->hWnd = hWnd;
	this->position = position; //Reduntant
	if (hWnd != NULL)
	{
		updateClass();
		updateTitle();
		state = VISIBLE;
	}
	else
	{
		windowClass = "";
		windowTitle = "";
		state = NONE;
	}
}

void WindowState::updateTitle()
{
	char windowTitleAux[80]; //TODO might fail
	GetWindowText(*hWnd, windowTitleAux, sizeof(windowTitleAux));
	windowTitle = windowTitleAux;
}

void WindowState::updateClass()
{
	char windowClassAux[80];
	GetClassName(*hWnd, windowClassAux, sizeof(windowClassAux));
	windowClass = windowClassAux;
}

std::string WindowState::getState()
{
	ostringstream str_stream;
	if (position < 100) // Very hard coded
		str_stream << "0";
	if (position < 10)
		str_stream << "0";

	string sState; //Almost as bad code as before
	if (state==HIDDEN) sState = "HIDDEN";
	else if (state==VISIBLE) sState = "VISIBLE";
	if (state==NONE) sState = "NONE";

	str_stream << position  << "\t" << sState<< "\t" << windowClass << "\t" <<windowTitle;
	
	//char* str_res = new char[255];
	//strcpy (str_res, str_stream.str().c_str());
	return str_stream.str();
}