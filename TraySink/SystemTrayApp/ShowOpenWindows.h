#pragma once
#ifndef SHOW_OPEN_WINDOWS_H
	#define SHOW_OPEN_WINDOWS_H

#include "printC.h"

BOOL CALLBACK EnumWindowsProc (HWND hwnd, LPARAM lParam);
void showWindows ();

#endif