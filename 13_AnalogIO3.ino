int sensorPin = 0;
int led1 = 2;
int led2 = 4;
int led3 = 5;
int led4 = 6;
int buz = 8;

void setup()
{
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(buz,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int sensorValue=0;
  int mappingValue=0;

  sensorValue=analogRead(sensorPin);
  mappingValue=map(sensorValue, 0, 1023, 0, 4);
  
  Serial.print("sensorValue: ");
  Serial.print(sensorValue);
  Serial.print(", ");
  Serial.print("mappingValue: ");
  Serial.print(mappingValue);
  Serial.print(", ");
  if(sensorValue==0)
  {
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    noTone(buz);
    Serial.print("tone: ");
    Serial.print(sensorValue);
    Serial.print("Hz, ");
    Serial.println("No level");
  }
  else if(mappingValue==0 && sensorValue>0)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    tone(buz,sensorValue);
    Serial.print("tone: ");
    Serial.print(sensorValue);
    Serial.print("Hz, ");
    Serial.println("level 1");
  }
  else if(mappingValue==1)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    tone(buz,sensorValue);
    Serial.print("tone: ");
    Serial.print(sensorValue);
    Serial.print("Hz, ");
    Serial.println("level 2");
  }
  else if(mappingValue==2)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
    tone(buz,sensorValue);
    Serial.print("tone: ");
    Serial.print(sensorValue);
    Serial.print("Hz, ");
    Serial.println("level 3");
  }
  else if(mappingValue>=3)
  {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
    tone(buz,sensorValue);
    Serial.print("tone: ");
    Serial.print(sensorValue);
    Serial.print("Hz, ");
    Serial.println("level 4");
  }
  delay(100);
}
