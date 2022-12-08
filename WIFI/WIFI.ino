#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <DHT.h>
#include "html.h"
#include <Servo.h>    
#include <Stepper.h> 
Servo myservo; 
     
const int DHTTYPE = DHT11;  

DHT dht(D1, DHTTYPE);

const int stepsPerRevolution = 2048;
Stepper myStepper = Stepper(stepsPerRevolution, D5, D7, D6, D8);
float nhietdo;
float doam;
int val_Light;
int val_Gas;
int val_Line;
int val_Motion;
ESP8266WebServer server(80);
char* ssid = "Le Hoang T3";
char* pass = "12345678";

void docdulieunhietdo() {
  nhietdo = dht.readTemperature();
  String snhietdo = String(nhietdo);
  if(isnan(nhietdo)) {
    server.send(200, "text/plain", "Cam bien khong hoat dong");
  }
  else {
    server.send(200, "text/plain", snhietdo + "°C");
  }
}

void docdulieudoam() {
  doam = dht.readHumidity();
  String sdoam = String(doam);
  if(isnan(doam)) {
    server.send(200, "text/plain", "Cam bien khong hoat dong");
  }
  else {
    server.send(200, "text/plain", sdoam + "%");
  }
}

void docdulieuanhsang(){
  val_Light = analogRead(0);
  String light = String(val_Light);
  // Serial.println(val_Light);
  // delay(1000);
  if (val_Light == 4 || val_Light == 5){
    server.send(200, "text/plain", "Cam bien khong hoat dong");
  }
  else {
    if (val_Light < 750){
      server.send(200, "text/plain", light);
    }
    else {
      server.send(200, "text/plain", "Khong co anh sang");
    }
  }
}

void docdulieudoline(){
  val_Line = digitalRead(0);
  Serial.println(val_Line);
  delay(1000);
  if (val_Line == NULL){
    server.send(200, "text/plain", "Cam bien khong hoat dong");
  }
  else {
    if (val_Line > 750){
      server.send(200, "text/plain", "Line den");
    }
    else {
      server.send(200, "text/plain", "Line trang");
    }
  }
}


void setup() {
  myStepper.setSpeed(15);
  pinMode(D4,OUTPUT); // DC  // in1
  pinMode(D3,OUTPUT); // DC  // in2
  pinMode(D2,OUTPUT); // LED
  myservo.attach(D0); // SERVO
  pinMode(D1, INPUT);
  myservo.write(0);
  dht.begin();
  WiFi.begin(ssid,pass);
  Serial.begin(9600);
  Serial.println("Connecting");
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());

  server.on("/",mainpage);
  server.on("/docnhietdo", docdulieunhietdo);
  server.on("/docdoam", docdulieudoam);
  // server.on("/docdulieuanhsang", docdulieuanhsang);
  server.on("/docdulieudoline", docdulieudoline);
  // server.on("/docdulieusieuam", docdulieusieuam);
  // server.on("/docdulieuchuyendong", docdulieuchuyendong);
  server.on("/onD2",on_D2);
  server.on("/offD2",off_D2);
  server.on("/onDC",on_DC);
  server.on("/offDC",off_DC);
  server.on("/onSV90",on_SV90);
  server.on("/onSV180",on_SV180);
  server.on("/offSV",off_SV);
  server.on("/onStepMotor",on_StepMotor);
  server.on("/offStepMotor",off_StepMotor);
  server.begin();
}
void loop() {
  server.handleClient();
}

void mainpage(){
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void on_D2(){
  digitalWrite(D2, HIGH);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void off_D2(){
  digitalWrite(D2, LOW);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void on_DC(){
  digitalWrite(D3, HIGH);
  digitalWrite(D4, LOW);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void off_DC(){
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void on_SV90(){
  myservo.write(180);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void on_SV180(){
  myservo.write(240);
    
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void off_SV(){
  myservo.write(0);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}

void on_StepMotor(){
  myStepper.step(stepsPerRevolution);
  delay(100);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
void off_StepMotor(){
  myStepper.step(0);
  String s = FPSTR(MAIN_page);
  server.send(200,"text/html",s);
}
