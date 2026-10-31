// 04 – Taster und Serieller Monitor
// Taster A (Pin 9) schaltet die LED ein, Taster B (Pin 8) schaltet sie aus.
// Mit Flankenerkennung wird jede Betätigung nur einmal gemeldet.

int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

int lastStateA = HIGH;   // vorheriger Zustand von Taster A (Merker)
int lastStateB = HIGH;   // vorheriger Zustand von Taster B (Merker)

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);   // nicht gedrückt = HIGH, gedrückt = LOW
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() {
  int stateA = digitalRead(buttonApin);

  // Flankenerkennung: vorher nicht gedrückt (HIGH), jetzt gedrückt (LOW)
  if (stateA == LOW && lastStateA == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Taster A gedrueckt");
  }
  lastStateA = stateA;

  int stateB = digitalRead(buttonBpin);

  if (stateB == LOW && lastStateB == HIGH) {
    digitalWrite(ledPin, LOW);
    Serial.println("Taster B gedrueckt");
  }
  lastStateB = stateB;
}
