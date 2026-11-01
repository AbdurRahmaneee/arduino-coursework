#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

int br=9600;
int dt=150;
int i;
int j;


byte frame[8][12]={
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0,0,0,0},
};
void setup() {
  // put your setup code here, to run once:
    Serial.begin(br);
    matrix.begin();

}

void loop() {
  // put your main code here, to run repeatedly:
  for (i=0; i<=11; i++){
    for (j=0; j<=7; j++){
    frame[j][i] = !frame[j][i];
    
  }
  matrix.renderBitmap(frame,8,12);
  delay(dt);
  }
  
}
