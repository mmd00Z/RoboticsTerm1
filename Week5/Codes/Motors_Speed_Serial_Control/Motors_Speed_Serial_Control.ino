// Motors speed control from serial monitor
// Set ending char to No Line Ending!!

#define IN1 8 // motor pin 1
#define IN2 9 // motor pin 2
#define EN 10 // enabel pin (PWM)

void setup() {
  Serial.begin(9600);
  
  // set output motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

int speed = 0; // speed of motor value

void loop() {
  if(Serial.available()) {
    speed = Serial.parseInt(); // get speed from serial port
  }

  digitalWrite(IN1, 1); 
  digitalWrite(IN2, 0);
  analogWrite(EN, speed); // set speed
}
