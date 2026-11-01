int MS;
int BI = 10;
int FI = 9;
int potPin = A2;
int butPin = 2;
int butCount = 0;
int butVal = 0;
int butValOld = 0;
int PV;
int rem = 0;
void setup() {
  // put your setup code here, to run once:
  pinMode(BI, OUTPUT);
  pinMode(FI,OUTPUT);
  pinMode(potPin, INPUT);
  pinMode(butPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  if (butVal==0 && butValOld==1){
    butCount= butCount + 1;
    if (rem==1){
      analogWrite(FI, 0);
      analogWrite(BI, 0);
      delay(1000);
    }
  }
  butValOld=butVal;
  rem=butCount%3;
  PV = analogRead(potPin);
  MS = 205./1023. * PV +50;
  if (rem == 0) {
    analogWrite(FI, 0);
    analogWrite(BI, 0);
  }
  if (rem == 1){
    analogWrite(FI, MS);
    analogWrite(BI, 0);    
  }
  if (rem == 2) {
    analogWrite(FI, 0);
    analogWrite(BI, MS);
  }
}
