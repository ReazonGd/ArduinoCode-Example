int lamp1 = 2,
int lamp2 = 3;

void setup(){
    pinMode(lamp1,OUTPUT);
    pinMode(lamp2,OUTPUT);
}

void loop(){
    digitalWrite(lamp2,LOW);
    digitalWrite(lamp1,HIGH);
    delay(1000);
    digitalWrite(lamp1,LOW);
    digitalWrite(lamp2,HIGH);
    delay(1000);
}
