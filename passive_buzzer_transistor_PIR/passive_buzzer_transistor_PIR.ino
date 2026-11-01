int buzzPin = 8;
int pirPin = 12;
int motion = 0;
// int freq;
// int note;
// int dt = 100;
void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(115200);
  pinMode(pirPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly : 
  motion = digitalRead(pirPin);
  if (motion == HIGH) {
    Serial.println("Intruder Alert!!");
    tone(buzzPin, 480, 500);
    delay(500);

    tone(buzzPin, 600, 500);
    delay(500);
  }
  else{
    Serial.println("Monitoring .... All Clear");
    tone(buzzPin, 200, 50);
    delay(100);
  }

  // delay(10);
}