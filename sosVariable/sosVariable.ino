int redPin=3;
int greenPin=12;
int dit=150;
int dah=500;
int endWait=1000;
float myPi=3.14159265;
char myInitial='P';
String myName="Abdur Rahman"; 

void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  // pinMode(11, OUTPUT);
  // pinMode(10, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redPin,HIGH);
  delay(dit);
  digitalWrite(redPin,LOW);
  delay(dit);

  digitalWrite(redPin,HIGH);
  delay(dit);
  digitalWrite(redPin,LOW);
  delay(dit);

  digitalWrite(redPin,HIGH);
  delay(dit);
  digitalWrite(redPin,LOW);
  delay(dit);

  digitalWrite(greenPin,HIGH);
  delay(dah);
  digitalWrite(greenPin,LOW);
  delay(dah);

  digitalWrite(greenPin,HIGH);
  delay(dah);
  digitalWrite(greenPin,LOW);
  delay(dah);

  digitalWrite(greenPin,HIGH);
  delay(dah);
  digitalWrite(greenPin,LOW);
  delay(dah);




  delay(endWait);
}
