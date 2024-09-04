/**
 * @author Sérgio Carmo
 * @file script_get_Data.js
 * @brief Javascript to get data from firmware
 * @version 1.0
 * @details This script will get the data from the firmware using fetch API and update the webpage elements with the data received from the firmware
 * The data is fetched from the firmware using the /readTimer, /readHour, /readMinute, /readSecound, /readAutoMode, /readManualMode, /readResistor, /readPump, /readWaterIn, /readWaterOut, /readWaterMax, /readWaterMin, /readWaterAlarm, /readWifiSSID, /readWifiQuality endpoints
 * The data is updated in the webpage elements with the id timer, hour, minute, secound, autoMode, manualMode, resistor, pump, waterIn, waterOut, waterMax, waterMin, waterAlarm, wifiSSID, wifiQuality
 * If the fetch request fails, it will log an error message to the console
 * @see script_get_Data.js
 */

/*************************************************************************/
/*  Webpage Javascript to get data from firmware                         */
/*************************************************************************/
/**
 * This script will get the data from the firmware using fetch API and update the webpage elements
 * with the data received from the firmware 
 * The data is fetched from the firmware using the /readTimer, /readHour, /readMinute, /readSecound, /readAutoMode, /readManualMode, /readResistor, /readPump, /readWaterIn, /readWaterOut, /readWaterMax, /readWaterMin, /readWaterAlarm, /readWifiSSID, /readWifiQuality endpoints
 * The data is updated in the webpage elements with the id timer, hour, minute, secound, autoMode, manualMode, resistor, pump, waterIn, waterOut, waterMax, waterMin, waterAlarm, wifiSSID, wifiQuality
 * If the fetch request fails, it will log an error message to the console
 */
let wsUri = `ws://${window.location.hostname}/ws`; // Websocket URI to connect to the firmware websocket server (ws://esp32.local/ws)
let websocket;  // Websocket object to connect to the firmware websocket server

/**
 * Initialize the websocket connection to the firmware websocket server (ws://esp32.local/ws)
 * and set the event handlers for onOpen, onClose and onMessage
 * onOpen: When the websocket connection is opened
 * onClose: When the websocket connection is closed
 * onMessage: When the websocket receives a message
 * The onMessage function will parse the JSON data and update the webpage elements
 * with the data received from the firmware 
 * If the data type is unknown, it will log an error message to the console with the data type and value
 * If the websocket connection is closed, it will try to reconnect after 2 seconds
 * If the websocket connection is opened, it will update the status
 * If the websocket connection is closed, it will log a message
 */
function initWebSocket() {
    console.log('Trying to open a WebSocket connection...');
    websocket = new WebSocket(wsUri);
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

/**
 * @param {*} event  
 * When the websocket connection is opened, it will update the status
 * It will log a message to the console
 */
function onOpen(event) {
    updateStatus();
    console.log('Connection opened');
}

/**
 * @param {*} event 
 * When the websocket connection is closed, it will log a message to the console
 * It will try to reconnect after 2 seconds
 */
function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

/**
 * @param {*} event 
 * When the websocket receives a message, it will parse the JSON data
 * and update the webpage elements with the data received from the firmware
 * If the data type is unknown, it will log an error message to the console with the data type and value
 */
function onMessage(event) {
    let data = JSON.parse(event.data);  // Parse the JSON data received from the firmware websocket server
    switch (data.type) {                // Check the data type and update the webpage elements with the data received from the firmware
        /*case "wifiQuality":
            document.getElementById('wifiQuality').innerHTML = data.value;
            break;*/
        case "manualMode":
            document.getElementById('manualMode').innerHTML = data.value;
            break;
        case "autoMode":
            document.getElementById('autoMode').innerHTML = data.value;
            break;
        case "resistor":
            document.getElementById('resistor').innerHTML = data.value;
            break;
        case "pump":
            document.getElementById('pump').innerHTML = data.value;
            break;
        case "waterIn":
            document.getElementById('waterIn').innerHTML = data.value;
            break;
        case "waterOut":
            document.getElementById('waterOut').innerHTML = data.value;
            break;
        case "waterMin":
            document.getElementById('waterMin').innerHTML = data.value;
            break;
        case "waterMax":
            document.getElementById('waterMax').innerHTML = data.value;
            break;
        case "waterAlarm":
            document.getElementById('waterAlarm').innerHTML = data.value;
            break;
        case "timer":
            document.getElementById('hour').innerHTML = data.hour;
            document.getElementById('minute').innerHTML = data.minute;
            document.getElementById('secound').innerHTML = data.second;
            //document.getElementById('timerStat').innerHTML = data.timerStat ? 'ON' : 'OFF';
            document.getElementById('timerStat').innerHTML = data.timerStat;
            document.getElementById('timer').innerHTML = document.getElementById('hour').innerHTML + 'h :' + document.getElementById('minute').innerHTML + 'm :' + document.getElementById('secound').innerHTML + 's';
            break;
        default:
            console.log("Unknown data type= " + data.type + " with value " + data.value);
    }
}

window.addEventListener('load', initWebSocket); // When the window loads, initialize the websocket connection to the firmware websocket server (ws://esp32.local/ws)

//***********************************************************************
// Get timer data                                                       *
//***********************************************************************

/**
 * Get the timer data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id timer with the data received from the firmware
 * The data is fetched from the firmware using the /readTimer endpoint
 * The data is updated in the webpage element with the id timer
 */
async function getTimerData() {                             // Get the timer data from the firmware
    try {                                                   // Try to fetch the data from the firmware using the /readTimer endpoint
        const response = await fetch('/readTimer');         // Fetch the data from the firmware using the /readTimer endpoint
        if (response.status !== 200) {                      // If the fetch request fails, log an error message to the console
            throw new Error('Request failed');              // Log an error message to the console
        }
        const text = await response.text();                 // Parse the text data received from the firmware
        document.getElementById("timer").innerHTML = text;  // Update the webpage element with the id timer with the data received from the firmware
    } catch (error) {                                       // If the fetch request fails, log an error message to the console
        console.error('Error:', error);                     // Log an error message to the console
    }
}

/**
 * Get the timer hour data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id hour with the data received from the firmware
 * The data is fetched from the firmware using the /readHour endpoint
 * The data is updated in the webpage element with the id hour
 */
async function getTimerHourData() {
    try {
        const response = await fetch('/readHour');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("hour").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the timer minute data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id minute with the data received from the firmware
 * The data is fetched from the firmware using the /readMinute endpoint
 * The data is updated in the webpage element with the id minute
 */
async function getTimerMinuteData() {
    try {
        const response = await fetch('/readMinute');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("minute").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the timer secound data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id secound with the data received from the firmware
 * The data is fetched from the firmware using the /readSecound endpoint
 * The data is updated in the webpage element with the id secound
 */
async function getTimerSecoundData() {
    try {
        const response = await fetch('/readSecound');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("secound").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the auto mode data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id autoMode with the data received from the firmware
 * The data is fetched from the firmware using the /readAutoMode endpoint
 * The data is updated in the webpage element with the id autoMode
 */
async function getAutoModeData() {
    try {
        const response = await fetch('/readAutoMode');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("autoMode").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the manual mode data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id manualMode with the data received from the firmware
 * The data is fetched from the firmware using the /readManualMode endpoint
 * The data is updated in the webpage element with the id manualMode
 */
async function getManualModeData() {
    try {
        const response = await fetch('/readManualMode');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("manualMode").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the resistor data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id resistor with the data received from the firmware
 * The data is fetched from the firmware using the /readResistor endpoint
 * The data is updated in the webpage element with the id resistor
 */
async function getResistorData() {
    try {
        const response = await fetch('/readResistor');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("resistor").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the pump data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id pump with the data received from the firmware
 * The data is fetched from the firmware using the /readPump endpoint
 * The data is updated in the webpage element with the id pump
 */
async function getPumpData() {
    try {
        const response = await fetch('/readPump');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("pump").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the water in data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id waterIn with the data received from the firmware
 * The data is fetched from the firmware using the /readWaterIn endpoint
 * The data is updated in the webpage element with the id waterIn
 */
async function getWaterInData() {
    try {
        const response = await fetch('/readWaterIn');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("waterIn").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the water out data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id waterOut with the data received from the firmware
 * The data is fetched from the firmware using the /readWaterOut endpoint
 * The data is updated in the webpage element with the id waterOut
 */
async function getWaterOutData() {
    try {
        const response = await fetch('/readWaterOut');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("waterOut").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the water max data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id waterMax with the data received from the firmware
 * The data is fetched from the firmware using the /readWaterMax endpoint
 * The data is updated in the webpage element with the id waterMax
 */
async function getWaterMaxData() {
    try {
        const response = await fetch('/readWaterMax');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("waterMax").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the water min data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id waterMin with the data received from the firmware
 * The data is fetched from the firmware using the /readWaterMin endpoint
 * The data is updated in the webpage element with the id waterMin
 */
async function getWaterMinData() {
    try {
        const response = await fetch('/readWaterMin');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("waterMin").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the water alarm data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id waterAlarm with the data received from the firmware
 * The data is fetched from the firmware using the /readWaterAlarm endpoint
 * The data is updated in the webpage element with the id waterAlarm
 */
async function getWaterAlarmData() {
    try {
        const response = await fetch('/readWaterAlarm');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("waterAlarm").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the WiFi SSID data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id wifiSSID with the data received from the firmware
 * The data is fetched from the firmware using the /readWifiSSID endpoint
 * The data is updated in the webpage element with the id wifiSSID
 */
async function getWifiSSIDData() {
    try {
        const response = await fetch('/readWifiSSID');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("wifiSSID").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

/**
 * Get the WiFi quality data from the firmware using fetch API
 * If the fetch request fails, it will log an error message to the console
 * If the fetch request is successful, it will update the webpage element with the id wifiQuality with the data received from the firmware
 * The data is fetched from the firmware using the /readWifiQuality endpoint
 * The data is updated in the webpage element with the id wifiQuality
 */
async function getWifiQualityData() {
    try {
        const response = await fetch('/readWifiQuality');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("wifiQuality").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}
