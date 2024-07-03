const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <title>Intelligent Distiller</title>
    <link rel="icon" href="test-tube.png">
    <style>
      .card {
        max-width: 500px;
        min-height: 850px;
        background: #013220;
        padding: 5px;
        color: #FFF;
        margin: 0 auto;
        box-shadow: 0px 0px 18px -4px rgba(255, 160, 0, 1);
      }

      html {
        font-family: Helvetica;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }

      .button {
        transition-duration: 0.4s;
        background-color: #4C7AAE;
        border: none;
        border-radius: 15px;
        color: white;
        padding: 10px 10px;
        text-decoration: none;
        font-size: 20px;
        margin: 2px;
        cursor: pointer;
      }

      button.button:hover {
        background-color: blue;
      }

      button.button:active {
        background-color: red;
      }

      .buttonWater {
        background-color: #000000;
        border: none;
        border-radius: 15px;
        color: white;
        padding: 10px 10px;
        text-decoration: none;
        font-size: 20px;
        margin: 2px;
        cursor: pointer;
        font: bold 18pt Arial, Helvetica, sans-serif;
      }

      body {
        background-color: #191970;
        font-size: 100%;
        color: #FFFFFF;
        <title>Intelligent Distiller</title><link rel="icon"href="img/test-tube.png">
      }

      #main {
        display: table;
        margin: auto;
        padding: 30px 30px 30px 30px;
      }

      #content {
        border: 2px solid blue;
        border-radius: 15px;
        padding: 10px 10px 10px 10px;
      }

      h2 {
        text-align: center;
        margin: 10px 0px 10px 0px;
      }

      p {
        text-align: center;
        margin: 5px 0px 10px 0px;
        font-size: 120%;
      }

      #time_P {
        margin: 10px 0px 15px 0px;
      }

      blc {
        display: inline-block;
      }

      @media,
        {
        blc {
          display: inline;
          margin-right: 10px;
          text-align: center;
        }

        blc2 {
          display: inline;
          margin-right: 10px;
          line-height: 10px;
          text-align: center;
        }

        blc3 {
          display: inline;
          margin-left: 10px;
          line-height: 10px;
          text-align: center;
        }
      }
    </style>
  </head>
  <body>
    <div id='main'>
      <h2>Intelligent Distiller</h2>
      <hr>
    </div>
    <div class="card">
      <h3>
        <span id="timerbuttons"></span>
      </h3>
      <br>
      <button id="ButtonStartTimer" class="button" onclick="startTimer()">Start</button>
      <button id="ButtonStopTimer" class="button" onclick="stopTimer()">Stop</button>
      <button id="ButtonResetTimer" class="button" onclick="resetTimer()">Reset</button>
      <br>
      <h3>Timer: <span id="timer">0</span>
      </h3>
      <br>
      <button id="ButtonAdd1s" class="button" onclick="add1s()">+1s</button>
      <button id="ButtonAdd5s" class="button" onclick="add5s()">+5s</button>
      <button id="ButtonAdd10s" class="button" onclick="add10s()">+10s</button>
      <button id="ButtonAdd1m" class="button" onclick="add1m()">+1m</button>
      <button id="ButtonAdd5m" class="button" onclick="add5m()">+5m</button>
      <button id="ButtonAdd10m" class="button" onclick="add10m()">+10m</button>
      <br>
      <button id="ButtonRem1s" class="button" onclick="rem1s()">-1s</button>
      <button id="ButtonRem5s" class="button" onclick="rem5s()">-5s</button>
      <button id="ButtonRem10s" class="button" onclick="rem10s()">-10s</button>
      <button id="ButtonRem1m" class="button" onclick="rem1m()">-1m</button>
      <button id="ButtonRem5m" class="button" onclick="rem5m()">-5m</button>
      <button id="ButtonRem10m" class="button" onclick="rem10m()">-10m</button>
      <br>
      <hr>
      <br>
      <button id="ButtonToggleAuto" class="button" onclick="toggleAutoMode()">Auto</button>
      <button id="ButtonTogglePump" class="button" onclick="togglePump()">Pump</button>
      <button id="ButtonToggleWaterIn" class="button" onclick="toggleWaterIn()">Water In</button>
      <br>
      <button id="ButtonToggleResistor" class="button" onclick="toggleResistor()">Resistor</button>
      <button id="ButtonToggleDumpWater" class="button" onclick="toggleDumpWater()">Dump Water</button>
      <br>
      <hr>
      <br>
      <button id="ButtonWaterMax" class="buttonWater">Water Max</button>
      <button id="ButtonWaterMin" class="buttonWater">Water Min</button>
      <button id="ButtonWaterAlarm" class="buttonWater">Water Alarm</button>
      <br>
      <hr>
      <br>
      <h3>Auto mode: <span id="autoMode">0</span>
      </h3>
      <h3>Resistor: <span id="resistor">0</span>
      </h3>
      <h3>Pump: <span id="pump">0</span>
      </h3>
      <h3>Water In: <span id="waterIn">0</span>
      </h3>
      <h3>Dump Water: <span id="dumpWater">0</span>
      </h3>
      <h3>Water Min: <span id="waterMin">0</span>
      </h3>
      <h3>Water Max: <span id="waterMax">0</span>
      </h3>
      <h3>Water Alarm: <span id="waterAlarm">0</span>
      </h3>
    </div>
    <script>
      setInterval(function() {
        // Call a function repetatively with 1 Second interval
        getTimerData();
        getAutoData();
        getResistorData();
        getDumpWaterData();
        getWaterInData();
        getPumpData();
        getWaterMinData();
        getWaterMaxData();
        getWaterAlarmData();
        if (document.getElementById("autoMode").innerHTML == "1") {
          document.getElementById("ButtonToggleAuto").style.border = "4px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleAuto").style.border = "4px solid #000000";
        }
        if (document.getElementById("resistor").innerHTML == "1") {
          document.getElementById("ButtonToggleResistor").style.border = "4px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleResistor").style.border = "4px solid #000000";
        }
        if (document.getElementById("pump").innerHTML == "1") {
          document.getElementById("ButtonTogglePump").style.border = "4px solid #00ff00";
        } else {
          document.getElementById("ButtonTogglePump").style.border = "4px solid #000000";
        }
        if (document.getElementById("waterIn").innerHTML == "1") {
          document.getElementById("ButtonToggleWaterIn").style.border = "4px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleWaterIn").style.border = "4px solid #000000";
        }
        if (document.getElementById("dumpWater").innerHTML == "1") {
          document.getElementById("ButtonToggleDumpWater").style.border = "4px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleDumpWater").style.border = "4px solid #000000";
        }
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
      }, 1000); //1000 mSeconds update rate
      function getTimerData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timer").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readTimer", true);
        xhttp.send();
      }

      function startTimer() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "timerStart", true);
        xhttp.send();
      }

      function stopTimer() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "timerStop", true);
        xhttp.send();
      }

      function resetTimer() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "timerReset", true);
        xhttp.send();
      }

      function add1s() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "add1s", true);
        xhttp.send();
      }

      function add5s() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "add5s", true);
        xhttp.send();
      }

      function add10s() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "add10s", true);
        xhttp.send();
      }

      function add1m() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "add1m", true);
        xhttp.send();
      }

      function add5m() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "add5m", true);
        xhttp.send();
      }

      function add10m() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "add10m", true);
        xhttp.send();
      }

      function rem1s() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "rem1s", true);
        xhttp.send();
      }

      function rem5s() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "rem5s", true);
        xhttp.send();
      }

      function rem10s() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "rem10s", true);
        xhttp.send();
      }

      function rem1m() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "rem1m", true);
        xhttp.send();
      }

      function rem5m() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "rem5m", true);
        xhttp.send();
      }

      function rem10m() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("timerbuttons").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "rem10m", true);
        xhttp.send();
      }

      function toggleDumpWater() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("toggleDumpWater").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "toggleDumpWater", true);
        xhttp.send();
      }

      function toggleResistor() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("toggleResistor").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "toggleResistor", true);
        xhttp.send();
      }

      function toggleAutoMode() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("toggleAuto").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "toggleAuto", true);
        xhttp.send();
      }

      function togglePump() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("togglePump").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "togglePump", true);
        xhttp.send();
      }

      function toggleWaterIn() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("toggleWaterIn").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "toggleWaterIn", true);
        xhttp.send();
      }

      function getAutoData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("autoMode").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readAuto", true);
        xhttp.send();
      }

      function getResistorData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("resistor").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readResistor", true);
        xhttp.send();
      }

      function getDumpWaterData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("dumpWater").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readDumpWater", true);
        xhttp.send();
      }

      function getWaterInData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterIn").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readWaterIn", true);
        xhttp.send();
      }

      function getPumpData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("pump").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readPump", true);
        xhttp.send();
      }

      function getWaterMinData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterMin").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readWaterMin", true);
        xhttp.send();
      }

      function getWaterMaxData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterMax").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readWaterMax", true);
        xhttp.send();
      }

      function getWaterAlarmData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("waterAlarm").innerHTML = this.responseText;
          }
        };
        xhttp.open("GET", "readWaterAlarm", true);
        xhttp.send();
      }
    </script>
  </body>
</html> )=====";