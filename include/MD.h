/**
 * @author Sérgio Carmo
 * @file MD.h
 * @brief Header file for the MD project
 * @version 1.0
 */

////////////////////////////////////////////////////////////////////////////////////////
/// MiddleWare Header
////////////////////////////////////////////////////////////////////////////////////////

#ifndef _MD_h
#define _MD_h

#include "OS.h"

////////////////////////////////////////////////////////////////////////////////////////
/// I/O Map Header
////////////////////////////////////////////////////////////////////////////////////////

/// Function prototypes
void toggleAutoMode();       /// Toggle auto mode
void toggleIndAuto();        /// Toggle auto indicator
void indicatorsManagement(); /// Indicators management
void modeManagement();       /// Mode management

void updateOutputsWeb();       /// Update outputs for the web interface
void toggleAutoModeWeb();      /// Toggle auto mode
void togglePumpWeb();          /// Toggle pump state
void toggleValveWaterInWeb();  /// Toggle valve water in
void toggleValveWaterOutWeb(); /// Toggle valve water out
void toggleResistorWeb();      /// Toggle resistor

void setAutoModeWeb(bool state);      /// Set auto mode
void setPumpWeb(bool state);          /// Set pump state
void setValveWaterInWeb(bool state);  /// Set valve water in
void setValveWaterOutWeb(bool state); /// Set valve water out
void setResistorWeb(bool state);      /// Set resistor

bool getAutoModeWeb();       /// Get auto mode
bool getPumpWeb();           /// Get pump state
bool getValv_Water_InWeb();  /// Get valve water in
bool getValv_Water_OutWeb(); /// Get valve water out
bool getResistorWeb();       /// Get resistor

////////////////////////////////////////////////////////////////////////////////////////
/// ROUTES AND HANDLERS
////////////////////////////////////////////////////////////////////////////////////////
/// Handlers
String handleTimer();                              /// Handle timer
String handleHour();                               /// Handle hour
String handleMinute();                             /// Handle minute
String handleSecound();                            /// Handle secound
String handleWifiQuality();                        /// Handle wifi quality
String handleWifiSSID();                           /// Handle wifi SSID
String handleWifiTX();                             /// Handle wifi TX
String handleWifiIP();                             /// Handle wifi IP
String handleTimeAdjust(const String &adjustment); /// Handle time adjustment
String handleTimerControl(const String &control);  /// Handle timer control
String handleState(const String &state);           /// Handle state
String handleToggle(const String &toggle);         /// Handle toggle
String processor(const String &var);               /// Processor

////////////////////////////////////////////////////////////////////////////////////////
/// TIMERS
////////////////////////////////////////////////////////////////////////////////////////

/// Defining timers for the alarm indicator blinking
#define ALARM_TIME_ON 600  /// Alarm time on
#define ALARM_TIME_OFF 200 /// Alarm time off

/// Timer Functions calls
long webTimer(String op, int16_t amount); /// Timer for web operations
int getTimerSecound();                    /// Get timer secound
int getTimerMinute();                     /// Get timer minute
int getTimerHour();                       /// Get timer hour
bool getTimerStatus();                    /// Get timer status
void add1s();                             /// Add 1 secound to timer
void add5s();                             /// Add 5 secounds to timer
void add10s();                            /// Add 10 secounds to timer
void add1m();                             /// Add 1 minute to timer
void add5m();                             /// Add 5 minutes to timer
void add10m();                            /// Add 10 minutes to timer
void rem1s();                             /// Remove 1 secound from timer
void rem5s();                             /// Remove 5 secounds from timer
void rem10s();                            /// Remove 10 secounds from timer
void rem1m();                             /// Remove 1 minute from timer
void rem5m();                             /// Remove 5 minutes from timer
void rem10m();                            /// Remove 10 minutes from timer
void resetTimer();                        /// Reset timer
void setTimer(bool stat);                 /// Set timer status

////////////////////////////////////////////////////////////////////////////////////////
/// SERIAL
////////////////////////////////////////////////////////////////////////////////////////

/// Serial Functions calls
void initSerial();            /// Inicia a serial
void sPrint(char *abc);       /// Print string
void sPrintLn(char *abc);     /// Print string with new line
void sPrintStr(String abc);   /// Print string
void sPrintNbr(int nbr);      /// Print number
void sPrintLnStr(String abc); /// Print string with new line
void sPrintLnNbr(int nbr);    /// Print number with new line

////////////////////////////////////////////////////////////////////////////////////////
/// Test I/Os
////////////////////////////////////////////////////////////////////////////////////////
void test_IO();               /// Testa as entradas e saidas

////////////////////////////////////////////////////////////////////////////////////////
/// WIFI SERVICE
////////////////////////////////////////////////////////////////////////////////////////

/// WIFI Functions calls
#define WIFI_MODE_OPTIONS 3     /// 1 - Connect to local WiFi, 2 - Create a local AP, 3 - Both
bool initWIFI();                /// Inicia o wifi
String wifiQuality();           /// Retorna a qualidade do wifi

#endif
