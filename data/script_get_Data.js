
/*************************************************************************/
/*  Webpage Javascript to get data from firmware                         */
/*************************************************************************/

//***********************************************************************
// Get timer data                                                       *
//***********************************************************************
function getTimerData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timer").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readTimer", true);
    xhttp.send();
}

function getTimerHourData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("hour").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readHour", true);
    xhttp.send();
}

function getTimerMinuteData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("minute").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readMinute", true);
    xhttp.send();
}

function getTimerSecoundData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("secound").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readSecound", true);
    xhttp.send();
}

//***********************************************************************
// Get for Auto/Manual mode                                             *
//***********************************************************************
function getAutoModeData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("autoMode").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readAutoMode", true);
    xhttp.send();
}

function getManualModeData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("manualMode").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readManualMode", true);
    xhttp.send();
}

//***********************************************************************
// Get for I/Os                                                         *
//***********************************************************************
function getResistorData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("resistor").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readResistor", true);
    xhttp.send();
}

function getPumpData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("pump").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readPump", true);
    xhttp.send();
}

function getWaterInData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterIn").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readWaterIn", true);
    xhttp.send();
}

function getDumpWaterData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("dumpWater").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readDumpWater", true);
    xhttp.send();
}

function getWaterMaxData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterMax").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readWaterMax", true);
    xhttp.send();
}

function getWaterMinData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterMin").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readWaterMin", true);
    xhttp.send();
}

function getWaterAlarmData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterAlarm").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readWaterAlarm", true);
    xhttp.send();
}

//***********************************************************************
// Get for WiFi Data                                                    *
//***********************************************************************
function getWifiSSIDData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("wifiSSID").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readWifiSSID", true);
    xhttp.send();
}

function getWifiQualityData() {
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            document.getElementById("wifiQuality").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET", "/readWifiQuality", true);
    xhttp.send();
}