#include <Adafruit_BMP085.h>

Adafruit_BMP085 BP;
bool BMPconnected;
bool haveBase = false;

float basePressure;
float Height = 0;
float HeightNow=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BMPconnected = BP.begin();
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
    Serial.println("Place Device at Base, Enter Go:");
    while (Serial.available() == 0) {}
    basePressure = BP.readPressure();
    haveBase = true;
  }
  HeightNow = findHeight(basePressure);
  Height = .95*Height + 0.05*HeightNow;
  Serial.print(4);
  Serial.print(",");
  Serial.print(-5);
  Serial.print(",");
  Serial.print(HeightNow);
  Serial.print(",");
  Serial.println(Height);
  delay(10);
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
  d = d * 3.28084; //converting into foot
  return d;
}
