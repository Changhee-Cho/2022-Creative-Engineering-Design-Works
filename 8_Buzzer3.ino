int BUZ = 8;
int btn1 = 9;
int btn2 = 10;

// 5주차 3번과제 : 버튼 두 개를 사용하여 하나는 연속적인 소리, 다른 하나는 단속적인 소리가 나오게 함
void setup()
{
  pinMode(BUZ, OUTPUT);
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
}

void loop()
{
  // 위에 버튼만 누르면 연속적인 소리
  if(!digitalRead(btn1) && digitalRead(btn2))
    digitalWrite(BUZ, HIGH);

  // 아래 버튼만 누르면 단속적인 소리
  else if(digitalRead(btn1) && !digitalRead(btn2))
    {
      digitalWrite(BUZ, HIGH);
      delay(50);
      digitalWrite(BUZ, LOW);
      delay(50);
    }

  // 버튼 두 개를 동시에 눌렀거나 버튼을 아무것도 안 눌렀을 때
  else
    digitalWrite(BUZ, LOW);
  delay(100); // 하드웨어와 소프트웨어 간의 속도차이로 인한 동작 불량 발생을 예방하기 위해
}
