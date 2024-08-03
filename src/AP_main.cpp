/**
 * @author Sérgio Carmo
 * @file AP_main.cpp
 * @brief Main file for the MD project
 * @version 1.0
 */

#include "AP.h"

bool DEBUG = 1; /// Debug mode

AsyncWebSocket ws("/ws");
AsyncWebServer server(80); /// Create a webserver object that listens for HTTP request on port 80

/// setup to run on 1st cpu core
void setup()
{
	initPinsInputs();  /// Initiate all pins as inputs
	initPinsOutputs(); /// Initiate all pins as outputs
	// test_IO();
	initSerial();	 /// Initiate Serial communication
	initMultiCore(); /// Initiate MultiCore
	initFS();		 /// Initiate SPIFFS
	readInputs();
	updateOutputsWeb();
	
	setupRoutes(); /// Setup Routes
	 server.addHandler(&ws);
}

/// loop to run on 1st cpu core
void loop(void)
{
	readInputs();
	destiler(); /// Destiler function to operate the machine
	//updateOutputsWeb();
	writeOutputs();
}

/// loop to run on 2nd cpu core
void loop2(void *pvParameters)
{
	while (1) /// Main loop
	{
		ws.cleanupClients();
		webTimer("*", 0);
		initWIFI();
	}
}
