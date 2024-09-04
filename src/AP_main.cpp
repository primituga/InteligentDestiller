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
	initSerial();	   /// Initiate Serial communication (9600 bps)
	test_IO();			/// Test IO
	initMultiCore();		/// Initiate MultiCore (Second Core)
	initFS();				/// Initiate SPIFFS (SPI Flash File System)
	readInputs();			/// Read inputs for the first time
	updateOutputsWeb();		/// Update outputs for the web interface
	initWIFI();				/// Initiate WIFI
	setupRoutes();			/// Setup Routes
	server.addHandler(&ws); /// Add handler to the server (Websocket)
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
	// updateOutputsWeb(); /// Update outputs for the web interface
	destiler();		/// Destiler function to operate the machine
	writeOutputs(); /// Update outputs
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
		ws.cleanupClients(); /// Cleanup clients
		webTimer("*", 0);	 /// WebTimer function
		resetWiFi(); 		 /// Reset WiFi
	}
}