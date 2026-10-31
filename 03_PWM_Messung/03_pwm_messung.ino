// 03 – PWM-Messung: Theorie vs. Messung
// Rote LED an Pin 6 mit festem PWM-Wert.
// Für die Messungen wurden die Werte 64 und 255 verwendet.

#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  analogWrite(RED, 64);   // Tastgrad g = 64 / 255 ≈ 0,25
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

void loop() {
}
