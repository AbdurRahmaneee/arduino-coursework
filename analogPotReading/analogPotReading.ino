int potPin=A2;
int potVal;
int br=9600;
int waitT=100;
float volts;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin,INPUT);
  Serial.begin(br);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal=analogRead(potPin);
  volts=(5./1023.)*potVal;
  Serial.print("potVal: ");
  Serial.print(potVal);
  Serial.print("  Voltage: ");
  Serial.println(volts);

  delay(waitT);
}
