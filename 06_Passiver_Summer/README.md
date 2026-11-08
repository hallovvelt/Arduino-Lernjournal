# 06 – Passiver Summer und Melodie

## Ziel
Mit einem passiven Summer verschiedene Töne erzeugen und eine Melodie
programmieren und abspielen.

## Bauteile
- ELEGOO UNO R3
- ein passiver Summer
- ein Steckbrett
- 2 Jumper-Kabel

## Schaltung
Zuerst stecke ich den passiven Summer in das Steckbrett. Dann verbinde ich
ein Bein (+) mit Pin 8 und das andere Bein mit dem GND-Pin.

## Funktionsprinzip
Im passiven Summer gibt es keine eingebaute Schwingungsquelle. Deshalb erzeugt
der Arduino den Ton mit der Funktion `tone(pin, frequenz, dauer)`.
Der Pin wird dabei sehr schnell ein- und ausgeschaltet, zum Beispiel
523-mal pro Sekunde für den Ton „Do" (523 Hz).

```cpp
tone(summerPin, 523, 500);   // Do: 523 Hz, 500 ms
delay(500);
```

## Beobachtung
Je höher die Frequenz ist, desto kürzer ist die Periodendauer
und desto höher klingt der Ton:

| Ton | Frequenz | Periodendauer |
|-----|----------|---------------|
| Do  | 523 Hz   | ≈ 1,91 ms     |
| Re  | 587 Hz   | ≈ 1,70 ms     |
| Mi  | 659 Hz   | ≈ 1,52 ms     |

## Problem & Lösung
- **`tone()` wartet nicht:** Der Code geht sofort zur nächsten Zeile weiter.
  Deshalb braucht man nach jedem Ton ein `delay()`.
- **Gleiche Töne klingen wie ein langer Ton:** Wenn ein Ton etwas kürzer ist
  als die Wartezeit (z. B. `tone(..., 450)` und `delay(500)`),
  entsteht eine kleine Pause zwischen den Tönen.
- **Der Code war zu lang:** Meine erste Melodie hatte über 60 Zeilen.
  Ich konnte Fehler nicht finden und nicht korrigieren.
  Lösung:
  - Die Frequenzen haben Namen bekommen (`#define MI5 659`).
  - Die Noten und die Tondauern stehen in zwei Arrays.
  - Eine `for`-Schleife spielt alle Noten nacheinander ab.
  - Der serielle Monitor zeigt die Nummer der aktuellen Note.
    So finde ich sofort die falsche Note.
- **Die Melodie klang komisch:** Alle Noten waren gleich lang.
  Erst mit verschiedenen Tondauern (kurz, mittel, lang)
  war die Melodie zu erkennen.

## Projekt: İzmir Marşı
Mit diesem Wissen habe ich den İzmir-Marsch programmiert (112 Noten).
Das Lied besteht aus vier Phrasen (A, A', B, C), die sich wiederholen.
Deshalb musste ich jede Phrase nur einmal schreiben und dann kopieren.

## Erkenntnis
- Ein Array speichert viele Werte unter einem Namen. Die Zählung beginnt bei 0.
- Mit `sizeof(melody) / sizeof(melody[0])` zählt der Arduino die Noten selbst.
- Ein gut strukturierter Code ist leichter zu korrigieren als ein langer Code.

## Code
💾 [İzmir Marşı](06_izmir_marsi.ino)
