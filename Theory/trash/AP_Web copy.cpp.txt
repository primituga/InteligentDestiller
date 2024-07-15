/*! \file AP_WEB.cpp */

#include "AP.h"			// Definitions
#include "AP_Web.h" // WebPage HTML content

WebServer server(80); // Create a webserver object that listens for HTTP request on port 80

//********************************************************************************
// This routine is executed when you open its IP in browser
//********************************************************************************
void handleRoot() {
  String MAINPAGE = MAIN_page;                  //Read HTML contents
  server.send(200, "text/html", MAINPAGE);      //Send web page
}
//********************************************************************************
// Timer handlers
//********************************************************************************
void handleTimer() {  
  String timer = String(getTimerHour()) + "h :" + String(getTimerMinute()) + "m :" + String(getTimerSecound())+ "s";  // Read timer
  server.send(200, "text/plain", timer);        // Send response to client
}

void handleHour() {  
  String hour = String(getTimerHour());  // Read timer
  server.send(200, "text/plain", hour);        // Send response to client
}

void handleMinute() {  
  String minute = String(getTimerMinute());  // Read timer
  server.send(200, "text/plain", minute);        // Send response to client
}

void handleSecound() {  
  String secound = String(getTimerSecound());  // Read timer
  server.send(200, "text/plain", secound);        // Send response to client
}

//************************************************************************************************
// Handlers for Wifi Quality, SSID, TX and IP
//************************************************************************************************
void handleWifiQuality() {
  String _wifiQuality = wifiQuality(); 
  server.send(200, "text/plain", _wifiQuality);
}

void handleWifiSSID() {
  String _wifiSSID = WiFi.SSID(); 
  server.send(200, "text/plain", _wifiSSID);
}

void handleWifiTX() {
  String _wifiTX = String(WiFi.getTxPower() + " dBm"); 
  server.send(200, "text/plain", _wifiTX);
}

void handleWifiIP() {
  String _wifiIP = String(WiFi.localIP().toString().c_str()); 
  server.send(200, "text/plain", _wifiIP);
}

//********************************************************************************
// Timer Add/Remove Time
//********************************************************************************
void handleAdd1s() {
  add1s();                                      // Call add1s() function
  server.send(200, "text/plain", "1 sec added"); // Send response to client
}

void handleAdd5s() {
  add5s();
  server.send(200, "text/plain", "5 sec added"); // Send response to client
}


void handleAdd10s() {
  add10s();
  server.send(200, "text/plain", "10 sec added"); // Send response to client
}

void handleAdd1m() {
  add1m();
  server.send(200, "text/plain", "1 min added"); // Send response to client
}

void handleAdd5m() {
  add5m();
  server.send(200, "text/plain", "5 min added"); // Send response to client
}

void handlAadd10m() {
  add10m();
  server.send(200, "text/plain", "10 min added"); // Send response to client
}

void handleRem1s() {
  rem1s();
  server.send(200, "text/plain", "1 sec removed"); // Send response to client
}

void handlerem5s() {
  rem5s();
  server.send(200, "text/plain", "5 sec removed"); // Send response to client
}

void handlerem10s() {
  rem10s();
  server.send(200, "text/plain", "10 sec removed"); // Send response to client
}

void handlerem1m() {
  rem1m();
  server.send(200, "text/plain", "1 min removed"); // Send response to client
} 

void handlerem5m() {
  rem5m();
  server.send(200, "text/plain", "5 min removed"); // Send response to client
}

void handlerem10m() {
  rem10m();
  server.send(200, "text/plain", "10 min removed"); // Send response to client
}

//********************************************************************************
// Timer Start/Stop/Reset
//********************************************************************************
void handleTimerStart() {
  setTimer(ON);
  server.send(200, "text/plain", "Start timer"); // Send response to client
}

void handleTimerStop() {
  setTimer(OFF);
  server.send(200, "text/plain", "Stop timer"); // Send response to client
}

void handleTimerReset() {
  resetTimer();
  server.send(200, "text/plain", "Reset timer"); // Send response to client
}

//************************************************************************************************
// Handlers for Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax With Response
//************************************************************************************************
void handleAuto() {
  String autoMode = String(getAutoMode());    // Read auto mode status
  server.send(200, "text/plain", autoMode);   // Send auto mode status to client
}

void handlePump() {
  String pump = String(getPump());            // Read pump status
  server.send(200, "text/plain", pump);       // Send pump status to client
}

void handleDumpWater() {
  String dumpWater = String(getValv_Water_Out());
  server.send(200, "text/plain", dumpWater); 
}

void handleResistor() {
  String resistor = String(getResistor());
  server.send(200, "text/plain", resistor);
}

void handleWaterIn() { // Call handleWaterIn() function
  String waterIn = String(getValv_Water_In());
  server.send(200, "text/plain", waterIn);
}

void handleWaterMax() {   
  String waterMax = String(getWaterMax());
  server.send(200, "text/plain", waterMax);
}

void handleWaterMin() {   
  String waterMin = String(getWaterMin());
  server.send(200, "text/plain", waterMin); 
}

void handleWaterAlarm() {   
  String waterAlarm = String(getWaterAlarm());
  server.send(200, "text/plain", waterAlarm); 
}

//********************************************************************************
// Handlers for Toggle Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax
//********************************************************************************


void handleToggleAuto() {
  toggleAutoModeWEB();  
  server.send(200, "text/plain", "Auto mode toggled");    // Send response to client
}

void handleTogglePump() {
  togglePump();   
  server.send(200, "text/plain", "Pump toggled");         // Send response to client
}

void handleToggleDumpWater() {
  toggleValveWaterOut();  
  server.send(200, "text/plain", "Dump Condensor toggled"); // Send response to client
}

void handleToggleWaterIn() {
  toggleValveWaterIn();   
  server.send(200, "text/plain", "Water In toggled");     // Send response to client
}

void handleToggleResistor() {
  sPrintLnStr("toggleResistor");
  toggleResistor();   
  server.send(200, "text/plain", "Resistor toggled");     // Send response to client
}

//********************************************************************************
// Setup Calls
//********************************************************************************

void setupCalls() {
  server.on("/", handleRoot);                             //Which routine to handle at root location. This is display page
  ///////
  server.on("/readTimer", handleTimer);                   // Call handleTimer() function
  server.on("/readHour", handleHour);                     // Call handleHour() function
  server.on("/readMinute", handleMinute);                 // Call handleMinute() function
  server.on("/readSecound", handleSecound);               // Call handleSecound() function
  ///////
  server.on("/readWifiQuality", handleWifiQuality);       // Call handleWifiQuality() function
  server.on("/readWifiSSID", handleWifiSSID);             // Call handleWifiSSID() function
  server.on("/readWifiTX", handleWifiTX);                 // Call handleWifiTX() function
  server.on("/readWifiIP", handleWifiIP);                 // Call handleWifiIP() function
  ///////
  server.on("/add1s", handleAdd1s);
  server.on("/add5s", handleAdd5s);
  server.on("/add10s", handleAdd10s);
  server.on("/add1m", handleAdd1m);
  server.on("/add5m", handleAdd5m);
  server.on("/add10m", handlAadd10m);
  ///////
  server.on("/rem1s",  handleRem1s);
  server.on("/rem5s",  handlerem5s);
  server.on("/rem10s", handlerem10s);
  server.on("/rem1m",  handlerem1m);
  server.on("/rem5m",  handlerem5m);
  server.on("/rem10m", handlerem10m); 
  ///////
  server.on("/timerStart", handleTimerStart);             // Call handleTimerStart() function
  server.on("/timerStop", handleTimerStop);               // Call handleTimerStop() function
  server.on("/timerReset", handleTimerReset);             // Call handleTimerReset() function

  server.on("/readAuto", handleAuto);                     // Call handleAuto() function
  server.on("/toggleAuto", handleToggleAuto);             // Call handleToggleAuto() function
  server.on("/readPump", handlePump);                     // Call handlePump() function
  server.on("/togglePump", handleTogglePump);             // Call handlePump() function
  server.on("/readDumpWater", handleDumpWater);           // Call handleDumpCondensor() function
  server.on("/toggleDumpWater", handleToggleDumpWater);   // Call handleDumpCondensor() function
  server.on("/readWaterIn", handleWaterIn);               // Call handleWaterIn() function
  server.on("/toggleWaterIn", handleToggleWaterIn);       // Call handleWaterIn() function
  server.on("/readResistor", handleResistor);             // Call handleResistor() function
  server.on("/toggleResistor", handleToggleResistor);     // Call handleResistor() function
  server.on("/readWaterMax", handleWaterMax);             // Call handleDumpCondensor() function
  server.on("/readWaterMin", handleWaterMin);             // Call handleDumpCondensor() function
  server.on("/readWaterAlarm", handleWaterAlarm);         // Call handleDumpCondensor() function
  server.begin();                                         // Start the HTTP server
  Serial.println("HTTP server started");
}

//********************************************************************************
// This routine is executed when you open its IP in browser
//********************************************************************************
void ProcessWebPage() { 
  server.handleClient();                                  //Handle client requests
  delay(1);                                               // Allow the web server to process the request
}
