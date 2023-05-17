// In this program, the intensity of the LED light is controlled so that the LED turns on and off slowly.

#define LED 3

void setup() {
}

void loop() {
  // smooth and slowly turn on
  for(int i=0; i<256; i++) { // make counter in range 0 to 255
    analogWrite(LED, i); // set PWM to pin
    delay(4);
  }

  delay(200);

  // smooth and slowly turn off
  for(int i=255; i>=0; i--) { // make counter in range 0 to 255
    analogWrite(LED, i); // set PWM to pin
    delay(4);
  }

  delay(200);
}
