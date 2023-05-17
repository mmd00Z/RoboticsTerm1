/*
  This program controls the LED by button
*/


#define BUTTON 5  // IR button on pin 5
#define LED 3    // led on pin 13

void setup() {
  // set button as input pullup
  pinMode(BUTTON, INPUT_PULLUP);
  
  // set led as output
  pinMode(LED, OUTPUT);
}

void loop() {
  int button_val = digitalRead(BUTTON);

  // if(button_val == 0) {
  //   digitalWrite(LED, 1);
  // }
  // else {
  //   digitalWrite(LED, 0);
  // }

  digitalWrite(LED, !button_val);
}
