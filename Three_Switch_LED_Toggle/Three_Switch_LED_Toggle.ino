// Red LED button vairables
int butPinRed=2;
int redPin=10;
int butValRed=1;
int butValOldRed=1;
int LEDstateRed=0;

// Blue LED button variables
int butPinBlue=4;
int BluePin=12;
int butValBlue=1;
int butValOldBlue=1;
int LEDstateBlue=0;

// Green LED button variables
int butPinGreen=3;
int GreenPin=11;
int butValGreen=1;
int butValOldGreen=1;
int LEDstateGreen=0;



int br=9600;
int dt = 50;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(br);

  // Pin setup for Red
  pinMode(redPin,OUTPUT);
  pinMode(butPinRed,INPUT);

    // Pin setup for Green
  pinMode(GreenPin,OUTPUT);
  pinMode(butPinGreen,INPUT);

  // Pin setup for Blue
  pinMode(BluePin,OUTPUT);
  pinMode(butPinBlue,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // Red LED code
  butValRed=digitalRead(butPinRed);
  if (butValOldRed==0 && butValRed==1){
    if (LEDstateRed==0){
      digitalWrite(redPin, HIGH);
    }
    if (LEDstateRed==1){
      digitalWrite(redPin, LOW);
    }
    LEDstateRed = !LEDstateRed;
  }
  butValOldRed=butValRed;

  // Green LED code
  butValGreen=digitalRead(butPinGreen);
  if (butValOldGreen==0 && butValGreen==1){
    if (LEDstateGreen==0){
      digitalWrite(GreenPin, HIGH);
    }
    if (LEDstateGreen==1){
      digitalWrite(GreenPin, LOW);
    }
    LEDstateGreen = !LEDstateGreen;
  }
  butValOldGreen=butValGreen;


  // Blue LED code
  butValBlue=digitalRead(butPinBlue);
  if (butValOldBlue==0 && butValBlue==1){
    if (LEDstateBlue==0){
      digitalWrite(BluePin, HIGH);
    }
    if (LEDstateBlue==1){
      digitalWrite(BluePin, LOW);
    }
    LEDstateBlue = !LEDstateBlue;
  }
  butValOldBlue=butValBlue;



  delay(dt);
}

