float grades[25];
int numGrades;
int i;
int j;
String myPrompt;
float total = 0;
float avg;
float maxGrade = 0;
float minGrade = 0;
float sorted[25];
float tmp;
int flag;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("How many grades?: ");
  while (Serial.available() == 0) {
  }
  numGrades = Serial.parseInt();
  for (i = 0; i < numGrades; i++) {
    myPrompt = "Please Input Grade: " + String(i + 1);
    Serial.println(myPrompt);
    while (Serial.available() == 0) {}
    grades[i] = Serial.parseFloat();
  }
  Serial.println();
  Serial.println("Your Grades Are: ");
  for (i = 0; i < numGrades; i++) {
    Serial.println(grades[i]);
  }

  Serial.println();
  Serial.print("The Average of the Grades is: ");
  total = 0;  // emptying the bucket
  for (i = 0; i < numGrades; i++) {
    total = total + grades[i];
  }
  avg = total / numGrades;
  Serial.println(avg);

  Serial.println();
  Serial.print("The Max Grade among the " + String(numGrades) + " is: ");
  maxGrade = 0;
  for (i = 0; i < numGrades; i++) {
    if (maxGrade < grades[i]) {
      maxGrade = grades[i];
    }
  }
  Serial.println(maxGrade);

  Serial.println();
  Serial.print("The minimum Grade among the " + String(numGrades) + " is: ");
  minGrade = grades[0];
  for (i = 0; i < numGrades; i++) {
    if (minGrade > grades[i]) {
      minGrade = grades[i];
    }
  }
  Serial.println(minGrade);

  Serial.println();
  Serial.print("Sorted list: ");
  sorted[0] = grades[0];
  flag=1;
  while(flag==1){
    flag=0;
    for (i = 0; i < numGrades - 1; i++) {
      if (grades[i] < grades[i + 1]) {
        tmp = grades[i];
        grades[i] = grades[i + 1];
        grades[i + 1] = tmp;
        flag=1;
      }
    }
  }
  for (i = 0; i < numGrades; i++) {
    Serial.println(grades[i]);
  }
}
