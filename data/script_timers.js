
/*************************************************************************/
/*  Webpage Javascript for Timers                                        */
/*************************************************************************/

/*************************************************************************/
/* Timer for the wifi                                                     *
/* ***********************************************************************/
setInterval(function () {
    getWifiSSIDData();
    getWifiQualityData();
}, 5245);

/*************************************************************************/
/* Timer to get data                                                      *
/* ***********************************************************************/

window.addEventListener('load', (event) => {
    setInterval(function () {
        if (document.getElementById("autoMode").innerHTML == "1") {
            if (document.getElementById("timer").innerHTML != "0h :0m :0s") {
                getTimerData();
            }
        }
    }, 1000);
});

window.addEventListener('load', (event) => {
    setInterval(function () {
        if (document.getElementById("autoMode").innerHTML == "1") {
            if (document.getElementById("timer").innerHTML != "0h :0m :0s") {
                getTimerHourData();
                getTimerMinuteData();
                getTimerSecoundData();
            }
        }
    }, 1012);
});

window.addEventListener('load', (event) => {
    setInterval(function () {
        getAutoModeData();
        getManualModeData();
    }, 1453);
});

window.addEventListener('load', (event) => {
    setInterval(function () {
        getResistorData();
        getPumpData();
        getWaterInData();
        getDumpWaterData();
    }, 1359);
});

window.addEventListener('load', (event) => {
    setInterval(function () {
        getWaterMinData();
        getWaterAlarmData();
        getWaterMaxData();
    }, 1864);
});

/*************************************************************************/
/* Timer for EN/Disable buttons                                           *
/* ***********************************************************************/
window.addEventListener('load', (event) => {
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
    }, 1429);
});