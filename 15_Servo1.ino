#include <Servo.h>

int btn = 2;
int buz = 8;
int servo = 9;

int pos = 0;

Servo myservo;

void setup() {
  pinMode(btn, INPUT_PULLUP);
  pinMode(buz, OUTPUT);
  myservo.attach(servo);
  Serial.begin(9600);
}

void loop() {
  for(pos = 0; pos < 180; pos +=1)
  {
    myservo.write(pos);
    delay(50);
    digitalWrite(buz, LOW);
    if(!digitalRead(btn)==HIGH)
      Serial.println(pos);
  }
  for(pos = 180; pos >= 1; pos -= 1)
  {
    myservo.write(pos);
    delay(50);
    digitalWrite(buz, LOW);
    if(!digitalRead(btn)==HIGH)
    {
      Serial.println(pos);
      if(pos==180) // 버튼을 누르고 있는 상태에서 180도가 되면 beep 소리가 난다.
        digitalWrite(buz, HIGH);
    }
  }
}
