float myPi=3.14;
float myRadius=2;
float myArea;
String mess1="A Circle of Radius ";
String mess2=" Has an Area of ";
int waitT=1000;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  myArea=myPi*myRadius*myRadius;
  Serial.print(mess1);
  Serial.print(myRadius);
  Serial.print(mess2);
  Serial.println(myArea);
  delay(waitT);
  myRadius=myRadius+.1;
}
