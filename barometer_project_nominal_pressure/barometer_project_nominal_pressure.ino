#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>

Adafruit_BMP085 BP;
bool BMPconnected = false;

float BarPress = 30;
float BarPressNow = 30;
float alt =  37.5;

int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BMPconnected = BP.begin();
  if (BMPconnected == true) {
    Serial.println("BMP180 found and Connected");
  }
  if (BMPconnected == false) {
    Serial.println("BMP180 not found, Check Connections");
  }
  oled.begin(SSD1306_SWITCHCAPVCC,SCREEN_ADDRESS);
  oled.clearDisplay();
  oled.display();
}

void loop() {
  // put your main code here, to run repeatedly:
  BarPressNow = normPress(alt);
  BarPress = .95*BarPress + .05*BarPressNow;
  oled.clearDisplay();
  oled.setCursor(0,12);
  oled.setTextColor(WHITE);
  oled.setTextSize(3);
  oled.println(BarPress);
  oled.println("In HG");
  oled.display();
}

float normPress(float elev){
  float BPRaw;
  float BPNorm;
  float T0 = 288.15;
  float L = .0065 ;
  float R = 8.3144598;
  float M = .0289644;
  float g = 9.8;
  float c = M*g/(R*L);
  BPRaw =BP.readPressure()*.0002953;
  BPNorm = BPRaw/pow(1-L*elev/T0,c);
  return BPNorm;
}