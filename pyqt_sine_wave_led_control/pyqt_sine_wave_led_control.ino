#include <WiFiS3.h>
#include "secrets.h"
WiFiUDP udp;
int PORT = 12345;
char myPacket[255];
int dataLen;
int bluePin = 11;
int redPin = 9;
int greenPin = 10;
int R;
int G;
int B;
bool gotPacket;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.print("Connecting to ");
  Serial.println(mySSID);
  WiFi.begin(mySSID, myPASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi ");
  Serial.println(WiFi.localIP());
  udp.begin(PORT);
  Serial.print("UDP Server started on port ");
  Serial.println(PORT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Read every waiting packet and keep only the newest one,
  // so the LED never falls behind the Python graph.
  gotPacket = false;
  while (udp.parsePacket()) {
    dataLen = udp.read(myPacket, sizeof(myPacket) - 1);
    if (dataLen < 0) {
      dataLen = 0;
    }
    myPacket[dataLen] = 0;  // terminate the string before using it
    gotPacket = true;
  }

  if (gotPacket) {
    R = constrain(atoi(myPacket), 0, 255);
    analogWrite(redPin, R);
    Serial.println(R);  // one short print; view it in the Serial Plotter
  }
}
