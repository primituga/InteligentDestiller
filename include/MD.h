
//********************************************************************************
// MiddleWare Header
//********************************************************************************

#ifndef _MD_h
#define _MD_h

#include "OS.h"

// Function prototypes
void ProcessWebPage(void);
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
void workingMaxMin();
void waterManagement();
void indicatorsManagement();
void modeManagement();

// Handlers
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

#endif
