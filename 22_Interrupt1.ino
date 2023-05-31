#define BOUNCE_TIME 190
int btn = 0;
volatile int pressed=0;
volatile unsigned long last_int_time=0;

void setup()
{
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
  attachInterrupt(btn, button, FALLING);
}

void loop()
{
  
}

void button(){
  unsigned long int_time = millis();
  if(int_time - last_int_time > BOUNCE_TIME)
  {
      pressed++;
      Serial.print("Button has been pressed ");
      Serial.print(pressed);
      Serial.println(" times");
  }
  last_int_time=int_time;
}
