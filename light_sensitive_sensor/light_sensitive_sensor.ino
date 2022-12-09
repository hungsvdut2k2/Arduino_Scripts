int led = 13;
int light = 0;
int val = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(light);
  Serial.println(val);
  if(val < 700) {
    digitalWrite(led, LOW);
  } else {
    digitalWrite(led, HIGH);
  }
  delay(10);
}
//den: 1 chan dai noi chan 13
//chan ngan: chan noi dat
//cam bien:
// vcc : 5v
// gnd : noi dat
// a0: chan a0