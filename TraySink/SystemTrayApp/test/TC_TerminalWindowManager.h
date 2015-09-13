#pragma once

#include "..\TerminalWindowManager.h"

class TC_TerminalWindowManager: public test::TestingInterface
{
public:
	TC_TerminalWindowManager ();
	~TC_TerminalWindowManager ();
	void preprocessing (void);
	void testprocessing (void);
	void postprocessing (void);
};