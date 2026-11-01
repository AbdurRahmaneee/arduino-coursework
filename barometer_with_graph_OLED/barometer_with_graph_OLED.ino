#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>

// ---------- Pins ----------
#define DHTPIN     9
#define DHTTYPE    DHT11     // change to DHT11 if that's your sensor
#define BUTTON_PIN 8        // button between pin 10 and GND

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 BP;
bool BMPconnected = false;

// ---------- OLED ----------
const int screenWidth  = 128;
const int screenHeight = 64;
const int oledReset    = -1;
#define SCREEN_ADDRESS 0x3C
Adafruit_SSD1306 oled(screenWidth, screenHeight, &Wire, oledReset);

// ---------- Sensors ----------
enum { SENS_TEMP, SENS_HUM, SENS_PRES, NUM_SENSORS };

const char* sensorLabel[NUM_SENSORS]    = {"TEMP", "HUMID", "PRESS"};
const char* sensorUnit[NUM_SENSORS]     = {"C", "%", "inHg"};
const int   sensorDecimals[NUM_SENSORS] = {1, 1, 2};
const float sensorMinSpan[NUM_SENSORS] = {0.5, 2.0, 0.05};   // smallest graph range per sensor

float alt = 37.5;                         // station altitude (m), used for pressure
float value[NUM_SENSORS] = {NAN, NAN, NAN};   // latest reading (NAN = no reading)
float smoothPres = NAN;                   // smoothed pressure

// ---------- Screens ----------
// 0 = overview (all three values)
// 1 = temperature graph, 2 = humidity graph, 3 = pressure graph
const int NUM_SCREENS = 4;
int currentScreen = 0;

// ---------- Graph ----------
const int GRAPH_W     = 128;              // one sample per pixel column
const int GRAPH_TOP   = 18;               // graph area sits below the value row
const int GRAPH_BOT   = screenHeight - 1;
const unsigned long SAMPLE_MS = 2000;     // DHT needs at least 2 s between reads

float history[NUM_SENSORS][GRAPH_W];      // [s][0] = oldest (left), [s][127] = newest (right)
int   histCount = 0;                      // number of samples taken so far
unsigned long lastSample = 0;

// ---------- Button ----------
const unsigned long DEBOUNCE_MS = 50;
bool lastRaw     = HIGH;
bool buttonState = HIGH;
unsigned long lastChange = 0;

void setup() {
  Serial.begin(9600);

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  dht.begin();

  BMPconnected = BP.begin();
  Serial.println(BMPconnected ? "BMP180 found" : "BMP180 not found, check connections");

  oled.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  oled.setTextColor(SSD1306_WHITE);
  oled.clearDisplay();
  oled.display();
}

void loop() {
  checkButton();

  if (millis() - lastSample >= SAMPLE_MS) {
    lastSample = millis();
    takeSample();
    drawScreen();
  }
}

// ---------- Button ----------

void checkButton() {
  bool raw = digitalRead(BUTTON_PIN);
  if (raw != lastRaw) {
    lastRaw = raw;
    lastChange = millis();
  }
  if (millis() - lastChange >= DEBOUNCE_MS && raw != buttonState) {
    buttonState = raw;
    if (buttonState == LOW) {             // pressed (button connects pin to GND)
      currentScreen = (currentScreen + 1) % NUM_SCREENS;
      drawScreen();
    }
  }
}

// ---------- Reading and history ----------

void takeSample() {
  value[SENS_TEMP] = dht.readTemperature();
  value[SENS_HUM]  = dht.readHumidity();

  if (BMPconnected) {
    float p = normPress(alt);
    smoothPres = isnan(smoothPres) ? p : 0.95 * smoothPres + 0.05 * p;
  }
  value[SENS_PRES] = smoothPres;

  Serial.print("Temp: ");   Serial.print(value[SENS_TEMP]);
  Serial.print("  Hum: ");  Serial.print(value[SENS_HUM]);
  Serial.print("  Pres: "); Serial.println(value[SENS_PRES]);

  pushSample();
}

// Shift every history one column left and add the new values on the right
void pushSample() {
  for (int s = 0; s < NUM_SENSORS; s++) {
    for (int i = 0; i < GRAPH_W - 1; i++) {
      history[s][i] = history[s][i + 1];
    }
    history[s][GRAPH_W - 1] = value[s];
  }
  if (histCount < GRAPH_W) histCount++;
}

float normPress(float elev) {
  float BPRaw;
  float BPNorm;
  float T0 = 288.15;
  float L  = .0065;
  float R  = 8.3144598;
  float M  = .0289644;
  float g  = 9.8;
  float c  = M * g / (R * L);
  BPRaw  = BP.readPressure() * .0002953;
  BPNorm = BPRaw / pow(1 - L * elev / T0, c);
  return BPNorm;
}

// ---------- Drawing ----------

void drawScreen() {
  oled.clearDisplay();

  if (currentScreen == 0) {
    for (int s = 0; s < NUM_SENSORS; s++) {
      drawValueRow(s * 22, s);            // rows at y = 0, 22, 44
    }
  } else {
    int s = currentScreen - 1;
    drawValueRow(0, s);
    drawGraph(s);
  }

  oled.display();
}

// One line: label on the left, large value in the middle, unit on the right
void drawValueRow(int y, int s) {
  oled.setTextSize(1);
  oled.setCursor(0, y + 4);
  oled.print(sensorLabel[s]);

  oled.setTextSize(2);
  oled.setCursor(36, y);
  if (isnan(value[s])) oled.print("--");
  else                 oled.print(value[s], sensorDecimals[s]);

  oled.setTextSize(1);
  oled.setCursor(100, y + 4);
  oled.print(sensorUnit[s]);
}

void drawGraph(int s) {
  int first = GRAPH_W - histCount;        // first column holding a real sample

  // Find the range of the samples on screen
  bool any = false;
  float lo = 0, hi = 0;
  for (int x = first; x < GRAPH_W; x++) {
    float v = history[s][x];
    if (isnan(v)) continue;
    if (!any) { lo = hi = v; any = true; }
    if (v < lo) lo = v;
    if (v > hi) hi = v;
  }
  if (!any) {
    oled.setTextSize(1);
    oled.setCursor(40, 36);
    oled.print("no data");
    return;
  }

  // Scale the graph to the samples, keeping a minimum range
  float span = max(hi - lo, sensorMinSpan[s]);
  float mid  = (lo + hi) / 2;
  lo = mid - span / 2;
  hi = mid + span / 2;

  // Connect neighbouring samples with line segments
  for (int x = first + 1; x < GRAPH_W; x++) {
    float a = history[s][x - 1];
    float b = history[s][x];
    if (isnan(a) || isnan(b)) continue;
    oled.drawLine(x - 1, valueToY(a, lo, hi),
                  x,     valueToY(b, lo, hi),
                  SSD1306_WHITE);
  }
}

// Convert a value to a pixel row inside the graph area
int valueToY(float v, float lo, float hi) {
  float t = (v - lo) / (hi - lo);                                 // 0 = bottom, 1 = top
  int y = GRAPH_BOT - (int)(t * (GRAPH_BOT - GRAPH_TOP) + 0.5f);
  return constrain(y, GRAPH_TOP, GRAPH_BOT);
}