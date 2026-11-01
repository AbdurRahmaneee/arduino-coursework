#include <WiFiS3.h>
#include "secrets.h"
WiFiUDP udp;
int PORT = 12345;
char myPacket[255];
int dataLen;
String color;
String response;
int bluePin = 11;
int redPin = 9;
int greenPin = 10;
int R;
int G;
int B;
int firstComma;
int secondComma;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
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
    color = String(myPacket);
    color.trim();
    Serial.println("Received color: " + color);
    firstComma = color.indexOf(',', 0);
    secondComma = color.indexOf(',', firstComma + 1);
    R = color.substring(0, firstComma).toInt();
    G = color.substring(firstComma + 1, secondComma).toInt();
    B = color.substring(secondComma + 1).toInt();
    Serial.println(R);
    Serial.println(G);
    Serial.println(B);
    analogWrite(redPin, R);
    analogWrite(greenPin, G);
    analogWrite(bluePin, B);

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

    // response = "Here is your " + color + " Marble";
    response = color + " has been deployed";
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.print(response);
    udp.endPacket();
    Serial.println("SENT: " + response);
  }
  delay(50);
}
