/*! \file AP_WEB.cpp */

#include "AP.h"			// Definitions
#include "AP_WebPage_example.h" // WebPage HTML content

WebServer server(80); // Create a webserver object that listens for HTTP request on port 80

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void handleRoot() {
  String MAINPAGE = MAIN_page; //Read HTML contents
  server.send(200, "text/html", MAINPAGE); //Send web page
}
//===============================================================
// Timer handlers
//===============================================================
void handleTimer() {  
  String timer = String(getTimerHour()) + "h :" + String(getTimerMinute()) + "m :" + String(getTimerSecound())+ "s";
  server.send(200, "text/plain", timer); //Send ADC value only to client ajax request
}



void handleAdd1s() {
  add1s();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handleAdd5s() {
  add5s();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}


void handleAdd10s() {
  add10s();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handleAdd1m() {
  add1m();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handleAdd5m() {
  add5m();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handlAadd10m() {
  add10m();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handleRem1s() {
  rem1s();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handlerem5s() {
  rem5s();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handlerem10s() {
  rem10s();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handlerem1m() {
  rem1m();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
} 

void handlerem5m() {
  rem5m();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handlerem10m() {
  rem10m();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

//===============================================================
// Timer Start/Stop/Reset
//===============================================================
void handleTimerStart() {
  setTimer(ON);
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handleTimerStop() {
  setTimer(OFF);
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

void handleTimerReset() {
  resetTimer();
  String timerbuttons = " ";
  server.send(200, "text/plain", timerbuttons); // Send response to client
}

//===============================================================
void handleAuto() {
  String autoMode = String(getAutoMode());
  server.send(200, "text/plain", autoMode); //Send ADC value only to client ajax request
}

void handlePump() {
  String pump = String(getPump());
  server.send(200, "text/plain", pump); //Send ADC value only to client ajax request
}

void handleDumpWater() {
  String dumpWater = String(getValv_Water_Out());
  server.send(200, "text/plain", dumpWater); //Send ADC value only to client ajax request
}

void handleResistor() {
  String resistor = String(getResistor());
  server.send(200, "text/plain", resistor); //Send ADC value only to client ajax request
}

void handleWaterIn() { // Call handleWaterIn() function
  String waterIn = String(getValv_Water_In());
  server.send(200, "text/plain", waterIn); //Send ADC value only to client ajax request
}

void handleWaterMax() { // Call handleWaterIn() function
  String waterMax = String(getWaterMax());
  server.send(200, "text/plain", waterMax); //Send ADC value only to client ajax request
}

void handleWaterMin() { // Call handleWaterIn() function
  String waterMin = String(getWaterMin());
  server.send(200, "text/plain", waterMin); //Send ADC value only to client ajax request
}

void handleWaterAlarm() { // Call handleWaterIn() function
  String waterAlarm = String(getWaterAlarm());
  server.send(200, "text/plain", waterAlarm); //Send ADC value only to client ajax request
}

void handleToggleAuto() {
  toggleAutoModeWEB(); // Call the toggleAutoMode() function
  server.send(200, "text/plain", "Auto mode toggled"); // Send response to client
}

void handleTogglePump() {
  togglePump(); // Call the toggleAutoMode() function
  server.send(200, "text/plain", "Pump toggled"); // Send response to client
}

void handleToggleDumpWater() {
  toggleValveWaterOut(); // Call the toggleAutoMode() function
  server.send(200, "text/plain", "Dump Condensor toggled"); // Send response to client
}

void handleToggleWaterIn() {
  toggleValveWaterIn(); // Call the toggleAutoMode() function
  server.send(200, "text/plain", "Water In toggled"); // Send response to client
}

void handleToggleResistor() {
  sPrintLnStr("toggleResistor");
  toggleResistor(); // Call the toggleAutoMode() function
  server.send(200, "text/plain", "Resistor toggled"); // Send response to client
}

//===============================================================
// Setup Calls
//===============================================================

void setupCalls() {
  server.on("/", handleRoot);  //Which routine to handle at root location. This is display page
  ///////
  server.on("/readTimer", handleTimer); // Call handleTimer() function
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
  server.on("/timerStart", handleTimerStart); // Call handleTimerStart() function
  server.on("/timerStop", handleTimerStop); // Call handleTimerStop() function
  server.on("/timerReset", handleTimerReset); // Call handleTimerReset() function

  server.on("/readAuto", handleAuto);                     // Call handleAuto() function
  server.on("/toggleAuto", handleToggleAuto);             // Call handleToggleAuto() function
  server.on("/readPump", handlePump);                     // Call handlePump() function
  server.on("/togglePump", handleTogglePump);                   // Call handlePump() function
  server.on("/readDumpWater", handleDumpWater);   // Call handleDumpCondensor() function
  server.on("/toggleDumpWater", handleToggleDumpWater); // Call handleDumpCondensor() function
  server.on("/readWaterIn", handleWaterIn);               // Call handleWaterIn() function
  server.on("/toggleWaterIn", handleToggleWaterIn);             // Call handleWaterIn() function
  server.on("/readResistor", handleResistor);             // Call handleResistor() function
  server.on("/toggleResistor", handleToggleResistor);           // Call handleResistor() function
  server.on("/readWaterMax", handleWaterMax);   // Call handleDumpCondensor() function
  server.on("/readWaterMin", handleWaterMin);   // Call handleDumpCondensor() function
  server.on("/readWaterAlarm", handleWaterAlarm);   // Call handleDumpCondensor() function
  server.begin();                                         // Start the HTTP server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void ProcessWebPage() { 
  server.handleClient(); //Handle client requests
  delay(1); // Allow the web server to process the request
}
