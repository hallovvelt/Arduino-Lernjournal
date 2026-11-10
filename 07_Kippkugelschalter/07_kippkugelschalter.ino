// 07 – Kippkugelschalter (Neigungsschalter)
// Wenn der Sensor geneigt ist (Kontakt offen -> HIGH), leuchtet die LED.

int Neigung = 2;    // Kippkugelschalter an Pin 2 (anderes Bein an GND)
int ledPin = 12;    // LED mit 220-Ohm-Vorwiderstand an Pin 12

void setup() {
  pinMode(Neigung, INPUT_PULLUP);   // offen = HIGH, geschlossen = LOW
  pinMode(ledPin, OUTPUT);
}

void loop() {
  if (digitalRead(Neigung) == HIGH) {
    digitalWrite(ledPin, HIGH);     // Sensor geneigt -> LED an
  } else {
    digitalWrite(ledPin, LOW);      // Sensor senkrecht -> LED aus
  }
}
