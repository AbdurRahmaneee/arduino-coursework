#include <ArduinoGraphics.h>
#include "Arduino_LED_Matrix.h"
ArduinoLEDMatrix matrix;
#include <DHT.h>
#define DHTPIN 11
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);

int br=9600;
int setUpDelay=1000;
int measDelay=1000;

float tempC;
float tempF;
float hum;
float HIC;
float HIF;
int butPin=2;
int butVal=1;
int butValOld=1;

String msg;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  dht.begin();
  matrix.begin();
  delay(setUpDelay);
  pinMode(butPin,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal=digitalRead(butPin);
  if (butVal==0 && butValOld==1){

    
    tempC=dht.readTemperature(false);
    tempF=dht.readTemperature(true);
    hum=dht.readHumidity();
    
    if (isnan(tempC) || isnan(tempF) || isnan(hum)){
      Serial.println("Failed to Read Data on DHT11");
      return;
    }

    HIC=dht.computeHeatIndex(tempC,hum,false);
    HIF=dht.computeHeatIndex(tempF,hum,true);
    msg = "Temp: " + String(tempC) + " deg C " + String(tempF) + " deg F Humidity: " + String(hum) + " % Heat Index: " + String(HIC) + " deg C " + String(HIF) + " deg F.";
    Serial.println(msg);
    
  
    matrix.beginDraw();
    matrix.textScrollSpeed(50);
    matrix.textFont(Font_5x7);
    matrix.beginText(0,1,255,0,0);
    matrix.println(msg);
    matrix.endText(SCROLL_LEFT);
    matrix.endDraw();
    
    // Serial.print("Temp: ");
    // Serial.print(tempC);
    // Serial.println(" deg C");
    // Serial.print("Temp: ");
    // Serial.print(tempF);
    // Serial.println(" deg F");
    // Serial.print("Humidity: ");
    // Serial.print(hum);
    // Serial.println(" %");
    // Serial.print("Heat Index: ");
    // Serial.print(HIC);
    // Serial.println(" deg C");
    // Serial.print("Heat Index: ");
    // Serial.print(HIF);
    // Serial.println(" deg F\n");
    // Serial.print("\n");

    delay(measDelay);
  }
  butValOld=butVal;
}
