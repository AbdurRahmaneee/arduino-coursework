int butPin=2;
int butVal;
int br=115200;
int dt = 50;
int redPin=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(butPin, INPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  Serial.println(butVal);
if (butVal==1) {
  digitalWrite(redPin,LOW);
}else if (butVal==0) {
  digitalWrite(redPin,HIGH);
}

  delay(dt);

}
