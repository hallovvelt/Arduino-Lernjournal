// 08 – Servomotor (SG90)
// Der Servo dreht sich langsam von 0° bis 180° und wieder zurück.

#include <Servo.h>      // Servo-Bibliothek (erzeugt die 50-Hz-Steuerimpulse)
Servo meinServo;        // Servo-Objekt mit dem Namen "meinServo"

void setup() {
  meinServo.attach(9);  // Signalkabel (orange) an Pin 9
}

void loop() {
  // von 0° bis 180°: jeder Schritt 1 Grad, danach 10 ms warten
  for (int i = 0; i < 180; i += 1) {
    meinServo.write(i);
    delay(10);
  }

  // von 180° zurück bis 0°
  for (int i = 180; i > 0; i -= 1) {
    meinServo.write(i);
    delay(10);
  }
}
