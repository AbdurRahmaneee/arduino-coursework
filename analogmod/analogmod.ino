int redPin=11;
int b1=0;
int b2=5;
int b3=20;
int b4=60;
int b5=100;
int b6=150;
int b7=200;
int b8=255;
int waitT=500;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(redPin,b1);
  delay(waitT);

  analogWrite(redPin,b2);
  delay(waitT);

  analogWrite(redPin,b3);
  delay(waitT);

  analogWrite(redPin,b4);
  delay(waitT);

  analogWrite(redPin,b5);
  delay(waitT);

  analogWrite(redPin,b6);
  delay(waitT);

  analogWrite(redPin,b7);
  delay(waitT);

  analogWrite(redPin,b8);
  delay(waitT);

  analogWrite(redPin,b7);
  delay(waitT);

  analogWrite(redPin,b6);
  delay(waitT);

  analogWrite(redPin,b5);
  delay(waitT);

  analogWrite(redPin,b4);
  delay(waitT);

  analogWrite(redPin,b3);
  delay(waitT);

  analogWrite(redPin,b2);
  delay(waitT);

  analogWrite(redPin,b1);
  delay(waitT);
}
