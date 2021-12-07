#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define FIVE 6
#define CO 13
#define CI 12

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); //LCD 초기화
  lcd.backlight(); //LCD 백라이트 켜기
  pinMode(FIVE, INPUT);
  pinMode(CO, OUTPUT);
  pinMode(CI, INPUT);
}

void reloadLcd() {
  digitalWrite(CO, HIGH);
  lcd.clear(); //LCD 모든 내용 삭제
  lcd.setCursor(0,0);
  lcd.print(":^D        Jelly");
  lcd.setCursor(0,1);
  lcd.print("is going to you!!");
  delay(5000);
  if(CI) {
    digitalWrite(CO, LOW);
  }
}

void loop() {
  
  int five = digitalRead(FIVE);
  lcd.clear(); //LCD 모든 내용 삭제
  lcd.setCursor(0,0);
  lcd.print("Put 500 won");
  lcd.setCursor(0,1);
  lcd.print("Put 500 won Put 500 won");
  
  if(five) {
    reloadLcd();
   }
}
