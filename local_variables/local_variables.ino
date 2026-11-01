void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  float width;
  float length;
  float area;
  float perimeter;
  float diagonal;
  Serial.println("Input Lenght of Rectangle: ");
  while (Serial.available() == 0) {
  }
  length = Serial.parseFloat();

  Serial.println("Input Width of Rectangle: ");
  while (Serial.available() == 0) {
  }
  width = Serial.parseFloat();
  findArea(length, width, area);
  Serial.println("Your Area is: " + String(area));
  findPerimeter(length, width, perimeter);
  Serial.println("Your Perimeter is: " + String(perimeter));
  findDiagonal(length, width, diagonal);
  Serial.println("Your diagonal is: " + String(diagonal));
  Serial.println();

}

void findArea(float l, float w, float &a) {
  // float a;
  a = l * w;
  // return a;
}

void findPerimeter(float l, float w, float &p) {
  // float p;
  p = 2 * l + 2 * w;
  // return p;
}
void findDiagonal(float l, float w, float &d){
  // float d;
  d = sqrt(l*l + w*w);
  // return d;
}