int readPin = A2;
int LEDPin = 9;
int dt = 100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(readPin, INPUT);
  pinMode(LEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  float potVal;
  float brightVal;
  potVal = readPot(readPin);
  Serial.println(potVal);
  brightVal = findBright(potVal);
  Serial.println(brightVal);
  setLED(LEDPin, brightVal);


  delay(dt);
}

float readPot(int potPin) {
  float readVal;
  readVal = analogRead(potPin);
  return readVal;
}

float findBright(int pv) {
  float bv;
  // bv=(255./1023.)*pv;
  bv = pow(2, (pv / 127.875)) - 1;
  return bv;
}

void setLED(int lp, float bv) {
  analogWrite(lp, bv);
}
