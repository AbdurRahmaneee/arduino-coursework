int butPin = 2;
int redPin = 10;
int br = 9600;
int butVal = 1;
int butValOld = 1;
int LEDstate = 0;
int dt(50);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(redPin, OUTPUT);
  pinMode(butPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  if (butValOld == 0 && butVal == 1) {
    if (LEDstate == 0) {
      digitalWrite(redPin, HIGH);
    }
    if (LEDstate == 1) {
      digitalWrite(redPin, LOW);
    }
    LEDstate = !LEDstate;
  }
  butValOld = butVal;
  delay(dt);
}
