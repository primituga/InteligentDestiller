![alt text](https://github.com/primisc/InteligentDestiller/blob/main/Documentation/etc/Pictures/20240806_191158.jpg)

# Intelligent Distiller Project

This project involves the modernization of an old analog distiller machine by removing most of its outdated components and integrating an ESP32 microcontroller to control all its functions. The ESP32 also includes a built-in web server, enabling remote control and monitoring of the machine through a web interface.

## Machine Components

The modernized distiller machine includes:

- **1 Water Tank**: Stores water for the distillation process.
- **1 Water Pump (BMB)**: Circulates water within the system.
- **1 Water Heater (RAQ)**: Heats the water to produce steam.
- **2 Valves (V1 and V2)**: 
  - **V1**: Controls the flow of water to cool the distiller coil.
  - **V2**: Controls the release of steam from the system.
- **3 Water Level Sensors (SMAX, SMIN, and ALARM)**:
  - **SMAX**: Detects when the water tank is full and stops the water pump.
  - **SMIN**: Detects when the water level is low and starts the water pump.
  - **ALARM**: Shuts down the distillation process if the water level is critically low.
- **Manual/Automatic Mode Switches**: Allows switching between manual and automatic operation modes.

## Software and Control

The software runs on the ESP32's dual-core processor:

- **Core 0**: Runs the firmware responsible for controlling all machine functions, including the pump, heater, and valves. It also sends water level data to the web server in real-time.
- **Core 1**: Runs the web server, providing a user-friendly interface for monitoring and controlling the machine remotely.

### Firmware and Web Server

- The **firmware** controls the machine's functions, such as turning the water pump and heater on or off and opening/closing the valves. It communicates with the web server using WebSockets to ensure real-time updates and control.
  
- The **web server** displays the machine status and allows users to control the machine's functions. It updates the interface in real-time to reflect the current status of the water level, pump, heater, and valves.

### Key Features

- **AsyncWebServer**: Used to create the web server on the ESP32.
- **WiFiManager**: Facilitates connecting the ESP32 to a Wi-Fi network without hardcoding credentials. Users can set up Wi-Fi credentials via smartphone, tablet, or computer.
- **SPIFFS (SPI Flash File System)**: Used to store web server files (HTML, CSS, JavaScript, images) directly on the ESP32.
- **WebSockets**: Enables communication between the firmware and the web server, allowing real-time command execution and status updates.
- **EEPROM**: Saves Wi-Fi credentials, allowing the ESP32 to automatically reconnect to the Wi-Fi network on startup.
- **SoftAP Mode**: If the ESP32 is not connected to a Wi-Fi network, it creates a Soft Access Point (AP) for users to connect and set up the network credentials.

## Libraries Used

```cpp
#include "WiFiManager.h"        // WiFi Manager 
#include "esp_netif.h"          // ESP32 Network Interface
#include "ESPmDNS.h"            // mDNS library

// Async Libraries
#include "ESPAsyncWebServer.h"  // Async Web Server

// SPIFFS Libraries
#include "SPIFFS.h"             // SPI Flash File System
```

## Addicional board manager URL:
https://dl.espressif.com/dl/package_esp32_index.json,https://github.com/earlephilhower/arduino-pico/releases/download/global/package_rp2040_index.json

## Board Configuration

- **Board**: ESP32 Dev Module (ESP32-WROOM-32)
- **Pins**: ESP32 Dev Module (38 pins)
- **Flash Frequency**: 80MHz
- **Flash Mode**: QIO
- **Upload Speed**: 921600
- **CPU Frequency**: 240MHz (WiFi/BT)
- **Flash Size**: 4MB (32Mb)
- **Partition Scheme**: Default 4MB with SPIFFS (1.2MB APP / 1.5MB SPIFFS)
- **Core Debug Level**: None
- **PSRAM**: Disabled
