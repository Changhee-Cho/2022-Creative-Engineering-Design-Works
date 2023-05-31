int sensorPin = 0;
int buz = 8;

void setup()
{
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue=0;
  sensorValue=analogRead(sensorPin);
  
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  Serial.print(", ");
  if(sensorValue==0)
    noTone(buz);
  else
    tone(buz, sensorValue);
  Serial.print("tone: ");
  Serial.print(sensorValue);
  Serial.println("Hz");
  delay(100);
}
