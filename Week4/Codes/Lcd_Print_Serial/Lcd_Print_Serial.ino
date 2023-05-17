/*
 * Displays text sent over the serial port (e.g. from the Serial Monitor) on an attached LCD.
 */
 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  lcd.init();  // initialize the lcd
  lcd.backlight(); // turn on backlight

  Serial.begin(9600); // serial begin
  while (!Serial); // wait to serial port opening
}

void loop() {
  // when characters arrive over the serial port...
  if (Serial.available()) {
    // clear the screen
    lcd.clear();

    // read the string
    String str = Serial.readString();
    str.remove(str.length() - 1); // remove last char (\n) from the text

    // display each character to the LCD
    lcd.print(str);
  }
}
