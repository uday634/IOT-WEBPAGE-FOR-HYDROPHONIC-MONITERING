const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link href="https://use.fontawesome.com/releases/v5.7.2/css/all.css" rel="stylesheet">
    <style>
      html {
        font-family: Arial;
        display: inline-block;
        margin: 0px auto;
        text-align: center;
      }
      h1 { font-size: 2.0rem; }
      p { font-size: 2.0rem; }
      .units { font-size: 1.2rem; }
      .dht-labels{
        font-size: 1.5rem;
        vertical-align:middle;
        padding-bottom: 15px;
      }
      
    </style>
  </head>
  <body>
    <h1>NodeMCU ESP8266 Monitoring Sensor DHT11</h1>
    <p>
      <i class="fa fa-thermometer-half" style="font-size:3.0rem;color:#62a1d3;"></i> 
      <span class="dht-labels">Temperature : </span> 
      <span id="TemperatureValue">0</span>
      <sup class="units">&deg;C</sup>
    </p>
    <p>
      <i class="fa fa-tint" style="font-size:3.0rem;color:#75e095;"></i>
      <span class="dht-labels">Humidity : </span>
      <span id="HumidityValue">0</span>
      <sup class="units">%</sup>
    </p>
    <p>
        <i class="fas fa-water" style="font-size:3.0rem;color:#6ec4fd;"></i>
        <span class="dht-labels">Water Level : </span>
        <span id="WaterLevelValue">0</span>
        <sup class="units">%</sup>
      </p>
      <p>
        <i class="fas fa-temperature-low" style="font-size:3.0rem;color:#7fdbb6;"></i>
        <span class="dht-labels">Water Temperature : </span>
        <span id="WaterTemperatureValue">0</span>
        <sup class="units">&deg;C</sup>
      </p>
      <p>
        <i class="fas fa-flask" style="font-size:3.0rem;color:#ff851b;"></i>
        <span class="dht-labels">pH Value : </span>
        <span id="PHValue">0</span>
      </p>
      
    <p>
      <i class="far fa-clock" style="font-size:1.0rem;color:#e3a8c7;"></i>
      <span style="font-size:1.0rem;">Time </span>
      <span id="time" style="font-size:1.0rem;"></span>
      
      <i class="far fa-calendar-alt" style="font-size:1.0rem;color:#f7dc68";></i>
      <span style="font-size:1.0rem;">Date </span>
      <span id="date" style="font-size:1.0rem;"></span>
    </P>
  <p>
    <i class="fab fa-youtube" style="font-size:1.0rem;color:red;"></i>
    <span style="font-size:1.0rem;">Don't Forget to Subscribe </span>
    <a href="https://www.youtube.com/channel/UCk8rZ8lhAH4H-75tQ7Ljc1A" target="_blank" style="font-size:1.0rem;">Uteh Str YouTube Channel</a>
  </P>
    <script>
      setInterval(function() {
        // Call a function repetatively with 2 Second interval
        getTemperatureData();
        getHumidityData();
      }, 2000); 
      
      setInterval(function() {
        // Call a function repetatively with 1 Second interval
        Time_Date();
      }, 1000); 

      function getTemperatureData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
            document.getElementById("TemperatureValue").innerHTML =
            this.responseText;
          }
        };
        xhttp.open("GET", "readTemperature", true);
        xhttp.send();
      }

      function getHumidityData() {
        var xhttp = new XMLHttpRequest();
        xhttp.onreadystatechange = function() {
          if (this.readyState == 4 && this.status == 200) {
          document.getElementById("HumidityValue").innerHTML =
          this.responseText;
          }
        };
        xhttp.open("GET", "readHumidity", true);
        xhttp.send();
      }
      function getPHData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("PHValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readPH", true);
  xhttp.send();
}
function getWaterLevelData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("WaterLevelValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readWaterLevel", true);
  xhttp.send();
}
function getWaterTemperatureData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("WaterTemperatureValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readWaterTemperature", true);
  xhttp.send();
}
setInterval(function() {
  // Call a function repetitively with 2 Second interval
  getTemperatureData();
  getHumidityData();
  getPHData();
  getWaterLevelData();
  getWaterTemperatureData();
}, 2000); 




      function Time_Date() {
        var t = new Date();
        document.getElementById("time").innerHTML = t.toLocaleTimeString();
        var d = new Date();
        const dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday","Saturday"];
        const monthNames = ["January", "February", "March", "April", "May", "June","July", "August", "September", "October", "November", "December"];
        document.getElementById("date").innerHTML = dayNames[d.getDay()] + ", " + d.getDate() + "-" + monthNames[d.getMonth()] + "-" + d.getFullYear();
      }
    </script>
  </body>
</html>
)=====";
