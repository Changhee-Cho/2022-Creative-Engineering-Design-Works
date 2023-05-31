#include <Servo.h>

Servo myservo;

void setup(){
  myservo.attach(9);
  Serial.begin(9600);
  Serial.println("default angle : 90");
}

void loop(){
    if(Serial.available()){
      int angle=Serial.parseInt();
      char temp = Serial.read(); // parseInt 사용 후 원치않는 0이 입력되는 것을 막아줌
      if(angle>=0 && angle<=180)
      {
        myservo.write(angle);
        Serial.print("angle : "); 
        Serial.println(angle);
      }
      else
        Serial.println("입력오류, 0~180 사이의 값을 다시 입력하세요.");
  }
}
