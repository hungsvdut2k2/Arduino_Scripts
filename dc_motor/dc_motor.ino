int IN1 = 9;
int IN2 = 10;

int potpin = 0; // A0

void setup()
{
    Serial.begin(9600);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
}

void loop()
{

    // doc val tu bien tro
    int val = analogRead(potpin);
    Serial.println(val);

    int speed = val / 4;

    // -> run with speed by val
    motorRun(speed);

    // -> spin with max speed
    // motorRun(-1);

    // -> spin with speed by val (reverse)
    // motorRunReverse(speed);

    // -> spin with max speed (reverse)
    // motorRunReverse(-1);

    // -> stop motor
    // motorStop();

    delay(100);
}

void motorStop()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
}

void motorRun(int speed)
{
    if (speed == -1)
    {
        digitalWrite(IN1, HIGH);
        digitalWrite(IN2, LOW);
    }

    if (speed != -1)
    {
        analogWrite(IN1, speed);
        digitalWrite(IN2, LOW);
    }
}

void motorRunReverse(int speed)
{
    if (speed == -1)
    {
        digitalWrite(IN1, LOW);
        digitalWrite(IN2, HIGH);
    }

    if (speed != -1)
    {
        analogWrite(IN1, LOW);
        digitalWrite(IN2, speed);
    }
}
