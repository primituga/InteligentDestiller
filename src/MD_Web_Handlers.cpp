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
String handleTimer()
{
  return String(getTimerHour()) + "h :" + String(getTimerMinute()) + "m :" + String(getTimerSecound()) + "s";
}

String handleHour() { return String(getTimerHour()); }
String handleMinute() { return String(getTimerMinute()); }
String handleSecound() { return String(getTimerSecound()); }

////////////////////////////////////////////////////////////////////////////////////////
/// Handlers for Wifi Quality, SSID, TX and IP
////////////////////////////////////////////////////////////////////////////////////////
String handleWifiQuality() { return wifiQuality(); }
String handleWifiSSID() { return WiFi.SSID(); }
String handleWifiTX() { return String(WiFi.getTxPower() + " dBm"); }
String handleWifiIP() { return WiFi.localIP().toString(); }

////////////////////////////////////////////////////////////////////////////////////////
/// Timer Add/Remove Time
////////////////////////////////////////////////////////////////////////////////////////
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
String handleToggle(const String &toggle)
{
  if (toggle == "auto")
    toggleAutoModeWEB();
  else if (toggle == "pump")
    togglePump();
  else if (toggle == "dumpWater")
    toggleValveWaterOut();
  else if (toggle == "waterIn")
    toggleValveWaterIn();
  else if (toggle == "resistor")
    toggleResistor();
  return toggle + " toggled";
}

////////////////////////////////////////////////////////////////////////////////////////
/// Function to handle the HTTP requests for the variables
////////////////////////////////////////////////////////////////////////////////////////
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