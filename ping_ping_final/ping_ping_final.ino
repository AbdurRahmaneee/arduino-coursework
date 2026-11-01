#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String message = "  GAME OVER";
int br=9600;
int dt=250;
int xPos=3;
int yPos=2;
int deltaX=1;
int deltaY=1;
int i;
int j;
int butPin=2;
int butPin2=3;
int myRow=4;
int butVal;
int butVal2;
int rowInc=1;
int cnt=0;


byte frame[8][12];


void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  matrix.begin();
  pinMode(butPin,INPUT_PULLUP);
  pinMode(butPin2,INPUT_PULLUP);
}

void loop() {
  butVal=digitalRead(butPin);
  butVal2=digitalRead(butPin2);

  if (butVal==0){
    myRow=myRow+rowInc;
  }
  if (butVal2==0){
    myRow=myRow-rowInc;
  }

  if (cnt%2==0){
    for (i=0; i<=11; i=i+1){
      for (j=0; j<=7; j=j+1){
        frame[j][i]=0;
        if (i==xPos && j==yPos){
          frame[j][i]=1;
        }
      if (i==0 && j==myRow) {
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

    if (xPos==0 && yPos!=myRow){
      Serial.println("Game Over, Player 1");
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0,1,255,0,0);
    matrix.println(message);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
      delay(5000);
    }

    xPos=xPos+deltaX;
    yPos=yPos+deltaY;
  }
  cnt=cnt+1;
  delay(dt);
}
