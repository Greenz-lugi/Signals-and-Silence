int sensor = 2; 
int led = 13; 
boolean is_on = false; // default is that led is off so false

void setup() {
  // Using INPUT_PULLUP ensures the pin isn't "floating"
  pinMode(sensor, INPUT_PULLUP); 
  pinMode(led, OUTPUT); 
}

void loop() {
  int data = digitalRead(sensor); 

  // Most KY-038 modules pull the pin LOW when sound is detected.
  if (data == HIGH) { // btw high would mean we picked up noise (so when i'm snapping)
    is_on = !is_on; // Toggle the state
    digitalWrite(led, is_on ? HIGH : LOW);
    
    // Crucial: Wait long enough for the sound to finish 
    // this gets rid of our bug earlier
    delay(600); 
  }
}
