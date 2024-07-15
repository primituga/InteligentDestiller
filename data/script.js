
/*************************************************************************/
/*  Webpage Javascript                                                   */
/*************************************************************************/

//***********************************************************************
//  show/hide IOsDiv when IOsButton is clicked                          *
//***********************************************************************
var button = document.getElementById('IOsButton');
button.onclick = function () {
    var div = document.getElementById('IOsDiv');
    if (div.style.display !== 'block') {
        div.style.display = 'block';
    } else {
        div.style.display = 'none';
    }
};

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
// Get for Start/Stop/Reset                                             *
//***********************************************************************
function startTimer() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/startTimer", true);
    xhttp.send();
}

function stopTimer() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/stopTimer", true);
    xhttp.send();
}

function resetTimer() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/resetTimer", true);
    xhttp.send();
}

//***********************************************************************
// Get for Add time buttons                                             *
//***********************************************************************
function add1s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add1s", true);
    xhttp.send();
}

function add5s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add5s", true);
    xhttp.send();
}

function add10s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add10s", true);
    xhttp.send();
}

function add1m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add1m", true);
    xhttp.send();
}

function add5m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add5m", true);
    xhttp.send();
}

function add10m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add10m", true);
    xhttp.send();
}

//***********************************************************************
// Get for Remove time buttons                                          *
//***********************************************************************
function rem1s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem1s", true);
    xhttp.send();
}

function rem5s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem5s", true);
    xhttp.send();
}

function rem10s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem10s", true);
    xhttp.send();
}

function rem1m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem1m", true);
    xhttp.send();
}

function rem5m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem5m", true);
    xhttp.send();
}

function rem10m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem10m", true);
    xhttp.send();
}

//***********************************************************************
// Get for toggable states                                              *
//***********************************************************************
function toggleAutoMode() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleAutoMode", true);
    xhttp.send();
}

function togglePump() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/togglePump", true);
    xhttp.send();
}

function toggleWaterIn() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleWaterIn", true);
    xhttp.send();
}

function toggleResistor() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleResistor", true);
    xhttp.send();
}

function toggleDumpWater() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleDumpWater", true);
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

// ********************************************************************************************************************************
//                                                      Timers
// ********************************************************************************************************************************
/*************************************************************************/
/* Timer for the wifi                                                     *
/* ***********************************************************************/
setInterval(function () {
    getWifiSSIDData();
    getWifiQualityData();
}, 5000);

/*************************************************************************/
/* Timer to get data                                                      *
/* ***********************************************************************/
setInterval(function () {
    getTimerData();
}, 500);

setInterval(function () {
    getTimerHourData();
    getTimerMinuteData();
    getTimerSecoundData();
    getAutoModeData();
    getResistorData();
    getPumpData();
    getWaterInData();
    getDumpWaterData();
    getWaterMinData();
    getWaterAlarmData();
    getWaterMaxData();
    getManualModeData()
}, 1000);

/*************************************************************************/
/* Timer to update water levels indicators                                *
/* ***********************************************************************/
setInterval(function () {
    if (document.getElementById("waterMax").innerHTML == "1") {
        document.getElementById("ButtonWaterMax").style.backgroundColor = "green";
    } else {
        document.getElementById("ButtonWaterMax").style.backgroundColor = "grey";
    }
    if (document.getElementById("waterMin").innerHTML == "1") {
        document.getElementById("ButtonWaterMin").style.backgroundColor = "orange";
    } else {
        document.getElementById("ButtonWaterMin").style.backgroundColor = "grey";
    }
    if (document.getElementById("waterAlarm").innerHTML == "1") {
        document.getElementById("ButtonWaterAlarm").style.backgroundColor = "red";
    } else {
        document.getElementById("ButtonWaterAlarm").style.backgroundColor = "grey";
    }
}, 1000);
/*************************************************************************/
/* Timer to update border buttons green or black                          *
/* ***********************************************************************/
setInterval(function () {
    if (document.getElementById("autoMode").innerHTML == "1") {
        document.getElementById("ButtonToggleAuto").style.border = "5px solid #00ff00";
    } else {
        document.getElementById("ButtonToggleAuto").style.border = "5px solid #000000";
    }
    if (document.getElementById("autoMode").innerHTML == "1") {
        document.getElementById("ButtonToggleAuto").style.border = "5px solid #00ff00";
    } else {
        document.getElementById("ButtonToggleAuto").style.border = "5px solid #000000";
    }
    if (document.getElementById("resistor").innerHTML == "1") {
        document.getElementById("ButtonToggleResistor").style.border = "5px solid #00ff00";
    } else {
        document.getElementById("ButtonToggleResistor").style.border = "5px solid #000000";
    }
    if (document.getElementById("pump").innerHTML == "1") {
        document.getElementById("ButtonTogglePump").style.border = "5px solid #00ff00";
    } else {
        document.getElementById("ButtonTogglePump").style.border = "5px solid #000000";
    }
    if (document.getElementById("waterIn").innerHTML == "1") {
        document.getElementById("ButtonToggleWaterIn").style.border = "5px solid #00ff00";
    } else {
        document.getElementById("ButtonToggleWaterIn").style.border = "5px solid #000000";
    }
    if (document.getElementById("dumpWater").innerHTML == "1") {
        document.getElementById("ButtonToggleDumpWater").style.border = "5px solid #00ff00";
    } else {
        document.getElementById("ButtonToggleDumpWater").style.border = "5px solid #000000";
    }
}, 1000); //1000 mSeconds update rate

/*************************************************************************/
/* Timer for EN/Disable buttons                                           *
/* ***********************************************************************/
setInterval(function () {
    if (document.getElementById("secound").innerHTML == "0" && document.getElementById("minute").innerHTML == "0" && document.getElementById("hour").innerHTML == "0") {
        document.getElementById("ButtonStartTimer").classList.remove("button");
        document.getElementById("ButtonStartTimer").classList.add("buttonDisabled");
        document.getElementById("ButtonStopTimer").classList.remove("button");
        document.getElementById("ButtonStopTimer").classList.add("buttonDisabled");
        document.getElementById("ButtonResetTimer").classList.remove("button");
        document.getElementById("ButtonResetTimer").classList.add("buttonDisabled");

        document.getElementById("ButtonRem1s").classList.add("buttonDisabled");
        document.getElementById("ButtonRem5s").classList.add("buttonDisabled");
        document.getElementById("ButtonRem10s").classList.add("buttonDisabled");
        document.getElementById("ButtonRem1m").classList.add("buttonDisabled");
        document.getElementById("ButtonRem5m").classList.add("buttonDisabled");
        document.getElementById("ButtonRem10m").classList.add("buttonDisabled");

        document.getElementById("ButtonRem1s").classList.remove("button");
        document.getElementById("ButtonRem5s").classList.remove("button");
        document.getElementById("ButtonRem10s").classList.remove("button");
        document.getElementById("ButtonRem1m").classList.remove("button");
        document.getElementById("ButtonRem5m").classList.remove("button");
        document.getElementById("ButtonRem10m").classList.remove("button");

    } else {
        document.getElementById("ButtonStartTimer").classList.add("button");
        document.getElementById("ButtonStartTimer").classList.remove("buttonDisabled");
        document.getElementById("ButtonStopTimer").classList.add("button");
        document.getElementById("ButtonStopTimer").classList.remove("buttonDisabled");
        document.getElementById("ButtonResetTimer").classList.add("button");
        document.getElementById("ButtonResetTimer").classList.remove("buttonDisabled");

        document.getElementById("ButtonRem1s").classList.remove("buttonDisabled");
        document.getElementById("ButtonRem5s").classList.remove("buttonDisabled");
        document.getElementById("ButtonRem10s").classList.remove("buttonDisabled");
        document.getElementById("ButtonRem1m").classList.remove("buttonDisabled");
        document.getElementById("ButtonRem5m").classList.remove("buttonDisabled");
        document.getElementById("ButtonRem10m").classList.remove("buttonDisabled");

        document.getElementById("ButtonRem1s").classList.add("button");
        document.getElementById("ButtonRem5s").classList.add("button");
        document.getElementById("ButtonRem10s").classList.add("button");
        document.getElementById("ButtonRem1m").classList.add("button");
        document.getElementById("ButtonRem5m").classList.add("button");
        document.getElementById("ButtonRem10m").classList.add("button");
    }

    if (document.getElementById("waterMax").innerHTML == "1" || document.getElementById("waterMin").innerHTML == "1" || document.getElementById("waterAlarm").innerHTML == "1") {
        document.getElementById("ButtonTogglePump").classList.remove("button");
        document.getElementById("ButtonTogglePump").classList.add("buttonDisabled");
    } else {
        document.getElementById("ButtonTogglePump").classList.add("button");
        document.getElementById("ButtonTogglePump").classList.remove("buttonDisabled");
    }

    if (document.getElementById("autoMode").innerHTML == "0") {
        document.getElementById("ButtonStartTimer").classList.remove("button");
        document.getElementById("ButtonStartTimer").classList.add("buttonDisabled");
        document.getElementById("ButtonStopTimer").classList.remove("button");
        document.getElementById("ButtonStopTimer").classList.add("buttonDisabled");
    } else {
        document.getElementById("ButtonStartTimer").classList.add("button");
        document.getElementById("ButtonStartTimer").classList.remove("buttonDisabled");
        document.getElementById("ButtonStopTimer").classList.add("button");
        document.getElementById("ButtonStopTimer").classList.remove("buttonDisabled");
    }
}, 1000);