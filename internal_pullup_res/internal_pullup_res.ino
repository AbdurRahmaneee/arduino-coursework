int butPin=6;
int butVal;
int  br=9600;
int dt=100;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(butPin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal=digitalRead(butPin);
  Serial.println(butVal);
  delay(dt);
}
