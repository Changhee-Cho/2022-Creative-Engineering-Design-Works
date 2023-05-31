int btn = 10;
int status = LOW;
void setup()
{
  pinMode(btn, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop()
{
  static int pressed = 0;
  if(!digitalRead(btn)==HIGH && status==LOW)
  {
    pressed++;
    Serial.print("Button has been pressed ");
    Serial.print(pressed);
    Serial.println(" times");
    delay(200);
    status=HIGH;
  }
  if(!digitalRead(btn)==LOW)
  status=LOW;
}
