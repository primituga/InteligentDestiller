#include "AP.h"

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
	if (initWIFI())
	{
		// ProcessWebPage(); // Process WebPage
		webTimer("*", 0);
	}
}

// loop to run on 2nd cpu core
void loop2(void *pvParameters)
{
	while (1) // Main loop
	{
		destiler(); // Destiler function to operate the machine
	}
}
