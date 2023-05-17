// sensor pins
#define SENSOR1 7
#define SENSOR2 6
#define SENSOR3 5
#define SENSOR4 4
#define SENSOR5 3
#define SENSOR6 2
#define SENSOR7 A0

// motor pins
#define IN1 13
#define IN2 8
#define ENA 11
#define IN3 12
#define IN4 9
#define ENB 10

const uint8_t sensor_pins[] = { SENSOR1, SENSOR2, SENSOR3, SENSOR4, SENSOR5, SENSOR6, SENSOR7 };
uint8_t sensor[7];

int8_t last_sensor = -1;

void setup() {
  Serial.begin(9600);

  for (uint8_t i = 0; i < 7; i++) {
    pinMode(sensor_pins[i], INPUT);
  }
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  readSensors();
  sensor_print();

  if (sensor[3]) last_sensor = 3;
  else if (sensor[4]) last_sensor = 4;
  else if (sensor[2]) last_sensor = 2;
  else if (sensor[5]) last_sensor = 5;
  else if (sensor[1]) last_sensor = 1;
  else if (sensor[6]) last_sensor = 6;
  else if (sensor[0]) last_sensor = 0;

  switch (last_sensor) {
    case 3: general_move(0, 1, 70, 0, 1, 70); break;
    case 4: general_move(0, 1, 90, 0, 1, 60); break;
    case 2: general_move(0, 1, 60, 0, 1, 90); break;
    case 5: general_move(0, 1, 90, 0, 0,255); break;
    case 1: general_move(0, 0,255, 0, 1, 90); break;
    case 6: general_move(0, 1, 70, 1, 0, 70); break;
    case 0: general_move(1, 0, 70, 0, 1, 70); break;
    default:general_move(0, 1, 70, 0, 1, 70); break;
  }
}

void readSensors() {
  for (uint8_t i = 0; i < 7; i++) {
    sensor[i] = digitalRead(sensor_pins[i]);
  }
}

// set robot movement by setting direction and speed of motor.
// set value of IN1, IN2, ENA, IN3, IN4, ENB.
void general_move(uint8_t in1, uint8_t in2, uint8_t ena, uint8_t in3, uint8_t in4, uint8_t enb) {
  digitalWrite(IN1, in1);
  digitalWrite(IN2, in2);
  digitalWrite(IN3, in3);
  digitalWrite(IN4, in4);
  analogWrite(ENA, ena);
  analogWrite(ENB, enb);
}

// Print IR sensor values on serial monitor to check the sensors
void sensor_print() {
  for (uint8_t i = 0; i < 7; i++) {
    Serial.print(sensor[i]);
    Serial.print("\t");
  }
  Serial.println("");
}
