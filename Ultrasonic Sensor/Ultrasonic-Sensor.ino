// constants won't change
const int TRIG_PIN = 9; // Arduino pin connected to Ultrasonic Sensor's TRIG pin
const int ECHO_PIN = 10; // Arduino pin connected to Ultrasonic Sensor's ECHO pin
const int LED_PIN  = 3; // Arduino pin connected to LED's pin
const int DISTANCE_THRESHOLD = 15; // centimeters

// variables will change:
float duration_us, distance_cm;

void setup() {
  pinMode(TRIG_PIN, OUTPUT); // set arduino pin to output mode
  pinMode(ECHO_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN, OUTPUT);  // set arduino pin to output mode
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);
  // calculate the distance
  distance_cm = 0.017 * duration_us; // 0.0343 * time/ 2 = 0.017 * time

  if (distance_cm < DISTANCE_THRESHOLD) {
    digitalWrite(LED_PIN, HIGH); // turn on LED
  } else {
    digitalWrite(LED_PIN, LOW);  // turn off LED
  }

  delay(500);
}
