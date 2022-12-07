#include <DHT.h>
float sinVal = 0;
float toneVal = 0;
const int DHTPIN = 4;      
const int DHTTYPE = DHT11;  
int alarm = 8;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  pinMode(alarm, OUTPUT);
  dht.begin();       
}

void loop() {
  float h = dht.readHumidity();    
  float t = dht.readTemperature(); 

  Serial.print("Nhiet do: ");
  Serial.println(t);               
  Serial.print("Do am: ");
  Serial.println(h);  
  Serial.println();
  if(t >= 28.0) {
    sinWaveSound();               
  } else {
    noTone(alarm);
  }
  delay(1000);                     
}
//dat: chan input
void sinWaveSound(){
  for(int x = 0; x < 180; x++) {
    sinVal = (sin(x * (3.1412 / 180)));
    toneVal = 2000 + (int(sinVal * 1000));
    tone(alarm, toneVal);
    delay(2);
  }
}
