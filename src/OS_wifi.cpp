
#include "OS.h"

char WIFI_SSID[eepromTextVariableSize] = "aaa";
char WIFI_PASSWORD[eepromTextVariableSize] = "aaa";

const char *soft_ap_ssid = "Destiller-AP";
const char *soft_ap_password = "Destiller-AP";

void OnWiFiEvent(WiFiEvent_t event)
{
  switch (event)
  {

  case SYSTEM_EVENT_STA_CONNECTED:
    Serial.println("ESP32 Connected to WiFi Network");
    break;
  case SYSTEM_EVENT_AP_START:
    Serial.println("ESP32 soft AP started");
    break;
  case SYSTEM_EVENT_AP_STACONNECTED:
    Serial.println("Station connected to ESP32 soft AP");
    break;
  case SYSTEM_EVENT_AP_STADISCONNECTED:
    Serial.println("Station disconnected from ESP32 soft AP");
    break;
  default:
    break;
  }
}

// AsyncWebServer server(80);

void initWIFI()
{
  /* run next line <saveSettingsToEEPPROM> on the first running     */
  /* or every time you want to save the default settings to eeprom  */
  // saveSettingsToEEPPROM(WIFI_SSID, WIFI_PASSWORD);

  readSettingsFromEEPROM(WIFI_SSID, WIFI_PASSWORD); // read the SSID and Passsword from the EEPROM

  // WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
  WiFiManager wifiManager;

  wifiManager.setClass("invert");         // dark theme
  wifiManager.setConfigPortalTimeout(60); // timeout to web server
  wifiManager.setConnectTimeout(20);      // timeout to connect
  wifiManager.setDebugOutput(true);       // set to true to see debug output
  wifiManager.setHostname("Destiler");    // set hostname
  WiFi.setHostname("Destiler");           // set hostname

  // Create AP
  bool res;
  res = wifiManager.autoConnect("DestilerAP");

  ///////////////////////////////////////////////////////////////////////////////////
  WiFi.onEvent(OnWiFiEvent);  // Set event handler for WiFi events (connected, disconnected etc.)
  WiFi.setAutoReconnect(true); // Enable auto reconnect
// Set ESP32 to Station + Access Point mode (AP mode) to allow multiple connections to the ESP32 at the same time (up to 4 stations)
  WiFi.mode(WIFI_MODE_APSTA); 

  WiFi.softAP(soft_ap_ssid, soft_ap_password);  

  // Set IP Address of the ESP32 Soft Access Point
  WiFi.softAPConfig(IPAddress(192, 168, 100, 100), // AP IP
                    IPAddress(192, 168, 100, 1),   // GW IP, which is the same
                    IPAddress(255, 255, 255, 0));

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  ///////////////////////////////////////////////////////////////////////////////////

  if (!res) // if not connected
  {
    Serial.println("Failed to connect");

    // convert string to char ssid and password:
    char *WIFI_SSID = new char[wifiManager.getWiFiSSID().length() + 1]; 
    strcpy(WIFI_SSID, wifiManager.getWiFiSSID().c_str()); 
    char *WIFI_PASSWORD = new char[wifiManager.getWiFiPass().length() + 1];
    strcpy(WIFI_PASSWORD, wifiManager.getWiFiPass().c_str());

    saveSettingsToEEPPROM(WIFI_SSID, WIFI_PASSWORD);
    // ESP.restart();
    // free memory
    delete[] WIFI_SSID; 
    delete[] WIFI_PASSWORD;
  }
  else
  {
    // connected to wifi
    Serial.print("====Connected to: ");
    Serial.println(WiFi.SSID());
    Serial.print("====TxPower: ");
    Serial.print(WiFi.getTxPower());
    Serial.println(" dBm");
    Serial.println(wifiQuality());
    Serial.println(" ");
    Serial.println("Hostname: " + String(WiFi.getHostname()));
    Serial.println("wmHostname: " + wifiManager.getWiFiHostname());
    Serial.print("ESP32 IP as soft AP: ");
    Serial.println(WiFi.softAPIP());
    Serial.print("ESP32 IP on the WiFi network: ");
    Serial.println(WiFi.localIP());
  }
}

// print wifi connection quality
String wifiQuality()
{
  int rssi = -WiFi.RSSI();
  int WiFiperct;
  if (rssi < 27)
  {
    WiFiperct = 100;
  }
  else if (rssi >= 27 && rssi < 33)
  {
    WiFiperct = 150 - (5 / 2.7) * rssi;
  }
  else if (rssi >= 33 && rssi < 36)
  {
    WiFiperct = 150 - (5 / 3) * rssi;
  }
  else if (rssi >= 36 && rssi < 40)
  {
    WiFiperct = 150 - (5 / 3.3) * rssi;
  }
  else if (rssi >= 40 && rssi < 80)
  {
    WiFiperct = 150 - (5 / 3.5) * rssi;
  }
  else if (rssi >= 80 && rssi < 90)
  {
    WiFiperct = 150 - (5 / 3.4) * rssi;
  }
  else if (rssi >= 90 && rssi < 99)
  {
    WiFiperct = 150 - (5 / 3.3) * rssi;
  }
  else
  {
    WiFiperct = 0;
  }
  return String("RSSI: " + String(-rssi) + " dBm" + " (" + WiFiperct + " %)");
}