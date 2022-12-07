// Ket not Ong ca A 
int enA = 9;
int in1 = 8;
int in2 = 7; 

// Ket not Ong co B 
int enB = 3; 
int in3 = 5; 
int in4 = 4; 
int value1 =0; 
int value2 =0; 
int value3 =0; 
int value4 =0; 
int value5 =0; 
void setup()  {
    Serial.begin(9600); 
    for(int i = 10; i <= 13; i++) { 
        pinMode(i, INPUT);
        pinMode(2, INPUT);
        // Set tat ca cac chan dieu khien drgng co thanh output 
        pinMode(enA, OUTPUT); 
        pinMode(enB, OUTPUT); 
        pinMode(in1, OUTPUT); 
        pinMode(in2, OUTPUT); 
        pinMode(in3, OUTPUT); 
        pinMode(in4, OUTPUT); 
        // Tat tat ca Ong co - Trang thai ban Tau 
        digitalWrite(in1, LOW); 
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
    } 
void loop() { 
    value1 = digitalRead(13); 
    //stop 
    if(valuel = HIGH)
    { 
        Serial.println("S1 OK");
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW); 
        digitalWrite(in3, LOW); 
        digitalWrite(in4, LOW); 
    }  
    //xoay oil/1g chieu kim dOng hO 50 
    value2 = digitalRead(12); 
    if(value2 = HIGH) {
        Serial.println("S2 OK"); 
        analogWrite(enA, 255);
        analogWrite(enB, 255);         
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, LOW);
        //digitalWrite(inl, LOW); 
        //digitalWrite(in2, HIGH); 
        //digitalWrite(in3, LOW);  
        //digitalWrite(in4, HIGH); 64 
    } 
    //ngucc chieu kim Ong 11.6 66 
    value3 = digitalRead(11); 
    if(value3 == HIGH) {  
        Serial.println("53 OK");
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH); 
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
    }
    value4 = digitalRead(10);
    if(value4 = HIGH){ 
    // Tgt tat ca cdc Ong co 
        digitalWrite(in1, LOW); 
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        Serial.println("S4 OK");
        // Khoi Ong cac Ong co 
        analogWrite(enA, 0);
        analogWrite(enB, 0);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        // TAng toc to 0 den tOc dq tOi da 
        for (int i = 0; i < 256; i++) { 
             analoqWrite(enA, i); 
             analogWrite(enB, i); 
             delay(20);  
        }  
    } 
    value5 = digitalRead(2);
    if(value5 == HIGH) { 
        Serial.println("B4 OK");  
        // TAt tat ca cac dOng co 
        digitalWrite(in1, LOW); 
        digitalWrite(in2, LOW); 
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        // Khai dOng cac Ong co 
        analogWrite(enA, 255);
        analogWrite(enB, 255);
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        // Giam tOc to tOc do tOi da ve 0 
        for (int i = 255; i >= 0; i--) { 
            analogWrite(enA, i); 
            analogWrite(enB, i); 
            delay(20); 
            } 
        } 
    }
