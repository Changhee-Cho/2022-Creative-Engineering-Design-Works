int BUZ = 8;

// 1번과제 : 버저에서 소리가 단속적으로 10초 동안 발생
void setup()
{
  pinMode(BUZ, OUTPUT);
  for(int i=0; i<10; i++)
    {
      digitalWrite(BUZ, HIGH);
      delay(500);
      digitalWrite(BUZ, LOW);
      delay(500); 
    }
}

void loop()
{

}
