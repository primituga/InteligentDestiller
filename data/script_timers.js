/**
 * @author Sérgio Carmo
 * @file data/script_timers.js
 * @brief Javascript for the webpage
 * @version 1.0
 */

/*************************************************************************/
/*  Webpage Javascript for Timers                                        */
/*************************************************************************/

/*************************************************************************/
/* Timer for the wifi                                                    */
/*************************************************************************/

/**
 * @brief Timer to update the wifi data
 * @details Timer to update the wifi data
 * @see data/script_timers.js
 * 
 * @param {function} function
 * @param {number} delay
 * @returns {void}
 */
setInterval(async function () {
    try {
        await getWifiSSIDData();
        await getWifiQualityData();
    } catch (error) {
        console.error('Error:', error);
    }
}, 5245);

/*************************************************************************/
/* Timer for EN/Disable buttons                                          */
/*************************************************************************/
/**
 * @brief Timer to update the buttons
 * @details Timer to update the buttons
 * @see data/script_timers.js
 * 
 * @param {function} function
 * @param {number} delay
 * @returns {void}
 */
window.addEventListener('load', (event) => {
    setInterval(function () {
        const timerStat = document.getElementById("timerStat").innerHTML;
        const second = document.getElementById("secound").innerHTML;
        const minute = document.getElementById("minute").innerHTML;
        const hour = document.getElementById("hour").innerHTML;

        const isTimerZero = second === "0" && minute === "0" && hour === "0";

        const buttonStart = document.getElementById("ButtonStartTimer");
        const buttonStop = document.getElementById("ButtonStopTimer");
        const buttonReset = document.getElementById("ButtonResetTimer");

        const rem1s = document.getElementById("ButtonRem1s");
        const rem5s = document.getElementById("ButtonRem5s");
        const rem10s = document.getElementById("ButtonRem10s");
        const rem1m = document.getElementById("ButtonRem1m");
        const rem5m = document.getElementById("ButtonRem5m");
        const rem10m = document.getElementById("ButtonRem10m");

        if (isTimerZero) {

            [rem1s, rem5s, rem10s, rem1m, rem5m, rem10m].forEach(btn => btn.classList.replace("button", "buttonDisabled"));
        } else {

            [rem1s, rem5s, rem10s, rem1m, rem5m, rem10m].forEach(btn => btn.classList.replace("buttonDisabled", "button"));
        }

        if (isTimerZero || document.getElementById("autoMode").innerHTML === "0") {
            buttonStart.classList.replace("button", "buttonDisabled");
            buttonStop.classList.replace("button", "buttonDisabled");
        } else {
            buttonStart.classList.replace("buttonDisabled", "button");
            buttonStop.classList.replace("buttonDisabled", "button");
        }

        if (isTimerZero) {
            buttonReset.classList.replace("button", "buttonDisabled");
        } else {
            buttonReset.classList.replace("buttonDisabled", "button");
        }

        if (second < 1 && minute < 1 && hour < 1)
            rem1s.classList.replace("button", "buttonDisabled");
        else
            rem1s.classList.replace("buttonDisabled", "button");

        if (second < 5 && minute < 1 && hour < 1)
            rem5s.classList.replace("button", "buttonDisabled");
        else
            rem5s.classList.replace("buttonDisabled", "button");

        if (second < 10 && minute < 1 && hour < 1)
            rem10s.classList.replace("button", "buttonDisabled");
        else
            rem10s.classList.replace("buttonDisabled", "button");

        if (minute < 1 && hour < 1)
            rem1m.classList.replace("button", "buttonDisabled");
        else
            rem1m.classList.replace("buttonDisabled", "button");

        if (minute < 5 && hour < 1)
            rem5m.classList.replace("button", "buttonDisabled");
        else
            rem5m.classList.replace("buttonDisabled", "button");

        if (minute < 10 && hour < 1)
            rem10m.classList.replace("button", "buttonDisabled");
        else
            rem10m.classList.replace("buttonDisabled", "button");

        if (timerStat == 0)
            document.getElementById("content").style.border = "3px solid #0000ff";
        else if (timerStat == 1)
            document.getElementById("content").style.border = "3px solid #10ff10";
        if (!isTimerZero && timerStat == 0)
            document.getElementById("content").style.border = "3px solid #00ffff";


    }, 211);
});
