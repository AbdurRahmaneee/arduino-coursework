#include <Servo.h>
int potPin=A2;
int potVal;
int br = 9600;
int dt=50;
int servoPin = 9;
int servoInp; //servo input in angle
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  Serial.begin(br);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin); // 0-1023
  servoInp = (180./1023.) * potVal; //servo input in angle (0-180)
  Serial.print("potVal: ");
  Serial.println(potVal);
  
  Serial.print("   servoInp: ");
  Serial.println(servoInp);
  myServo.write(servoInp);

  delay(dt);
}
