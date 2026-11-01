int blueLed = 11;
int greenLed = 10;
int redLed = 9;
String myPrompt1="Please Select an LED to light up (R for RED / G for GREEN / B for BLUE / Y for Yellow / C for Cyan / M for Magenta / O for Orange / W for White): ";
String myPrompt2="The Brightness of the LED (0-10): ";
int UI; //user input
int WV; //write value
int br=115200;
String selectedLED;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(myPrompt1);
  while(Serial.available()==0) {
  }
  selectedLED = Serial.readString();

  Serial.println(myPrompt2);
  while(Serial.available()==0) {
  }
  UI = Serial.parseInt();

  selectedLED.toLowerCase();
  Serial.print("You selected: ");
  Serial.println(selectedLED);
  Serial.print("And selected brightness: ");
  Serial.println(UI);

  WV = pow(2, (8./10.)*UI) - 1;
  Serial.print("Write Value: ");
  Serial.println(WV);


  if(selectedLED == "r") {
    analogWrite(redLed, WV);
    analogWrite(greenLed, 0);
    analogWrite(blueLed, 0);
  }else if(selectedLED == "g") {
    analogWrite(greenLed, WV);
    analogWrite(redLed, 0);
    analogWrite(blueLed, 0);
  }else if(selectedLED == "b") {
    analogWrite(blueLed, WV);
    analogWrite(greenLed, 0);
    analogWrite(redLed, 0);
  }else if(selectedLED == "y") {
    analogWrite(redLed, WV);
    analogWrite(greenLed, WV/21);
    analogWrite(blueLed, 0);
  }else if(selectedLED == "c") {
    analogWrite(redLed, 0);
    analogWrite(greenLed, WV);
    analogWrite(blueLed, WV);
  }else if(selectedLED == "m") {
    analogWrite(redLed, WV);
    analogWrite(greenLed, 0);
    analogWrite(blueLed, WV);
  }else if(selectedLED == "o") {
    analogWrite(redLed, WV);
    analogWrite(greenLed, WV/35);
    analogWrite(blueLed, 0);
  }else if(selectedLED == "w") {
    analogWrite(redLed, WV);
    analogWrite(greenLed, WV/5);
    analogWrite(blueLed, WV);
  }else if(selectedLED == "off") {
    analogWrite(redLed, 0);
    analogWrite(greenLed, 0);
    analogWrite(blueLed, 0);
  }
  
  
  else{
    Serial.println("Typo! or wrong selection! Your only choices are: R for RED / G for GREEN / B for BLUE / Y for Yellow / C for Cyan / M for Magenta / O for Orange / W for White");
  }
}
