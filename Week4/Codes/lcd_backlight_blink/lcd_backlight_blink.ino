/*
 * This program is for blinking lcd backlight
 */
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();  // initialize the lcd
  lcd.clear();
  lcd.print("mmd");
}

void loop() {
  lcd.backlight(); // turn on backlight
  delay(500);
  lcd.noBacklight(); // turn off backlight
  delay(500);
}
