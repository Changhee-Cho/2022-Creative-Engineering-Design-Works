int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup(){
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop(){
  for(int i=0; i<7; i++)
  {
    switch(i)
    {
      case 0: // 빨
        setColor(255,0,0);
        break;
      case 1: // 주
        setColor(255,50,0);
        break;
      case 2: // 노
        setColor(255,255,0);
        break;
      case 3: // 초
        setColor(0,255,0);
        break;
      case 4: // 파
        setColor(0,0,255);
        break;
      case 5: // 남
        setColor(0,5,255);
        break;
      case 6: // 보
        setColor(100,0,255);
        break;
    }
    delay(500); // 0.5초 간격
  }
}

void setColor(int redv, int greenv, int bluev){
  // common anode type 이므로 255를 빼준 값을 적용함
  analogWrite(redPin, 255-redv);
  analogWrite(greenPin, 255-greenv);
  analogWrite(bluePin, 255-bluev);
}
