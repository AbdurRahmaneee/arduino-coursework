int butPin=2;
int butVal;
int LED=0;
int br=9600;
int dt = 100;
int redPin=10;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);
  pinMode(butPin, INPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  butVal = digitalRead(butPin);
  // Serial.println(butVal);

  if (butVal==0 && LED==0) {
    while(digitalRead(butPin)==0){}
    digitalWrite(redPin,HIGH);
    LED=1;
    delay(dt);
    // while(butVal==1){}
    while (digitalRead(butPin)==1) {
    // Serial.println("ON");
    }
  }



  if (butVal==0 && LED==1) {
    while(digitalRead(butPin)==0){}
    digitalWrite(redPin,LOW);
    LED=0;
    delay(dt);
    while (digitalRead(butPin)==1){
      // Serial.println("OFF");
    }
    
  }
}
