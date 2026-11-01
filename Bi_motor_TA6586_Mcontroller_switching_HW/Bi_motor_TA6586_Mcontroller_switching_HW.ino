int potPin = A2;
int BI = 10;
int FI = 9;
int MS;
int dt = 100;
int butVal = 1;
int butValOld = 1;
int potVal;
int butPin = 2;
int Mstate = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(potPin, INPUT);
  pinMode(BI, OUTPUT);
  pinMode(FI, OUTPUT);
  pinMode(butPin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(potPin);
  MS = (255. / 1023.) * potVal;
  butVal = digitalRead(butPin);
  if (butValOld == 0 && butVal == 1) {
    if (Mstate == 0) {
      analogWrite(FI, 0);
      analogWrite(BI, 0);
      delay(dt);
      analogWrite(FI, MS);
      analogWrite(BI, 0);
    }
    if (Mstate == 1) {
      analogWrite(FI, 0);
      analogWrite(BI, 0);
      delay(dt);
      analogWrite(FI, 0);
      analogWrite(BI, MS);
    }
    Mstate = !Mstate;
  }
  butValOld = butVal;
  


  // Serial.println(MS);
  // analogWrite(FI, MS);
  // analogWrite(BI, 0);
  delay(dt);
}
