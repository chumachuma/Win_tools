#pragma once

#include "..\WindowManager.h"

class TC_WindowManager: public test::TestingInterface
{
public:
	TC_WindowManager ();
	~TC_WindowManager ();
	void preprocessing (void);
	void testprocessing (void);
	void postprocessing (void);

protected:
	WindowManager* wMan;
};