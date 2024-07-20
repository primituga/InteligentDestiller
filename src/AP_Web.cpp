/*! \file AP_WEB.cpp */

#include "AP.h" // Definitions

AsyncWebServer server(80); // Create a webserver object that listens for HTTP request on port 80

//********************************************************************************
// Timer handlers
//********************************************************************************
String handleTimer()
{
  return String(getTimerHour()) + "h :" + String(getTimerMinute()) + "m :" + String(getTimerSecound()) + "s";
}

String handleHour() { return String(getTimerHour()); }
String handleMinute() { return String(getTimerMinute()); }
String handleSecound() { return String(getTimerSecound()); }

//************************************************************************************************
// Handlers for Wifi Quality, SSID, TX and IP
//************************************************************************************************
String handleWifiQuality() { return wifiQuality(); }
String handleWifiSSID() { return WiFi.SSID(); }
String handleWifiTX() { return String(WiFi.getTxPower() + " dBm"); }
String handleWifiIP() { return WiFi.localIP().toString(); }

//********************************************************************************
// Timer Add/Remove Time
//********************************************************************************
String handleTimeAdjust(const String &adjustment)
{
  if (adjustment == "add1s") add1s();
  else if (adjustment == "add5s") add5s();
  else if (adjustment == "add10s") add10s();
  else if (adjustment == "add1m") add1m();
  else if (adjustment == "add5m") add5m();
  else if (adjustment == "add10m") add10m();
  else if (adjustment == "rem1s") rem1s();
  else if (adjustment == "rem5s") rem5s();
  else if (adjustment == "rem10s") rem10s();
  else if (adjustment == "rem1m") rem1m();
  else if (adjustment == "rem5m") rem5m();
  else if (adjustment == "rem10m") rem10m();
  return adjustment;
}

//********************************************************************************
// Timer Start/Stop/Reset
//********************************************************************************
String handleTimerControl(const String &control)
{
  if (control == "start") setTimer(ON);
  else if (control == "stop") setTimer(OFF);
  else if (control == "reset") resetTimer();
  return "Timer " + control;
}

//************************************************************************************************
// Handlers for Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax With Response
//************************************************************************************************
String handleState(const String &state)
{
  if (state == "auto") return String(getAutoMode());
  else if (state == "manual") return String(getManualMode());
  else if (state == "pump") return String(getPump());
  else if (state == "dumpWater") return String(getValv_Water_Out());
  else if (state == "resistor") return String(getResistor());
  else if (state == "waterIn") return String(getValv_Water_In());
  else if (state == "waterMax") return String(getWaterMax());
  else if (state == "waterMin") return String(getWaterMin());
  else if (state == "waterAlarm") return String(getWaterAlarm());
  return String();
}

//********************************************************************************
// Handlers for Toggle Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax
//********************************************************************************
String handleToggle(const String &toggle)
{
  if (toggle == "auto") toggleAutoModeWEB();
  else if (toggle == "pump") togglePump();
  else if (toggle == "dumpWater") toggleValveWaterOut();
  else if (toggle == "waterIn") toggleValveWaterIn();
  else if (toggle == "resistor") toggleResistor();
  return toggle + " toggled";
}

//********************************************************************************
// Function to handle the HTTP requests for the variables
//********************************************************************************
String processor(const String &var)
{
  if (var == "TIMER") return handleTimer();
  if (var == "WATERMAX") return handleState("waterMax");
  if (var == "WATERMIN") return handleState("waterMin");
  if (var == "WATERALARM") return handleState("waterAlarm");
  if (var == "AUTO") return handleState("auto");
  if (var == "MANUAL") return handleState("manual");
  if (var == "PUMP") return handleState("pump");
  if (var == "DUMPWATER") return handleState("dumpWater");
  if (var == "RESISTOR") return handleState("resistor");
  if (var == "WATERIN") return handleState("waterIn");
  if (var == "WIFIQUALITY") return handleWifiQuality();
  if (var == "WIFISSID") return handleWifiSSID();
  if (var == "WIFITX") return handleWifiTX();
  if (var == "WIFIIP") return handleWifiIP();
  if (var == "TIMERHOUR") return handleHour();
  if (var == "TIMERMINUTE") return handleMinute();
  if (var == "TIMERSECOUND") return handleSecound();
  return String(); // Return nothing
}

//********************************************************************************
// Setup Calls
//********************************************************************************
void setupCalls()
{
  //////////////////////////////////////////////////////////////
  // Route for root / and index_webButtons.html
  //////////////////////////////////////////////////////////////
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", String(), false, processor); });

  server.on("/index_2.html", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/web_2/index_2.html", String(), false, processor); });

  //////////////////////////////////////////////////////////////
  // Route for CSS files
  //////////////////////////////////////////////////////////////
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style.css", "text/css"); });

  server.on("/style_2.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/web_2/style2.css", "text/css"); });

  server.on("/style_Img.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style_Img.css", "text/css"); });

  //////////////////////////////////////////////////////////////
  // Route JS files
  //////////////////////////////////////////////////////////////
  server.on("/script_actions.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_actions.js", "text/javascript"); });

  server.on("/script_get_Data.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_get_Data.js", "text/javascript"); });

  server.on("/script_timers.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_timers.js", "text/javascript"); });

  server.on("/script_timers_Img.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_timers_Img.js", "text/javascript"); });

  server.on("/script_timers_2.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/web_2/script_timers_2.js", "text/javascript"); });

  //////////////////////////////////////////////////////////////
  // Route for image files
  //////////////////////////////////////////////////////////////
  server.on("/icon.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/icon.png", "image/png"); });

  server.on("/estg_logo.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/estg_logo.png", "image/png"); });

  server.on("/bg.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/bg.png", "image/png"); });

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

  server.on("/sMin.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/sMin.png", "image/png"); });

  server.on("/sMax.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/sMax.png", "image/png"); });

  server.on("/sAlarm.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/sAlarm.png", "image/png"); });

  server.on("/button_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/button_ON.png", "image/png"); });

  server.on("/button_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/button_OFF.png", "image/png"); });

  //////////////////////////////////////////////////////////////
  // Routes for handling time adjustments
  //////////////////////////////////////////////////////////////
  server.on("/add1s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add1s").c_str()); });

  server.on("/add5s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add5s").c_str()); });

  server.on("/add10s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add10s").c_str()); });

  server.on("/add1m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add1m").c_str()); });

  server.on("/add5m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add5m").c_str()); });

  server.on("/add10m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add10m").c_str()); });

  server.on("/rem1s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem1s").c_str()); });

  server.on("/rem5s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem5s").c_str()); });

  server.on("/rem10s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem10s").c_str()); });

  server.on("/rem1m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem1m").c_str()); });

  server.on("/rem5m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem5m").c_str()); });

  server.on("/rem10m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem10m").c_str()); });

  //////////////////////////////////////////////////////////////
  // Routes for handling timer control
  //////////////////////////////////////////////////////////////
  server.on("/startTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerControl("start").c_str()); });

  server.on("/stopTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerControl("stop").c_str()); });

  server.on("/resetTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerControl("reset").c_str()); });

  //////////////////////////////////////////////////////////////
  // Routes for handling toggle actions
  //////////////////////////////////////////////////////////////
  server.on("/toggleAuto", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("auto").c_str()); });

  server.on("/togglePump", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("pump").c_str()); });

  server.on("/toggleDumpWater", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("dumpWater").c_str()); });

  server.on("/toggleWaterIn", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("waterIn").c_str()); });

  server.on("/toggleResistor", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("resistor").c_str()); });

  //////////////////////////////////////////////////////////////
  // Routes for handling state actions
  //////////////////////////////////////////////////////////////
  server.on("/readAutoMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("auto").c_str()); });

  server.on("/readManualMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("manual").c_str()); });

  server.on("/readPump", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("pump").c_str()); });

  server.on("/readDumpWater", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("dumpWater").c_str()); });

  server.on("/readResistor", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("resistor").c_str()); });

  server.on("/readWaterIn", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterIn").c_str()); });

  server.on("/readWaterMax", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterMax").c_str()); });

  server.on("/readWaterMin", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterMin").c_str()); });

  server.on("/readWaterAlarm", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterAlarm").c_str()); });

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
  // Start Server
  //////////////////////////////////////////////////////////////
  server.begin();
}
