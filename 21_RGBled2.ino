int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup()
{
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  // 0~255 사이의 난수 추출
  int randRed=(random(256));
  int randGreen=(random(256));
  int randBlue=(random(256));

  setColor(randRed, randGreen, randBlue);
  valPrint(randRed, randGreen, randBlue);
  delay(1000);
}

void setColor(int redv, int greenv, int bluev){
  analogWrite(redPin, redv);
  analogWrite(greenPin, greenv);
  analogWrite(bluePin, bluev);
}

void valPrint(int redv, int greenv, int bluev){
  // RGB led가 anode type이기에 255를 빼 줘야 실제 출력되는 led 색상이랑 맞게 나옴.
  Serial.print("Red: ");
  Serial.print(255-redv);
  Serial.print(", ");
  Serial.print("Green: ");
  Serial.print(255-greenv);
  Serial.print(", ");
  Serial.print("Blue: ");
  Serial.println(255-bluev);
}
