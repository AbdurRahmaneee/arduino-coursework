int echoPin=5;
int trigPin = 6;
int pingTime;
float dist;
float speedRate = (767. * 63360.) / (60. * 60. * 1000.);
void setup() {
  // put your setup code here, to run once:
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pingTime = pulseIn(echoPin,HIGH);
  dist = speedRate * (pingTime / 1000.) / 2.;
  Serial.println(dist);

  delay(200);
}
