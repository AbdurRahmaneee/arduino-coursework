int pirPin = 2;
int motion = 0;
int dt = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(pirPin, INPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  motion = digitalRead(pirPin);
  if (motion == HIGH){
    Serial.println("Intruder Alert!!");
  }
  if (motion == LOW) {
    Serial.println("Monitoring .... All Clear");
  }
  
  delay(100);
}
