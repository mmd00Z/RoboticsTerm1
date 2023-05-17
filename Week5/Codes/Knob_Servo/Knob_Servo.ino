#include <Servo.h>

#define POT_PIN A0  // analog pin used to connect the potentiometer
#define SERVO_PIN 5

Servo myservo;  // create servo object to control a servo

int val; // variable to read the value from the analog pin

void setup() {
  myservo.attach(SERVO_PIN); // attaches the servo on pin 9 to the servo object
}

void loop() {
  val = analogRead(POT_PIN);           // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it for use with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(10);                           // waits for the servo to get there
}
