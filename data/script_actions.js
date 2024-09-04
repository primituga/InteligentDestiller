/**
 * @author Sérgio Carmo
 * @file data/script_actions.js
 * @brief Javascript for the webpage
 * @version 1.0
 * @details Javascript for the webpage
 * @see data/script_actions.js
 */

/*************************************************************************/
/*  Webpage Javascript                                                   */
/*************************************************************************/
/**
 * @brief Javascript for the webpage 
 * @details Javascript for the webpage 
 * @see data/script_actions.js
 */
//***********************************************************************
//  show/hide IOsDiv when IOsButton is clicked                          *
//***********************************************************************
/**
 * @brief show/hide IOsDiv when IOsButton is clicked
 * @details show/hide IOsDiv when IOsButton is clicked
 * @see data/script_actions.js
 * 
 * @param {string} action
 * @returns {Promise<void>}
 */
var button = document.getElementById('IOsButton'); /// Assumes element with id='button' exists in the DOM 
button.onclick = function () {                   /// When button is clicked 
    var div = document.getElementById('IOsDiv');    /// Assumes element with id='div' exists in the DOM
    if (div.style.display !== 'block') {       /// If div is not visible, then make it visible
        div.style.display = 'block';       /// Make div visible
    } else {                                    /// Otherwise, make it invisible
        div.style.display = 'none';       /// Make div invisible
    }
};

//***********************************************************************
// Get for Start/Stop/Reset                                             *
//***********************************************************************

/**
 * 
 */
async function startTimer() {           /// Start timer button 
    try {                               /// Try to do the following 
        await fetch('/startTimer');     /// Fetch the URL '/startTimer' 
        //updateStatus();               /// Update the status
    } catch (error) {                   /// If there is an error, then do the following
        console.error('Error:', error); /// Log the error to the console
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
