int buzzPin = 9;
int dt = 500;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzPin, HIGH);
  delay(dt);
  digitalWrite(buzzPin,LOW);
  delay(dt);
}
