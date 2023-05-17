#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino Nano:       A4(SDA), A5(SCL)
#define OLED_RESET -1        // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C  // See datasheet for Address. 0x3D or 0x3C
Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);

  if (!oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    while (true);  // Don't proceed, loop forever
  }
  oled.clearDisplay();
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available()) {
    oled.clearDisplay();

    //Parameters: x, y, size, color, text
    oled_print(0, 16, 2, WHITE, Serial.readString());
  }

  oled.startscrollleft(0x0, 0x07);
}

void oled_print(int16_t x, int16_t y, uint8_t s, uint16_t c, String text) {
  oled.setCursor(x, y);         // set text position
  oled.setTextSize(s);          // set text size
  oled.setTextColor(c, BLACK);  // set text color and background color
  oled.print(text);             // set text
  oled.display();               // show text
}