#include <shellapi.h>
#include "stdafx.h"
#include "resource.h"

using namespace std;
#include "SystemTrayHandler.h"

HWND SystemTrayHandler::hWnd = NULL;
bool SystemTrayHandler::isVisible = false;

SystemTrayHandler::SystemTrayHandler (HWND hWnd, HWND hiddenhWnd): hiddenhWnd(hiddenhWnd)
{
	// Get Self Window
	// hWnd = FindWindow ("ConsoleWindowClass", NULL);
	// Hide Self Window
	// hide();
	this->hWnd = hWnd;

	// Tray Info
	Tray.cbSize = sizeof(Tray);
	Tray.hIcon = LoadIcon( GetModuleHandle(NULL), MAKEINTRESOURCE(IDI_ICON1) );//IDI_WINLOGO);
	Tray.hWnd = hiddenhWnd; // If this is not here the Icon disappears
	strcpy (Tray.szTip, "Tray Sink");
	Tray.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE;
	Tray.uID = TRAY_ICON_UID;
	Tray.uCallbackMessage = WM_TRAY_MESSAGE;//WM_LBUTTONDOWN;
	// Set icon in taskbar tray
	Shell_NotifyIcon(NIM_ADD, &Tray);
	isVisible = true;
}

SystemTrayHandler::~SystemTrayHandler ()
{
	// Show Self Window Before Killing
	show();

	// Remove icon
	Shell_NotifyIcon(NIM_DELETE, &Tray);
}

void SystemTrayHandler::swtich ()
{
	if (isVisible)
		hide();
	else
		show();
	isVisible = !isVisible;
}

void SystemTrayHandler::hide ()
{
	ShowWindow(hWnd, 0);
}

void SystemTrayHandler::show ()
{
	ShowWindow(hWnd, 1);
}

void SystemTrayHandler::focus()
{
	SetWindowPos(hWnd, HWND_TOP, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE); //SWP_NOMOVE | SWP_NOSIZE => ignore 0s
}