#include <shellapi.h>
#include "stdafx.h"
#include "resource.h"

using namespace std;
#include "SystemTrayHandler.h"

const char szClassName[] = "Base_Tray_Window";

SelfClassWindow::SelfClassWindow()
{
	//Create Window
	wincl.hInstance = GetModuleHandle(NULL);
					//GetWindowLong(hWnd, GWL_HINSTANCE);
					//GetModuleHandle(NULL); //problems with dll
	wincl.lpszClassName = szClassName;
	wincl.lpfnWndProc = WindowProcedure;
	wincl.style = CS_DBLCLKS;
	wincl.cbSize = sizeof (WNDCLASSEX);
	//Use default icon and mouse-pointer
	wincl.hIcon = LoadIcon( GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1) );
	wincl.hIconSm = LoadIcon( GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1) );
	wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
	wincl.lpszMenuName = NULL;
	wincl.cbClsExtra = 0;
	wincl.cbWndExtra = 0;
	wincl.hbrBackground = (HBRUSH)( CreateSolidBrush( RGB(255, 255, 255) ) );
}

void SelfClassWindow::selfCreateWindow ()
{
	if (RegisterClassEx (&wincl))  
	{
		myhWnd = CreateWindowEx (
				0,                   /* Extended possibilites for variation */ 
				szClassName,         /* Classname */ 
				szClassName,         /* Title Text */ 
				WS_OVERLAPPEDWINDOW, /* default window */ 
				CW_USEDEFAULT,       /* Windows decides the position */ 
				CW_USEDEFAULT,       /* where the window ends up on the screen */ 
				544,                 /* The programs width */ 
				375,                 /* and height in pixels */ 
				HWND_DESKTOP,        /* The window is a child-window to desktop */ 
				NULL,                /* No menu */ 
				GetModuleHandle(NULL),       /* Program Instance handler */ 
				NULL                 /* No Window Creation data */ 
		);
		//ShowWindow (myhWnd, 1);
	}
}

void SelfClassWindow::mainLoop ()
{
	while (GetMessage (&messages, NULL, 0, 0))  
	{  
		/* Translate virtual-key messages into character messages */ 
		TranslateMessage(&messages);  
		/* Send message to WindowProcedure */ 
		DispatchMessage(&messages);  
	} 
}

HWND SelfClassWindow::getHandler ()
{
	return myhWnd;
}

//Procedure
LRESULT CALLBACK WindowProcedure (HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_TRAY_MESSAGE:
		switch (lParam)
		{
		case WM_LBUTTONDBLCLK:
			SystemTrayHandler::swtich();
			cout << "WM_LBUTTONDBLCLK" << endl;
			break;
		case WM_RBUTTONDOWN:
			cout  << "WM_RBUTTONDOWN" << endl;
			break;
		case WM_DESTROY:
			cout << WM_DESTROY << endl;
			break;
		default:
			break;
		/*case WM_CONTEXTMENU:
			cout << "WM_CONTEXTMENU" << endl;
			break;*/
		/*case WM_CLOSE: an applicaion can prompt user confirmation before destroying*/
		}
		break;
	}
	return 1;
}