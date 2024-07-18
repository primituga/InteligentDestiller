
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
setInterval(function () {
    if (document.getElementById("autoMode").innerHTML == "1") {
        if (document.getElementById("timer").innerHTML != "0h :0m :0s") {
            getTimerData();
        }
    }
}, 1000);

setInterval(function () {
    if (document.getElementById("autoMode").innerHTML == "1") {
        if (document.getElementById("timer").innerHTML != "0h :0m :0s") {
            getTimerHourData();
            getTimerMinuteData();
            getTimerSecoundData();
        }
    }
}, 1012);

setInterval(function () {
    getAutoModeData();
    getManualModeData();
}, 1453);

setInterval(function () {
    getResistorData();
    getPumpData();
    getWaterInData();
    getDumpWaterData();
}, 1359);

setInterval(function () {
    getWaterMinData();
    getWaterAlarmData();
    getWaterMaxData();
}, 1389);

/*************************************************************************/
/* Timer to update water levels indicators                                *
/* ***********************************************************************/
setInterval(function () {
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

    if (document.getElementById("waterMax").innerHTML == "1") {
        document.getElementById("tank").src = "sMax.png";
    }
    if (document.getElementById("waterMin").innerHTML == "1") {
        document.getElementById("tank").src = "sMin.png";
    }
    if (document.getElementById("waterAlarm").innerHTML == "1" && document.getElementById("waterMin").innerHTML == "1") {
        document.getElementById("tank").src = "sAlarm.png";
    }
}, 1423);