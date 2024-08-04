/**
 * @author Sérgio Carmo
 * @file AP_main.cpp
 * @brief Main file for the MD project
 * @version 1.0
 */

#include "AP.h"

bool DEBUG = 1; /// Debug mode

/**
 * @brief AsyncWebSocket object to handle websocket connections
 */
AsyncWebSocket ws("/ws");

/**
 * @brief AsyncWebSocket object to handle websocket connections 
 */
AsyncWebServer server(80); /// Create a webserver object that listens for HTTP request on port 80

/**
 * @brief Setup function to initiate all the necessary functions to run the machine
 * 
 * This function is responsible for initiating all the necessary functions to run the machine.
 * 
 * @note Initiate all pins as inputs
 * @note Initiate all pins as outputs
 * @note Initiate Serial communication
 * @note Initiate MultiCore
 * @note Initiate SPIFFS
 * @note Read inputs
 * @note Update outputs
 * @note Setup Routes
 * @note Add handler to the server
 * 
 */
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

/**
 * @brief Loop function to run the machine operation 
 * 
 * This function is responsible for running the machine operation.
 * 
 * @note Read inputs 
 * @note Destiler function to operate the machine
 * @note Update outputs
 * 
 * @see readInputs()
 * @see destiler()
 * @see updateOutputsWeb()
 * 
 */
void loop(void)
{
	readInputs();
	destiler(); /// Destiler function to operate the machine
	//updateOutputsWeb();
	writeOutputs();
}

/**
 * @brief Main function to run the second core operation
 * 
 * This function is responsible for running the second core operation.
 * 
 * @note Initiate WIFI
 * @note Cleanup clients 
 * @note WebTimer function
 * 
 * @see initWIFI()
 * @see ws.cleanupClients()
 * @see webTimer()
 * 
 * @param pvParameters 
 */
void loop2(void *pvParameters)
{
	while (1) /// Main loop
	{
		ws.cleanupClients();
		webTimer("*", 0);
		initWIFI();
	}
}