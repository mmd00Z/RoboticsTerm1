#define LED_PIN 3

void setup() {
  Serial.begin(9600);

  pinMode(LED_PIN, OUTPUT);
}


void loop() {
  String state;

  if (Serial.available()) {
    state = Serial.readString();
  }
  
  if (state == "on") {
    digitalWrite(LED_PIN, 1);
  } else if (state == "off") {
    digitalWrite(LED_PIN, 0);
  }
}
