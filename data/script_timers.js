/*************************************************************************/
/*  Webpage Javascript for Timers                                        */
/*************************************************************************/

/*************************************************************************/
/* Timer for the wifi                                                    */
/*************************************************************************/
setInterval(async function () {
    try {
        await getWifiSSIDData();
        await getWifiQualityData();
    } catch (error) {
        console.error('Error:', error);
    }
}, 5245);

/*************************************************************************/
/* Timer to get data                                                     */
/*************************************************************************/
window.addEventListener('load', (event) => {
    setInterval(async function () {
        try {
            if (document.getElementById("autoMode").innerHTML === "1" && document.getElementById("timer").innerHTML !== "0h :0m :0s") {
                await getTimerData();
            }
        } catch (error) {
            console.error('Error:', error);
        }
    }, 500);
});

window.addEventListener('load', (event) => {
    setInterval(async function () {
        try {
            if (document.getElementById("autoMode").innerHTML === "1" && document.getElementById("timer").innerHTML !== "0h :0m :0s") {
                await getTimerHourData();
                await getTimerMinuteData();
                await getTimerSecoundData();
            }
        } catch (error) {
            console.error('Error:', error);
        }
    }, 1012);
});

window.addEventListener('load', (event) => {
    setInterval(async function () {
        try {
            await getAutoModeData();
            await getManualModeData();
        } catch (error) {
            console.error('Error:', error);
        }
    }, 952);
});

window.addEventListener('load', (event) => {
    setInterval(async function () {
        try {
            await getResistorData();
            await getPumpData();
            await getWaterInData();
            await getDumpWaterData();
        } catch (error) {
            console.error('Error:', error);
        }
    }, 932);
});

window.addEventListener('load', (event) => {
    setInterval(async function () {
        try {
            await getWaterMinData();
            await getWaterAlarmData();
            await getWaterMaxData();
        } catch (error) {
            console.error('Error:', error);
        }
    }, 943);
});

/*************************************************************************/
/* Timer for EN/Disable buttons                                          */
/*************************************************************************/
window.addEventListener('load', (event) => {
    setInterval(function () {
        const second = document.getElementById("secound").innerHTML;
        const minute = document.getElementById("minute").innerHTML;
        const hour = document.getElementById("hour").innerHTML;

        const isTimerZero = second === "0" && minute === "0" && hour === "0";

        const buttonStart   = document.getElementById("ButtonStartTimer");
        const buttonStop    = document.getElementById("ButtonStopTimer");
        const buttonReset   = document.getElementById("ButtonResetTimer");

        const rem1s         = document.getElementById("ButtonRem1s");
        const rem5s         = document.getElementById("ButtonRem5s");
        const rem10s        = document.getElementById("ButtonRem10s");
        const rem1m         = document.getElementById("ButtonRem1m");
        const rem5m         = document.getElementById("ButtonRem5m");
        const rem10m        = document.getElementById("ButtonRem10m");

        if (isTimerZero) {

            [rem1s, rem5s, rem10s, rem1m, rem5m, rem10m].forEach(btn => btn.classList.replace("button", "buttonDisabled"));
        } else {

            [rem1s, rem5s, rem10s, rem1m, rem5m, rem10m].forEach(btn => btn.classList.replace("buttonDisabled", "button"));
        }

        if (document.getElementById("autoMode").innerHTML === "0" || isTimerZero) {
            buttonStart.classList.replace("button", "buttonDisabled");
            buttonStop.classList.replace("button", "buttonDisabled");
        } else {
            buttonStart.classList.replace("buttonDisabled", "button");
            buttonStop.classList.replace("buttonDisabled", "button");
        }

        if (isTimerZero) {
            buttonStart.classList.replace("button", "buttonDisabled");
            buttonStop.classList.replace("button", "buttonDisabled");
            buttonReset.classList.replace("button", "buttonDisabled");
        } else {
            buttonStart.classList.replace("buttonDisabled", "button");
            buttonStop.classList.replace("buttonDisabled", "button");
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

        
    }, 931);
});
