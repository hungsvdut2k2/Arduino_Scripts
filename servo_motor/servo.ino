#include <Servo.h>
Servo myservo;
int potpin = 0;
int val;
int toneVal;
float sinVal;

void setup() {
  myservo.attach(9);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(potpin);

  val = map(val, 0, 1023, 0, 180);

  myservo.write(val);
  Serial.println(val);

  if (val > 90) {
    piezoSound();  
  } else {
    noTone(8);  
  }

  delay(15);
  
}

void piezoSound() {
  for (int i = 0; i < 180; i++){
      sinVal = sin(i * 3.1412 / 180);
      toneVal = int(sinVal * 1000) + 2000;
      tone(8, toneVal);
  }
}
