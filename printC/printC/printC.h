#pragma once
#ifdef PRINTC_EXPORTS
	#define PRINTC_DLL __declspec(dllexport)
#else
	#define PRINTC_DLL __declspec(dllimport)
#endif

enum Color
{
	BLACK,
	DARKBLUE,
	DARKGREEN,
	DARKAQUA,
	DARKRED,
	DARKPURPLE,
	DARKYELLOW,
	DARKWHITE,
	GRAY,
	BLUE,
	GREEN,
	AQUA,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
};

extern "C"
{
	PRINTC_DLL void printC (char* msg, unsigned char color); // Change the font color mantaining the background color
	PRINTC_DLL void highlight (char* msg, unsigned char color); // Change the font background mantaining the color
	PRINTC_DLL void printCH (char* msg, unsigned char color); // Change the font color and background
	PRINTC_DLL void stdoutC (char* msg, unsigned char color, unsigned char mask=0xFF); // PrintC but it does make newline
}

void printBase (char* msg, unsigned char color, unsigned char mask);

void printColor (char* msg, unsigned char color, HANDLE* hConsole); // Most Basic rutine to set the attributes of the console and printing

unsigned char getConsoleDefaultColor (HANDLE* hConsole);