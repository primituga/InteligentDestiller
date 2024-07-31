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

/// Function prototypes
void togglePump();
void toggleValveWaterIn();
void toggleValveWaterOut();
void toggleResistor();
void toggleAutoMode();
void toggleAutoModeWEB();
void workingMax();
void workingMin();
void workingAlarm();
void workingIdle();
void workingOFF();
void workingMaxMin();
void waterManagementAuto();
void waterManagementManual();
void indicatorsManagement();
void modeManagement();

/// Handlers
String handleTimer();
String handleHour();
String handleMinute();
String handleSecound();
String handleWifiQuality();
String handleWifiSSID();
String handleWifiTX();
String handleWifiIP();
String handleTimeAdjust(const String &adjustment);
String handleTimerControl(const String &control);
String handleState(const String &state);
String handleToggle(const String &toggle);
String processor(const String &var);

////////////////////////////////////////////////////////////////////////////////////////
/// TIMERS
////////////////////////////////////////////////////////////////////////////////////////

/// Defining timers for the alarm indicator blinking
#define ALARM_TIME_ON   600
#define ALARM_TIME_OFF  200

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
void test_IO();

////////////////////////////////////////////////////////////////////////////////////////
/// WIFI SERVICE
////////////////////////////////////////////////////////////////////////////////////////

/// WIFI Functions calls
#define WIFI_MODE_OPTIONS 2 /// 1 - Connect to local WiFi, 2 - Create a local AP, 3 - Both
bool initWIFI();            /// Inicia o wifi
String wifiQuality();       /// Retorna a qualidade do wifi

#endif
