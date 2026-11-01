#include <Stepper.h>
int STEPS = 2038;
int rpm = 15;
Stepper stepper(STEPS, 9, 5, 6, 7);  // pin 3->IN1, 6->IN2, 5->IN3, 7->IN4
int butPin = 8;
int butVal = 1;
int butValOld = 1;

int butPin2 = 12;
int butVal2 = 1;
int butValOld2 = 1;

int butPin3 = 11;
int butVal3 = 1;
int butValOld3 = 1;


void setup() {
  // put your setup code here, to run once:
  pinMode(butPin, INPUT_PULLUP);
  pinMode(butPin2, INPUT_PULLUP);
  pinMode(butPin3, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  butVal2 = digitalRead(butPin2);
  butVal3 = digitalRead(butPin3);
  if (butValOld == 0 && butVal == 1) {
    stepper.setSpeed(rpm);
    stepper.step(STEPS / 4);
    // delay(1000);
    // stepper.setSpeed(rpm);
    // stepper.step(-STEPS);
  }
  butValOld = butVal;

  if (butValOld2 == 0 && butVal2 == 1) {
    stepper.setSpeed(rpm);
    stepper.step(STEPS / 2);
    // delay(1000);
    // stepper.setSpeed(rpm);
    // stepper.step(-STEPS / 36);
  }
  butValOld2 = butVal2;

  if (butValOld3 == 0 && butVal3 == 1) {
    stepper.setSpeed(rpm);
    stepper.step(-(STEPS / 2));
    // delay(1000);
    // stepper.setSpeed(rpm);
    // stepper.step(-STEPS / 36);
  }
  butValOld3 = butVal3;

  delay(100);
}
