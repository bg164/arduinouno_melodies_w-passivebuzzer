// The Legend of Zelda - Lost Woods (Saria's Song) - Uzatılmış Tam Versiyon
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880

const int buzzerPin = 8;
const int BPM = 140; 

// Şarkının 1. ve 2. bölümlerini içeren uzatılmış melodi dizisi
int melody[] = {
  // --- BÖLÜM 1 (Az Önceki Kısım) ---
  NOTE_F4, NOTE_A4, NOTE_B4, 
  NOTE_F4, NOTE_A4, NOTE_B4,
  NOTE_F4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_D5,
  NOTE_B4, NOTE_C5, NOTE_B4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4,
  NOTE_D4, NOTE_E4, NOTE_G4, NOTE_E4,

  // --- BÖLÜM 2 (Yeni Eklenen Uzatılmış Kısım) ---
  NOTE_F4, NOTE_A4, NOTE_B4, 
  NOTE_F4, NOTE_A4, NOTE_B4,
  NOTE_F4, NOTE_A4, NOTE_B4, NOTE_E5, NOTE_D5,
  NOTE_B4, NOTE_C5, NOTE_E5, NOTE_B4, NOTE_G4,
  NOTE_B4, NOTE_G4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_E4, NOTE_F4, NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5
};

// Uzatılmış melodinin milimetrik vuruş süreleri
float noteBeats[] = {
  // --- BÖLÜM 1 RİTMİ ---
  0.5, 0.5, 1.0, 
  0.5, 0.5, 1.0,
  0.5, 0.5, 0.5, 0.5, 1.5,
  0.5, 0.5, 0.5, 0.5, 2.0,
  0.5, 0.5, 0.5, 1.5,
  0.5, 0.5, 0.5, 2.0,

  // --- BÖLÜM 2 RİTMİ ---
  0.5, 0.5, 1.0, 
  0.5, 0.5, 1.0,
  0.5, 0.5, 0.5, 0.5, 1.5,
  0.5, 0.5, 0.5, 0.5, 2.0,
  0.5, 0.5, 1.0, 1.0,
  0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 2.0  // Sonda şarkıyı zirveye taşıyan tırmanış
};

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int totalNotes = sizeof(melody) / sizeof(int);
  float beatDuration = 60000.0 / BPM; 

  for (int thisNote = 0; thisNote < totalNotes; thisNote++) {
    int noteDuration = noteBeats[thisNote] * beatDuration;
    
    // Ritmik staccato (%75 doluluk) hissi korunuyor
    tone(buzzerPin, melody[thisNote], noteDuration * 0.75);

    delay(noteDuration);
    noTone(buzzerPin);
  }
  
  // Şarkı bitip en başa sarmadan önce 2 saniye nefes alma boşluğu
  delay(2000); 
}
