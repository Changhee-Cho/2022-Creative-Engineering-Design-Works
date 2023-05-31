int led = 6;
int key1 = 13;
int key2 = 12; 

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(key1, INPUT_PULLUP);
  pinMode(key2, INPUT_PULLUP);
}

//3.XOR Gate
void loop()
{
  if(!digitalRead(key1) ^ !digitalRead(key2))
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);

  delay(100);
}
