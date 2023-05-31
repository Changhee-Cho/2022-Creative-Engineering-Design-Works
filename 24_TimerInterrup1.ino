const int led1 = 8;
const int led2 = 9;

int led1_status = LOW;
int led2_status = HIGH;
unsigned long previousMillis = 0;
const long interval = 500;

void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop(){
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    if(led1_status == LOW)
    {
      led1_status = HIGH;
      led2_status = LOW;
    }
    else
    {
      led1_status = LOW; 
      led2_status = HIGH;
    }
    digitalWrite(led1, led1_status);
    digitalWrite(led2, led2_status);
  }
}
