int InfraredPin = 2;
int led = 13;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(InfraredPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(InfraredPin) == HIGH) {
    digitalWrite(led, HIGH);
    Serial.println(digitalRead(InfraredPin));
  } else {
    digitalWrite(led,LOW);
    Serial.println(digitalRead(InfraredPin));
  }
  delay(1000);
}
//chan ben trai cung noi dat
//chan giua noi 5v
//chan ben phai noi chan 2
