
//////////////////////////////////////////////////////////////////////////
// Operating System Header
//////////////////////////////////////////////////////////////////////////

#ifndef _OS_h
#define _OS_h

// #include "WiFiUdp.h"
// #include "WiFi.h"
#include <stdint.h>
#include "WiFiManager.h"
// #include "NTPClient.h"
#include "EEPROM.h"

#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define DEBUG 1
#define DEBUGlog 0

//////////////////////////////////////////////////////////////////////////
// I/O Map Header
//////////////////////////////////////////////////////////////////////////

// INPUTS
#define PIN_SW_MAN 26  // Interruptor  de modo manual
#define PIN_SMIN 27    // Sensor de nivel agua minimo
#define PIN_SMAX 14    // Sensor de nivel agua maximo
#define PIN_SW_AUTO 32 // Botão  de modo auto
#define PIN_SALARM 25  // Botão  de modo alarme

// OUTPUTS
#define PIN_RAQ 23            // Resistencia aquecimento
#define PIN_BMB 22            // Bomba agua
#define PIN_VALV_WATER_OUT 21 // Valvula descarga vapor
#define PIN_VALV_WATER_IN 19  // Valvula entrada agua fria
#define PIN_IND_ALARM 18      // Indicador luminoso alarme
#define PIN_IND_MIN 05        // Indicador luminoso de nivel agua minimo
#define PIN_IND_MAX 04        // Indicador luminoso de nivel agua maximo
#define PIN_IND_AUTO 15       // Indicador luminoso modo auto
#define PIN_IND_MAN 33        // Indicador luminoso modo manual

#define ON HIGH // Define ON as HIGH
#define OFF LOW // Define OFF as LOW

//////////////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////////////
void loop2(void *pvParameters);

//////////////////////////////////////////////////////////////////////////
// Multicore
//////////////////////////////////////////////////////////////////////////
void initMultiCore();

//////////////////////////////////////////////////////////////////////////
// I/O
//////////////////////////////////////////////////////////////////////////

// I/O Functions calls
void initPinsOutputs();            // Inicia os outputs
void initPinsInputs();             // Inicia os inputs
bool getWaterMax();                // Retorna estado do sensor de agua de maximo
bool getWaterMin();                // Retorna estado do sensor de agua de minimo
bool getWaterAlarm();              // Retorna estado do sensor de agua de alarme
bool getAutoMode();                // Retorna estado do modo auto
bool getAutoModeSW();              // Retorna estado do interruptor auto
bool getManualMode();              // Retorna estado do botao manual
bool getResistor();                // Retorna estado do resistor
bool getValv_Water_In();           // Retorna estado da entrada de agua
bool getValv_Water_Out();          // Retorna estado da valvula de vapor
bool getPump();                    // Retorna estado da bomba de agua
bool getAlarm();                   // Retorna estado do alarme
void setIndMax(bool state);        // Liga/desliga o indicador luminoso nivel agua maximo
void setIndMin(bool state);        // Liga/desliga o indicador luminoso  nivel agua minimo
void setIndAlarm(bool state);      // Liga/desliga o indicador luminoso alarme
void setIndMan(bool state);        // Liga/desliga o indicador luminoso modo manual
void setPump(bool state);          // Liga/desliga o indicador luminoso da bomba de agua
void setValveWaterIn(bool state);  // Liga/desliga o indicador luminoso da valvula 1
void setValveWaterOut(bool state); // Liga/desliga o indicador luminoso da valvula 2
void setResistor(bool state);      // Liga/desliga o indicador luminoso da resistencia
void setAutoMode(bool state1);     // Liga/desliga o modo auto

//////////////////////////////////////////////////////////////////////////
// SERIAL
//////////////////////////////////////////////////////////////////////////

// Serial Functions calls
void initSerial();
void sPrintStr(String abc);
void sPrintNbr(int nbr);
void sPrintLnStr(String abc);
void sPrintLnNbr(int nbr);

//////////////////////////////////////////////////////////////////////////
// EEPROM
//////////////////////////////////////////////////////////////////////////

// Web Server Functions calls
#define accessPointLed 2
#define eepromTextVariableSize 33 // the max size of the ssid, password etc. 32+null terminated
#define eepromBufferSize 200

void readSettingsFromEEPROM(char *ssid_, char *pass_);
void saveSettingsToEEPPROM(char *ssid_, char *pass_);
byte getStatusFromEeprom();

//////////////////////////////////////////////////////////////////////////
// WIFI SERVICE
//////////////////////////////////////////////////////////////////////////

// WiFi SSID and Password
// #define WIFI_SSID "carmo2"
// #define WIFI_PASSWORD "Segio19??."

// WIFI Functions calls

WiFiClient isClientAvailable();
// extern WiFiUDP ntpUDP;
// extern NTPClient timeClient;
// extern bool wifi_Status;

void initWIFI();
void stopWifi();
void wifiQuality(int rssi);

//////////////////////////////////////////////////////////////////////////
// WEB SERVER
//////////////////////////////////////////////////////////////////////////

// Web Server Functions calls
void webServer();

/*
//////////////////////////////////////////////////////////////////////////
//  SCREENS
//////////////////////////////////////////////////////////////////////////

// Screens Management Function Calls
void caseMenu(uint8 );

boolean opt1(ILI9488*, boolean);	//Frequency
boolean opt2(ILI9488*, boolean);	//Phase Conductor Voltage
void opt3(ILI9488*);				//Phase Voltage
void opt4(ILI9488*);				//Current
void opt5(ILI9488*);				//Active Power
void opt6(ILI9488*);				//Apparent Power
void opt7(ILI9488*);				//Power Factor
void opt8(ILI9488*);				//Variation
*/

//////////////////////////////////////////////////////////////////////////
// TIMERS
//////////////////////////////////////////////////////////////////////////

// Defining timers
#define ALARM_TIME_ON 600
#define ALARM_TIME_OFF 200

// Timer Functions calls
long webTimer(String op, int16_t amount);
int getTimerSecound();
int getTimerMinute();
int getTimerHour();
bool timerStatus();
void add1s();
void add5s();
void add10s();
void add1m();
void add5m();
void add10m();
void rem1s();
void rem5s();
void rem10s();
void rem1m();
void rem5m();
void rem10m();
void resetTimer();
void setTimer(bool stat);

#endif
