#include <WiFiS3.h>
#include "secrets.h"
WiFiUDP udp;
int PORT = 12345;
String myString;
String stringArray[10];
String response = "ACK\n";

int redPin = 9;
int greenPin = 10;
int bluePin = 11;

// Brightness (0-255) set by the sliders, used by the toggle and blink commands
int redBrightness = 255;
int greenBrightness = 255;
int blueBrightness = 255;

// Remembers which LEDs are toggled on, so the sliders can dim them live
bool redIsOn = false;
bool greenIsOn = false;
bool blueIsOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  Serial.print("Connecting to ");
  Serial.println(mySSID);
  WiFi.begin(mySSID, myPASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConnected to WiFi");
  Serial.println(WiFi.localIP());
  udp.begin(PORT);
  Serial.print("UDP Server started on port ");
  Serial.print(PORT);
  // put your setup code here, to run once:
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
    if (stringArray[0]=="redblink"){
      for (int i =0; i<stringArray[1].toInt();i=i+1){
        Serial.println("Blink Red");
        analogWrite(redPin,redBrightness);
        delay(stringArray[2].toInt());
          analogWrite(redPin,0);
        delay(stringArray[2].toInt());
      }
      // If the LED was toggled on before the blink, turn it back on
      if (redIsOn){
        analogWrite(redPin,redBrightness);
      }
    }
        if (stringArray[0]=="greenblink"){
      for (int i =0; i<stringArray[1].toInt();i=i+1){
        Serial.println("Blink Green");
        analogWrite(greenPin,greenBrightness);
        delay(stringArray[2].toInt());
          analogWrite(greenPin,0);
        delay(stringArray[2].toInt());
      }
      if (greenIsOn){
        analogWrite(greenPin,greenBrightness);
      }
    }    if (stringArray[0]=="blueblink"){
      for (int i =0; i<stringArray[1].toInt();i=i+1){
        Serial.println("Blink Blue");
        analogWrite(bluePin,blueBrightness);
        delay(stringArray[2].toInt());
          analogWrite(bluePin,0);
        delay(stringArray[2].toInt());
      }
      if (blueIsOn){
        analogWrite(bluePin,blueBrightness);
      }
    }
    if (stringArray[0]=="redbright"){
      redBrightness = constrain(stringArray[1].toInt(),0,255);
      if (redIsOn){
        analogWrite(redPin,redBrightness);
      }
    }
    if (stringArray[0]=="greenbright"){
      greenBrightness = constrain(stringArray[1].toInt(),0,255);
      if (greenIsOn){
        analogWrite(greenPin,greenBrightness);
      }
    }
    if (stringArray[0]=="bluebright"){
      blueBrightness = constrain(stringArray[1].toInt(),0,255);
      if (blueIsOn){
        analogWrite(bluePin,blueBrightness);
      }
    }
    if (stringArray[0]=="redOn"){
      redIsOn = true;
      analogWrite(redPin,redBrightness);
    }
        if (stringArray[0]=="redOff"){
      redIsOn = false;
      analogWrite(redPin,0);
    }
        if (stringArray[0]=="greenOn"){
      greenIsOn = true;
      analogWrite(greenPin,greenBrightness);
    }
        if (stringArray[0]=="greenOff"){
      greenIsOn = false;
      analogWrite(greenPin,0);
    }
        if (stringArray[0]=="blueOn"){
      blueIsOn = true;
      analogWrite(bluePin,blueBrightness);
    }
        if (stringArray[0]=="blueOff"){
      blueIsOn = false;
      analogWrite(bluePin,0);
    }
  }
}