// printC.cpp: define las funciones exportadas de la aplicación DLL.
//

#include "stdafx.h"

#include "printC.h" 
//TODO mask are not working

void printC (char* msg, unsigned char color)
{
	printBase ( msg, color, 0x0F ); //0xF0 mask to get background color
	std::cout << std::endl;
}

void highlight (char* msg, unsigned char color)
{
	printBase ( msg, color<<4, 0xF0 ); //0xF0 mask to get color, displace color to second quartet
	std::cout << std::endl;
}

void printCH (char* msg, unsigned char color)
{
	printBase ( msg, color, 0xFF ); //0xFF everything is accepted
	std::cout << std::endl;
}

void stdoutC (char* msg, unsigned char color, unsigned char mask)
{
	printBase ( msg, color, mask );
}


void printBase (char* msg, unsigned char color, unsigned char mask)
{
	HANDLE hConsole;
	hConsole = GetStdHandle( STD_OUTPUT_HANDLE );

	int consoleDefaultAttributes = getConsoleDefaultColor( &hConsole );
	int consoleAttributes = (consoleDefaultAttributes & ~mask) + (color & mask);

	printColor (msg, consoleAttributes, &hConsole);

	SetConsoleTextAttribute(hConsole, consoleDefaultAttributes);
}

void printColor (char* msg, unsigned char color, HANDLE* hConsole)
{
	SetConsoleTextAttribute(*hConsole, color);
	std::cout << msg;
}

unsigned char getConsoleDefaultColor (HANDLE* hConsole)
{
	CONSOLE_SCREEN_BUFFER_INFO iConsole;
	GetConsoleScreenBufferInfo(*hConsole, &iConsole);
	return (unsigned char)iConsole.wAttributes;
}

