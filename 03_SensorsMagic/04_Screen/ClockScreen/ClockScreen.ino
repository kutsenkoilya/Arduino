/*
 * Отображают время в формате 24:60:60s
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int counter;


void setup() {
  lcd.begin(16, 2);
  counter = 0;
}

void loop() {
  counter++;
  if (counter>86400)
  {
    counter = 0;
  }
  lcd.setCursor(0, 1);
  //потестить этот printf, должен работать в библиотекой 3ей версии
  lcd.Printf("%02d h %02d m %02d s", (int)counter/3600, (int)counter/60, (int)counter%60);
  delay(1000);
}
