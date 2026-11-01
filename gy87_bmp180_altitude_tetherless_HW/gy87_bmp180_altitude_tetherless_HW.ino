#include <Adafruit_BMP085.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

Adafruit_BMP085 BP;
bool BMPconnected;
bool haveBase = false;

float basePressure;
float Height = 0;
float HeightNow = 0;

int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);

int butPin = 8;
int butVal = 1;
// int butValOld = 1;
// int state = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BMPconnected = BP.begin();
  pinMode(butPin, INPUT_PULLUP);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  if (BMPconnected == true) {
    Serial.println("BMP found and Connected.");
  }
  if (BMPconnected == false) {
    Serial.println("BMP180 Not Found! Check Connections.");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (haveBase == false) {

    oled.clearDisplay();
    oled.display();
    oled.setCursor(0, 0);
    oled.setTextColor(WHITE);
    oled.setTextSize(1);
    oled.print("Press to Register Base Height.");
    oled.display();

    // butVal = digitalRead(butPin);
    while (digitalRead(butPin) == 1) {}
    // Serial.println("Place Device at Base, Enter Go:");
    // while (Serial.available() == 0) {}
    basePressure = BP.readPressure();
    haveBase = true;
  }
  HeightNow = findHeight(basePressure);
  Height = .95 * Height + 0.05 * HeightNow;
  // Serial.print(4);
  // Serial.print(",");
  // Serial.print(-5);
  // Serial.print(",");
  // Serial.print(HeightNow);
  // Serial.print(",");
  // Serial.println(Height);
  oled.clearDisplay();
  oled.display();
  oled.setCursor(0, 0);
  oled.setTextColor(WHITE);
  oled.setTextSize(2);
  oled.print("Altitude: ");
  oled.print(Height);
  oled.println(" feet");
  oled.display();
  delay(150);
}

float findHeight(float p0) {
  float d;
  float T0 = 288.15;
  float L = .0065;
  float R = 8.3144598;
  float M = .0289644;
  float g = 9.8;
  float pH;
  pH = BP.readPressure();
  float c = R * L / (M * g);
  d = T0 / L * (1 - pow((pH / p0), c));
  d = d * 3.28084;  //converting into foot
  return d;
}
