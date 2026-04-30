// On digital pin 
const int SW_pin = 2;

const int X_pin  = 0;   // X-axis signal
const int Y_pin  = 1;   // Y-axis signal

// LED pins (on digtial pins)
#define UP_LED    11
#define RIGHT_LED 10
#define LEFT_LED  9
#define DOWN_LED  8

// Thresholds for joystick directions (kinda like our origion point)
const int THRESHOLD_HIGH = 900;   // near 1023 (max)
const int THRESHOLD_LOW  = 100;   // near 0 (min)

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);    
  Serial.begin(115200);

  pinMode(UP_LED,    OUTPUT);
  pinMode(RIGHT_LED, OUTPUT);
  pinMode(LEFT_LED,  OUTPUT);
  pinMode(DOWN_LED,  OUTPUT);
}

void loop() {
  // Read joystick values ONCE per loop
  int xVal = analogRead(X_pin);
  int yVal = analogRead(Y_pin);
  int swVal = digitalRead(SW_pin);

  // --- LED control logic using thresholds ---
  
  if (xVal >= THRESHOLD_HIGH) {           // UP
    digitalWrite(UP_LED,    HIGH);
    digitalWrite(DOWN_LED,  LOW);
    digitalWrite(LEFT_LED,  LOW);
    digitalWrite(RIGHT_LED, LOW);
  }
  else if (xVal <= THRESHOLD_LOW) {       // DOWN
    digitalWrite(DOWN_LED,  HIGH);
    digitalWrite(UP_LED,    LOW);
    digitalWrite(LEFT_LED,  LOW);
    digitalWrite(RIGHT_LED, LOW);
  }
  else if (yVal >= THRESHOLD_HIGH) {      // RIGHT
    digitalWrite(RIGHT_LED, HIGH);
    digitalWrite(UP_LED,    LOW);
    digitalWrite(DOWN_LED,  LOW);
    digitalWrite(LEFT_LED,  LOW);
  }
  else if (yVal <= THRESHOLD_LOW) {       // LEFT
    digitalWrite(LEFT_LED,  HIGH);
    digitalWrite(UP_LED,    LOW);
    digitalWrite(DOWN_LED,  LOW);
    digitalWrite(RIGHT_LED, LOW);
  }
  else if (swVal == LOW) {               // Button pressed – all LEDs ON
    digitalWrite(UP_LED,    HIGH);
    digitalWrite(DOWN_LED,  HIGH);
    digitalWrite(LEFT_LED,  HIGH);
    digitalWrite(RIGHT_LED, HIGH);
  }
  else {                                 // Neutral position – all LEDs OFF
    digitalWrite(UP_LED,    LOW);
    digitalWrite(DOWN_LED,  LOW);
    digitalWrite(LEFT_LED,  LOW);
    digitalWrite(RIGHT_LED, LOW);
  }

  delay(500);   // small delay for stable serial output (half a second)
}
