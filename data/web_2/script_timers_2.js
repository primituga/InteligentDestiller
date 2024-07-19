
/*************************************************************************/
/*  Webpage Javascript for Timers (Shared)                               */
/*************************************************************************/

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
}, 1432); //1000 mSeconds update rate*/
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
}, 1365); //1000 mSeconds update rate*/

/*************************************************************************/
/* Timer for EN/Disable buttons                                           *
/* ***********************************************************************/
setInterval(function () {
    if (document.getElementById("waterMax").innerHTML == "1" || document.getElementById("waterMin").innerHTML == "1" || document.getElementById("waterAlarm").innerHTML == "1") {
        document.getElementById("ButtonTogglePump").classList.remove("button");
        document.getElementById("ButtonTogglePump").classList.add("buttonDisabled");
    } else {
        document.getElementById("ButtonTogglePump").classList.add("button");
        document.getElementById("ButtonTogglePump").classList.remove("buttonDisabled");
    }

    if (document.getElementById("manualMode").innerHTML == "1") {
        document.getElementById("ButtonManualMode").style.backgroundColor = "green";
        document.getElementById("ButtonToggleAuto").classList.remove("button");
        document.getElementById("ButtonToggleAuto").classList.add("buttonDisabled");
        document.getElementById("ButtonToggleAuto").classList.remove("button");
        document.getElementById("ButtonToggleAuto").classList.add("buttonDisabled");
    } else {
        document.getElementById("ButtonManualMode").style.backgroundColor = "grey";
        document.getElementById("ButtonToggleAuto").classList.add("button");
        document.getElementById("ButtonToggleAuto").classList.remove("buttonDisabled");
        document.getElementById("ButtonToggleAuto").classList.add("button");
        document.getElementById("ButtonToggleAuto").classList.remove("buttonDisabled");
    }
}, 1429);