int myInt;
float myFloat;
String myName;

int br=9600;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("What is your Number: ");
  while(Serial.available()==0) {
  }
  myInt=Serial.parseInt();
  Serial.print("Your number is: ");
  Serial.println(myInt);

  Serial.println("Please input a Float: ");
  while (Serial.available()==0) {
  }
  myFloat=Serial.parseFloat();
  Serial.print("Your Float is: ");
  Serial.println(myFloat);

  Serial.println("What is your Name: ");
  while(Serial.available()==0) {
  }
  myName=Serial.readString();
  Serial.print("Hello, ");
  Serial.print(myName);
  Serial.println(". Welcome to Arduino! ");
}
