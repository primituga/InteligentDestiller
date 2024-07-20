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
    }, 1000);
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

        const buttonStart = document.getElementById("ButtonStartTimer");
        const buttonStop = document.getElementById("ButtonStopTimer");
        const buttonReset = document.getElementById("ButtonResetTimer");

        const rem1s = document.getElementById("ButtonRem1s");
        const rem5s = document.getElementById("ButtonRem5s");
        const rem10s = document.getElementById("ButtonRem10s");
        const rem1m = document.getElementById("ButtonRem1m");
        const rem5m = document.getElementById("ButtonRem5m");
        const rem10m = document.getElementById("ButtonRem10m");

        const isTimerZero = second === "0" && minute === "0" && hour === "0";

        if (isTimerZero) {
            buttonStart.classList.replace("button", "buttonDisabled");
            buttonStop.classList.replace("button", "buttonDisabled");
            buttonReset.classList.replace("button", "buttonDisabled");

            [rem1s, rem5s, rem10s, rem1m, rem5m, rem10m].forEach(btn => btn.classList.replace("button", "buttonDisabled"));
        } else {
            buttonStart.classList.replace("buttonDisabled", "button");
            buttonStop.classList.replace("buttonDisabled", "button");
            buttonReset.classList.replace("buttonDisabled", "button");

            [rem1s, rem5s, rem10s, rem1m, rem5m, rem10m].forEach(btn => btn.classList.replace("buttonDisabled", "button"));
        }

        if (document.getElementById("autoMode").innerHTML === "0") {
            buttonStart.classList.replace("button", "buttonDisabled");
            buttonStop.classList.replace("button", "buttonDisabled");
        } else {
            buttonStart.classList.replace("buttonDisabled", "button");
            buttonStop.classList.replace("buttonDisabled", "button");
        }
    }, 931);
});
