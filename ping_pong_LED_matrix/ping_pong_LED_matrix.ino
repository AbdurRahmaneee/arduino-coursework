#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String message = "   HELLO FROM ARDUINO R4";
int br=9600;
int dt=50;
int xPos=3;
int yPos=2;
int deltaX=1;
int deltaY=1;
int i;
int j;

byte frame[8][12];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  matrix.begin();
}

void loop() {
  for (i=0; i<=11; i=i+1){
    for (j=0; j<=7; j=j+1){
      frame[j][i]=0;
      if (i==xPos && j==yPos){
        frame[j][i]=1;
      }
    }
  }
  matrix.renderBitmap(frame,8,12);
  if (xPos>11 || xPos<=0){
    deltaX=-deltaX;
  }
  if (yPos>=7 || yPos<=0){
    deltaY=-deltaY;
  }
  xPos=xPos+deltaX;
  yPos=yPos+deltaY;
  delay(dt);
}
