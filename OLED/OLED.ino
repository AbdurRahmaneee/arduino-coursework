#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
}

void loop() {
  // put your main code here, to run repeatedly:
  oled.clearDisplay();
  oled.display();
  oled.setCursor(0, 12);
  oled.setTextColor(WHITE);
  oled.setTextSize(3);
  oled.println(" Hello");
  oled.println(" World!");

  oled.display();
  delay(1000);
  oled.invertDisplay(1);
  delay(1000);
  oled.invertDisplay(0);
  delay(1000);

  oled.clearDisplay();
  oled.drawPixel(64, 32, WHITE);
  oled.display();
  delay(1000);

  oled.clearDisplay();
  oled.drawLine(0, 0, 127, 63, WHITE);
  oled.display();
  delay(1000);

  oled.clearDisplay();
  oled.drawLine(0, 32, 127, 32, WHITE);
  oled.drawLine(64, 0, 64, 63, WHITE);
  oled.display();
  delay(1000);

  oled.clearDisplay();
  oled.drawRect(0, 0, 128, 64, WHITE);  // it is asking for absolute widht no pixel thus 64
  oled.display();
  delay(1000);

  oled.clearDisplay();
  oled.fillRect(0, 0, 128, 64, WHITE);  // it is asking for absolute widht no pixel thus 64
  oled.fillRect(5, 5, 118, 54, BLACK);
  oled.display();
  delay(1000);

  oled.clearDisplay();
  oled.drawCircle(64, 32, 31, WHITE);  
  oled.display();
  delay(1000);

  oled.clearDisplay();
  oled.fillCircle(64, 32, 31, WHITE);
  oled.fillCircle(64, 32, 24, BLACK);
  oled.display();
  delay(1000);
}
