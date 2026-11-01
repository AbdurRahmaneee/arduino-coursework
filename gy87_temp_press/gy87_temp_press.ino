#include <Adafruit_BMP085.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_BMP085 BP;

float Pressure;
float tempC;
bool BMPconnected;



int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  BMPconnected = BP.begin();
  if (BMPconnected == true) {
    Serial.println("BMP180 was found and Connected.");
  }
  if (BMPconnected == false) {
    Serial.println("BMP180 Not Found.");
  }
  Serial.println("time_ms,temp_C,pressure_Pa");
}

void loop() {
  // put your main code here, to run repeatedly:
  tempC = BP.readTemperature();
  Pressure = BP.readPressure();
  // Serial.println("READINGS from BPM180---------");
  // Serial.print("Temperature = ");
  // Serial.print(tempC);
  // Serial.println(" *C");
  // Serial.print("Pressure = ");
  // Serial.print(Pressure);
  // Serial.println(" Pascals");
  // Serial.println("");

  oled.clearDisplay();
  oled.display();
  oled.setCursor(0, 0);
  oled.setTextColor(WHITE);
  oled.setTextSize(2);
  oled.print("Temp: ");
  oled.print(tempC);
  oled.println(" *C");
  oled.print("Pres: ");
  oled.print(Pressure);
  oled.print(" Pa");
  oled.display();

  Serial.print(millis());
  Serial.print(",");
  Serial.print(tempC, 2);
  Serial.print(",");
  Serial.println(Pressure);

  delay(1000);
}
