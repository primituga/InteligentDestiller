
/*************************************************************************/
/*  Webpage Javascript for Timers                                        */
/*************************************************************************/

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

/*setInterval(function () {
    getTimerHourData();
    getTimerMinuteData();
    getTimerSecoundData();
}, 1500);*/

setInterval(function () {
    getAutoModeData();
    getManualModeData()

}, 1500);

setInterval(function () {
    getResistorData();
    getPumpData();
    getWaterInData();
    getDumpWaterData();
}, 1500);

setInterval(function () {
    getWaterMinData();
    getWaterAlarmData();
    getWaterMaxData();
}, 1500);

/*************************************************************************/
/* Timer to update water levels indicators                                *
/* ***********************************************************************/
setInterval(function () {
    /*if (document.getElementById("waterMax").innerHTML == "1") {
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
    }*/
///////////////////////////////////////////////////////////////////////////
    if (document.getElementById("pump").innerHTML == "1") {
        document.getElementById("BMB_img").src = "BMB_ON.png";
    } else {
        document.getElementById("BMB_img").src = "BMB_OFF.png";
    }

    if (document.getElementById("waterIn").innerHTML == "1") {
        document.getElementById("valve1_img").classList.remove("valve1_off");
        document.getElementById("valve1_img").classList.add("valve1_on");
        document.getElementById("valve1_img").src = "Valve_ON.png";
    } else {
        document.getElementById("valve1_img").classList.remove("valve1_on");
        document.getElementById("valve1_img").classList.add("valve1_off");
        document.getElementById("valve1_img").src = "Valve_OFF.png";
    }

    if (document.getElementById("dumpWater").innerHTML == "1") {
        document.getElementById("valve2_img").classList.remove("valve2_off");
        document.getElementById("valve2_img").classList.add("valve2_on");
        document.getElementById("valve2_img").src = "Valve_ON.png";
    } else {
        document.getElementById("valve2_img").classList.remove("valve2_on");
        document.getElementById("valve2_img").classList.add("valve2_off");
        document.getElementById("valve2_img").src = "Valve_OFF.png";
    }

    if (document.getElementById("resistor").innerHTML == "1") {
        document.getElementById("RAQ_img").src = "RAQ_ON.png";
    } else {
        document.getElementById("RAQ_img").src = "RAQ_OFF.png";
    }
}, 1500);
/*************************************************************************/
/* Timer to update border buttons green or black                          *
/* ***********************************************************************/
/*setInterval(function () {
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
}, 1000); //1000 mSeconds update rate*/

/*************************************************************************/
/* Timer for EN/Disable buttons                                           *
/* ***********************************************************************/
/*setInterval(function () {
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
}, 1000);*/