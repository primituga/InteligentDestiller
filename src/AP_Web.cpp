/**
 * @author Sérgio Carmo
 * @file AP_Web.cpp
 * @brief Web Server functions
 * @version 1.0
 */

#include "AP.h" /// Definitions

////////////////////////////////////////////////////////////////////////////////////////
/// Variables and Constants for Web Server and WebSocket Server
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Web Server and WebSocket Server variables
 *
 * These variables are used to create the Web Server and WebSocket Server.
 *
 * @note These variables are used to create the Web Server and WebSocket Server.
 * @note These variables are used to handle the HTTP GET requests for various resources.
 *
 * @param server Web Server
 * @param ws WebSocket Server
 * @param processor Web Server Processor
 * @param wsFrameInfo WebSocket Frame Information
 * @param wsMask WebSocket Mask
 *
 * @return void
 */
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len)
{
  AwsFrameInfo *info = (AwsFrameInfo *)arg;                                           /// WebSocket Frame Information Structure Pointer (info)
  if (info->final && info->index == 0 && info->len == len && info->opcode == WS_TEXT) /// Check if the WebSocket message is a text message and the final message in the frame sequence and the length of the message is equal to the length of the frame and the index of the frame is 0
  {
    data[len] = 0;                                            /// Null-terminate the data to make it a string (char array)
    String message = (char *)data;                            /// Convert the data to a String object
    Serial.println("Received WebSocket message: " + message); /// Print the received WebSocket message
  }
}

/**
 * @brief Web Server and WebSocket Server variables and constants initialization function
 *
 * This function initializes the Web Server and WebSocket Server variables and constants.
 *
 * @note This function initializes the Web Server and WebSocket Server variables and constants.
 *
 * @param server
 * @param client
 * @param type
 * @param arg
 * @param data
 * @param len
 */
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len)
{
  switch (type) /// Handle WebSocket events based on the event type (type)
  {
  case WS_EVT_CONNECT:                                                              /// WebSocket client connected event
    Serial.println("WebSocket client connected: " + client->remoteIP().toString()); /// Print the IP address of the connected WebSocket client
    break;
  case WS_EVT_DISCONNECT:                                                              /// WebSocket client disconnected event
    Serial.println("WebSocket client disconnected: " + client->remoteIP().toString()); /// Print the IP address of the disconnected WebSocket client
    break;
  case WS_EVT_DATA:                         /// WebSocket data event
    handleWebSocketMessage(arg, data, len); /// Handle the WebSocket message data event
    break;
  case WS_EVT_PONG:  /// WebSocket Pong event (response to a Ping)
  case WS_EVT_ERROR: /// WebSocket error event
    break;
  }
}

////////////////////////////////////////////////////////////////////////////////////////
/// Setup Calls
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Setup the routes for the web server.
 *
 * This function defines the routes for handling HTTP GET requests for various
 * resources such as HTML pages, CSS files, JS files, images, time adjustments,
 * timer control, toggle actions, state actions, WiFi handlers, and timer handlers.
 */
void setupRoutes()
{
  ws.onEvent(onEvent);    /// Set the WebSocket event handler function for the WebSocket Server (ws)
  server.addHandler(&ws); /// Add the WebSocket handler to the server (server)
  ////////////////////////////////////////////////////////////////////////////////////////
  /// Route for root / and index_webButtons.html
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/index.html", String(), false, processor); }); /// Send the index.html file to the client when the root / is requested

  server.on("/index_2.html", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/web_2/index_2.html", String(), false, processor); }); /// Send the index.html file to the client when the root / is requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Route for CSS files
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/style.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style.css", "text/css"); }); /// Send the style.css file to the client when requested

  server.on("/style_2.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/web_2/style_2.css", "text/css"); }); /// Send the style.css file to the client when requested

  server.on("/style_Img.css", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/style_Img.css", "text/css"); }); /// Send the style.css file to the client when requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Route JS files
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/script_actions.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_actions.js", "text/javascript"); }); /// Send the script_actions.js file to the client when requested

  server.on("/script_get_Data.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_get_Data.js", "text/javascript"); });  /// Send the script_get_Data.js file to the client when requested

  server.on("/script_timers.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_timers.js", "text/javascript"); });  /// Send the script_timers.js file to the client when requested

  server.on("/script_timers_Img.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/script_timers_Img.js", "text/javascript"); });  /// Send the script_timers.js file to the client when requested

  server.on("/script_timers_2.js", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/web_2/script_timers_2.js", "text/javascript"); });  /// Send the script_timers.js file to the client when requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Route for image files
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/icon.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/icon.png", "image/png"); });  /// Send the icon.png file to the client when requested

  server.on("/estg_logo.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/estg_logo.png", "image/png"); }); /// Send the estg_logo.png file to the client when requested 

  server.on("/bg.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/bg.png", "image/png"); });  /// Send the bg.png file to the client when requested

  server.on("/destiller.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/destiller.png", "image/png"); }); /// Send the destiller.png file to the client when requested

  server.on("/BMB_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/BMB_ON.png", "image/png"); });  /// Send the BMB_ON.png file to the client when requested

  server.on("/BMB_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/BMB_OFF.png", "image/png"); }); /// Send the BMB_OFF.png file to the client when requested

  server.on("/RAQ_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/RAQ_ON.png", "image/png"); });  /// Send the RAQ_ON.png file to the client when requested

  server.on("/RAQ_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/RAQ_OFF.png", "image/png"); }); /// Send the RAQ_OFF.png file to the client when requested

  server.on("/Valve_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Valve_ON.png", "image/png"); });  /// Send the Valve_ON.png file to the client when requested

  server.on("/Valve_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Valve_OFF.png", "image/png"); }); /// Send the Valve_OFF.png file to the client when requested

  server.on("/Auto_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Auto_ON.png", "image/png"); }); /// Send the Auto_ON.png file to the client when requested

  server.on("/Auto_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Auto_OFF.png", "image/png"); });  /// Send the Auto_OFF.png file to the client when requested

  server.on("/Man_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Man_ON.png", "image/png"); });  /// Send the Man_ON.png file to the client when requested

  server.on("/Man_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/Man_OFF.png", "image/png"); }); /// Send the Man_OFF.png file to the client when requested

  server.on("/sMin.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/sMin.png", "image/png"); });  /// Send the sMin.png file to the client when requested

  server.on("/sMax.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/sMax.png", "image/png"); });  /// Send the sMax.png file to the client when requested

  server.on("/sAlarm.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/sAlarm.png", "image/png"); });  /// Send the sAlarm.png file to the client when requested

  server.on("/button_ON.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/button_ON.png", "image/png"); }); /// Send the button_ON.png file to the client when requested

  server.on("/button_OFF.png", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send(SPIFFS, "/img/button_OFF.png", "image/png"); });  /// Send the button_OFF.png file to the client when requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Routes for handling time adjustments
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/add1s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add1s").c_str()); });  /// Send the response to the client when the /add1s route is requested

  server.on("/add5s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add5s").c_str()); });  /// Send the response to the client when the /add5s route is requested

  server.on("/add10s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add10s").c_str()); }); /// Send the response to the client when the /add10s route is requested

  server.on("/add1m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add1m").c_str()); });  /// Send the response to the client when the /add1m route is requested

  server.on("/add5m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add5m").c_str()); });  /// Send the response to the client when the /add5m route is requested

  server.on("/add10m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("add10m").c_str()); }); /// Send the response to the client when the /add10m route is requested

  server.on("/rem1s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem1s").c_str()); });  /// Send the response to the client when the /rem1s route is requested

  server.on("/rem5s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem5s").c_str()); });  /// Send the response to the client when the /rem5s route is requested

  server.on("/rem10s", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem10s").c_str()); });   /// Send the response to the client when the /rem10s route is requested

  server.on("/rem1m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem1m").c_str()); });  /// Send the response to the client when the /rem1m route is requested

  server.on("/rem5m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem5m").c_str()); });  /// Send the response to the client when the /rem5m route is requested

  server.on("/rem10m", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimeAdjust("rem10m").c_str()); }); /// Send the response to the client when the /rem10m route is requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Routes for handling timer control
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/startTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerControl("start").c_str()); });  /// Send the response to the client when the /startTimer route is requested

  server.on("/stopTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerControl("stop").c_str()); }); /// Send the response to the client when the /stopTimer route is requested

  server.on("/resetTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimerControl("reset").c_str()); });  /// Send the response to the client when the /resetTimer route is requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Routes for handling toggle actions
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/toggleAutoMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("auto").c_str()); }); /// Send the response to the client when the /toggleAutoMode route is requested

  server.on("/togglePump", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("pump").c_str()); }); /// Send the response to the client when the /togglePump route is requested

  server.on("/toggleWaterOut", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("waterOut").c_str()); }); /// Send the response to the client when the /toggleWaterOut route is requested

  server.on("/toggleWaterIn", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("waterIn").c_str()); });  /// Send the response to the client when the /toggleWaterIn route is requested

  server.on("/toggleResistor", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleToggle("resistor").c_str()); }); /// Send the response to the client when the /toggleResistor route is requested


  ////////////////////////////////////////////////////////////////////////////////////////
  /// Routes for handling read actions
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/readAutoMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("auto").c_str()); });  /// Send the response to the client when the /readAutoMode route is requested

  server.on("/readManualMode", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("manual").c_str()); });  /// Send the response to the client when the /readManualMode route is requested

  server.on("/readPump", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("pump").c_str()); });  /// Send the response to the client when the /readPump route is requested

  server.on("/readWaterOut", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterOut").c_str()); });  /// Send the response to the client when the /readWaterOut route is requested

  server.on("/readResistor", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("resistor").c_str()); });  /// Send the response to the client when the /readResistor route is requested

  server.on("/readWaterIn", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterIn").c_str()); }); /// Send the response to the client when the /readWaterIn route is requested

  server.on("/readWaterMax", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterMax").c_str()); });  /// Send the response to the client when the /readWaterMax route is requested

  server.on("/readWaterMin", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterMin").c_str()); });  /// Send the response to the client when the /readWaterMin route is requested

  server.on("/readWaterAlarm", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleState("waterAlarm").c_str()); });  /// Send the response to the client when the /readWaterAlarm route is requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Route for WiFi Handlers
  ////////////////////////////////////////////////////////////////////////////////////////
  server.on("/readWifiQuality", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiQuality().c_str()); });  /// Send the response to the client when the /readWifiQuality route is requested

  server.on("/readWifiSSID", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiSSID().c_str()); }); /// Send the response to the client when the /readWifiSSID route is requested

  server.on("/readWifiTX", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiTX().c_str()); }); /// Send the response to the client when the /readWifiTX route is requested

  server.on("/readWifiIP", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleWifiIP().c_str()); }); /// Send the response to the client when the /readWifiIP route is requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Route for Timer Handlers
  ////////////////////////////////////////////////////////////////////////////////////////

  server.on("/readTimer", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleTimer().c_str()); });  /// Send the response to the client when the /readTimer route is requested

  server.on("/readHour", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleHour().c_str()); }); /// Send the response to the client when the /readHour route is requested

  server.on("/readMinute", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleMinute().c_str()); }); /// Send the response to the client when the /readMinute route is requested

  server.on("/readSecound", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/plain", handleSecound().c_str()); });  /// Send the response to the client when the /readSecound route is requested

  ////////////////////////////////////////////////////////////////////////////////////////
  /// Start Server
  ////////////////////////////////////////////////////////////////////////////////////////
  server.begin(); /// Start the server 
}
