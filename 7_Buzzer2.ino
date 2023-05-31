int BUZ = 8;
int btn = 9;

// 2번과제 : 버튼 하나를 누르면 소리가 나오도록 함
void setup()
{
  pinMode(BUZ, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop()
{
  if(!digitalRead(btn))
    digitalWrite(BUZ, HIGH);
  else
    digitalWrite(BUZ, LOW);
  delay(100); // 하드웨어와 소프트웨어 간의 속도차이로 인한 동작 불량 발생을 예방하기 위해
}
