/*! \file AP_WEB.cpp */

#include "AP.h" // Definitions

AsyncWebServer server(80); // Create a webserver object that listens for HTTP request on port 80

//********************************************************************************
// Timer handlers
//********************************************************************************
String handleTimer()
{
  String t = String(getTimerHour()) + "h :" + String(getTimerMinute()) + "m :" + String(getTimerSecound()) + "s"; // Read timer
  return String(t);
}

String handleHour()
{
  String hour = String(getTimerHour()); // Read timer
  return String(hour);
}

String handleMinute()
{
  String minute = String(getTimerMinute()); // Read timer
  return String(minute);
}

String handleSecound()
{
  String secound = String(getTimerSecound()); // Read timer
  return String(secound);
}

//************************************************************************************************
// Handlers for Wifi Quality, SSID, TX and IP
//************************************************************************************************
String handleWifiQuality()
{
  String _wifiQuality = wifiQuality();
  return String(_wifiQuality);
}

String handleWifiSSID()
{
  String _wifiSSID = WiFi.SSID();
  return String(_wifiSSID);
}

String handleWifiTX()
{
  String _wifiTX = String(WiFi.getTxPower() + " dBm");
  return String(_wifiTX);
}

String handleWifiIP()
{
  String _wifiIP = String(WiFi.localIP().toString().c_str());
  return String(_wifiIP);
}

//********************************************************************************
// Timer Add/Remove Time
//********************************************************************************
String handleAdd1s()
{
  String t = "add1s";
  add1s(); // Call add1s() function
  return String(t);
}

String handleAdd5s()
{
  String t = "add15s";
  add5s();
  return String(t);
}

String handleAdd10s()
{
  String t = "add10s";
  add10s();
  return String(t);
}

String handleAdd1m()
{
  String t = "add1m";
  add1m();
  return String(t);
}

String handleAdd5m()
{
  String t = "add5m";
  add5m();
  return String(t);
}

String handlAadd10m()
{
  String t = "add10m";
  add10m();
  return String(t);
}

String handleRem1s()
{
  String t = "rem1s";
  rem1s();
  return String(t);
}

String handlerem5s()
{
  String t = "rem5s";
  rem5s();
  return String(t);
}

String handlerem10s()
{
  String t = "rem10s";
  rem10s();
  return String(t);
}

String handlerem1m()
{
  String t = "rem1m";
  rem1m();
  return String(t);
}

String handlerem5m()
{
  String t = "rem5m";
  rem5m();
  return String(t);
}

String handlerem10m()
{
  String t = "rem10m";
  rem10m();
  return String(t);
}

//********************************************************************************
// Timer Start/Stop/Reset
//********************************************************************************
String handleTimerStart()
{
  String t = "Timer Start";
  setTimer(ON);
  return String(t);
}

String handleTimerStop()
{
  String t = "Timer Stop";
  setTimer(OFF);
  return String(t);
}

String handleTimerReset()
{
  String t = "Timer Reset";
  resetTimer();
  return String(t);
}

//************************************************************************************************
// Handlers for Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax With Response
//************************************************************************************************
String handleAuto()
{
  String autoMode = String(getAutoMode());
  return String(autoMode);
}

String handleManual()
{
  String manualMode = String(getManualMode());
  return String(manualMode);
}

String handlePump()
{
  String pump = String(getPump());
  return String(pump);
}

String handleDumpWater()
{
  String dumpWater = String(getValv_Water_Out());
  return String(dumpWater);
}

String handleResistor()
{
  String resistor = String(getResistor());
  return String(resistor);
}

String handleWaterIn()
{
  String waterIn = String(getValv_Water_In());
  return String(waterIn);
}

String handleWaterMax()
{
  String waterMax = String(getWaterMax());
  return String(waterMax);
}

String handleWaterMin()
{
  String waterMin = String(getWaterMin());
  return String(waterMin);
}

String handleWaterAlarm()
{
  String waterAlarm = String(getWaterAlarm());
  return String(waterAlarm);
}

//********************************************************************************
// Handlers for Toggle Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax
//********************************************************************************
String handleToggleAuto()
{
  String t = "Auto mode toggled";
  toggleAutoModeWEB();
  return String(t);
}

String handleTogglePump()
{
  String t = "Pump toggled";
  togglePump();
  return String(t);
}

String handleToggleDumpWater()
{
  String t = "Dump Condensor toggled";
  toggleValveWaterOut();
  return String(t);
}

String handleToggleWaterIn()
{
  String t = "Water In toggled";
  toggleValveWaterIn();
  return String(t);
}

String handleToggleResistor()
{
  String t = "Resistor toggled";
  toggleResistor();
  return String(t);
}

//////////////////////////////////////////////////////////////
// Function to handle the HTTP requests for the variables
//////////////////////////////////////////////////////////////
String processor(const String &var)
{
  // Serial.println(var);
  if (var == "TIMER")
  {
    return handleTimer();
  } // Read Timer
  else if (var == "WATERMAX")
  {
    return String(handleWaterMax());
  } // Read WaterMax
  else if (var == "WATERMIN")
  {
    return String(handleWaterMin());
  } // Read WaterMin
  else if (var == "WATERALARM")
  {
    return String(handleWaterAlarm());
  } // Read WaterAlarm
  else if (var == "WIFIQUALITY")
  {
    return handleWifiQuality();
  } // Read Wifi Quality
  else if (var == "WIFISSID")
  {
    return handleWifiSSID();
  } // Read Wifi SSID
  else if (var == "WIFITX")
  {
    return handleWifiTX();
  } // Read Wifi TX
  else if (var == "WIFIIP")
  {
    return handleWifiIP();
  } // Read Wifi IP
  else if (var == "AUTO")
  {
    return handleAuto();
  } // Read Auto
  else if (var == "MANUAL")
  {
    return handleManual();
  } // Read Manual
  else if (var == "PUMP")
  {
    return handlePump();
  } // Read Pump
  else if (var == "DUMPWATER")
  {
    return handleDumpWater();
  } // Read DumpWater
  else if (var == "RESISTOR")
  {
    return handleResistor();
  } // Read Resistor
  else if (var == "WATERIN")
  {
    return handleWaterIn();
  } // Read WaterIn
  else if (var == "TIMERHOUR")
  {
    return handleHour();
  } // Read Timer Hour
  else if (var == "TIMERMINUTE")
  {
    return handleMinute();
  } // Read Timer Minute
  else if (var == "TIMERSECOUND")
  {
    return handleSecound();
  } // Read Timer Secound

  return String(); // Return nothing
}

//********************************************************************************
// Setup Calls
//********************************************************************************
void setupCalls()
{
  //////////////////////////////////////////////////////////////
  // Route for root / web page, JS and CSS
  //////////////////////////////////////////////////////////////
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", String(), false, processor); });

  server.on("/script_actions.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_actions.js", "text/javascript"); });

  server.on("/script_get_Data.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_get_Data.js", "text/javascript"); });

  server.on("/script_timers.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_timers.js", "text/javascript"); });

  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style.css", "text/css"); });

  //////////////////////////////////////////////////////////////
  // Route for image files
  //////////////////////////////////////////////////////////////
  server.on("/icon.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/icon.png", "image/png"); });

  server.on("/estg_logo.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/estg_logo.png", "image/png"); });

  server.on("/destiller.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/destiller.png", "image/png"); });

  server.on("/BMB_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/BMB_ON.png", "image/png"); });

  server.on("/BMB_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/BMB_OFF.png", "image/png"); });

  server.on("/RAQ_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/RAQ_ON.png", "image/png"); });

  server.on("/RAQ_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/RAQ_OFF.png", "image/png"); });

  server.on("/Valve_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Valve_ON.png", "image/png"); });

  server.on("/Valve_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Valve_OFF.png", "image/png"); });

  server.on("/Auto_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Auto_ON.png", "image/png"); });

  server.on("/Auto_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Auto_OFF.png", "image/png"); });

  server.on("/Man_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Man_ON.png", "image/png"); });

  server.on("/Man_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Man_OFF.png", "image/png"); });

  //////////////////////////////////////////////////////////////
  // Route for sensors Handlers
  //////////////////////////////////////////////////////////////
  server.on("/readWaterMax", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWaterMax().c_str()); });

  server.on("/readWaterMin", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWaterMin().c_str()); });

  server.on("/readWaterAlarm", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWaterAlarm().c_str()); });

  //////////////////////////////////////////////////////////////
  // Route for WiFi Handlers
  //////////////////////////////////////////////////////////////
  server.on("/readWifiQuality", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiQuality().c_str()); });

  server.on("/readWifiSSID", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiSSID().c_str()); });

  server.on("/readWifiTX", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiTX().c_str()); });

  server.on("/readWifiIP", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiIP().c_str()); });

  //////////////////////////////////////////////////////////////
  // Route for Timer Handlers
  //////////////////////////////////////////////////////////////
  server.on("/readTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimer().c_str()); });

  server.on("/readHour", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleHour().c_str()); });

  server.on("/readMinute", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleMinute().c_str()); });

  server.on("/readSecound", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleSecound().c_str()); });

  //////////////////////////////////////////////////////////////
  // Route for Timer Start/Stop/Reset Handlers
  //////////////////////////////////////////////////////////////
  server.on("/startTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerStart().c_str()); });

  server.on("/stopTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerStop().c_str()); });

  server.on("/resetTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerReset().c_str()); });

  //////////////////////////////////////////////////////////////
  // Route for Add/Remove Time Handlers
  //////////////////////////////////////////////////////////////
  server.on("/add1s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleAdd1s().c_str()); });

  server.on("/add5s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleAdd5s().c_str()); });

  server.on("/add10s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleAdd10s().c_str()); });

  server.on("/add1m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleAdd1m().c_str()); });

  server.on("/add5m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleAdd5m().c_str()); });

  server.on("/add10m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlAadd10m().c_str()); });

  server.on("/rem1s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleRem1s().c_str()); });

  server.on("/rem5s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlerem5s().c_str()); });

  server.on("/rem10s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlerem10s().c_str()); });

  server.on("/rem1m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlerem1m().c_str()); });

  server.on("/rem5m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlerem5m().c_str()); });

  server.on("/rem10m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlerem10m().c_str()); });

  //////////////////////////////////////////////////////////////
  // Route for Toggle Handlers
  //////////////////////////////////////////////////////////////
  server.on("/togglePump", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTogglePump().c_str()); });

  server.on("/toggleDumpWater", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggleDumpWater().c_str()); });

  server.on("/toggleWaterIn", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggleWaterIn().c_str()); });

  server.on("/toggleResistor", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggleResistor().c_str()); });

  server.on("/toggleAutoMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggleAuto().c_str()); });

  //////////////////////////////////////////////////////////////
  // Route for Read Handlers
  //////////////////////////////////////////////////////////////
  server.on("/readAutoMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleAuto().c_str()); });

  server.on("/readManualMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleManual().c_str()); });

  server.on("/readPump", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handlePump().c_str()); });

  server.on("/readDumpWater", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleDumpWater().c_str()); });

  server.on("/readResistor", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleResistor().c_str()); });

  server.on("/readWaterIn", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWaterIn().c_str()); });

  server.begin(); // Start the HTTP server
  Serial.println("HTTP server started");
}
