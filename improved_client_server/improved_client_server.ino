#include <WiFiS3.h>
#include "secrets.h"
WiFiUDP udp;
int PORT = 12345;
String myString;
String stringArray[10];
String response = "ACK";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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
  Serial.print(PORT);
}

void splitString() {
  int startIndex = 0;
  int indexCount = 0;
  int i;
  int j;
  myString = myString + ':';
  for (i = 0; i < myString.length(); i = i + 1) {
    if (myString[i] == ':') {
      stringArray[indexCount] = myString.substring(startIndex, i);
      indexCount = indexCount + 1;
      startIndex = i + 1;
    }
  }
  for (j = 0; j < indexCount; j = j + 1) {
    Serial.println(stringArray[j]);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (udp.parsePacket()) {
    myString = udp.readStringUntil('\n');
    Serial.println("Received : " + myString);
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.print(response);
    udp.endPacket();
    Serial.println("SENT: " + response);
    splitString();
  }
  delay(50);
}
