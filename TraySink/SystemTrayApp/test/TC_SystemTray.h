#pragma once

#include "..\SystemTrayHandler.h"

class TC_SystemTray: public test::TestingInterface
{
public:
	TC_SystemTray ();
	~TC_SystemTray ();
	void preprocessing (void);
	void testprocessing (void);
	void postprocessing (void);
};