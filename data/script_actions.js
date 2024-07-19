
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
function startTimer() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/startTimer", true);
    xhttp.send();
    updateStatus();
}

function stopTimer() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/stopTimer", true);
    xhttp.send();
    updateStatus();
}

function resetTimer() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/resetTimer", true);
    xhttp.send();
    updateStatus();
}

function updateStatus() {
    getTimerData();
    getResistorData();
    getPumpData();
    getWaterInData();
    getDumpWaterData();
}

function onloadStatus() {
    getTimerData();
    getTimerHourData();
    getTimerMinuteData();
    getTimerSecoundData();
}

//***********************************************************************
// Get for Add time buttons                                             *
//***********************************************************************
function add1s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add1s", true);
    xhttp.send();
    getTimerData();
}

function add5s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add5s", true);
    xhttp.send();
    getTimerData();
}

function add10s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add10s", true);
    xhttp.send();
    getTimerData();
}

function add1m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add1m", true);
    xhttp.send();
    getTimerData();
}

function add5m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add5m", true);
    xhttp.send();
    getTimerData();
}

function add10m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/add10m", true);
    xhttp.send();
    getTimerData();
}

//***********************************************************************
// Get for Remove time buttons                                          *
//***********************************************************************
function rem1s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem1s", true);
    xhttp.send();
    getTimerData();
}

function rem5s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem5s", true);
    xhttp.send();
    getTimerData();
}

function rem10s() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem10s", true);
    xhttp.send();
    getTimerData();
}

function rem1m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem1m", true);
    xhttp.send();
    getTimerData();
}

function rem5m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem5m", true);
    xhttp.send();
    getTimerData();
}

function rem10m() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/rem10m", true);
    xhttp.send();
    getTimerData();
}

//***********************************************************************
// Get for toggable states                                              *
//***********************************************************************
function toggleAutoMode() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleAutoMode", true);
    xhttp.send();
    getAutoModeData();
}

function togglePump() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/togglePump", true);
    xhttp.send();
    getPumpData();
}

function toggleWaterIn() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleWaterIn", true);
    xhttp.send();
    getWaterInData();
}

function toggleResistor() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleResistor", true);
    xhttp.send();
    getResistorData();
}

function toggleDumpWater() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "/toggleDumpWater", true);
    xhttp.send();
    getDumpWaterData();
}