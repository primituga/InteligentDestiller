/*! \file AP_WEB.cpp */

#include "AP.h"			// Definitions
#include "AP_WebPage_example.h" // WebPage HTML content

WebServer server(80);

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
 String MAINPAGE = MAIN_page; //Read HTML contents
 server.send(200, "text/html", MAINPAGE); //Send web page
}
 
void handleAuto() {

  String autoMode = String(getAutoMode());

  server.send(200, "text/plane", autoMode); //Send ADC value only to client ajax request
}

void handleResistor() {

  String resistor = String(getResistor());

  server.send(200, "text/plane", resistor); //Send ADC value only to client ajax request
}

// Add a new handler function to toggle the auto mode
void handleToggleAuto() {
  toggleAutoMode();
  server.send(200, "text/plain", "Auto mode toggled"); // Send response to client
}

//===============================================================
// Setup
//===============================================================

void setuped(){

  server.on("/", handleRoot);      //This is display page
  server.on("/readAuto", handleAuto);//To get update of ADC Value only
  server.on("/readResistor", handleResistor);//To get update of ADC Value only
  server.on("/toggleAuto", handleToggleAuto); // Map the new handler to the "/toggleAuto" URL
  
 
  server.begin();                  //Start server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void ProcessWebPage(){
  server.handleClient();
  delay(1);
}



