/*************************************************************************/
/*  Webpage Javascript for Timers (Img page)                             */
/*************************************************************************/

/*************************************************************************/
/* Timer to update water levels indicators                                *
/* ***********************************************************************/
window.addEventListener('load', (event) => {
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
});