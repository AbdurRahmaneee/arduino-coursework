#include <Servo.h>
int servoPin=9;
int servoAngle;
int br=115200;
String prompt="What Angle do you Desire?";
Servo myServo;
int dt=100;
int i;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(prompt);
  // while(Serial.available()==0) {
  // }
  // servoAngle = Serial.parseInt();
  // myServo.write(servoAngle);
  // delay(dt);
  for (i=0; i<=180; i++) {
    myServo.write(i);
    delay(dt);
  }

  for (i=180; i>=0; i--) {
    myServo.write(i);
    delay(dt);
  }
}
