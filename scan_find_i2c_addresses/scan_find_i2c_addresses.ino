// ====================================================================
// DISCLAIMER:
// This code is provided as-is for educational and experimental 
// purposes only. The author makes no representations or warranties of 
// any kind concerning the safety, suitability, or accuracy of this 
// code. Use at your own risk. The author assumes no liability for any 
// damages, system failures, security breaches, or network issues 
// resulting from the use or implementation of this script.
// ====================================================================

#include <Wire.h>
#define myWire Wire
int numDevices;
byte error, address;
void setup() {
  myWire.begin();
  Serial.begin(115200);
  Serial.println("Find I2C Devices: ");
}
void loop() {
  Serial.println("Scanning...");
  numDevices = 0;
  for (address = 1; address < 127; address=address+1) {
    myWire.beginTransmission(address);
    error = myWire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.print(address, HEX);
      Serial.println("  !");
      numDevices = numDevices + 1;
    } else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16)
        Serial.print("0");
      Serial.println(address, HEX);
    }
  }
  if (numDevices == 0)
    Serial.println("No I2C devices found");
  delay(5000);  
}