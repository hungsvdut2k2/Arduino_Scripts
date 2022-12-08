const char MAIN_page[] PROGMEM = R"=====(
  <!DOCTYPE html> 
  <html>
   <head> 
       <title>HOME PAGE</title> 
       <meta charset="UTF-8">
       <style> 
          body {text-align:center;}
          h1 {color:#003399;}
          a {text-decoration: none;color:#FFFFFF;}
          .bt_on {height:50px; width:100px; margin:10px 0;background-color:#FF6600;border-radius:5px;}
          .bt_off {height:50px; width:100px; margin:10px 0;background-color:#00FF00;border-radius:5px;}
       </style>
   </head>
   <body> 
      <div>Trạng thái trên chân D2: </div>
      <div>
        <button class="bt_on"><a href="/onD2">ON</a></button>
        <button class="bt_off"><a href="/offD2">OFF</a></button>
      </div>
      <div>Control DC motor </div>
      <div>
        <button class="bt_on"><a href="/onDC">ON</a></button>
        <button class="bt_off"><a href="/offDC">OFF</a></button>
      </div>
      <div>Control servo motor </div>
      <div>
        <button class="bt_on"><a href="/onSV90">SPIN 90 DEG</a></button>
        <button class="bt_on"><a href="/onSV180">SPIN 180 DEG</a></button>
        <button class="bt_off"><a href="/offSV">OFF</a></button>
      </div>
      <div>Control Step motor </div>
      <div>
        <button class="bt_on"><a href="/onStepMotor">ON</a></button>
        <button class="bt_off"><a href="/offStepMotor">OFF</a></button>
      </div>
      <div>
        Nhiet do: <span id="nhietdos">0</span><br>
        Do am: <span id="doams">0</span><br>
      </div>
      <div>
        Anh sang: <span id="anhsang"></span><br>
      </div>
      <div>
        Do line: <span id="doline"></span><br>
      </div>
      <script>
        setInterval(function() {
          getnhietdo();
          getdoam();
        }, 1000);
        function getnhietdo() {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
              document.getElementById("nhietdos").innerHTML = this.responseText;
            }
          };
          xhttp.open("GET", "docnhietdo", true);
          xhttp.send();
        }

        function getdoam() {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
              document.getElementById("doams").innerHTML = this.responseText;
            }
          };
          xhttp.open("GET", "docdoam", true);
          xhttp.send();
        }
                setInterval(function() {
          getLight();
        }, 1000);

        function getLight() {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
              document.getElementById("anhsang").innerHTML = this.responseText;
            }
          };
          xhttp.open("GET", "docdulieuanhsang", true);
          xhttp.send();
        }

        function getLine() {
          var xhttp = new XMLHttpRequest();
          xhttp.onreadystatechange = function() {
            if(this.readyState == 4 && this.status == 200) {
              document.getElementById("doline").innerHTML = this.responseText;
            }
          };
          xhttp.open("GET", "docdulieudoline", true);
          xhttp.send();
        }

        
      </script>
   </body> 
  </html>
)=====";