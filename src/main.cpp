#include "AP.h"

void setup()
{
	initPinsInputs();
	initPinsOutputs();
	initSerial(); // Initiate serial link
	initMultiCore();
}

// loop to run on 1st cpu core
void loop(void)
{
	destiler();
}

// loop to run on 2nd cpu core
void loop2(void *pvParameters)
{
	//Created the 'FLAG_INIT_WIFI' to be able to operate the machine while 
	//WIFI is init, this way, user can operate the machine manualy, no need 
	//to wait for WIFI to init
	static bool FLAG_INIT_WIFI = 0;
	while (1)
	{
		if (FLAG_INIT_WIFI == 0)
		{
			initWIFI();
			FLAG_INIT_WIFI = 1;
			setupCalls();
		}
		else
		{
			ProcessWebPage();
			webTimer("*", 0);
		}
	}
}
