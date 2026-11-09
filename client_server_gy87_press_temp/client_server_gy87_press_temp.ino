#include <WiFiS3.h>
#include "secrets.h"
#include <Adafruit_BMP085.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
Adafruit_BMP085 BP;

float Pressure;
float tempC;
bool BMPconnected;


WiFiUDP udp;
int PORT = 12345;
char myPacket[255];
int dataLen;
String rqt;
String response;
String rsp;
// int bluePin = 11;
// int redPin = 9;
// int greenPin = 10;
// int R;
// int G;
// int B;
// int firstComma;
// int secondComma;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BMPconnected = BP.begin();
  // pinMode(bluePin, OUTPUT);
  // pinMode(redPin, OUTPUT);
  // pinMode(greenPin, OUTPUT);
  Serial.print("Connecting to ");
  Serial.println(SSID);
  WiFi.begin(SSID, PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi ");
  Serial.println(WiFi.localIP());
  udp.begin(PORT);
  Serial.print("UDP Server started on port ");
  Serial.print(PORT);
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
  if (udp.parsePacket()) {
    dataLen = udp.available();
    Serial.println(dataLen);
    udp.read(myPacket, 255);
    Serial.println(myPacket);
    myPacket[dataLen] = 0;
    Serial.println(myPacket);
    rqt = String(myPacket);
    rqt.trim();
    Serial.println("Received request: " + rqt);
    // firstComma = color.indexOf(',', 0);
    // secondComma = color.indexOf(',', firstComma + 1);
    // R = color.substring(0, firstComma).toInt();
    // G = color.substring(firstComma + 1, secondComma).toInt();
    // B = color.substring(secondComma + 1).toInt();
    // Serial.println(R);
    // Serial.println(G);
    // Serial.println(B);
    // analogWrite(redPin, R);
    // analogWrite(greenPin, G);
    // analogWrite(bluePin, B);

    // if (color == "blue") {
    //   digitalWrite(bluePin, HIGH);
    //   response = color + " LED is ON";
    // }
    // if (color == "red") {
    //   digitalWrite(redPin, HIGH);
    //   response = color + " LED is ON";
    // }
    // if (color == "off") {
    //   digitalWrite(redPin, LOW);
    //   digitalWrite(bluePin, LOW);
    //   response ="ALL LEDs are off";
    // }
    if (rqt == "t") {
      tempC = BP.readTemperature();
      Serial.println("READINGS from BPM180---------");
      Serial.print("Temperature = ");
      Serial.print(tempC);
      Serial.println(" *C");
      rsp = String("temperature is: ") + tempC + " *C";
    }

    if (rqt == "p") {
      Pressure = BP.readPressure();
      Serial.println("READINGS from BPM180---------");
      Serial.print("Pressure = ");
      Serial.print(Pressure);
      Serial.println(" Pascals");
      Serial.println("");
      rsp = String("Pressure is ") + Pressure + " Pascals";
    }
    if (rqt == "b") {
      tempC = BP.readTemperature();
      Pressure = BP.readPressure();
      Serial.println("READINGS from BPM180---------");
      Serial.print("Temperature = ");
      Serial.print(tempC);
      Serial.println(" *C");
      Serial.print("Pressure = ");
      Serial.print(Pressure);
      Serial.println(" Pascals");
      Serial.println("");
      rsp = String("temperature is: ") + tempC + " *C" + " ||__|| Pressure is " + Pressure + " Pascals";
    }

    // Serial.print(millis());
    // Serial.print(",");
    // Serial.print(tempC, 2);
    // Serial.print(",");
    // Serial.println(Pressure);


    // response = "Here is your " + color + " Marble";
    // response = String("temperature is: ") + tempC + " *C" + " ||||| Pressure is " + Pressure + " Pascals";
    response = rsp;
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.print(response);
    udp.endPacket();
    Serial.println("SENT: " + response);
  }
  delay(50);
}
