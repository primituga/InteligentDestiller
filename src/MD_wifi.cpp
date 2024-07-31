/**
 * @file OS_wifi.cpp
 * @brief Operating System WiFi functions
 * @version 1.0
 */

#include "MD.h"

const char *soft_ap_ssid = "Destiller-AP";
const char *soft_ap_password = "Destiller-AP";

void OnWiFiEvent(WiFiEvent_t event)
{
  switch (event)
  {
  case SYSTEM_EVENT_STA_CONNECTED:
    sPrintLnStr("ESP32 Connected to WiFi Network");
    break;
  case SYSTEM_EVENT_AP_START:
    sPrintLnStr("ESP32 soft AP started");
    break;
  case SYSTEM_EVENT_AP_STACONNECTED:
    sPrintLnStr("Station connected to ESP32 soft AP");
    break;
  case SYSTEM_EVENT_AP_STADISCONNECTED:
    sPrintLnStr("Station disconnected from ESP32 soft AP");
    break;
  default:
    break;
  }
}

String wifiQuality()
{
  int rssi = WiFi.RSSI();
  int quality;

  if (rssi <= -100)
  {
    quality = 0;
  }
  else if (rssi >= -5)
  {
    quality = 100;
  }
  else
  {
    quality = (rssi + 100) * 1.25;
  }
  return "RSSI: " + String(rssi) + " dBm (" + String(quality) + " %)";
}

void connectToWIFI()
{
  // readSettingsFromEEPROM(WIFI_SSID, WIFI_PASSWORD); // Read the SSID and Password from the EEPROM

  WiFiManager wifiManager;

  wifiManager.setClass("invert");         // Dark theme
  wifiManager.setConfigPortalTimeout(60); // Timeout to web server
  wifiManager.setConnectTimeout(20);      // Timeout to connect
  wifiManager.setDebugOutput(true);       // Debug output
  wifiManager.setHostname("Destiler");    // Hostname
  WiFi.setHostname("Destiler");           // Hostname

  if (!wifiManager.autoConnect("DestilerAP"))
  {
    sPrintLnStr("Failed to connect");
    return;
  }

  String ssid = wifiManager.getWiFiSSID();
  String password = wifiManager.getWiFiPass();

  // saveSettingsToEEPPROM(WIFI_SSID, WIFI_PASSWORD);

  WiFi.begin(ssid.c_str(), password.c_str());
  delay(100);
  sPrintLnStr("--Hostname: " + String(WiFi.getHostname()));
  sPrintLnStr("--wmHostname: " + wifiManager.getWiFiHostname());
  // Serial.print("--ESP32 IP on the WiFi network: ");
  // sPrintLnStr(WiFi.localIP().toString());
  // Serial.print("--Connected to: ");
  // Serial.println(WiFi.SSID());
  sPrintStr("--TxPower: ");
  sPrintStr(String(WiFi.getTxPower()));
  sPrintLnStr(" dBm");
  sPrintLnStr("--" + wifiQuality());
}

void connectToSoftAP()
{
  WiFi.setHostname("Destiler"); // Set hostname
  WiFi.onEvent(OnWiFiEvent);    // Set event handler for WiFi events
  WiFi.setAutoReconnect(true);  // Enable auto reconnect
  WiFi.mode(WIFI_MODE_APSTA);   // Set to Station + Access Point mode

  WiFi.softAP(soft_ap_ssid, soft_ap_password);

  // Set IP Address of the ESP32 Soft Access Point
  WiFi.softAPConfig(IPAddress(192, 168, 100, 100), // AP IP
                    IPAddress(192, 168, 100, 1),   // Gateway IP
                    IPAddress(255, 255, 255, 0));  // Subnet Mask

  sPrintLnStr("Hostname: " + String(WiFi.getHostname()));
  sPrintStr("ESP32 IP as soft AP: ");
  sPrintLnStr(WiFi.softAPIP().toString());
}

bool initWIFI()
{
  static bool WIFI_SOFTAP_FLAG = true;

  if (WiFi.status() != WL_CONNECTED && WIFI_MODE_OPTIONS == 1)
  {
    sPrintLnStr("WIFI INIT....");
    connectToWIFI(); // Initiate WiFi
    return true;
  }
  else if (WIFI_SOFTAP_FLAG && WIFI_MODE_OPTIONS == 2)
  {
    sPrintLnStr("SoftAP INIT....");
    connectToSoftAP(); // Initiate WiFi in AP mode only
    WIFI_SOFTAP_FLAG = false;
    return true;
  }
  else if (WiFi.status() != WL_CONNECTED && WIFI_MODE_OPTIONS == 3)
  {
    sPrintLnStr("WIFI INIT and SoftAP....");
    connectToSoftAP(); // Initiate WiFi in AP mode
    connectToWIFI();   // Initiate WiFi
    return true;
  }
  else
  {
    return false;
  }
}