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

void handleResistor() {
  String resistor = String(getResistor());
  server.send(200, "text/plain", resistor); //Send ADC value only to client ajax request
}

void handleToggleAuto() {
  toggleAutoModeWEB(); // Call the toggleAutoMode() function
  Serial.println("handleToggleAuto");
  server.send(200, "text/plain", "Auto mode toggled"); // Send response to client
}


//===============================================================
// Setup Calls
//===============================================================

void setupCalls() {
  server.on("/", handleRoot);      // This is display page
  ///////
  server.on("/readTimer", handleTimer);
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
  server.on("/timerStart", handleTimerStart);
  server.on("/timerStop", handleTimerStop);
  server.on("/timerReset", handleTimerReset);

  server.on("/readAuto", handleAuto);
  server.on("/readResistor", handleResistor); // Call handleResistor() function
  server.on("/toggleAuto", handleToggleAuto); // Call toggleAutoMode() function
  server.begin();                  // Start server
  Serial.println("HTTP server started");
}

//===============================================================
// This routine is executed when you open its IP in browser
//===============================================================
void ProcessWebPage() {
  server.handleClient();
  delay(1);
}
