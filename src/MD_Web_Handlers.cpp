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
  /// Adjust the timer based on the adjustment parameter
  if (adjustment == "add1s") /// Add 1 secound to timer
    add1s();
  else if (adjustment == "add5s") /// Add 5 secounds to timer
    add5s();
  else if (adjustment == "add10s") /// Add 10 secounds to timer
    add10s();
  else if (adjustment == "add1m") /// Add 1 minute to timer
    add1m();
  else if (adjustment == "add5m") /// Add 5 minutes to timer
    add5m();
  else if (adjustment == "add10m") /// Add 10 minutes to timer
    add10m();
  else if (adjustment == "rem1s") /// Remove 1 secound from timer
    rem1s();
  else if (adjustment == "rem5s") /// Remove 5 secounds from timer
    rem5s();
  else if (adjustment == "rem10s") /// Remove 10 secounds from timer
    rem10s();
  else if (adjustment == "rem1m") /// Remove 1 minute from timer
    rem1m();
  else if (adjustment == "rem5m") /// Remove 5 minutes from timer
    rem5m();
  else if (adjustment == "rem10m") /// Remove 10 minutes from timer
    rem10m();
  return adjustment; /// Return the adjustment message for the timer (add1s, add5s, add10s, add1m, add5m, add10m, rem1s, rem5s, rem10s, rem1m, rem5m, rem10m)
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
  /// Control the timer based on the control parameter (start, stop, reset)
  if (control == "start") /// Start the timer
    setTimer(ON);
  else if (control == "stop") /// Stop the timer
    setTimer(OFF);
  else if (control == "reset") /// Reset the timer
    resetTimer();
  return "Timer " + control; /// Return the control message for the timer (start, stop, reset)
}

////////////////////////////////////////////////////////////////////////////////////////
/// Handlers for Auto, Pump, WaterOut, Resistor, WaterIn and WaterMax With Response
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle State
 * @param state
 * @return String
 * @note This function handles the state of the variable (auto, manual, pump, waterOut, resistor, waterIn, waterMax, waterMin, waterAlarm)
 * @note This function returns the state of the variable (auto, manual, pump, waterOut, resistor, waterIn, waterMax, waterMin, waterAlarm)
 */
String handleState(const String &state)
{
  /// Get the state of the variable (auto, manual, pump, waterOut, resistor, waterIn, waterMax, waterMin, waterAlarm)
  if (state == "auto") /// Get the auto mode indicator state
    return String(getIndAuto());
  else if (state == "manual") /// Get the manual mode indicator state
    return String(getManualMode());
  else if (state == "pump") /// Get the pump state
    return String(getPump());
  else if (state == "waterOut") /// Get the water out valve state
    return String(getValv_Water_Out());
  else if (state == "resistor") /// Get the resistor state
    return String(getResistor());
  else if (state == "waterIn") /// Get the water in valve state
    return String(getValv_Water_In());
  else if (state == "waterMax") /// Get the water max state
    return String(getWaterMax());
  else if (state == "waterMin") /// Get the water min state
    return String(getWaterMin());
  else if (state == "waterAlarm") /// Get the water alarm state
    return String(getAlarm());
  return String(); /// Return nothing if the state is not found
}

////////////////////////////////////////////////////////////////////////////////////////
/// Handlers for Toggle Auto, Pump, waterOut, Resistor, WaterIn and WaterMax
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Handle Toggle
 * @param toggle
 * @return String
 * @note This function toggles the variable (auto, pump, waterOut, resistor, waterIn)
 * @note This function returns the toggle message for the variable (auto, pump, waterOut, resistor, waterIn)
 */
String handleToggle(const String &toggle)
{
  /// Toggle the variable (auto, pump, waterOut, resistor, waterIn)
  if (toggle == "auto") /// Toggle the auto mode indicator state
    toggleAutoModeWeb();
  else if (toggle == "pump") /// Toggle the pump state
    togglePumpWeb();
  else if (toggle == "waterOut") /// Toggle the water out valve state
    toggleValveWaterOutWeb();
  else if (toggle == "waterIn") /// Toggle the water in valve state
    toggleValveWaterInWeb();
  else if (toggle == "resistor") /// Toggle the resistor state
    toggleResistorWeb();
  return toggle + " toggled"; /// Return the toggle message for the variable (auto, pump, waterOut, resistor, waterIn)
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
  /// Process the variable for the web server request (var) and return the variable value
  if (var == "TIMER")                 /// Timer variable request
    return handleTimer();             /// Return the timer value in the format HH:MM:SS
  if (var == "WATERMAX")              /// WaterMax variable request
    return handleState("waterMax");   /// Return the waterMax value
  if (var == "WATERMIN")              /// WaterMin variable request
    return handleState("waterMin");   /// Return the waterMin value
  if (var == "WATERALARM")            /// WaterAlarm variable request
    return handleState("waterAlarm"); /// Return the waterAlarm value
  if (var == "AUTO")                  /// Auto variable request
    return handleState("auto");       /// Return the auto value
  if (var == "MANUAL")                /// Manual variable request
    return handleState("manual");     /// Return the manual value
  if (var == "PUMP")                  /// Pump variable request
    return handleState("pump");       /// Return the pump value
  if (var == "WATEROUT")              /// WaterOut variable request
    return handleState("waterOut");   /// Return the waterOut value
  if (var == "RESISTOR")              /// Resistor variable request
    return handleState("resistor");   /// Return the resistor value
  if (var == "WATERIN")               /// WaterIn variable request
    return handleState("waterIn");    /// Return the waterIn value
  if (var == "WIFIQUALITY")           /// WifiQuality variable request
    return handleWifiQuality();       /// Return the wifiQuality value
  if (var == "WIFISSID")              /// WifiSSID variable request
    return handleWifiSSID();          /// Return the wifiSSID value
  if (var == "WIFITX")                /// WifiTX variable request
    return handleWifiTX();            /// Return the wifiTX value
  if (var == "WIFIIP")                /// WifiIP variable request
    return handleWifiIP();            /// Return the wifiIP value
  if (var == "TIMERHOUR")             /// TimerHour variable request
    return handleHour();              /// Return the timerHour value
  if (var == "TIMERMINUTE")           /// TimerMinute variable request
    return handleMinute();            /// Return the timerMinute value
  if (var == "TIMERSECOUND")          /// TimerSecound variable request
    return handleSecound();           /// Return the timerSecound value
  return String();                    /// Return nothing if the variable is not found
}