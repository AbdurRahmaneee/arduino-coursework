int BI = 10;
int FI = 9;
int MS;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(BI, OUTPUT);
  pinMode(FI, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Please Enter Motor Speed: (0, 256)");
  while (Serial.available() == 0) {
  }
  MS = Serial.parseInt();

  analogWrite(FI, MS);
  analogWrite(BI, 0);
  delay(1000);
  analogWrite(FI, 0);
  analogWrite(BI, 0);
  delay(1000);

  analogWrite(FI, 0);
  analogWrite(BI, MS);
  delay(1000);
  analogWrite(FI, 0);
  analogWrite(BI, 0);
  delay(1000);
}
