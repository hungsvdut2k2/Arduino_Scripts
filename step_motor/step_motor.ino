int motorPinl = 8; 
int motorPin2 = 9; 
int motorPin3 = 10; 
int motorPin4 = 11; 
int step_number = 0; 
void setup(){ // put your setup code here, to run once: 
    pinMode(motorPinl, OUTPUT); 
    pinMode(motorPin2, OUTPUT); 
    pinMode(motorPin3, OUTPUT); 
    pinMode(motorPin4, OUTPUT); 
}
void loop() {// put your main code here, to run repeatedly: 
    OneStep(true); //truy4n tham sd true/false la chi6u quay clia dOng co 
    delay(2); 
}
void OneStep(bool dir){ 
    if (dir) { 
        switch(step_number){ 
            case 0:
                digitalWrite(motorPinl, HIGH);
                digitalWrite(motorPin2, LOW);
                digitalWrite(motorPin3, LOW);
                digitalWrite(motorPin4, LOW);
                break; 
            case 1: 
                digitalWrite(motorPinl, LOW);
                digitalWrite(motorPin2, HIGH);               
                digitalWrite(motorPin3, LOW);
                digitalWrite(motorPin4, LOW);
                break; 
            case 2: 
                digitalWrite(motorPinl, LOW);
                digitalWrite(motorPin2, LOW);
                digitalWrite(motorPin3, HIGH);
                digitalWrite(motorPin4, LOW);
                break; 
            case 3: 
                digitalWrite(motorPinl, LOW);              
                digitalWrite(motorPin2, LOW);
                digitalWrite(motorPin3, LOW);
                digitalWrite(motorPin4, HIGH);
                break; 
        }
    }else{
        switch (step_number){ 
            case 0: 
                digitalWrite (motorPinl, LOW) ; 
                digitalWrite (motorPin2, LOW) ; 
                digitalWrite (motorPin3, LOW) ; 
                digitalWrite (motorPin4, HIGH) ; 
                break;
            case 1: 
                digitalWrite (motorPinl, LOW) ; 
                digitalWrite (motorPin2, LOW) ; 
                digitalWrite (motorPin3, HIGH) ; 
                digitalWrite(motorPin4, LOW) ; 
                break; 
            case 2: 
                digitalWrite (motorPinl, LOW) ; 
                digitalWrite (motorPin2, HIGH) ; 
                digitalWrite (motorPin3, LOW) ; 
                digitalWrite (motorPin4, LOW) ; 
                break;
            case 3: 
                digitalWrite (motorPinl, HIGH) ; 
                digitalWrite (motorPin2, LOW) ; 
                digitalWrite (motorPin3, LOW) ; 
                digitalWrite (motorPin4, LOW) ; 
                break; 
        }
    }
    step_number++; 
    if (step_number > 3){ 
        step_number = 0;
    } 
}


