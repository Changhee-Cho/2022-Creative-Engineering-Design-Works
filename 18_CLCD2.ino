#include <LiquidCrystal.h>

int tempPin=A0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 온
byte newChar1[8] = {
        B01110,
        B10001,
        B01110,
        B00100,
        B11111,
        B10000,
        B10000,
        B11111
};
//도
byte newChar2[8] = {
        B11111,
        B10000,
        B10000,
        B11111,
        B00000,
        B00100,
        B00100,
        B11111
};
//º
byte newChar3[8] = {
        B00110,
        B01001,
        B01001,
        B00110,
        B00000,
        B00000,
        B00000,
        B00000
};

void setup(){
  lcd.begin(16,2);
  lcd.createChar(0, newChar1);
  lcd.createChar(1, newChar2);
  lcd.createChar(2, newChar3);
}

void loop(){
  lcd.clear();
  lcd.setCursor(0,0);

  // 틴커캐드 내 TMP36 온도센서의 온도 공식, temp가 최종 온도 값
  int readValue=analogRead(tempPin);
  float voltage = readValue*5.0/1024.0;
  float temp=voltage*100-50;
  
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(" ");
  lcd.print(temp);
  lcd.write(byte(2));
  lcd.write("C");
  delay(1000); // 1초에 한 번씩 샘플링
}
