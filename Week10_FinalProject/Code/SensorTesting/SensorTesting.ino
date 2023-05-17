#define SENSOR1 7
#define SENSOR2 6
#define SENSOR3 5
#define SENSOR4 4
#define SENSOR5 3
#define SENSOR6 2
#define SENSOR7 A0

const uint8_t sensor_pins[] = {SENSOR1, SENSOR2, SENSOR3, SENSOR4, SENSOR5, SENSOR6, SENSOR7};

void setup() {
  Serial.begin(9600);

  for (uint8_t i=0; i<7; i++) {
    pinMode(sensor_pins[i], INPUT);
  }
}

void loop() {
  sensor_print();
  delay(200);
}

// Print IR sensor values on serial monitor to check the sensors
void sensor_print() {
  for (uint8_t i=0; i<7; i++) {
    Serial.print(digitalRead(sensor_pins[i])); Serial.print("\t");
  }
  Serial.println("");
}
