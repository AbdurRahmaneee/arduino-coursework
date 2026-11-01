// int brit;
// int ledPin=10;
// float britC;
// float britF;
int ledPin=10;
int UI; //user input
int WV; //write value
int br=9600; //baud rate
int waitT=100;
String prompt = "Please Input Desired Brightness (0-10): ";
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  Serial.begin(br);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(prompt);
  while(Serial.available()==0) {  
  }
  UI = Serial.parseInt();
  Serial.print("You Have entered ");
  Serial.println(UI);
  WV = pow(2, (8./10.)*UI) - 1;
  Serial.print("Write Value: ");
  Serial.println(WV);
  analogWrite(ledPin, WV);
  
  // brit = Serial.parseInt();
  // britC = (255./10.)*brit;
  // britF = pow(2, (britC/31.875)) - 1;
  // Serial.print("You Have entered ");
  // Serial.println(brit);
  // Serial.print("Converted value: ");
  // Serial.println(britC);
  // Serial.println("Percievalbe value: ");
  // Serial.println(britF);
  // analogWrite(ledPin,britF);
}
