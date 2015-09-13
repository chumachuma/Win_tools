#pragma once

#include "..\ShowOpenWindows.h"

class TC_ShowWindow: public test::TestingInterface
{
public:
	TC_ShowWindow ();
	~TC_ShowWindow ();
	void preprocessing (void);
	void testprocessing (void);
	void postprocessing (void);
};