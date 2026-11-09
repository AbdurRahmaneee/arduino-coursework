void setup() {
  // Configure pins 10, 11, 12, and 13 as outputs
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

// Helper function to turn all 4 LEDs ON or OFF
void setAllLeds(uint8_t state) {
  digitalWrite(13, state);
  digitalWrite(12, state);
  digitalWrite(11, state);
  digitalWrite(10, state);
}

// Function for a short blink (Dot)
void dot() {
  setAllLeds(HIGH);
  delay(200);
  setAllLeds(LOW);
  delay(200); // Gap between dots/dashes
}

// Function for a long blink (Dash)
void dash() {
  setAllLeds(HIGH);
  delay(600);
  setAllLeds(LOW);
  delay(200); // Gap between dots/dashes
}

void loop() {
  // Letter 'S' (... short, short, short)
  dot(); dot(); dot();

  delay(400); // Additional gap between letters (total 600 ms)

  // Letter 'O' (--- long, long, long)
  dash(); dash(); dash();

  delay(400); // Additional gap between letters (total 600 ms)

  // Letter 'S' (... short, short, short)
  dot(); dot(); dot();

  // Wait 2 seconds before repeating the full SOS sequence
  delay(2000);
}