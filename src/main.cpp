#include "AP.h"	

// setup to run on 1st cpu core
void setup()	
{
	initPinsInputs();	// Initiate all pins as inputs
	initPinsOutputs();	// Initiate all pins as outputs
	initSerial(); 		// Initiate Serial communication
	initMultiCore();	// Initiate MultiCore
}

// loop to run on 1st cpu core
void loop(void)	// Main loop
{
	destiler();	// Destiler function to operate the machine 
}

// loop to run on 2nd cpu core
void loop2(void *pvParameters)
{
	//Created the 'FLAG_INIT_WIFI' to be able to operate the machine while 
	//WIFI is init, this way, user can operate the machine manualy, no need 
	//to wait for WIFI to init
	static bool FLAG_INIT_WIFI = 0;	// Flag to check if WIFI is connected
	while (1)	// Main loop
	{
		if (FLAG_INIT_WIFI == 0)
		{
			sPrintLnStr("WIFI INIT....");
			initWIFI();	// Initiate WIFI
			FLAG_INIT_WIFI = WiFi.isConnected();	// Check if WIFI is connected
			setupCalls();	// Initiate calls
		}
		else
		{
			FLAG_INIT_WIFI = WiFi.isConnected();	// Check if WIFI is connected
			ProcessWebPage();	// Process WebPage
			webTimer("*", 0);
		}
	}
}
