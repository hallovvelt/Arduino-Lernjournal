// 05 – Aktiver Summer
// Der aktive Summer an Pin 12 piept im Takt von 0,5 Sekunden.

int summerPin = 12;

void setup() {
  pinMode(summerPin, OUTPUT);
}

void loop() {
  digitalWrite(summerPin, HIGH);   // Summer ein
  delay(500);                      // 500 ms warten
  digitalWrite(summerPin, LOW);    // Summer aus
  delay(500);                      // 500 ms warten
}
