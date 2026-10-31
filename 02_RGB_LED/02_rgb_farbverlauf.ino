// 02 – RGB-LED Farbverlauf mit PWM
// Rot -> Grün -> Blau -> Rot, ein Durchlauf dauert ca. 7,5 s

#define BLUE 3
#define GREEN 5
#define RED 6

int redValue;
int greenValue;
int blueValue;

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  redValue = 255;
  greenValue = 0;
  blueValue = 0;

  // Phase 1: Rot -> Grün
  for (int i = 0; i < 255; i += 1) {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(10);
  }

  // Phase 2: Grün -> Blau
  for (int i = 0; i < 255; i += 1) {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(10);
  }

  // Phase 3: Blau -> Rot
  for (int i = 0; i < 255; i += 1) {
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(10);
  }
}
