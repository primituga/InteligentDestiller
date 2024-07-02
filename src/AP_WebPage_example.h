  const char MAIN_page[] PROGMEM = R"=====(<!DOCTYPE html>
<html>
<style>
.card{
  max-width: 400px;
   min-height: 250px;
   background: #02b875;
   padding: 5px;
   box-sizing: border-box;
   color: #FFF;
   margin:20px;
   box-shadow: 0px 2px 18px -4px rgba(0,0,0,0.75);
}
</style>
<body>

<div class="card">
  <h3>Auto mode:<span id="autoMode">0</span></h3><br>
  <h3>Resistor:<span id="resistor">0</span></h3><br>
  <button onclick="toggleAuto">Toggle Auto Mode</button>
</div>
<script>

setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getAutoData();
  getResistorData();
}, 1000); //2000mSeconds update rate

function getAutoData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {
    document.getElementById("autoMode").innerHTML =
    this.responseText;
  }
  };
  xhttp.open("GET", "readAuto", true);
  xhttp.send();
}

function getResistorData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {
    document.getElementById("resistor").innerHTML =
    this.responseText;
  }
  };
  xhttp.open("GET", "readResistor", true);
  xhttp.send();
}

function toggleAutoMode() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
  if (this.readyState == 4 && this.status == 200) {
    // Update the auto mode value
    document.getElementById("toggleAuto").innerHTML =
    this.responseText;
  }
  };
  xhttp.open("GET", "toggleAuto", true); 
  xhttp.send();
}

</script>
</body>
</html>)=====";

