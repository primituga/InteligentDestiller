
//********************************************************************************
// Operating System Header
//********************************************************************************

#ifndef _OS_h
#define _OS_h

//********************************************************************************
// Libraries
//********************************************************************************

// #Arduino Libraries
#include <stdint.h>

// #Wifi Libraries
//#include <WiFi.h>
#include "WiFiManager.h"
// #include "WiFiUdp.h"
#include "WiFi.h"
// #include "NTPClient.h"

// #EEPROM Libraries
#include "EEPROM.h"

// #Async Libraries
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

//********************************************************************************
// Definitions
//********************************************************************************

// EEPROM Definitions
#define accessPointLed 2
#define eepromTextVariableSize 33   // the max size of the ssid, password etc. 32+null terminated
#define eepromBufferSize 200

// Debug Definitions
#define DEBUG 1
#define DEBUGlog 0

//********************************************************************************
// I/O Map Header
//********************************************************************************

// INPUTS
#define PIN_SW_MAN 26               // Interruptor  de modo manual
#define PIN_SMIN 27                 // Sensor de nivel agua minimo
#define PIN_SMAX 14                 // Sensor de nivel agua maximo
#define PIN_SW_AUTO 32              // Botão  de modo auto
#define PIN_SALARM 25               // Botão  de modo alarme

// OUTPUTS
#define PIN_RAQ 23                  // Resistencia aquecimento
#define PIN_BMB 22                  // Bomba agua
#define PIN_VALV_WATER_OUT 21       // Valvula descarga vapor
#define PIN_VALV_WATER_IN 19        // Valvula entrada agua fria
#define PIN_IND_ALARM 18            // Indicador luminoso alarme
#define PIN_IND_MIN 05              // Indicador luminoso de nivel agua minimo
#define PIN_IND_MAX 04              // Indicador luminoso de nivel agua maximo
#define PIN_IND_AUTO 15             // Indicador luminoso modo auto
#define PIN_IND_MAN 33              // Indicador luminoso modo manual

#define ON HIGH // Define ON as HIGH
#define OFF LOW // Define OFF as LOW

//********************************************************************************
// MAIN
//********************************************************************************
void loop2(void *pvParameters);     // Main loop to run in core 1

//********************************************************************************
// Multicore
//********************************************************************************
void initMultiCore();

//********************************************************************************
// I/O
//********************************************************************************

// I/O Functions calls
void initPinsOutputs();             // Inicia os outputs
void initPinsInputs();              // Inicia os inputs
bool getWaterMax();                 // Retorna estado do sensor de agua de maximo
bool getWaterMin();                 // Retorna estado do sensor de agua de minimo
bool getWaterAlarm();               // Retorna estado do sensor de agua de alarme
bool getAutoMode();                 // Retorna estado do modo auto
bool getAutoModeSW();               // Retorna estado do interruptor auto
bool getManualMode();               // Retorna estado do botao manual
bool getResistor();                 // Retorna estado do resistor
bool getValv_Water_In();            // Retorna estado da entrada de agua
bool getValv_Water_Out();           // Retorna estado da valvula de vapor
bool getPump();                     // Retorna estado da bomba de agua
bool getAlarm();                    // Retorna estado do alarme
void setIndMax(bool state);         // Liga/desliga o indicador luminoso nivel agua maximo
void setIndMin(bool state);         // Liga/desliga o indicador luminoso  nivel agua minimo
void setIndAlarm(bool state);       // Liga/desliga o indicador luminoso alarme
void setIndMan(bool state);         // Liga/desliga o indicador luminoso modo manual
void setPump(bool state);           // Liga/desliga o indicador luminoso da bomba de agua
void setValveWaterIn(bool state);   // Liga/desliga o indicador luminoso da valvula 1
void setValveWaterOut(bool state);  // Liga/desliga o indicador luminoso da valvula 2
void setResistor(bool state);       // Liga/desliga o indicador luminoso da resistencia
void setAutoMode(bool state1);      // Liga/desliga o modo auto

//********************************************************************************
// SERIAL
//********************************************************************************

// Serial Functions calls
void initSerial();                  // Inicia a serial
void sPrint(char *abc);             // Print string
void sPrintLn(char *abc);           // Print string with new line
void sPrintStr(String abc);         // Print string
void sPrintNbr(int nbr);            // Print number
void sPrintLnStr(String abc);       // Print string with new line
void sPrintLnNbr(int nbr);          // Print number with new line

//********************************************************************************
// EEPROM
//********************************************************************************

// EEPROM Functions calls
void readSettingsFromEEPROM(char *ssid_, char *pass_);  // Read settings from EEPROM
void saveSettingsToEEPPROM(char *ssid_, char *pass_);   // Save settings to EEPROM
byte getStatusFromEeprom();                             // Get status from EEPROM

//********************************************************************************
// WIFI SERVICE
//********************************************************************************

// WIFI Functions calls
void initWIFI();                            // Inicia o wifi
void stopWifi();                            // Desliga o wifi
String wifiQuality();               // Retorna a qualidade do wifi

//********************************************************************************
// TIMERS
//********************************************************************************

// Defining timers
#define ALARM_TIME_ON 600
#define ALARM_TIME_OFF 200

// Timer Functions calls
long webTimer(String op, int16_t amount);   // Timer for web operations
int getTimerSecound();                      // Get timer secound
int getTimerMinute();                       // Get timer minute
int getTimerHour();                         // Get timer hour
bool timerStatus();                         // Get timer status
void add1s();                               // Add 1 secound to timer
void add5s();                               // Add 5 secounds to timer
void add10s();                              // Add 10 secounds to timer
void add1m();                               // Add 1 minute to timer
void add5m();                               // Add 5 minutes to timer
void add10m();                              // Add 10 minutes to timer
void rem1s();                               // Remove 1 secound from timer
void rem5s();                               // Remove 5 secounds from timer
void rem10s();                              // Remove 10 secounds from timer
void rem1m();                               // Remove 1 minute from timer
void rem5m();                               // Remove 5 minutes from timer
void rem10m();                              // Remove 10 minutes from timer
void resetTimer();                          // Reset timer
void setTimer(bool stat);                   // Set timer status

#endif
