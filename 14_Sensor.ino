int cds = A0;
int temp = A1;

int btn = 5;
int led1 = 2;
int led2 = 3;
int led3 = 4;

int cdsValue = 0;
int btn_status = LOW;
float tempValue = 0;

void setup() {
  Serial.begin(9600);
  pinMode(btn, INPUT_PULLUP);
  pinMode(cds, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  if(!digitalRead(btn) && btn_status==LOW)
  {
    btn_status=HIGH;
    cdsValue=analogRead(cds);
    tempValue=(analogRead(temp));
    Serial.print("Temp is ");
    Serial.print((5.0*tempValue*100)/1024.0);
    Serial.print(" and Light is ");
    if(cdsValue <= 150)
    {
      Serial.println("Off");
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if(cdsValue <= 300)
    {
      Serial.println("Low");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, LOW);
      digitalWrite(led3, LOW);
    }
    else if(cdsValue <= 500)
    {
      Serial.println("Medium");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, LOW);
    }
    else
    {
      Serial.println("High");
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
    }
  }
  if(!digitalRead(btn)==LOW)
    btn_status=LOW;
  delay(100);
}
