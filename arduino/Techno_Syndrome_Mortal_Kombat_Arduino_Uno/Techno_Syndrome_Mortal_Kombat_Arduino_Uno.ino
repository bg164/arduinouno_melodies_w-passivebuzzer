/*
  Mortal Kombat (Techno Syndrome) - Uzatılmış Kusursuz Versiyon
*/

#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F4  349
#define NOTE_G5  784
#define NOTE_A5  880

const int buzzerPin = 8; 

// Şarkı Yapısı: Giriş Vuruşları -> 4 Defa Ana Melodi -> Nakarat Kapanışı
int melody[] = {
  // --- BÖLÜM 1: İkonik "MORTAL KOMBAT!" Başlangıç Vuruşları ---
  NOTE_A4, 0, NOTE_C5, 0, NOTE_A4, 0, NOTE_D5, 0, 
  NOTE_A4, 0, NOTE_E5, 0, NOTE_D5, 0, 0, 0, 

  // --- BÖLÜM 2: Ana Techno Riff (1. Tekrar) ---
  NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_F4, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_F4, NOTE_C5, NOTE_B4,

  // --- BÖLÜM 3: Ana Techno Riff (2. Tekrar) ---
  NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_F4, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_F4, NOTE_C5, NOTE_B4,

  // --- BÖLÜM 4: Ana Techno Riff (3. Tekrar) ---
  NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_F4, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_F4, NOTE_C5, NOTE_B4,

  // --- BÖLÜM 5: Ana Techno Riff (4. Tekrar) ---
  NOTE_A4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_A4, NOTE_E5, NOTE_D5,
  NOTE_C5, NOTE_C5, NOTE_E5, NOTE_C5, NOTE_G5, NOTE_C5, NOTE_E5, NOTE_C5,
  NOTE_G4, NOTE_G4, NOTE_B4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_D5, NOTE_C5,
  NOTE_F4, NOTE_F4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_F4, NOTE_C5, NOTE_B4,

  // --- BÖLÜM 6: Çılgın Nakarat Kapanışı ---
  NOTE_A4, NOTE_A4, NOTE_G4, NOTE_A4, NOTE_C5, NOTE_A4, NOTE_D5, NOTE_C5,
  NOTE_E5, NOTE_E5, NOTE_D5, NOTE_E5, NOTE_G5, NOTE_E5, NOTE_A5, NOTE_G5,
  NOTE_A5, 0, NOTE_A5, 0, NOTE_A5, NOTE_A5, 0, 0
};

// Hassas ayarlanmış 137 BPM nota süreleri
int noteDurations[] = {
  // Giriş Vuruşları
  220, 110, 220, 110, 220, 110, 220, 110,
  220, 110, 220, 110, 220, 110, 220, 440,

  // Ana Riff 1
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,

  // Ana Riff 2
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,

  // Ana Riff 3
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,

  // Ana Riff 4
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,

  // Nakarat Kapanışı
  110, 110, 110, 110, 110, 110, 110, 110,
  110, 110, 110, 110, 110, 110, 110, 110,
  220, 110, 220, 110, 110, 110, 220, 800
};

void setup() {
  // Döngü loop içinde çalışacak
}

void loop() {
  int size = sizeof(melody) / sizeof(int);

  for (int thisNote = 0; thisNote < size; thisNote++) {
    int duration = noteDurations[thisNote];
    
    if (melody[thisNote] == 0) {
      delay(duration);
    } else {
      tone(buzzerPin, melody[thisNote], duration);
      
      // Kusursuz staccato (kesik klavye vuruşu) etkisi
      int pause = duration * 0.20; 
      delay(duration + pause);
    }
    noTone(buzzerPin);
  }
  
  // Döngü bitince baştan başlamadan önce 1.5 saniye es ver
  delay(1500); 
}
