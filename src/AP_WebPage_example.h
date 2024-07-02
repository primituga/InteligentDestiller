const char MAIN_page[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html>
  <style>
    .card {
      max-width: 500px;
      min-height: 850px;
      background: #02b875;
      padding: 5px;
      color: #FFF;
      margin: 0 auto;
      box-shadow: 0px 20px 18px -4px rgba(255, 160, 0, 1);
    }

    html {
      font-family: Helvetica;
      display: inline-block;
      margin: 0px auto;
      text-align: center;
    }

    .button {
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

    button:hover {
      background-color: blue;
    }

    button:active {
      background-color: red;
    }

    .button2 {
      background-color: #555555;
      border: none;
      border-radius: 15px;
      color: white;
      padding: 10px 10px;
      text-decoration: none;
      font-size: 20px;
      margin: 2px;
      cursor: pointer;
    }

    body {
      background-color: #191970;
      font-size: 100%;
      color: #FFFFFF;
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
  <body>
    <div class="card">
      <h3>
        <span id="timerbuttons"></span>
      </h3>
      <br>
      <button class="button" onclick="startTimer()">Start</button>
      <button class="button" onclick="stopTimer()">Stop</button>
      <button class="button" onclick="resetTimer()">Reset</button>
      <br>
      <h3>Timer: <span id="timer">0</span>
      </h3>
      <br>
      <button class="button" onclick="add1s()">+1s</button>
      <button class="button" onclick="add5s()">+5s</button>
      <button class="button" onclick="add10s()">+10s</button>
      <button class="button" onclick="add1m()">+1m</button>
      <button class="button" onclick="add5m()">+5m</button>
      <button class="button" onclick="add10m()">+10m</button>
      <br>
      <button class="button" onclick="rem1s()">-1s</button>
      <button class="button" onclick="rem5s()">-5s</button>
      <button class="button" onclick="rem10s()">-10s</button>
      <button class="button" onclick="rem1m()">-1m</button>
      <button class="button" onclick="rem5m()">-5m</button>
      <button class="button" onclick="rem10m()">-10m</button>
      <br>
      <h3>Auto mode: <span id="autoMode">0</span>
      </h3>
      <h3>Resistor: <span id="resistor">0</span>
      </h3>
      <button class="button" onclick="toggleAutoMode()">Auto</button>
    </div>
    <script>
      setInterval(function() {
        // Call a function repetatively with 1 Second interval
        getTimerData();
        getAutoData();
        getResistorData();
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
    </script>
  </body>
</html>
)=====";

