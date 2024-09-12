/**
 * @author Sérgio Carmo
 * @file OS.h
 * @brief Header file for the OS project
 * @version 1.0
 */

#ifndef _OS_h
#define _OS_h

////////////////////////////////////////////////////////////////////////////////////////
/// Libraries
////////////////////////////////////////////////////////////////////////////////////////

/// Wifi Libraries
#include "WiFiManager.h"        /// WiFi Manager 
#include "esp_netif.h"          /// ESP32 Network Interface
#include "ESPmDNS.h"            /// Include mDNS library

/// Async Libraries
#include "ESPAsyncWebServer.h"  /// Async Web Server

/// SPIFFS Libraries
#include "SPIFFS.h"             /// SPI Flash File System

#include "MD.h"                 /// MD Header

extern AsyncWebSocket ws;       /// WebSocket Server 
extern AsyncWebServer server;   /// WebServer 

extern bool DEBUG;              /// Debug mode
#define DEBUGlog 0              /// Debug log mode

////////////////////////////////////////////////////////////////////////////////////////
/// I/O Map Header
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Define the pins for the Inputs
 * 
 * Define the pins for the Inputs
 * 
 */
#define PIN_SW_AUTO 32          /// Botão  de modo auto
#define PIN_SALARM 25           /// Botão  de modo alarme
#define PIN_SW_MAN 26           /// Interruptor  de modo manual
#define PIN_SMIN 27             /// Sensor de nivel agua minimo
#define PIN_SMAX 14             /// Sensor de nivel agua maximo

#define PIN_INPUT_COUNT 5       /// Numero de entradas
#define POS_SW_MAN 0            /// Posicao do interruptor de modo manual
#define POS_SMIN 1              /// Posicao do sensor de nivel agua minimo
#define POS_SMAX 2              /// Posicao do sensor de nivel agua maximo
#define POS_SW_AUTO 3           /// Posicao do botao de modo auto
#define POS_SALARM 4            /// Posicao do botao de modo alarme
#define INTERNAL_BUTTON_BOOT 0  /// Botão interno de boot

/**
 * @brief Define the pins for the Outputs
 * 
 * Define the pins for the Outputs 
 */
#define PIN_RAQ 23              /// Resistencia aquecimento
#define PIN_BMB 22              /// Bomba agua
#define PIN_VALV_WATER_OUT 21   /// Valvula descarga vapor
#define PIN_VALV_WATER_IN 19    /// Valvula entrada agua fria
#define PIN_IND_ALARM 18        /// Indicador luminoso alarme
#define PIN_IND_MIN 05          /// Indicador luminoso de nivel agua minimo
#define PIN_IND_MAX 04          /// Indicador luminoso de nivel agua maximo
#define PIN_IND_AUTO 15         /// Indicador luminoso modo auto
#define PIN_IND_MAN 33          /// Indicador luminoso modo manual

#define PIN_OUTPUT_COUNT 9      /// Numero de saidas
#define POS_RAQ 0               /// Posicao da resistencia
#define POS_BMB 1               /// Posicao da bomba de agua  
#define POS_VALV_WATER_OUT 2    /// Posicao da valvula de vapor
#define POS_VALV_WATER_IN 3     /// Posicao da valvula de agua
#define POS_IND_ALARM 4         /// Posicao do indicador de alarme
#define POS_IND_MIN 5           /// Posicao do indicador de nivel agua minimo
#define POS_IND_MAX 6           /// Posicao do indicador de nivel agua maximo
#define POS_IND_AUTO 7          /// Posicao do indicador de modo auto
#define POS_IND_MAN 8           /// Posicao do indicador de modo manual

/**
 * @brief Define the ON/OFF states for the I/O pins
 * 
 * Define the ON/OFF states for the I/O pins
 * 
 */
#define ON HIGH                 /// Define ON as HIGH
#define OFF LOW                 /// Define OFF as LOW

/**
 * @brief Main function
 * 
 * Main function to start the loop2 in core 1
 * 
 * @return void
 */
void loop2(void *pvParameters); /// Main loop to run in core 1

/**
 * @brief Init MultiCore function
 * 
 * Init MultiCore function to start the second core
 * 
 * @return void
 */
void initMultiCore();           /// Inicia o segundo core

/**
 * @brief Init FS function
 * 
 * Init FS function to start the file system
 * 
 * @return void
 */
void initFS();                  /// Inicia o sistema de arquivos

////////////////////////////////////////////////////////////////////////////////////////
/// I/O
////////////////////////////////////////////////////////////////////////////////////////
void initPinsOutputs();             /// Inicia os outputs
void initPinsInputs();              /// Inicia os inputs
bool getWaterMax();                 /// Retorna estado do sensor de agua de maximo
bool getWaterMin();                 /// Retorna estado do sensor de agua de minimo
bool getAlarm();                    /// Retorna estado do alarme
bool getAlarmIND();                 /// Retorna estado do indicador de alarme
bool getIndAuto();                  /// Retorna estado do modo auto
bool getAutoModeSW();               /// Retorna estado do interruptor auto
bool getManualMode();               /// Retorna estado do botao manual
bool getResistor();                 /// Retorna estado do resistor
bool getValv_Water_In();            /// Retorna estado da entrada de agua
bool getValv_Water_Out();           /// Retorna estado da valvula de vapor
bool getPump();                     /// Retorna estado da bomba de agua

void setIndMax(bool state);         /// Liga/desliga o indicador luminoso nivel agua maximo
void setIndMin(bool state);         /// Liga/desliga o indicador luminoso  nivel agua minimo
void setIndAlarm(bool state);       /// Liga/desliga o indicador luminoso alarme
void setIndMan(bool state);         /// Liga/desliga o indicador luminoso modo manual
void setPump(bool state);           /// Liga/desliga o indicador luminoso da bomba de agua
void setValveWaterIn(bool state);   /// Liga/desliga o indicador luminoso da valvula 1
void setValveWaterOut(bool state);  /// Liga/desliga o indicador luminoso da valvula 2
void setResistor(bool state);       /// Liga/desliga o indicador luminoso da resistencia
void setIndAuto(bool state1);       /// Liga/desliga o modo auto
void writeOutputs();                /// Atualiza as saidas
void readInputs();                  /// Le as entradas

#endif  