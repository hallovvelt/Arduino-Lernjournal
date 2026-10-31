# 02 – RGB-LED mit PWM

## Ziel
Eine RGB-LED mit dem Arduino UNO ansteuern, Farben mischen
und einen fließenden Farbverlauf selbst programmieren.

## Bauteile
- ELEGOO UNO R3
- Steckbrett (830 Kontakte)
- RGB-LED mit gemeinsamer Kathode
- 3 × Widerstand 220 Ω
- Steckbrücken (Jumper-Kabel)

## Schaltung
In der RGB-LED befinden sich drei LEDs (Rot, Grün, Blau) mit einer
gemeinsamen Kathode. Jede Farbe hat einen eigenen Vorwiderstand
und einen eigenen PWM-Pin:

| Farbe | Pin | Vorwiderstand |
|-------|-----|---------------|
| Rot   | 6   | 220 Ω         |
| Grün  | 5   | 220 Ω         |
| Blau  | 3   | 220 Ω         |

Die gemeinsame Kathode (längstes Bein) ist mit GND verbunden.
Es handelt sich um drei unabhängige Stromkreise mit gemeinsamer Masse.

## Funktionsprinzip (PWM)
Mit `analogWrite(pin, wert)` wird ein Wert zwischen 0 und 255 ausgegeben.
Der Pin liefert dabei keine kleinere Spannung, sondern schaltet sehr schnell
zwischen 0 V und 5 V um. Der Tastgrad ist g = Wert / 255.
Unser Auge sieht nur den Mittelwert, deshalb wirkt die LED dunkler oder heller.
→ Die Theorie und Messungen dazu stehen in Projekt 03.

## Code: Farbverlauf (selbst geschrieben)
```cpp
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

  // Phase 1: Rot → Grün
  for (int i = 0; i < 255; i += 1) {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(10);
  }

  // Phase 2: Grün → Blau
  for (int i = 0; i < 255; i += 1) {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(10);
  }

  // Phase 3: Blau → Rot
  for (int i = 0; i < 255; i += 1) {
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(10);
  }
}
```

Eine Phase dauert 255 Schritte × 10 ms ≈ 2,5 s, ein ganzer Durchlauf ≈ 7,5 s.

## Eigene Farben
| Farbe | Rot | Grün | Blau |
|-------|-----|------|------|
| Lila  | 255 | 0    | 255  |
| Gelb  | 255 | 255  | 0    |
| Türkis| 0   | 255  | 255  |
| Weiß  | 255 | 255  | 255  |

## Beobachtung
- Mit `delay(2)` statt `delay(10)` läuft der Farbverlauf etwa fünfmal schneller.
- Der Sketch mit drei `int`-Variablen braucht 15 Bytes Arbeitsspeicher,
  ohne die Variablen nur 9 Bytes. Der Unterschied von 6 Bytes passt genau:
  Ein `int` braucht auf dem UNO 2 Bytes.

## Problem & Lösung
Beim Schreiben des Codes hatte ich mehrere Fehler:
- Ich habe `HIGH` und `LOW` statt Zahlen verwendet.
  `analogWrite` braucht aber Werte von 0 bis 255.
- Tippfehler wie `blauValue`, `Delay` oder `daley`.
  C++ unterscheidet Groß- und Kleinschreibung.
- Semikolon statt Komma zwischen den Parametern.

Ich habe die Fehler Schritt für Schritt gefunden und korrigiert.
Tipp: Die Arduino-IDE färbt bekannte Befehle ein. Ein schwarzes Wort
ist oft ein Tippfehler.

## Erkenntnis
- Der Code entscheidet nur, an welchem Pin wann wie viel Spannung anliegt.
  Welche Farbe leuchtet, hängt von der Verdrahtung ab.
- Mit PWM kann man die Helligkeit steuern, ohne die Spannung zu verändern.
- Eine `for`-Schleife wiederholt Befehle eine bestimmte Anzahl von Malen.
