#include "stdafx.h"

#include "TestEnvironment.h"
#include "TC_WindowManager.h"
#include "TC_ShowWindow.h"
#include "TC_SystemTray.h"
#include "TC_TerminalWindowManager.h"

int _tmain(int argc, char* argv[])
{
	test::TestPackage TP_TraySink;
	
	TP_TraySink.addTestCase(new TC_WindowManager);
	TP_TraySink.addTestCase(new TC_ShowWindow);
	//TP_TraySink.addTestCase(new TC_SystemTray);
	TP_TraySink.addTestCase(new TC_TerminalWindowManager);


	TP_TraySink.run();

	return 0;
}

