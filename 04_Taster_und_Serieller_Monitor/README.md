# 04 – Taster und Serieller Monitor

## Ziel
Mit zwei Tastern eine LED ein- und ausschalten, die Zustände im
seriellen Monitor anzeigen und jede Betätigung nur einmal erkennen.

## Bauteile
- ELEGOO UNO R3
- Steckbrett, rote LED, Widerstand 220 Ω
- Taster (Drucktaster)
- Steckbrücken (Jumper-Kabel)

## Schaltung
- LED mit Vorwiderstand an Pin 5
- Taster A an Pin 9 und GND, Taster B an Pin 8 und GND
- Die Taster brauchen keinen eigenen Widerstand, weil der Arduino
  einen internen Pull-up-Widerstand hat (`INPUT_PULLUP`):
  nicht gedrückt = HIGH, gedrückt = LOW.

## Funktionsprinzip: EVA
Die Taster schalten die LED nicht direkt. Es gibt zwei getrennte Stromkreise:
- **Eingabe:** Die Taster geben ein Signal an den Arduino.
- **Verarbeitung:** Das Programm entscheidet.
- **Ausgabe:** Der Arduino schaltet die LED.

Das ist dasselbe Prinzip wie bei einer SPS.

## Versuche und Beobachtungen
1. **Taster A drücken und loslassen:** Die LED bleibt an, bis Taster B
   gedrückt wird. Der Pin behält seinen letzten Zustand.
2. **Beide Taster gleichzeitig:** Die LED flackert bzw. leuchtet schwächer.
   Das Programm schaltet sie in jedem Durchlauf ein und sofort wieder aus.
3. **Parallelschaltung:** Ich habe vier Taster parallel an denselben Eingang
   angeschlossen. Jeder Taster kann die LED schalten, ohne dass der Code
   geändert werden muss.
4. **Serieller Monitor:** Beim Gedrückthalten erschien die Meldung etwa
   100-mal pro Sekunde, weil `loop()` sehr schnell immer wieder durchläuft.

## Lösung: Flankenerkennung
Der vorherige Zustand jedes Tasters wird in einer Variablen gespeichert
(wie ein Merker bei der SPS). Eine Meldung erscheint nur, wenn der Taster
vorher nicht gedrückt war und jetzt gedrückt ist:

```cpp
if (stateA == LOW && lastStateA == HIGH) {
  // Taster wurde gerade gedrückt
}
lastStateA = stateA;
```

Jetzt erscheint pro Betätigung nur noch eine Meldung,
auch wenn ich den Taster 10 Sekunden lang gedrückt halte.

## Problem & Lösung
- **Die Durchgangsprüfung piepte immer:** Ich hatte zwischen einem Kabel und
  einem Tasterbein in derselben Reihe gemessen. Das ist derselbe Punkt.
  Dann habe ich den Taster ohne Steckbrett gemessen und herausgefunden:
  Die Beine an der langen Seite sind immer verbunden, die an der kurzen
  Seite nur beim Drücken.
- **Die LED leuchtete nicht:** Sie war falsch herum eingesteckt.
  Das lange Bein (Anode) muss zum Pluspol.

## Erkenntnis
- Ein Taster gibt nur ein Signal; die Entscheidung trifft das Programm.
- `loop()` läuft tausende Male pro Sekunde.
- Mit einer Variablen außerhalb von `loop()` kann sich der Arduino
  etwas merken.
- `&&` bedeutet UND: Beide Bedingungen müssen wahr sein.

## Dateien
💾 [Arduino-Code](04_taster_flankenerkennung.ino)
