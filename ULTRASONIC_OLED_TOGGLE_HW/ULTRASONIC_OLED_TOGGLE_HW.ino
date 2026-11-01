#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

int butPin = 8;
int butVal = 1;
int butValOld = 1;
int state = 1;

int echoPin = 5;
int trigPin = 6;
int pingTime;
float dist;
float speedRate = (767. * 63360.) / (60. * 60. * 1000.);

int screenWidth = 128;
int screenHeight = 64;
int oledReset = -1;

int ft;
float in;

#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(butPin, INPUT_PULLUP);

  oled.clearDisplay();
  oled.display();
  oled.setCursor(1, 0);
  oled.setTextColor(SSD1306_WHITE);
  oled.setTextSize(2);
  oled.println("PRESS");
  oled.println("TO MEASURE");
  oled.println("DISTANCE");
  oled.display();
}

void loop() {
  // put your main code here, to run repeatedly:

  butVal = digitalRead(butPin);
  if (butValOld == 0 && butVal == 1) {
    if (state == 0) {
      oled.clearDisplay();
      oled.display();
      oled.setCursor(1, 0);
      oled.setTextColor(SSD1306_WHITE);
      oled.setTextSize(2);
      oled.println("PRESS");
      oled.println("TO MEASURE");
      oled.println("DISTANCE");
      oled.display();
      // delay(100);
    }

    if (state == 1) {
      
      dist = findDistance();
      ft = dist/12;
      in = dist-ft*12;
      oled.clearDisplay();
      oled.display();
      oled.setCursor(1, 0);
      oled.setTextColor(SSD1306_WHITE);
      oled.setTextSize(2);
      oled.println("Distance: ");
      oled.println(String(ft)+" ft.");
      oled.print(String(in)+ " In.");
      oled.display();
      // delay(100);
    }
    state = !state;
  }
  butValOld = butVal;
  delay(50);
}

float findDistance() {
  float d;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTime = pulseIn(echoPin, HIGH);
  d = speedRate * (pingTime / 1000.) / 2.;
  Serial.println(dist);
  return d;
}