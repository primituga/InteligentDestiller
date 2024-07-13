
#include "OS.h"

char WIFI_SSID[eepromTextVariableSize] = "aaa";
char WIFI_PASSWORD[eepromTextVariableSize] = "aaa";

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
  // wifiManager.setSTAStaticIPConfig(IPAddress(192,168,100,100), IPAddress(192,168,100,1), IPAddress(255,255,255,0)); // set static IP address for the ESP
  wifiManager.setDebugOutput(true); // set to true to see debug output
  wifiManager.setHostname("ipp-destiler");
  WiFi.setHostname("ipp-destiler");

  // Create AP
  bool res;
  res = wifiManager.autoConnect("DestilerAP");

  if (!res)
  {
    Serial.println("Failed to connect");

    // convert string to char ssid and password:
    char *WIFI_SSID = new char[wifiManager.getWiFiSSID().length() + 1];
    strcpy(WIFI_SSID, wifiManager.getWiFiSSID().c_str());
    char *WIFI_PASSWORD = new char[wifiManager.getWiFiPass().length() + 1];
    strcpy(WIFI_PASSWORD, wifiManager.getWiFiPass().c_str());

    saveSettingsToEEPPROM(WIFI_SSID, WIFI_PASSWORD);
    // ESP.restart();
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
    Serial.print("====IP address: ");
    Serial.println(WiFi.localIP());
    Serial.println("====Hostname: " + String(WiFi.getHostname()));
    Serial.println("====wmHostname: " + wifiManager.getWiFiHostname());

  }
}
/*
// Listen for incoming clients
WiFiClient isClientAvailable()
{
  WiFiClient client = server.available();
  return client;
}
*/

// Disconnect wifi
void stopWifi()
{
  WiFi.disconnect();
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