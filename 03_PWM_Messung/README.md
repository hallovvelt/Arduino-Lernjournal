# 03 – PWM-Messung: Theorie vs. Messung

## Ziel
Den Tastgrad und den arithmetischen Mittelwert eines PWM-Signals
berechnen und das Ergebnis mit dem Multimeter überprüfen.

## Bauteile
- ELEGOO UNO R3
- Steckbrett, rote LED (Kanal der RGB-LED), Widerstand 220 Ω
- Digitalmultimeter UNI-T UT33D+

## Theorie
- Periodendauer: T = 1 / f
- Tastgrad: g = t_i / T
- Beim Arduino (8-Bit-PWM): g = PWM-Wert / 255
- Arithmetischer Mittelwert: U_AV = g · Û

## Berechnung für `analogWrite(RED, 64)`
| Größe | Formel        | Ergebnis   |
|-------|---------------|------------|
| f     | gegeben (Pin 6)| ≈ 980 Hz  |
| T     | 1 / f         | ≈ 1 ms     |
| g     | 64 / 255      | ≈ 0,25     |
| t_i   | g · T         | ≈ 0,25 ms  |
| t_p   | T − t_i       | ≈ 0,75 ms  |
| U_AV  | g · 5 V       | ≈ 1,25 V   |

## Messung
| Messung                         | Erwartet | Gemessen |
|---------------------------------|----------|----------|
| Pin 6, PWM-Wert 64              | 1,25 V   | 1,06 V   |
| Pin 6, PWM-Wert 255 (g = 1)     | 5,00 V   | 4,19 V   |
| 5-V-Pin des UNO (USB-Versorgung)| 5,00 V   | 4,45 V   |

## Auswertung
Die Messung mit dem Wert 64 war kleiner als berechnet. Um den Grund zu finden,
habe ich den Pin mit dem Wert 255 gemessen. Dabei ist der Pin dauerhaft
eingeschaltet. Statt 5 V habe ich nur 4,19 V gemessen.
Das tatsächliche Û unter Last beträgt also 4,19 V.

Mit diesem Wert ergibt sich: U_AV = 0,25 · 4,19 V ≈ 1,05 V.
Das stimmt fast genau mit dem Messwert von 1,06 V überein.
Die Formel ist also richtig, nur die Annahme Û = 5 V war falsch.

Die zusätzliche Messung am 5-V-Pin zeigt, woher die Abweichung kommt:
- Die USB-Versorgung liefert nur 4,45 V.
- Unter Last fällt am Ausgangspin noch einmal etwa 0,26 V ab.

## Warum sieht man kein Flackern?
Die LED wird etwa 980-mal pro Sekunde ein- und ausgeschaltet.
Unser Auge ist zu träge, um so schnelle Wechsel zu erkennen.
Deshalb sehen wir nur eine geringere Helligkeit.

## Erkenntnis
- Theorie und Praxis weichen voneinander ab, weil reale Bauteile
  nicht ideal sind.
- Mit einer Kontrollmessung (g = 1) kann man den wahren Wert von Û
  bestimmen und die Berechnung korrigieren (Kalibrierung).
- Die Formel aus dem Unterricht (U_AV = g · Û) funktioniert auch in der Praxis.

## Code
💾 [Arduino-Code herunterladen](03_pwm_messung.ino)
