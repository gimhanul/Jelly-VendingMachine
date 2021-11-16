#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define FIVE 6
#define CN 13

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init(); //LCD 초기화
  lcd.backlight(); //LCD 백라이트 켜기
  pinMode(FIVE, INPUT);
  pinMode(CN, OUTPUT);
  Serial.begin(9600);
}

void reloadLcd() {
  digitalWrite(CN, HIGH);
  lcd.clear(); //LCD 모든 내용 삭제
  lcd.setCursor(0,0);
  lcd.print(":^D        Jelly");
  lcd.setCursor(0,1);
  lcd.print("is going to you!!");
  digitalWrite(CN, LOW);
}

void loop() {
  byte doing = 0;
  int five = digitalRead(FIVE);

  
  if(!doing) {
    lcd.clear(); //LCD 모든 내용 삭제
    lcd.setCursor(0,0);
    lcd.print("Put 500 won");
    lcd.setCursor(0,1);
    lcd.print("Put 500 won Put 500 won");
  }
  if(five) {
    doing = 1;
    reloadLcd();
    doing = 0;
    five = 0;
    Serial.println("잘됨");
   }
}
