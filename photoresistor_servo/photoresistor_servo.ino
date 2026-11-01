#include <Servo.h>
int photoVal;
int br = 9600;
int dt=50;
int servoPin = 9;
int servoInp; //servo input in angle
Servo myServo;

// volatage
int volt; //value in voltage;

int lightPin=A0;
int lightVal;


void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin,INPUT);
  myServo.attach(servoPin);
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal=analogRead(lightPin); // 0-1023
  servoInp = (180./1023.) * lightVal; //servo input in angle (0-180)
  volt = (5./1023.) * lightVal; // value in voltage;
  Serial.print("lightVal: ");
  Serial.println(lightVal);
  Serial.print("servoAngle: ");
  Serial.println(servoInp);
  Serial.print("Voltage: ");
  Serial.println(volt);


  //servo control
  myServo.write(servoInp);
  // myServo.write(0);
  delay(dt);
}
