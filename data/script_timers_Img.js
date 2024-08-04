/*************************************************************************/
/*  Webpage Javascript for Timers (Img page)                             */
/*************************************************************************/

/*************************************************************************/
/* Timer to update water levels indicators                               */
/*************************************************************************/
window.addEventListener('load', (event) => {
    setInterval(async function () {
        try {
            const pumpStatus = document.getElementById("pump").innerHTML;
            document.getElementById("BMB_img").src = pumpStatus === "1" ? "BMB_ON.png" : "BMB_OFF.png";

            const waterInStatus = document.getElementById("waterIn").innerHTML;
            const valve1Img = document.getElementById("valve1_img");
            if (waterInStatus === "1") {
                valve1Img.classList.remove("valve1_off");
                valve1Img.classList.add("valve1_on");
                valve1Img.src = "Valve_ON.png";
            } else {
                valve1Img.classList.remove("valve1_on");
                valve1Img.classList.add("valve1_off");
                valve1Img.src = "Valve_OFF.png";
            }

            const dumpWaterStatus = document.getElementById("waterOut").innerHTML;
            const valve2Img = document.getElementById("valve2_img");
            if (dumpWaterStatus === "1") {
                valve2Img.classList.remove("valve2_off");
                valve2Img.classList.add("valve2_on");
                valve2Img.src = "Valve_ON.png";
            } else {
                valve2Img.classList.remove("valve2_on");
                valve2Img.classList.add("valve2_off");
                valve2Img.src = "Valve_OFF.png";
            }

            const resistorStatus = document.getElementById("resistor").innerHTML;
            document.getElementById("RAQ_img").src = resistorStatus === "1" ? "RAQ_ON.png" : "RAQ_OFF.png";

            const waterMaxStatus = document.getElementById("waterMax").innerHTML;
            if (waterMaxStatus === "1") {
                document.getElementById("tank").src = "sMax.png";
            }

            const waterMinStatus = document.getElementById("waterMin").innerHTML;
            if (waterMinStatus === "1") {
                document.getElementById("tank").src = "sMin.png";
            }

            const waterAlarmStatus = document.getElementById("waterAlarm").innerHTML;
            if (waterAlarmStatus === "1" && waterMinStatus === "1") {
                document.getElementById("tank").src = "sAlarm.png";
            }

            const autoModeStatus = document.getElementById("autoMode").innerHTML;
            document.getElementById("button_Auto").src = autoModeStatus === "1" ? "button_ON.png" : "button_OFF.png";

            const manualModeStatus = document.getElementById("manualMode").innerHTML;
            document.getElementById("button_Man").src = manualModeStatus === "1" ? "button_ON.png" : "button_OFF.png";
        } catch (error) {
            console.error('Error:', error);
        }
    }, 945);
});
