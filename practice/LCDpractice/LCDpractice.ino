#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); //LCD객체 생성

void setup() {
  lcd.init(); //LCD 초기화
  lcd.backlight(); //LCD 백라이트 켜기
}

void loop() {
  //setCursor(n, m); -> m번째 줄 n번째 셀부터 입력
  lcd.setCursor(0,0);
  lcd.print("gim...");
  lcd.setCursor(0,1);
  lcd.print("gimigiminow");
  delay(3000);
  lcd.clear(); //LCD 모든 내용 삭제
}
