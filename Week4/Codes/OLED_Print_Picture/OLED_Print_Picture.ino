#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include "pictures.h"

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// On an arduino Nano:       A4(SDA), A5(SCL)
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // See datasheet for Address. 0x3D or 0x3C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);  // Don't proceed, loop forever
  }

  // show Sampad logo
  oled.clearDisplay();
  // x, y, picture, width, height
  oled.drawBitmap((oled.width()  - SAMPAD_WIDTH ) / 2, (oled.height() - SAMPAD_HEIGHT) / 2, sampad, SAMPAD_WIDTH, SAMPAD_HEIGHT, WHITE);
  oled.display();

  delay(3000);

  // show Harrys scar
  oled.clearDisplay();
  oled.drawBitmap((oled.width()  - HP_WIDTH ) / 2, (oled.height() - HP_HEIGHT) / 2, hp, HP_WIDTH, HP_HEIGHT, WHITE);
  oled.display();
  delay(3000);
}

uint16_t delay_val = 30;

void loop() {
  for(int i=0; i<7; i++){
    oled.clearDisplay();
    oled.drawBitmap((oled.width()  - WALKING_WIDTH ) / 2, (oled.height() - WALKING_HEIGHT) / 2, walking[i], WALKING_WIDTH, WALKING_HEIGHT, WHITE);
    oled.display();
    delay(delay_val);
  }
}

