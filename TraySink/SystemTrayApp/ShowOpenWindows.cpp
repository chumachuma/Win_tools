#include "stdafx.h"

using namespace std;
#include "ShowOpenWindows.h"


BOOL CALLBACK EnumWindowsProc (HWND hwnd, LPARAM lParam)
{
	if ( IsWindowVisible(hwnd) )
	{
		char class_name[80];
		char title[80];
		GetClassName( hwnd, class_name, sizeof(class_name) );
		GetWindowText( hwnd, title, sizeof(title) );
		if ( title[0] && class_name[0] )
		{
			cout << "Class name:   " << class_name << endl;
			cout << "Window title: " << title << endl << endl;
		}
	}
	return TRUE;
}

void showWindows ()
{
	EnumWindows (EnumWindowsProc, NULL);
}