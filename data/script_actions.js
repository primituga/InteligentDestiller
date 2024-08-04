/*************************************************************************/
/*  Webpage Javascript                                                   */
/*************************************************************************/

//***********************************************************************
//  show/hide IOsDiv when IOsButton is clicked                          *
//***********************************************************************
var button = document.getElementById('IOsButton');
button.onclick = function () {
    var div = document.getElementById('IOsDiv');
    if (div.style.display !== 'block') {
        div.style.display = 'block';
    } else {
        div.style.display = 'none';
    }
};

//***********************************************************************
// Get for Start/Stop/Reset                                             *
//***********************************************************************
async function startTimer() {
    try {
        await fetch('/startTimer');
        //updateStatus();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function stopTimer() {
    try {
        await fetch('/stopTimer');
        //updateStatus();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function resetTimer() {
    try {
        await fetch('/resetTimer');
        //updateStatus();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function updateStatus() {
    try {
        onloadStatus();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function onloadStatus() {
    try {
        await getTimerData();
        await getTimerHourData();
        await getTimerMinuteData();
        await getTimerSecoundData();
        await getWifiSSIDData();
        await getWifiQualityData();
        await getAutoModeData();
        await getManualModeData();
        await getResistorData();
        await getPumpData();
        await getWaterInData();
        await getWaterOutData();
        await getWaterMinData();
        await getWaterMaxData();
        await getWaterAlarmData();
    } catch (error) {
        console.error('Error:', error);
    }
}

//***********************************************************************
// Get for Add time buttons                                             *
//***********************************************************************
async function add1s() {
    try {
        await fetch('/add1s');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function add5s() {
    try {
        await fetch('/add5s');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function add10s() {
    try {
        await fetch('/add10s');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function add1m() {
    try {
        await fetch('/add1m');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function add5m() {
    try {
        await fetch('/add5m');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function add10m() {
    try {
        await fetch('/add10m');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

//***********************************************************************
// Get for Remove time buttons                                          *
//***********************************************************************
async function rem1s() {
    try {
        await fetch('/rem1s');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function rem5s() {
    try {
        await fetch('/rem5s');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function rem10s() {
    try {
        await fetch('/rem10s');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function rem1m() {
    try {
        await fetch('/rem1m');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function rem5m() {
    try {
        await fetch('/rem5m');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function rem10m() {
    try {
        await fetch('/rem10m');
        getTimerData();
    } catch (error) {
        console.error('Error:', error);
    }
}

//***********************************************************************
// Get for toggable states                                              *
//***********************************************************************
async function toggleAutoMode() {
    try {
        await fetch('/toggleAutoMode');
        //getAutoModeData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function togglePump() {
    try {
        await fetch('/togglePump');
        //getPumpData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function toggleWaterIn() {
    try {
        await fetch('/toggleWaterIn');
        //getWaterInData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function toggleResistor() {
    try {
        await fetch('/toggleResistor');
        //getResistorData();
    } catch (error) {
        console.error('Error:', error);
    }
}

async function toggleWaterOut() {
    try {
        await fetch('/toggleWaterOut');
        //getWaterOutData();
    } catch (error) {
        console.error('Error:', error);
    }
}
