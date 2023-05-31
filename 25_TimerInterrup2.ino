// led1은 1초마다 꺼졌다가 켜지기를 반복
// led2는 버튼을 누를 때 생성되는 난수(1~5)를 interval에 곱해 버튼을 누르고 있는 상태에서는 1~5초 사이의 간격으로 랜덤하게 점멸

const int led1 = 8;
const int led2 = 9;
const int btn = 10;

int led1_status = LOW;
int led2_status = LOW;
int random_status = LOW;
int randval = 0;

unsigned long previousMillis = 0;
unsigned long btnpreviousMillis = 0;

const long interval = 1000;
int led2_interval = 0;

void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(btn, INPUT_PULLUP);
}

void loop(){
  unsigned long currentMillis = millis();
  
  if(currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    if(led1_status == LOW)
      led1_status = HIGH;
    else
      led1_status = LOW;
    digitalWrite(led1, led1_status);
  }
  
  if(!digitalRead(btn))
  {
    if(random_status == LOW)
    {
      randval=random(1,6);
      random_status = HIGH;
      btnpreviousMillis = currentMillis;
      led2_interval = interval * randval;
    }
   
    if(currentMillis - btnpreviousMillis >= led2_interval)
    {
      btnpreviousMillis = currentMillis;

      if(led2_status == LOW)
        led2_status = HIGH;
      else
        led2_status = LOW;
    }
  }
  else
  {
    led2_status = LOW;
    random_status = LOW;
  }
  digitalWrite(led2, led2_status);
}
