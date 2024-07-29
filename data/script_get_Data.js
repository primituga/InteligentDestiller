
/*************************************************************************/
/*  Webpage Javascript to get data from firmware                         */
/*************************************************************************/

//***********************************************************************
// Get timer data                                                       *
//***********************************************************************

/*function getTimerHourData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("hour").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readHour", true);
    xhttp.send();
}
function getTimerHourData() {
    fetch('/readHour')
        .then(response => {
            if (response.status != 200) throw new Error('Request failed');
            return response.text();
        })
        .then(text => {
            document.getElementById("hour").innerHTML = text;
        });
}*/

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
async function getDumpWaterData() {
    try {
        const response = await fetch('/readDumpWater');
        if (response.status !== 200) {
            throw new Error('Request failed');
        }
        const text = await response.text();
        document.getElementById("dumpWater").innerHTML = text;
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