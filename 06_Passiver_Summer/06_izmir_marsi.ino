int summerPin = 8;

// Notalar (sayı = oktav)
#define SOLd4 415   // sol#
#define LA4   440
#define SI4   494
#define DO5   523
#define RE5   587
#define MI5   659
#define FA5   698
#define SOL5  784
#define LA5   880

// Süreler
#define KURZ   250   // normal nota
#define MITTEL 500   // _
#define LANG  1000   // ___

int melody[] = {
  // Phrase A
  LA4, MI5, MI5, MI5, MI5, MI5, MI5,   FA5, MI5, RE5, FA5, MI5,
  // Phrase A
  LA4, MI5, MI5, MI5, MI5, MI5, MI5,   FA5, MI5, RE5, FA5, MI5,
  // Phrase B
  MI5, LA5, SOL5, FA5, MI5, RE5,       MI5, RE5, DO5, SI4, DO5,
  // Phrase C
  DO5, MI5, RE5, DO5, SI4, LA4,        DO5, SI4, LA4, SOLd4, LA4,
  // Phrase A'
  LA4, MI5, MI5, MI5, MI5, MI5,   FA5, MI5, RE5, FA5, MI5,
  // Phrase A'
  LA4, MI5, MI5, MI5, MI5, MI5,   FA5, MI5, RE5, FA5, MI5,
  // Phrase B
  MI5, LA5, SOL5, FA5, MI5, RE5,       MI5, RE5, DO5, SI4, DO5,
  // Phrase C
  DO5, MI5, RE5, DO5, SI4, LA4,        DO5, SI4, LA4, SOLd4, LA4,
  // Phrase B
  MI5, LA5, SOL5, FA5, MI5, RE5,       MI5, RE5, DO5, SI4, DO5,
  // Phrase C
  DO5, MI5, RE5, DO5, SI4, LA4,        DO5, SI4, LA4, SOLd4, LA4,

};

int dauer[] = {
  // Phrase A
  MITTEL, KURZ, KURZ, KURZ, KURZ, KURZ, KURZ,   KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase A
  MITTEL, KURZ, KURZ, KURZ, KURZ, KURZ, KURZ,   KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase B
  MITTEL, MITTEL, KURZ, KURZ, KURZ, KURZ,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase C
  MITTEL, MITTEL, KURZ, KURZ, KURZ, KURZ,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase A'
  MITTEL, KURZ, KURZ, KURZ, KURZ, MITTEL,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase A'
  MITTEL, KURZ, KURZ, KURZ, KURZ, MITTEL,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase B
  MITTEL, MITTEL, KURZ, KURZ, KURZ, KURZ,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase C
  MITTEL, MITTEL, KURZ, KURZ, KURZ, KURZ,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase B
  MITTEL, MITTEL, KURZ, KURZ, KURZ, KURZ,       KURZ, KURZ, KURZ, KURZ, LANG,
  // Phrase C
  MITTEL, MITTEL, KURZ, KURZ, KURZ, KURZ,       KURZ, KURZ, KURZ, KURZ, LANG,
};

int anzahl = sizeof(melody) / sizeof(melody[0]);   // nota sayısını kendisi sayar

void setup() {
  Serial.begin(9600);
  pinMode(summerPin, OUTPUT);
  Serial.println(sizeof(melody) / sizeof(melody[0]));
  Serial.println(sizeof(dauer) / sizeof(dauer[0]));
}

void loop() {
  for (int i = 0; i < anzahl; i += 1) {
    Serial.println(i);
    tone(summerPin, melody[i], dauer[i] - 30);
    delay(dauer[i]);
  }
  delay(2000);   // şarkı bitince 2 saniye sus
}