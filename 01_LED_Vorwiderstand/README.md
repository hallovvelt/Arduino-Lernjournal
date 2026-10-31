# 01 – LED mit Vorwiderstand

## Ziel
Eine LED mit einem Vorwiderstand am Arduino UNO zum Leuchten bringen
und den Einfluss verschiedener Widerstände auf die Helligkeit untersuchen.

## Bauteile
- ELEGOO UNO R3 (als 5-V-Spannungsquelle)
- Steckbrett (830 Kontakte)
- Rote LED (5 mm)
- Widerstände: 220 Ω, 1 kΩ, 10 kΩ
- Steckbrücken (Jumper-Kabel)

## Schaltung
Die LED und der Vorwiderstand sind in Reihe geschaltet:
5 V → Widerstand → LED → GND

## Berechnung
- Gemessene Durchlassspannung der LED: U_F = 1,7 V
- Spannung am Widerstand: U_R = 5 V − 1,7 V = 3,3 V
- Strom: I = U_R / R = 3,3 V / 220 Ω ≈ 15 mA

| Widerstand | Strom (berechnet) | Beobachtung   |
|------------|-------------------|---------------|
| 220 Ω      | ≈ 15 mA           | hell          |
| 1 kΩ       | ≈ 3,3 mA          | dunkler       |
| 10 kΩ      | ≈ 0,33 mA         | kaum sichtbar |

## Beobachtung
Je größer der Widerstand ist, desto kleiner ist der Strom
und desto schwächer leuchtet die LED.

## Problem & Lösung
Beim ersten Versuch hat die LED nicht geleuchtet. Um den Fehler zu finden,
habe ich die Bauteile einzeln mit dem Multimeter geprüft (Diodentest)
und alle Verbindungen mit der Durchgangsprüfung kontrolliert.
Danach habe ich die Schaltung auf dem Steckbrett korrigiert,
und die LED hat geleuchtet.

## Erkenntnis
- Eine LED braucht immer einen Vorwiderstand, sonst wird der Strom zu groß.
- Eine LED hat keinen festen Widerstand. Deshalb rechnet man mit ihrer
  Durchlassspannung: U_ges = U_R + U_F.
- Die LED hat einen Plus- und einen Minuspol (Anode und Kathode).
- Bauteile müssen immer aus der Schaltung genommen werden, bevor man sie misst.

- ## Fotos
![Aufbau der Schaltung](aufbau.jpg)
![Messung des Widerstands mit dem Multimeter](widerstand_messung.jpg)
![Vergleich des Farbcodes mit dem Tabellenbuch](farbcode_vergleich.jpg)

📄 [Ausführliche Dokumentation (PDF)](01_LED_Vorwiderstand.pdf)
