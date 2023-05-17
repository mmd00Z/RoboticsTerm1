// Motors speed control from serial monitor
// Set ending char to No Line Ending!!

#define IN1 8 // motor pin 1
#define IN2 9 // motor pin 2
#define EN 10 // enabel pin (PWM)
#define POT A0 // potentiometer pin

void setup() {
  Serial.begin(9600);
  
  // set output motor pins
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

int speed = 0; // speed of motor value

void loop() {
  //      0 - 1023 / 4 ==> 0 - 255
  speed = analogRead(POT) / 4; // get speed from potentiometer
  Serial.println(analogRead(POT));
  delay(100);

  digitalWrite(IN1, 0); 
  digitalWrite(IN2, 1);
  analogWrite(EN, speed); // set speed
}
