#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16,2);
  lcd.clear();
}

void loop(){
  // CLCD 문자가 00100001부터 있기에 33부터 시작,
  // 11111111에서 끝나기에 255에서 종료
  /*
     교안파일과 tinker cad의 문자 set이 차이가 있음
     예로, 교안에 따르면 10000000(10진수 128)은 없어야 하지만,
     틴커캐드에서 실행 결과 존재함을 확인

     256 부터는 문자 Set이 없음을 확인하였음.
   */
  
  for(int i=33; i<=255; i++)
  {
    //lcd에서 16번째마다 줄바꿈, 화면이 차면, lcd를 clear함
    //계속 무한반복으로 모든 Character Set이 출력됨.
  if(i>33&&(i%16)==1)
    lcd.setCursor(0,1);
  if(i%32==1)
    lcd.clear();
  lcd.write(i);
  delay(700);
  }
}
