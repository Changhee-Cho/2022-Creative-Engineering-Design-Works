#define BOUNCE_TIME 190
int btn = 0;
int red = 9;
int green = 10;
int blue = 11;

volatile int state = 0;
volatile unsigned long last_int_time = 0;
void setup()
{
  pinMode(2, INPUT_PULLUP);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  attachInterrupt(btn, rgb, FALLING);

  //common anode type 이므로 처음 상태 전원 off로 초기화
  digitalWrite(red, HIGH);
  digitalWrite(green, HIGH);
  digitalWrite(blue, HIGH);
}

void loop()
{
  
}

void rgb(){
  unsigned long int_time = millis();
  if(int_time - last_int_time > BOUNCE_TIME)
  {
      switch(state)
      {
        case(0):
          digitalWrite(red,LOW);
          break;
        case(1):
          digitalWrite(red, HIGH);
          break;
        case(2):
          digitalWrite(green, LOW);
          break;
        case(3):
          digitalWrite(green, HIGH);
          break;
        case(4):
          digitalWrite(blue, LOW);
          break;
        case(5):
          digitalWrite(blue, HIGH);
          break;
      }
      state++;
      if(state == 6)
        state = 0;
  }
  last_int_time = int_time;
}
