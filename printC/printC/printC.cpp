// printC.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"

#include "printC.h"

void printC (char* msg, unsigned char color)
{
	printBase ( msg, color, 0xF0 ); //0xF0 mask to get background color
}

void highlight (char* msg, unsigned char color)
{
	printBase ( msg, color<<4, 0x0F ); //0xF0 mask to get color, displace color to second quartet
}

void printCH (char* msg, unsigned char color)
{
	printBase ( msg, color, 0x00 ); //0xFF everything is accepted
}


void printBase (char* msg, unsigned char color, unsigned char mask)
{
	HANDLE hConsole;
	hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

	int consoleDefaultAttributes = getConsoleDefaultColor( &hConsole );
	int consoleAttributes = (consoleDefaultAttributes & mask) + color;

	printColor (msg, consoleAttributes, &hConsole);

	SetConsoleTextAttribute(hConsole, consoleDefaultAttributes);
}

void printColor (char* msg, unsigned char color, HANDLE* hConsole)
{
	SetConsoleTextAttribute(*hConsole, color);
	std::cout << msg << std::endl;
}

unsigned char getConsoleDefaultColor (HANDLE* hConsole)
{
	CONSOLE_SCREEN_BUFFER_INFO iConsole;
	GetConsoleScreenBufferInfo(*hConsole, &iConsole);
	return (unsigned char)iConsole.wAttributes;
}

