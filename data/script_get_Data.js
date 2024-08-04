
/*************************************************************************/
/*  Webpage Javascript to get data from firmware                         */
/*************************************************************************/
let wsUri = `ws://${window.location.hostname}/ws`;
let websocket;

function initWebSocket() {
    console.log('Trying to open a WebSocket connection...');
    websocket = new WebSocket(wsUri);
    websocket.onopen = onOpen;
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}

function onOpen(event) {
    console.log('Connection opened');
}

function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function onMessage(event) {
    let data = JSON.parse(event.data);
    switch (data.type) {
        case "wifiQuality":
            document.getElementById('wifiQuality').innerHTML = data.value;
            break;
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
            document.getElementById('timerStat').innerHTML = data.timerStat ? 'ON' : 'OFF';
            document.getElementById('timer').innerHTML = document.getElementById('hour').innerHTML + ':' + document.getElementById('minute').innerHTML + ':' + document.getElementById('secound').innerHTML;
            break;
        default:
            console.log("Unknown data type= " + data.type + " with value " + data.value);
    }
}

window.addEventListener('load', initWebSocket);

//***********************************************************************
// Get timer data                                                       *
//***********************************************************************

// Timer Data
async function getTimerData() {
    try {
        const response = await fetch('/readTimer');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("timer").innerHTML = text;
    } catch (error) {
        console.error('Error:', error);
    }
}

// Timer Hour Data
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

// Timer Minute Data
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

// Timer Second Data
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

// Auto Mode Data
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

// Manual Mode Data
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

// Resistor Data
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

// Pump Data
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

// Water In Data
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

// Dump Water Data
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

// Water Max Data
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

// Water Min Data
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

// Water Alarm Data
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

// WiFi SSID Data
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

// WiFi Quality Data
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
