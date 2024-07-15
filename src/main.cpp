#include "AP.h"

const char *host = "destiller";

// setup to run on 1st cpu core
void setup()
{
	initPinsInputs();  // Initiate all pins as inputs
	initPinsOutputs(); // Initiate all pins as outputs
	initSerial();	   // Initiate Serial communication
	initMultiCore();   // Initiate MultiCore
	initFS();		   // Initiate SPIFFS
}

// loop to run on 1st cpu core
void loop(void) // Main loop
{
	destiler(); // Destiler function to operate the machine
}

// loop to run on 2nd cpu core
void loop2(void *pvParameters)
{
	// Created the 'FLAG_INIT_WIFI' to be able to operate the machine while
	// WIFI is init, this way, user can operate the machine manualy, no need
	// to wait for WIFI to init
	while (1) // Main loop
	{

		if (WiFi.status() != WL_CONNECTED)
		{
			sPrintLnStr("WIFI INIT....");
			initWIFI(); // Initiate WIFI
			setupCalls(); // Initiate calls
		}
		else
		{
			//ProcessWebPage(); // Process WebPage
			webTimer("*", 0);
		}
	}
}
