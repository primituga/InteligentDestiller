/**
 * @author Sérgio Carmo
 * @file OS_wifi.cpp
 * @brief WiFi file for the MD project (MiddleWare) - WiFi functions and handlers for the MD project
 * @version 1.0
 */

#include "MD.h"

const char *soft_ap_ssid = "Destiller-AP";
const char *soft_ap_password = "Destiller-AP";

/**
 * @brief WiFi Event Handler
 * @note This function handles the WiFi events
 * @param event
 * @return void
 */
void OnWiFiEvent(WiFiEvent_t event)
{
  /// Handle WiFi events
  switch (event)
  {
  case SYSTEM_EVENT_STA_CONNECTED: /// Station connected to WiFi network
    sPrintLnStr("ESP32 Connected to WiFi Network");
    break;
  case SYSTEM_EVENT_AP_START: /// Soft Access Point started
    sPrintLnStr("ESP32 soft AP started");
    break;
  case SYSTEM_EVENT_AP_STACONNECTED: /// Station connected to ESP32 Soft Access Point
    sPrintLnStr("Station connected to ESP32 soft AP");
    break;
  case SYSTEM_EVENT_AP_STADISCONNECTED: /// Station disconnected from ESP32 Soft Access Point
    sPrintLnStr("Station disconnected from ESP32 soft AP");
    break;
  default:
    break;
  }
}

/**
 * @brief WiFi Quality
 * @return String
 * @note This function returns the WiFi quality in percentage
 */
String wifiQuality()
{
  int rssi = WiFi.RSSI();     /// Get the Received Signal Strength Indicator (RSSI) in dBm
  int quality;                /// Quality in percentage
  String qualityStr;          /// Quality in string format
  static int lastQuality = 0; /// Last quality in percentage
  static int lastRSSI = 0;    /// Last RSSI in dBm

  if (lastRSSI == rssi) /// If the last RSSI is equal to the current RSSI
  {
    return qualityStr; /// Return the quality in string format with RSSI and quality in percentage values
  }
  else
  {

    /// Calculate the quality in percentage
    if (rssi <= -100) /// If the RSSI is less than or equal to -100 dBm
    {
      quality = 0; /// Set the quality to 0%
    }
    else if (rssi >= -5) /// If the RSSI is greater than or equal to -5 dBm
    {
      quality = 100; /// Set the quality to 100%
    }
    else /// If the RSSI is between -100 dBm and -5 dBm
    {
      quality = (rssi + 100) * 1.25; /// Calculate the quality in percentage
    }
    /// Return the quality in string format with RSSI and quality in percentage values
    qualityStr = "RSSI " + String(rssi) + " dBm (" + String(quality) + " %)";
    /// Send the quality in percentage to the web server as a JSON object
    //ws.textAll("{\"type\": \"wifiQuality\", \"value\": " + String(quality) + "}");
    return qualityStr; /// Return the quality in string format with RSSI and quality in percentage values
  }
  lastRSSI = rssi; /// Update the last RSSI with the current RSSI
}

/**
 * @brief Connect to WiFi
 * @return void
 * @note This function connects the ESP32 to a WiFi network
 */
void connectToWIFI()
{
  WiFiManager wifiManager;

  server.end();                           /// End the server
  wifiManager.setClass("invert");         /// Dark theme
  wifiManager.setConfigPortalTimeout(60); /// Timeout to web server
  wifiManager.setConnectTimeout(20);      /// Timeout to connect
  wifiManager.setDebugOutput(true);       /// Debug output
  wifiManager.setHostname("Destiler");    /// Hostname
  WiFi.setHostname("Destiler");           /// Hostname

  /// Set the WiFiManager parameters and connect to the WiFi network with the SSID and password stored in the EEPROM memory
  if (!wifiManager.autoConnect("Conf Destiler AP"))
  {
    sPrintLnStr("Failed to connect");
    return;
  }

  /// Get the SSID and password from the WiFiManager and connect to the WiFi network
  String ssid = wifiManager.getWiFiSSID();     /// Get the SSID from the WiFiManager
  String password = wifiManager.getWiFiPass(); /// Get the password from the WiFiManager

  /// Connect to the WiFi network with the SSID and password
  WiFi.begin(ssid.c_str(), password.c_str()); /// Connect to the WiFi network with the SSID and password
  delay(10);                                  /// Delay for 10 ms
  /// Wait for the ESP32 to connect to the WiFi network and print the connection status
  sPrintLnStr("--Hostname: " + String(WiFi.getHostname()));
  sPrintLnStr("--wmHostname: " + wifiManager.getWiFiHostname());
  sPrintStr("--SSID: ");
  sPrintLnStr(WiFi.SSID());
  sPrintStr("--TxPower: ");
  sPrintStr(String(WiFi.getTxPower()));
  sPrintLnStr(" dBm");
  sPrintLnStr("--" + wifiQuality());
}

/**
 * @brief Connect to SoftAP
 * @return void
 * @note This function creates a Soft Access Point
 * @note The IP Address of the ESP32 Soft Access Point is set to: 192.168.100.100
 */
void connectToSoftAP()
{
  WiFi.setHostname("DestilerSoft"); /// Set the hostname for the Soft Access Point
  WiFi.onEvent(OnWiFiEvent);        /// Set the WiFi event handler
  WiFi.setAutoReconnect(true);      /// Enable auto reconnect to the WiFi network
  WiFi.mode(WIFI_MODE_APSTA);       /// Set to Station + Access Point mode

  WiFi.softAP(soft_ap_ssid, soft_ap_password); /// Start the Soft Access Point with the SSID and password

  esp_netif_t *netif_ap = esp_netif_get_handle_from_ifkey("WIFI_AP_DEF"); /// Get the handle for the Soft Access Point interface

  /// Define IP configuration structure and set desired IPs
  esp_netif_ip_info_t ipInfo;                         /// IP configuration structure
  ipInfo.ip.addr = ipaddr_addr("192.168.100.100");    /// AP IP
  ipInfo.gw.addr = ipaddr_addr("192.168.100.1");      /// Gateway IP
  ipInfo.netmask.addr = ipaddr_addr("255.255.255.0"); /// Subnet Mask

  /// Set the IP configuration to the soft AP interface
  esp_netif_dhcps_stop(netif_ap);           /// Stop DHCP server to change settings
  esp_netif_set_ip_info(netif_ap, &ipInfo); /// Apply new IP settings
  esp_netif_dhcps_start(netif_ap);          /// Restart DHCP server with new settings

  sPrintLnStr("Hostname: " + String(WiFi.getHostname())); /// Print the hostname
  sPrintStr("ESP32 IP as soft AP: ");                     /// Print the IP address of the ESP32 Soft Access Point
  sPrintLnStr(WiFi.softAPIP().toString());                /// Print the IP address of the ESP32 Soft Access Point
}

/**
 * @brief Initiate WiFi
 * @return bool
 * @note This function initiates the WiFi connection
 */
bool initWIFI()
{
  static bool WIFI_SOFTAP_FLAG = true; /// SoftAP flag to create a Soft Access Point only once
  /**
   * @brief WIFI_MODE_OPTIONS
   *
   * 1 - Connect to local WiFi network only
   *
   * 2 - Create a local AP (SoftAP)
   *
   * 3 - Both (Connect to local WiFi network and create a local AP)
   */

  if (WiFi.status() != WL_CONNECTED && WIFI_MODE_OPTIONS == 1)
  {
    sPrintLnStr("WIFI INIT....");
    connectToWIFI(); /// Initiate WiFi
    return true;
  }
  else if (WIFI_SOFTAP_FLAG && WIFI_MODE_OPTIONS == 2)
  {
    sPrintLnStr("SoftAP INIT....");
    connectToSoftAP(); /// Initiate WiFi in AP mode only
    WIFI_SOFTAP_FLAG = false;
    return true;
  }
  else if (WiFi.status() != WL_CONNECTED && WIFI_MODE_OPTIONS == 3)
  {
    sPrintLnStr("WIFI INIT and SoftAP....");
    connectToWIFI();   /// Initiate WiFi
    connectToSoftAP(); /// Initiate WiFi in AP mode
    return true;
  }
  else
  {
    return false;
  }
}