// This is the client side HTML webpage that will be served by the ESP32. 
// It is stored in the PROGMEM memory of the ESP32.
// The PROGMEM memory is a special memory that is used to store data that is not going to be changed during the execution of the program.
// This is the case of the HTML webpage that is not going to be changed during the execution of the program.

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <title>Intelligent Distiller</title>
    <!--<link rel="icon" href="https://img.icons8.com/?size=80&id=65359&format=png">-->
    <link rel="icon" type="image/x-icon" href="data:image/png;base64,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">
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

      .buttonDisabled {
        disabled: true;
        background-color: grey;
        cursor: not-allowed;
        border-radius: 15px;
        padding: 10px 10px;
        font-size: 20px;
        margin: 2px;
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
        //margin: 10px 0 0 10px;
        text-align: center;
        //background-color: #d3d3d3;
        //position: absolute;
        //top: 45px;
        //left: 93px;
        //transform: translate(0%, -50%)
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
    <div id="main">
      <div class="header-logo">
        <!--<img align="left" alt="IPPortalegre" height="93" data-sticky-height="53" data-sticky-top="33" src="https://www.ipportalegre.pt/static/ippimages/LogoNovoPolitecnico.png">-->
        <img src="data:image/png;base64,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">
      </div>
      <br>
      <h2>Intelligent Distiller</h2>
      <hr>
    </div>
    <div id="card" class="card">
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
      <div id="ManButtons">
        <button id="ButtonToggleAuto" class="button" onclick="toggleAutoMode()">Auto</button>
        <button id="ButtonTogglePump" class="button" onclick="togglePump()">Pump</button>
        <button id="ButtonToggleWaterIn" class="button" onclick="toggleWaterIn()">Water In</button>
        <br>
        <button id="ButtonToggleResistor" class="button" onclick="toggleResistor()">Resistor</button>
        <button id="ButtonToggleDumpWater" class="button" onclick="toggleDumpWater()">Dump Water</button>
      </div>
      <br>
      <hr>
      <br>
      <div id="TimerCounter">
        <h3>
          <blc_line id="content">Timer: <span id="timer">0</span>
          </blc_line>
        </h3>
      </div>
      <br>
      <div id="TimerControl">
        <button id="ButtonStartTimer" class="button" onclick="startTimer()">Start</button>
        <button id="ButtonStopTimer" class="button" onclick="stopTimer()">Stop</button>
        <button id="ButtonResetTimer" class="button" onclick="resetTimer()">Reset</button>
        <br>
      </div>
      
      <br>
      <div id="TimerAddRem">
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
      </div>
      
      <br>
      <hr>
      <button id="IOsButton" class="button">More Data</button>
      <div id="IOsDiv" class="hidden">
        <br>
        <h5> Last action: <span id="timerbuttons">0</span>
        </h5>
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
        <h5>Hour: <span id="hour">0</span>
        </h5>
        <h5>Minute: <span id="minute">0</span>
        </h5>
        <h5>Secound: <span id="secound">0</span>
        </h5>
      </div>
    </div>
    <script>
      var button = document.getElementById('IOsButton');
      button.onclick = function() {
        var div = document.getElementById('IOsDiv');
        if (div.style.display !== 'block') {
          div.style.display = 'block';
        } else {
          div.style.display = 'none';
        }
      };

      function getTimerData() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("timer").innerHTML = this.responseText)
        }, t.open("GET", "readTimer", !0), t.send()
      }

      function getTimerHour() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("hour").innerHTML = this.responseText)
        }, t.open("GET", "readHour", !0), t.send()
      }

      function getTimerMin() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("minute").innerHTML = this.responseText)
        }, t.open("GET", "readMinute", !0), t.send()
      }

      function getTimerSec() {
        var t = new XMLHttpRequest;
        t.onreadystatechange = function() {
          4 == this.readyState && 200 == this.status && (document.getElementById("secound").innerHTML = this.responseText)
        }, t.open("GET", "readSecound", !0), t.send()
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
        getTimerHour();
        getTimerMin();
        getTimerSec();
        if (document.getElementById("secound").innerHTML == "0" && document.getElementById("minute").innerHTML == "0" && document.getElementById("hour").innerHTML == "0") {
          document.getElementById("ButtonStartTimer").classList.remove("button");
          document.getElementById("ButtonStartTimer").classList.add("buttonDisabled");
          document.getElementById("ButtonStopTimer").classList.remove("button");
          document.getElementById("ButtonStopTimer").classList.add("buttonDisabled");
          document.getElementById("ButtonResetTimer").classList.remove("button");
          document.getElementById("ButtonResetTimer").classList.add("buttonDisabled");

          document.getElementById("ButtonRem1s").classList.add("buttonDisabled");
          document.getElementById("ButtonRem5s").classList.add("buttonDisabled");
          document.getElementById("ButtonRem10s").classList.add("buttonDisabled");
          document.getElementById("ButtonRem1m").classList.add("buttonDisabled");
          document.getElementById("ButtonRem5m").classList.add("buttonDisabled");
          document.getElementById("ButtonRem10m").classList.add("buttonDisabled");
          
          document.getElementById("ButtonRem1s").classList.remove("button");
          document.getElementById("ButtonRem5s").classList.remove("button");
          document.getElementById("ButtonRem10s").classList.remove("button");
          document.getElementById("ButtonRem1m").classList.remove("button");
          document.getElementById("ButtonRem5m").classList.remove("button");
          document.getElementById("ButtonRem10m").classList.remove("button");

        } else {
          document.getElementById("ButtonStartTimer").classList.add("button");
          document.getElementById("ButtonStartTimer").classList.remove("buttonDisabled");
          document.getElementById("ButtonStopTimer").classList.add("button");
          document.getElementById("ButtonStopTimer").classList.remove("buttonDisabled");
          document.getElementById("ButtonResetTimer").classList.add("button");
          document.getElementById("ButtonResetTimer").classList.remove("buttonDisabled");

          document.getElementById("ButtonRem1s").classList.remove("buttonDisabled");
          document.getElementById("ButtonRem5s").classList.remove("buttonDisabled");
          document.getElementById("ButtonRem10s").classList.remove("buttonDisabled");
          document.getElementById("ButtonRem1m").classList.remove("buttonDisabled");
          document.getElementById("ButtonRem5m").classList.remove("buttonDisabled");
          document.getElementById("ButtonRem10m").classList.remove("buttonDisabled");
          
          document.getElementById("ButtonRem1s").classList.add("button");
          document.getElementById("ButtonRem5s").classList.add("button");
          document.getElementById("ButtonRem10s").classList.add("button");
          document.getElementById("ButtonRem1m").classList.add("button");
          document.getElementById("ButtonRem5m").classList.add("button");
          document.getElementById("ButtonRem10m").classList.add("button");
        }
        
        if (document.getElementById("waterMax").innerHTML == "1" || document.getElementById("waterMin").innerHTML == "1" || document.getElementById("waterAlarm").innerHTML == "1") {
          document.getElementById("ButtonTogglePump").classList.remove("button");
          document.getElementById("ButtonTogglePump").classList.add("buttonDisabled");
        } else {
          document.getElementById("ButtonTogglePump").classList.add("button");
          document.getElementById("ButtonTogglePump").classList.remove("buttonDisabled");
        }
        if (document.getElementById("autoMode").innerHTML == "1") {
          document.getElementById("ButtonToggleAuto").style.border = "5px solid #00ff00";
        } else {
          document.getElementById("ButtonToggleAuto").style.border = "5px solid #000000";
        }
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
