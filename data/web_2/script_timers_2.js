/*************************************************************************/
/*  Webpage Javascript for Timers (Shared)                               */
/*************************************************************************/

/*************************************************************************/
/* Timer to update water levels indicators                               */
/*************************************************************************/
window.addEventListener('load', (event) => {
    setInterval(function () {
        try {
            const waterMax = document.getElementById("waterMax").innerHTML;
            const waterMin = document.getElementById("waterMin").innerHTML;
            const waterAlarm = document.getElementById("waterAlarm").innerHTML;

            document.getElementById("ButtonWaterMax").style.backgroundColor = waterMax === "1" ? "green" : "grey";
            document.getElementById("ButtonWaterMin").style.backgroundColor = waterMin === "1" ? "orange" : "grey";
            document.getElementById("ButtonWaterAlarm").style.backgroundColor = waterAlarm === "1" ? "red" : "grey";
        } catch (error) {
            console.error('Error:', error);
        }
    }, 521);
});

/*************************************************************************/
/* Timer to update border buttons green or black                         */
/*************************************************************************/
window.addEventListener('load', (event) => {
    setInterval(function () {
        try {
            const autoMode = document.getElementById("autoMode").innerHTML;
            const resistor = document.getElementById("resistor").innerHTML;
            const pump = document.getElementById("pump").innerHTML;
            const waterIn = document.getElementById("waterIn").innerHTML;
            const waterOut = document.getElementById("waterOut").innerHTML;

            document.getElementById("ButtonToggleAuto").style.border = autoMode === "1" ? "5px solid #00ff00" : "5px solid #000000";
            document.getElementById("ButtonToggleResistor").style.border = resistor === "1" ? "5px solid #00ff00" : "5px solid #000000";
            document.getElementById("ButtonTogglePump").style.border = pump === "1" ? "5px solid #00ff00" : "5px solid #000000";
            document.getElementById("ButtonToggleWaterIn").style.border = waterIn === "1" ? "5px solid #00ff00" : "5px solid #000000";
            document.getElementById("ButtonToggleWaterOut").style.border = waterOut === "1" ? "5px solid #00ff00" : "5px solid #000000";
        } catch (error) {
            console.error('Error:', error);
        }
    }, 503);
});

/*************************************************************************/
/* Timer for EN/Disable buttons                                          */
/*************************************************************************/
window.addEventListener('load', (event) => {
    setInterval(function () {
        try {
            const waterMax = document.getElementById("waterMax").innerHTML;
            const waterMin = document.getElementById("waterMin").innerHTML;
            const waterAlarm = document.getElementById("waterAlarm").innerHTML;
            const manualMode = document.getElementById("manualMode").innerHTML;

            const togglePumpButton = document.getElementById("ButtonTogglePump");
            const manualModeButton = document.getElementById("ButtonManualMode");
            const toggleAutoButton = document.getElementById("ButtonToggleAuto");

            const isAnyWaterStateActive = waterMax === "1" || waterMin === "1" || waterAlarm === "1";

            if (isAnyWaterStateActive) {
                togglePumpButton.classList.replace("button", "buttonDisabled");
            } else {
                togglePumpButton.classList.replace("buttonDisabled", "button");
            }

            if (manualMode === "1") {
                manualModeButton.style.backgroundColor = "green";
                toggleAutoButton.classList.replace("button", "buttonDisabled");
            } else {
                manualModeButton.style.backgroundColor = "grey";
                toggleAutoButton.classList.replace("buttonDisabled", "button");
            }
        } catch (error) {
            console.error('Error:', error);
        }
    }, 546);
});
