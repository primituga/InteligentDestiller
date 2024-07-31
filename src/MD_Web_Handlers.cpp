/**
 * @author Sérgio Carmo
 * @file MD_Web_Handlers.cpp
 * @brief Web Handlers for the MD project
 * @version 1.0
 */
#include "MD.h" /// Definitions

////////////////////////////////////////////////////////////////////////////////////////
/// Timer handlers
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle Timer
 * @return String
 * @note This function handles the timer
 * @note This function returns the timer in the format HH:MM:SS
 */
String handleTimer()
{
  return String(getTimerHour()) + "h :" + String(getTimerMinute()) + "m :" + String(getTimerSecound()) + "s";
}
/**
 * @brief Handle Hour
 * @return String
 * @note This function returns the timer hour
 */
String handleHour() { return String(getTimerHour()); }
/**
 * @brief Handle Minute
 * @return String
 * @note This function returns the timer minute
 */
String handleMinute() { return String(getTimerMinute()); }
/**
 * @brief Handle Secound
 * @return String
 * @note This function returns the timer secound
 */
String handleSecound() { return String(getTimerSecound()); }

////////////////////////////////////////////////////////////////////////////////////////
/// Handlers for Wifi Quality, SSID, TX and IP
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle Wifi Quality
 * @return String
 * @note This function returns the WiFi quality in percentage
 */
String handleWifiQuality() { return wifiQuality(); }
/**
 * @brief Handle Wifi SSID
 * @return String
 * @note This function returns the WiFi SSID
 */
String handleWifiSSID() { return WiFi.SSID(); }
/**
 * @brief Handle Wifi TX
 * @return String
 * @note This function returns the WiFi TX power
 */
String handleWifiTX() { return String(WiFi.getTxPower() + " dBm"); }
/**
 * @brief Handle Wifi IP
 * @return String
 * @note This function returns the WiFi IP address
 */
String handleWifiIP() { return WiFi.localIP().toString(); }

////////////////////////////////////////////////////////////////////////////////////////
/// Timer Add/Remove Time
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle Time Adjust
 * @param adjustment
 * @return String
 * @note This function adjusts the timer
 * @note This function returns the adjustment message for the timer (add1s, add5s, add10s, add1m, add5m, add10m, rem1s, rem5s, rem10s, rem1m, rem5m, rem10m)
 */
String handleTimeAdjust(const String &adjustment)
{
  if (adjustment == "add1s")
    add1s();
  else if (adjustment == "add5s")
    add5s();
  else if (adjustment == "add10s")
    add10s();
  else if (adjustment == "add1m")
    add1m();
  else if (adjustment == "add5m")
    add5m();
  else if (adjustment == "add10m")
    add10m();
  else if (adjustment == "rem1s")
    rem1s();
  else if (adjustment == "rem5s")
    rem5s();
  else if (adjustment == "rem10s")
    rem10s();
  else if (adjustment == "rem1m")
    rem1m();
  else if (adjustment == "rem5m")
    rem5m();
  else if (adjustment == "rem10m")
    rem10m();
  return adjustment;
}

////////////////////////////////////////////////////////////////////////////////////////
/// Timer Start/Stop/Reset
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle Timer Control
 * @param control
 * @return String
 * @note This function controls the timer
 * @note This function returns the control message for the timer (start, stop, reset)
 */
String handleTimerControl(const String &control)
{
  if (control == "start")
    setTimer(ON);
  else if (control == "stop")
    setTimer(OFF);
  else if (control == "reset")
    resetTimer();
  return "Timer " + control;
}

////////////////////////////////////////////////////////////////////////////////////////
/// Handlers for Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax With Response
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle State
 * @param state
 * @return String 
 * @note This function handles the state of the variable (auto, manual, pump, dumpWater, resistor, waterIn, waterMax, waterMin, waterAlarm)
 * @note This function returns the state of the variable (auto, manual, pump, dumpWater, resistor, waterIn, waterMax, waterMin, waterAlarm)
 */
String handleState(const String &state)
{
  if (state == "auto")
    return String(getAutoMode());
  else if (state == "manual")
    return String(getManualMode());
  else if (state == "pump")
    return String(getPump());
  else if (state == "dumpWater")
    return String(getValv_Water_Out());
  else if (state == "resistor")
    return String(getResistor());
  else if (state == "waterIn")
    return String(getValv_Water_In());
  else if (state == "waterMax")
    return String(getWaterMax());
  else if (state == "waterMin")
    return String(getWaterMin());
  else if (state == "waterAlarm")
    return String(getAlarm());
  return String();
}

////////////////////////////////////////////////////////////////////////////////////////
/// Handlers for Toggle Auto, Pump, DumpWater, Resistor, WaterIn and WaterMax
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle Toggle
 * @param toggle
 * @return String
 * @note This function toggles the variable (auto, pump, dumpWater, resistor, waterIn)
 * @note This function returns the toggle message for the variable (auto, pump, dumpWater, resistor, waterIn)
 */
String handleToggle(const String &toggle)
{
  if (toggle == "auto")
    toggleAutoModeWeb();
  else if (toggle == "pump")
    togglePumpWeb();
  else if (toggle == "dumpWater")
    toggleValveWaterOutWeb();
  else if (toggle == "waterIn")
    toggleValveWaterInWeb();
  else if (toggle == "resistor")
    toggleResistorWeb();
  return toggle + " toggled";
}

////////////////////////////////////////////////////////////////////////////////////////
/// Function to handle the HTTP requests for the variables
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Processor
 * @param var
 * @return String
 * @note This function processes the variables for the web server requests
 * @note This function is called by the web server handle function (server.on)
 * @note This function returns the variable value for the web server request 
 */
String processor(const String &var)
{
  if (var == "TIMER")
    return handleTimer();
  if (var == "WATERMAX")
    return handleState("waterMax");
  if (var == "WATERMIN")
    return handleState("waterMin");
  if (var == "WATERALARM")
    return handleState("waterAlarm");
  if (var == "AUTO")
    return handleState("auto");
  if (var == "MANUAL")
    return handleState("manual");
  if (var == "PUMP")
    return handleState("pump");
  if (var == "DUMPWATER")
    return handleState("dumpWater");
  if (var == "RESISTOR")
    return handleState("resistor");
  if (var == "WATERIN")
    return handleState("waterIn");
  if (var == "WIFIQUALITY")
    return handleWifiQuality();
  if (var == "WIFISSID")
    return handleWifiSSID();
  if (var == "WIFITX")
    return handleWifiTX();
  if (var == "WIFIIP")
    return handleWifiIP();
  if (var == "TIMERHOUR")
    return handleHour();
  if (var == "TIMERMINUTE")
    return handleMinute();
  if (var == "TIMERSECOUND")
    return handleSecound();
  return String(); /// Return nothing
}