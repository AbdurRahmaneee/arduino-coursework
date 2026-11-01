// Red LED
int butPinRed = 2;
int redPin = 10;
int butValRed = 1;
int butValOldRed = 1;
int LEDstateRed = 0;

// Blue LED
int butPinBlue = 4;
int BluePin = 12;
int butValBlue = 1;
int butValOldBlue = 1;
int LEDstateBlue = 0;

// Green LED
int butPinGreen = 3;
int GreenPin = 11;
int butValGreen = 1;
int butValOldGreen = 1;
int LEDstateGreen = 0;

int br = 9600;
int dt = 50;

void setup() {
  Serial.begin(br);

  pinMode(redPin, OUTPUT);
  pinMode(butPinRed, INPUT_PULLUP);

  pinMode(GreenPin, OUTPUT);
  pinMode(butPinGreen, INPUT_PULLUP);

  pinMode(BluePin, OUTPUT);
  pinMode(butPinBlue, INPUT_PULLUP);
}

void loop() {
  // Red
  butValRed = digitalRead(butPinRed);
  if (butValOldRed == 0 && butValRed == 1) {
    LEDstateRed = !LEDstateRed;
    digitalWrite(redPin, LEDstateRed ? HIGH : LOW);
  }
  butValOldRed = butValRed;

  // Green
  butValGreen = digitalRead(butPinGreen);
  if (butValOldGreen == 0 && butValGreen == 1) {
    LEDstateGreen = !LEDstateGreen;
    digitalWrite(GreenPin, LEDstateGreen ? HIGH : LOW);
  }
  butValOldGreen = butValGreen;

  // Blue
  butValBlue = digitalRead(butPinBlue);
  if (butValOldBlue == 0 && butValBlue == 1) {
    LEDstateBlue = !LEDstateBlue;
    digitalWrite(BluePin, LEDstateBlue ? HIGH : LOW);
  }
  butValOldBlue = butValBlue;

  delay(dt);
}