const int _a=2;
const int _b=3;
const int _c=4;
const int _d=5;
const int _e=6;
const int _f=7;
const int _g=8;
const int _dp=9;

void display()
{     
  // 1. 모든  LED를 3번 깜빡임
  for(int i=0; i<3; i++)
  {
      // 1초간 모든 LED 켜기
      digitalWrite(_a,LOW);
      digitalWrite(_b,LOW);
      digitalWrite(_c,LOW);
      digitalWrite(_d,LOW);
      digitalWrite(_e,LOW);
      digitalWrite(_f,LOW);
      digitalWrite(_g,LOW);
      digitalWrite(_dp,LOW);
      delay(1000);

      // 1초간 모든 LED 끄기
      digitalWrite(_a,HIGH);
      digitalWrite(_b,HIGH);
      digitalWrite(_c,HIGH);
      digitalWrite(_d,HIGH);
      digitalWrite(_e,HIGH);
      digitalWrite(_f,HIGH);
      digitalWrite(_g,HIGH);
      digitalWrite(_dp,HIGH);
      delay(1000);
  }
      // 2. HELLO를 1초에 한 문자씩 출력(글자 구분을 위해 단어가 바뀌고 1초 지난 후 1초간 모든 LED 끄기 적용)
      for(int j=0; j<=4; j++)
      {
        switch(j)
        {
          case 0:
            // H
            digitalWrite(_a,HIGH);
            digitalWrite(_b,LOW);
            digitalWrite(_c,LOW);
            digitalWrite(_d,HIGH);
            digitalWrite(_e,LOW);
            digitalWrite(_f,LOW);
            digitalWrite(_g,LOW);
            digitalWrite(_dp,HIGH);
            delay(1000);
            break;
          case 1:
            // E
            digitalWrite(_a,LOW);
            digitalWrite(_b,HIGH);
            digitalWrite(_c,HIGH);
            digitalWrite(_d,LOW);
            digitalWrite(_e,LOW);
            digitalWrite(_f,LOW);
            digitalWrite(_g,LOW);
            digitalWrite(_dp,HIGH);
            delay(1000);
            break;
          case 2:
            // L
            digitalWrite(_a,HIGH);
            digitalWrite(_b,HIGH);
            digitalWrite(_c,HIGH);
            digitalWrite(_d,LOW);
            digitalWrite(_e,LOW);
            digitalWrite(_f,LOW);
            digitalWrite(_g,HIGH);
            digitalWrite(_dp,HIGH);
            delay(1000);
            break;
          case 3:
            // L
            digitalWrite(_a,HIGH);
            digitalWrite(_b,HIGH);
            digitalWrite(_c,HIGH);
            digitalWrite(_d,LOW);
            digitalWrite(_e,LOW);
            digitalWrite(_f,LOW);
            digitalWrite(_g,HIGH);
            digitalWrite(_dp,HIGH);
            delay(1000);
            break;
          case 4:
            // O
            digitalWrite(_a,LOW);
            digitalWrite(_b,LOW);
            digitalWrite(_c,LOW);
            digitalWrite(_d,LOW);
            digitalWrite(_e,LOW);
            digitalWrite(_f,LOW);
            digitalWrite(_g,HIGH);
            digitalWrite(_dp,HIGH);
            delay(1000);
            break;          
        }
             // switch(j)가 break문으로 빠져 나올 때마다 단어 구분을 위해 1초간 모든 LED 끄기
            digitalWrite(_a,HIGH);
            digitalWrite(_b,HIGH);
            digitalWrite(_c,HIGH);
            digitalWrite(_d,HIGH);
            digitalWrite(_e,HIGH);
            digitalWrite(_f,HIGH);
            digitalWrite(_g,HIGH);
            digitalWrite(_dp,HIGH);
            delay(1000);
     }
}

void setup()
{
  pinMode (_a,OUTPUT);
  pinMode (_b,OUTPUT);
  pinMode (_c,OUTPUT);
  pinMode (_d,OUTPUT);
  pinMode (_e,OUTPUT);
  pinMode (_f,OUTPUT);
  pinMode (_g,OUTPUT);
  pinMode (_dp,OUTPUT); 
  pinMode (10,OUTPUT);       
  digitalWrite(10,HIGH);
}

void loop()
{
  // 3. 1부터 반복
  display();
}
