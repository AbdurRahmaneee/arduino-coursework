#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;

String message = "   HELLO FROM ARDUINO R4";
int br=9600;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  matrix.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  matrix.beginDraw();
  matrix.textScrollSpeed(50);
  matrix.textFont(Font_5x7);
  matrix.beginText(0,1,255,0,0);
  matrix.println(message);
  matrix.endText(SCROLL_LEFT);
  matrix.endDraw();

}
