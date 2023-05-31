#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
  lcd.begin(16,2);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available())
  {
    delay(10);
    int cnt = 0;
    int i = 0;
    lcd.setCursor(0,0);
    lcd.clear();
    while(Serial.available())
    {
      char val=Serial.read();

      Serial.print(val);
      lcd.print(val);
      cnt++;
      if(cnt==16)
        lcd.setCursor(0,1);
    }
    Serial.println();
    delay(1000);
    while(Serial.available()==0)
    {
      while(i<3)
      {
        lcd.noDisplay();
        delay(1000);
        lcd.display();
        delay(1000);
        i++;
        if(Serial.available()>0)
          break;
      }
      if(Serial.available()>0)
        break;
      lcd.scrollDisplayLeft();
      delay(300);
    }
   }
}
