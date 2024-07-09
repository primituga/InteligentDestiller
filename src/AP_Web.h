// This is the client side HTML webpage that will be served by the ESP32. 
// It is stored in the PROGMEM memory of the ESP32.
// The PROGMEM memory is a special memory that is used to store data that is not going to be changed during the execution of the program.
// This is the case of the HTML webpage that is not going to be changed during the execution of the program.

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <title>Intelligent Distiller</title>
    <link rel="icon" href="https://img.icons8.com/?size=80&id=65359&format=png">
    <style>
      .card {
        max-width: 500px;
        min-height: 600px auto;
        background: #013220;
        padding: 5px;
        color: #fff;
        margin: 0 auto;
        box-shadow: 0 0 18px -4px rgba(255, 160, 0, 1)
      }

      html {
        font-family: Helvetica;
        display: inline-block;
        margin: 0 auto;
        text-align: center
      }

      .button {
        transition-duration: .4s;
        background-color: #4c7aae;
        border: none;
        border-radius: 15px;
        color: #fff;
        padding: 10px 10px;
        text-decoration: none;
        font-size: 20px;
        margin: 2px;
        cursor: pointer
      }

      button.button:hover {
        background-color: #00f
      }

      button.button:active {
        background-color: red
      }

      .buttonWater {
        background-color: #000;
        border: none;
        border-radius: 15px;
        color: #fff;
        padding: 10px 10px;
        text-decoration: none;
        font-size: 20px;
        margin: 2px;
        cursor: default;
        font: bold 18pt Arial, Helvetica, sans-serif
      }

      .hidden {
        visibility: hidden;
        display: none
      }

      body {
        background-color: #191970;
        font-size: 100%;
        color: #fff
      }

      #main {
        display: table;
        margin: auto;
        padding: 30px 30px 30px 30px
      }

      #content {
        border: 2px solid #00f;
        border-radius: 15px;
        padding: 10px 10px 10px 10px
      }

      h3 {
        text-align: center;
        font-size: 120%;
        margin: 10px 10px 10px 10px
      }

      h5 {
        text-align: center;
        font-size: 100%;
        margin: 1px 0 0 0
      }

      .header-logo {
        margin: 10px 0 0 10px;
        text-align: center;
        background-color: #d3d3d3;
        position: absolute;
        top: 45px;
        left: 93px;
        transform: translate(-50%, -50%)
      }

      #time_P {
        margin: 10px 0 15px 0
      }

      blc_line {
        display: inline-block
      }

      @media,
        {
        blc {
          display: inline;
          margin-right: 10px;
          text-align: center
        }

        blc2 {
          display: inline;
          margin-right: 10px;
          line-height: 10px;
          text-align: center
        }

        blc3 {
          display: inline;
          margin-left: 10px;
          line-height: 10px;
          text-align: center
        }
      }
    </style>
  </head>
  <body>
    <div class="header-logo">
      <img align="left" alt="IPPortalegre" height="93" data-sticky-height="53" data-sticky-top="33" src="https://www.ipportalegre.pt/static/ippimages/LogoNovoPolitecnico.png">
    </div>
    <div id="main">
      <br>
      <br>
      <br>
      <h2>Intelligent Distiller</h2>
      <hr>
    </div>
    <div class="card">
      <table style="width:100%">
        <tr>
          <th>
            <h5>Wifi SSID:</h5>
          </th>
          <th>
            <h5>Wifi Quality:</h5>
          </th>
          <!--
          <th><h5>Wifi TX Power:</h5></th><th><h5>Wifi IP:</h5></th>
          -->
        </tr>
        <tr>
          <td>
            <h5>
              <span id="wifiSSID">0</span>
            </h5>
          </td>
          <td>
            <h5>
              <span id="wifiQuality">0</span>
            </h5>
          </td>
          <!--
          <td><h5><span id="wifiTX">0</span> dBm
            </h5></td><td><h5><span id="wifiIP">0</span></h5></td>
          -->
      </table>
      <div id="WaterLVL">
        <hr>
        <br>
        <button id="ButtonWaterMax" class="buttonWater">Water Max</button>
        <button id="ButtonWaterMin" class="buttonWater">Water Min</button>
        <button id="ButtonWaterAlarm" class="buttonWater">Water Alarm</button>
        <br>
        <br>
        <hr>
      </div>
      <br>
      <button id="ButtonStartTimer" class="button" onclick="startTimer()">Start</button>
      <button id="ButtonStopTimer" class="button" onclick="stopTimer()">Stop</button>
      <button id="ButtonResetTimer" class="button" onclick="resetTimer()">Reset</button>
      <br>
      <h3>
        <blc_line id="content">Timer: <span id="timer">0</span>
        </blc_line>
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
      <div id="IOs" class="hidden">
        <h5>Auto mode: <span id="autoMode">0</span>
        </h5>
        <h5>Resistor: <span id="resistor">0</span>
        </h5>
        <h5>Pump: <span id="pump">0</span>
        </h5>
        <h5>Water In: <span id="waterIn">0</span>
        </h5>
        <h5>Dump Water: <span id="dumpWater">0</span>
        </h5>
        <h5>Water Min: <span id="waterMin">0</span>
        </h5>
        <h5>Water Max: <span id="waterMax">0</span>
        </h5>
        <h5>Water Alarm: <span id="waterAlarm">0</span>
        </h5>
      </div>
      <h5>
        <span id="timerbuttons"></span>
      </h5>
    </div>
    <script>
      function getTimerData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timer").innerHTML = this.responseText)
        }, t.open("GET", "readTimer", !0), t.send()
      }

      function startTimer() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "timerStart", !0), t.send()
      }

      function stopTimer() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "timerStop", !0), t.send()
      }

      function resetTimer() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "timerReset", !0), t.send()
      }

      function add1s() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "add1s", !0), t.send()
      }

      function add5s() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "add5s", !0), t.send()
      }

      function add10s() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "add10s", !0), t.send()
      }

      function add1m() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "add1m", !0), t.send()
      }

      function add5m() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "add5m", !0), t.send()
      }

      function add10m() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "add10m", !0), t.send()
      }

      function rem1s() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "rem1s", !0), t.send()
      }

      function rem5s() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "rem5s", !0), t.send()
      }

      function rem10s() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "rem10s", !0), t.send()
      }

      function rem1m() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "rem1m", !0), t.send()
      }

      function rem5m() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "rem5m", !0), t.send()
      }

      function rem10m() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "rem10m", !0), t.send()
      }

      function toggleDumpWater() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "toggleDumpWater", !0), t.send()
      }

      function toggleResistor() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "toggleResistor", !0), t.send()
      }

      function toggleAutoMode() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "toggleAuto", !0), t.send()
      }

      function togglePump() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "togglePump", !0), t.send()
      }

      function toggleWaterIn() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timerbuttons").innerHTML = this.responseText)
        }, t.open("GET", "toggleWaterIn", !0), t.send()
      }

      function getAutoData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("autoMode").innerHTML = this.responseText)
        }, t.open("GET", "readAuto", !0), t.send()
      }

      function getResistorData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("resistor").innerHTML = this.responseText)
        }, t.open("GET", "readResistor", !0), t.send()
      }

      function getDumpWaterData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("dumpWater").innerHTML = this.responseText)
        }, t.open("GET", "readDumpWater", !0), t.send()
      }

      function getWaterInData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("waterIn").innerHTML = this.responseText)
        }, t.open("GET", "readWaterIn", !0), t.send()
      }

      function getPumpData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("pump").innerHTML = this.responseText)
        }, t.open("GET", "readPump", !0), t.send()
      }

      function getWaterMinData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("waterMin").innerHTML = this.responseText)
        }, t.open("GET", "readWaterMin", !0), t.send()
      }

      function getWaterMaxData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("waterMax").innerHTML = this.responseText)
        }, t.open("GET", "readWaterMax", !0), t.send()
      }

      function getWaterAlarmData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("waterAlarm").innerHTML = this.responseText)
        }, t.open("GET", "readWaterAlarm", !0), t.send()
      }

      function readWifiQuality() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("wifiQuality").innerHTML = this.responseText)
        }, t.open("GET", "readWifiQuality", !0), t.send()
      }

      function readWifiSSID() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("wifiSSID").innerHTML = this.responseText)
        }, t.open("GET", "readWifiSSID", !0), t.send()
      }
      /*
            function readWifiTX() {
              var t = new XMLHttpRequest;
              t.onreadystatechange = function() {
                4 == this.readyState && 200 == this.status && (document.getElementById("wifiTX").innerHTML = this.responseText)
              }, t.open("GET", "readWifiTX", !0), t.send()
            }

            function readIP() {
              var t = new XMLHttpRequest;
              t.onreadystatechange = function() {
                4 == this.readyState && 200 == this.status && (document.getElementById("IP").innerHTML = this.responseText)
              }, t.open("GET", "readWifiIP", !0), t.send()
            }
            */
      setInterval(function() {
        readWifiSSID();
        readWifiQuality();
        //readWifiTX();
        //readWifiIP();
      }, 5000);
      setInterval(function() {
        getTimerData();
        getAutoData();
        if (document.getElementById("autoMode").innerHTML == "1") {
          document.getElementById("ButtonToggleAuto").style.border = "5px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleAuto").style.border = "5px solid #000000";
        }
        getResistorData();
        if (document.getElementById("resistor").innerHTML == "1") {
          document.getElementById("ButtonToggleResistor").style.border = "5px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleResistor").style.border = "5px solid #000000";
        }
        getPumpData();
        if (document.getElementById("pump").innerHTML == "1") {
          document.getElementById("ButtonTogglePump").style.border = "5px solid #00ff00";
        } else {
          document.getElementById("ButtonTogglePump").style.border = "5px solid #000000";
        }
        getWaterInData();
        if (document.getElementById("waterIn").innerHTML == "1") {
          document.getElementById("ButtonToggleWaterIn").style.border = "5px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleWaterIn").style.border = "5px solid #000000";
        }
        getDumpWaterData();
        if (document.getElementById("dumpWater").innerHTML == "1") {
          document.getElementById("ButtonToggleDumpWater").style.border = "5px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleDumpWater").style.border = "5px solid #000000";
        }
        getWaterMaxData();
        if (document.getElementById("waterMax").innerHTML == "1") {
          document.getElementById("ButtonWaterMax").style.backgroundColor = "green";
        } else {
          document.getElementById("ButtonWaterMax").style.backgroundColor = "grey";
        }
        getWaterMinData();
        if (document.getElementById("waterMin").innerHTML == "1") {
          document.getElementById("ButtonWaterMin").style.backgroundColor = "orange";
        } else {
          document.getElementById("ButtonWaterMin").style.backgroundColor = "grey";
        }
        getWaterAlarmData();
        if (document.getElementById("waterAlarm").innerHTML == "1") {
          document.getElementById("ButtonWaterAlarm").style.backgroundColor = "red";
        } else {
          document.getElementById("ButtonWaterAlarm").style.backgroundColor = "grey";
        }
      }, 1000); //1000 mSeconds update rate
    </script>
  </body>
</html>
)=====";