const int _a=2;
const int _b=3;
const int _c=4;
const int _d=5;
const int _e=6;
const int _f=7;
const int _g=8;
const int _dp=9;

//1,4. a-b-c-d-e-f 순방향이나 역방향으로 회전하는 함수
void circle(int k)
{
    switch(k)
    {
      //a
      case 0:
        digitalWrite(_a,LOW);
        digitalWrite(_b,HIGH);
        digitalWrite(_c,HIGH);
        digitalWrite(_d,HIGH);
        digitalWrite(_e,HIGH);
        digitalWrite(_f,HIGH);
        digitalWrite(_g,HIGH);
        digitalWrite(_dp,HIGH);
        delay(1000);
        break;

      //b
      case 1:
        digitalWrite(_a,HIGH);
        digitalWrite(_b,LOW);
        digitalWrite(_c,HIGH);
        digitalWrite(_d,HIGH);
        digitalWrite(_e,HIGH);
        digitalWrite(_f,HIGH);
        digitalWrite(_g,HIGH);
        digitalWrite(_dp,HIGH);
        delay(1000);
        break;

      //c
      case 2:
        digitalWrite(_a,HIGH);
        digitalWrite(_b,HIGH);
        digitalWrite(_c,LOW);
        digitalWrite(_d,HIGH);
        digitalWrite(_e,HIGH);
        digitalWrite(_f,HIGH);
        digitalWrite(_g,HIGH);
        digitalWrite(_dp,HIGH);
        delay(1000);
        break;

      //d
      case 3:
        digitalWrite(_a,HIGH);
        digitalWrite(_b,HIGH);
        digitalWrite(_c,HIGH);
        digitalWrite(_d,LOW);
        digitalWrite(_e,HIGH);
        digitalWrite(_f,HIGH);
        digitalWrite(_g,HIGH);
        digitalWrite(_dp,HIGH);
        delay(1000);
        break;


      //e
      case 4: 
        digitalWrite(_a,HIGH);
        digitalWrite(_b,HIGH);
        digitalWrite(_c,HIGH);
        digitalWrite(_d,HIGH);
        digitalWrite(_e,LOW);
        digitalWrite(_f,HIGH);
        digitalWrite(_g,HIGH);
        digitalWrite(_dp,HIGH);
        delay(1000);
        break;

      //f
      case 5:
        digitalWrite(_a,HIGH);
        digitalWrite(_b,HIGH);
        digitalWrite(_c,HIGH);
        digitalWrite(_d,HIGH);
        digitalWrite(_e,HIGH);
        digitalWrite(_f,LOW);
        digitalWrite(_g,HIGH);
        digitalWrite(_dp,HIGH);
        delay(1000);
        break;
  }
}

//2,4. a,b,c,d,e,f가 동시에 2번 깜빡이는 함수
void blinker()
{
      // 깜빡이 효과를 위해 전체 1초 꺼짐
      digitalWrite(_a,HIGH);
      digitalWrite(_b,HIGH);
      digitalWrite(_c,HIGH);
      digitalWrite(_d,HIGH);
      digitalWrite(_e,HIGH);
      digitalWrite(_f,HIGH);
      digitalWrite(_g,HIGH);
      digitalWrite(_dp,HIGH);
      delay(1000);

   // 2.a,b,c,d,e,f 동시에 2번 깜빡임
   for (int j=0; j<2; j++)
   {
      digitalWrite(_a,LOW);
      digitalWrite(_b,LOW);
      digitalWrite(_c,LOW);
      digitalWrite(_d,LOW);
      digitalWrite(_e,LOW);
      digitalWrite(_f,LOW);
      digitalWrite(_g,HIGH);
      digitalWrite(_dp,HIGH);
      delay(1000);
      
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
  pinMode(_a,OUTPUT);
  pinMode(_b,OUTPUT);
  pinMode(_c,OUTPUT);
  pinMode(_d,OUTPUT);
  pinMode(_e,OUTPUT);
  pinMode(_f,OUTPUT);
  pinMode(_g,OUTPUT);
  pinMode(_dp,OUTPUT);
  pinMode(10,OUTPUT);
  digitalWrite(10,HIGH);
}

void loop()
{
    //1-4 반복
    int i;
    int k;
    
    //1. a-b-c-d-e-f 순방향 3번 회전
    for(i=0;i<3;i++)
      {
        for(k=0;k<=5;k++)
          circle(k);
      }
    
    //2. a,b,c,d,e,f 동시에 2번 깜빡이는 함수 호출
    blinker();

    //3. 1과 반대 방향으로 3번 회전
    for(i=0;i<3;i++)
    {
        for(k=5;k>=0;k--)
          circle(k);
    }

    //4. a,b,c,d,e,f 동시에 2번 깜빡이는 함수 호출
    blinker();
}
