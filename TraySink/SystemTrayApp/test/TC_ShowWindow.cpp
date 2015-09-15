#include "stdafx.h"

#include "TestEnvironment.h"
#include "TC_ShowWindow.h"

TC_ShowWindow::TC_ShowWindow(){}
TC_ShowWindow::~TC_ShowWindow(){}

void TC_ShowWindow::preprocessing()
{
	log0("TITLE", "ShowOpenWindows");
	log0("DESC", "Show current open windows classes and titles");
	log0("PREP", "");
	log0("TEST", "Show windows");
	log0("POST", "");
}

void TC_ShowWindow::testprocessing()
{
	showWindows();
}

void TC_ShowWindow::postprocessing()
{
}