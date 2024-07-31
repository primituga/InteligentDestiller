/**
 * @author Sérgio Carmo
 * @file AP_main.cpp
 * @brief Main file for the MD project
 * @version 1.0
 */

#include "AP.h"

bool DEBUG = 1; /// Debug mode

/// setup to run on 1st cpu core
void setup()
{
	initPinsInputs();  /// Initiate all pins as inputs
	initPinsOutputs(); /// Initiate all pins as outputs
	initSerial();	   /// Initiate Serial communication
	initMultiCore();   /// Initiate MultiCore
	initFS();		   /// Initiate SPIFFS
	readInputs();
	test_IO();
}

/// loop to run on 1st cpu core
void loop(void)
{
	readInputs();
	destiler(); /// Destiler function to operate the machine
	writeOutputs();
}

/// loop to run on 2nd cpu core
void loop2(void *pvParameters)
{
	while (1) /// Main loop
	{
		if (initWIFI())
		{
			setupRoutes(); /// Setup Routes
		}
		else
		{
			webTimer("*", 0);
		}
	}
}
