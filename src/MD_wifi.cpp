/**
 * @author Sérgio Carmo
 * @file OS_wifi.cpp
 * @brief WiFi file for the MD project (MiddleWare) - WiFi functions and handlers for the MD project
 * @version 1.0
 */

#include "MD.h" /// Include MD header

const char *soft_ap_ssid = "Destiller-AP";     /// Soft Access Point SSID
const char *soft_ap_password = "Destiller-AP"; /// Soft Access Point password

WiFiManager wifiManager; // Create an instance of the WiFiManager library

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
    // ws.textAll("{\"type\": \"wifiQuality\", \"value\": " + String(quality) + "}");
    return qualityStr; /// Return the quality in string format with RSSI and quality in percentage values
  }
  lastRSSI = rssi; /// Update the last RSSI with the current RSSI
}

/**
 * @brief WiFi Connect Callback
 * @return void
 */
void onWiFiConnect()
{
  Serial.println("WiFi connected successfully! Rebooting...");
  delay(1000);   // Optional delay for stability
  ESP.restart(); // Reboot the ESP32
}

/**
 * @brief Start mDNS service
 * @param dnsName
 * @return void
 * @note This function starts the mDNS service with the desired hostname
 */
void initmDNSService(String dnsName)
{
  // Attempt to start mDNS service with the desired hostname
  if (!MDNS.begin(dnsName))
  {                                                  // Start mDNS with hostname "Destiler"
    sPrintLnStr("Error setting up MDNS responder!"); // Log error if mDNS fails to start
    return;
  }
  Serial.println("MDNS responder started");

  // Add a service to mDNS for demonstration (optional, but can help check if mDNS is working)
  MDNS.addService("http", "tcp", 80); // Add a service type (HTTP)
}

/**
 * @brief Connect to WiFi
 * @return void
 * @note This function connects the ESP32 to a WiFi network
 */
void connectToWIFI()
{
  const char *theHostName = "Destiler"; // Set the hostname for the ESP32

  // Stop any server that might be running (adjust this according to your server type, if used)
  server.end();

  // Configure WiFiManager settings
  wifiManager.setClass("invert");         // Set dark theme
  wifiManager.setConfigPortalTimeout(60); // Set config portal timeout to 60 seconds
  wifiManager.setConnectTimeout(20);      // Set Wi-Fi connection timeout to 20 seconds
  wifiManager.setDebugOutput(true);       // Enable debug output
  wifiManager.setHostname(theHostName);   // Set the hostname
  WiFi.setHostname(theHostName);          // Set hostname for ESP32
  wifiManager.setSaveConfigCallback(onWiFiConnect);

  // Attempt to auto-connect using WiFiManager with SSID "Conf Destiler AP"
  if (!wifiManager.autoConnect("Conf Destiler AP"))
  {
    sPrintLnStr("Failed to connect"); // Print failure message
    return;                           // Exit if connection fails
  }

  initmDNSService(theHostName); // Start mDNS service with the desired hostname

  // Display connection information
  sPrintLnStr("--Hostname: " + String(WiFi.getHostname()));      // Display ESP32 hostname
  sPrintLnStr("--wmHostname: " + wifiManager.getWiFiHostname()); // Display WiFiManager hostname
  sPrintStr("--SSID: ");
  sPrintLnStr(WiFi.SSID()); // Display connected SSID
  sPrintStr("--TxPower: ");
  sPrintStr(String(WiFi.getTxPower())); // Display Tx power in dBm
  sPrintLnStr(" dBm");
  sPrintLnStr("--" + wifiQuality()); // Display WiFi quality (assuming wifiQuality() is defined)
}

/**
 * @brief Reset WiFi settings if BOOT button is pressed
 *
 * @return void
 * @note This function resets the WiFi settings if the BOOT button is pressed
 * @note The BOOT button is connected to GPIO 0
 * @note The ESP32 will restart after the settings are reset
 *
 */
void resetWiFi() {
  static unsigned long pressStartTime = 0; // Time when the button press started
  static bool buttonPressed = false;      // Flag to track the button press state

  pinMode(0, INPUT_PULLUP); // Set GPIO 0 as input with an internal pull-up resistor (connected to BOOT button)

  // Check if the BOOT button is pressed (LOW state)
  if (digitalRead(0) == LOW) {
    // Button is pressed, check if this is the start of the press
    if (!buttonPressed) {
      pressStartTime = millis();  // Record the time when the button is first pressed
      buttonPressed = true;       // Set the button pressed flag
    }

    // Check if the button has been held down for more than 3 seconds
    if (buttonPressed && (millis() - pressStartTime >= 3000)) {
      Serial.println("BOOT button held for 3 seconds - Resetting WiFi settings...");
      wifiManager.resetSettings(); // Clear saved WiFi credentials
      delay(1000);                 // Small delay to ensure settings are reset
      ESP.restart();               // Restart the ESP32 to apply changes
    }
  } else {
    // Button is not pressed, reset the press state
    buttonPressed = false; // Reset the flag
  }
}

/**
 * @brief Connect to SoftAP
 * @return void
 * @note This function creates a Soft Access Point
 * @note The IP Address of the ESP32 Soft Access Point is set to: 192.168.100.100
 */
void connectToSoftAP()
{
  const char *theHostName = "DestilerAP"; // Set the hostname for the ESP32

  WiFi.setHostname(theHostName); /// Set the hostname for the Soft Access Point
  WiFi.onEvent(OnWiFiEvent);     /// Set the WiFi event handler
  WiFi.setAutoReconnect(true);   /// Enable auto reconnect to the WiFi network
  WiFi.mode(WIFI_MODE_APSTA);    /// Set to Station + Access Point mode

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

  initmDNSService(theHostName); // Start mDNS service with the desired hostname

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