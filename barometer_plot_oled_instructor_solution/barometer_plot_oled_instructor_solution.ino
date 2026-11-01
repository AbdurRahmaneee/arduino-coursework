// ====================================================================
// DISCLAIMER:
// This code is provided as-is for educational and experimental 
// purposes only. The author makes no representations or warranties of 
// any kind concerning the safety, suitability, or accuracy of this 
// code. Use at your own risk. The author assumes no liability for any 
// damages, system failures, security breaches, or network issues 
// resulting from the use or implementation of this script.
// ====================================================================

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

float rawXdata[128];
int normXdata[128];

float rawYdata[128];
int normYdata[128];

float xMin = 0;
float xMax = 2 * 3.1415;

float yMin = -1;
float yMax = 1;

float Pt = 32;
float Pb = 63;

float Pl = 64;
float Pr = 127;

float pi = 3.14159265;

int numPoints = 128;

int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);

int j=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  oled.clearDisplay();
  oled.display();
}
void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < numPoints; i = i + 1) {
    rawXdata[i] = i * (2 * pi / 127);
    rawYdata[i] = sin(2*rawXdata[i]);
    Serial.println(rawYdata[i]);
    delay(100);
  }
normData();
plotGraph();
oled.display();
}

void normData() {
  for (int i = 0; i < numPoints; i = i + 1) {
    normYdata[i] = (Pb - Pt) / (yMin - yMax) * (rawYdata[i] - yMax) + Pt;
    normXdata[i] = (Pr - Pl) / (xMax - xMin) * (rawXdata[i] - xMin) + Pl;
  }
}
void plotGraph(){
    oled.drawLine(Pl,Pt,Pl,Pb,WHITE);
    oled.drawLine(Pl,Pb,Pr,Pb,WHITE);
  for (int i=0;i<numPoints-1;i=i+1){
  oled.drawLine(normXdata[i],normYdata[i],normXdata[i+1],normYdata[i+1],WHITE);
  }
}