int blueLed = 11;
int greenLed = 10;
int redLed = 9;
int br = 9600;
int i;
int waitT1=150;
int waitT2 = 1000;
String myPrompt = "Enter the number of times it should blink.";
int numBlinks;
void setup() {
  // put your setup code here, to run once:
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  Serial.begin(br);
  i = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(myPrompt);
  while (Serial.available()==0) {

  }
  numBlinks=Serial.parseInt();

  for(i = 1; i <= numBlinks; i = i + 1) {
    digitalWrite(redLed, HIGH);
    delay(waitT1);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, HIGH);
    delay(waitT1);
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, HIGH);
    delay(waitT1);
    digitalWrite(blueLed, LOW);

    delay(waitT2);
    Serial.println(i);
  }
}
