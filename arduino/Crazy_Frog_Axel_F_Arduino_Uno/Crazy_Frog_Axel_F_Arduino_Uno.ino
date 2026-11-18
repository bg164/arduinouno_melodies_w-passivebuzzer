/*
  Star Wars (Imperial March) - Switch Kontrollü ve 5 Saniye Beklemeli Versiyon
*/

#define NOTE_F4  349
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_C5  523
#define NOTE_E5  659
#define NOTE_F5  698

const int buzzerPin = 8; 
const int switchPin = 2;

const unsigned long bekleme = 5000UL;      // Switch açıldıktan sonra ilk çalma öncesi 5 sn bekleme
const unsigned long sarkiArasi = 1500UL;   // Şarkı bitince tekrar başlamadan önce 1.5 sn es

// Imperial March Melodisi
int melody[] = {
  NOTE_A4, NOTE_A4, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_C5, NOTE_A4,
  NOTE_E5, NOTE_E5, NOTE_E5, NOTE_F5, NOTE_C5, NOTE_GS4, NOTE_F4, NOTE_C5, NOTE_A4
};

int noteDurations[] = {
  500, 500, 500, 350, 150, 500, 350, 150, 1000,
  500, 500, 500, 350, 150, 500, 350, 150, 1000
};

const int notaSayisi = sizeof(melody) / sizeof(int);

unsigned long acilmaZamani = 0;
unsigned long notaBaslangic = 0;
unsigned long sesSuresi = 0;
unsigned long slotSuresi = 0;
unsigned long bitisZamani = 0;
int notaIndex = 0;
bool sayiyor = false;
bool caliyor = false;
bool sesAcik = false;
bool bekliyor = false;

void notaCal(int i) {
  int duration = noteDurations[i];
  notaBaslangic = millis();
  
  if (melody[i] == 0) {
    noTone(buzzerPin);
    sesAcik = false;
    sesSuresi = 0;
    slotSuresi = duration;
  } else {
    tone(buzzerPin, melody[i]);
    sesAcik = true;
    sesSuresi = duration;
    // %15 staccato boşluğu
    slotSuresi = duration + (unsigned long)(duration * 0.15);
  }
}

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);  // Kapalı = LOW, Açık = HIGH
}

void loop() {
  bool switchAcik = (digitalRead(switchPin) == HIGH);

  if (!switchAcik) {
    // Switch kapalıyken her şeyi sıfırla ve sustur
    sayiyor = false;
    caliyor = false;
    sesAcik = false;
    bekliyor = false;
    notaIndex = 0;
    noTone(buzzerPin);
  } else {
    // Switch açıldıysa 5 saniyelik ilk sayacı başlat
    if (!sayiyor) {
      sayiyor = true;
      acilmaZamani = millis();
    }

    // 5 saniye dolduysa müziği başlat
    if (!caliyor && !bekliyor && millis() - acilmaZamani >= bekleme) {
      caliyor = true;
      notaIndex = 0;
      notaCal(notaIndex);
    }

    // Çalma süreci
    if (caliyor) {
      unsigned long gecen = millis() - notaBaslangic;

      if (sesAcik && gecen >= sesSuresi) {
        noTone(buzzerPin);
        sesAcik = false;
      }

      if (gecen >= slotSuresi) {
        notaIndex++;
        if (notaIndex >= notaSayisi) {
          caliyor = false;
          bekliyor = true;
          bitisZamani = millis();
          noTone(buzzerPin);
        } else {
          notaCal(notaIndex);
        }
      }
    }

    // Şarkı bittiğinde 1.5 saniye bekleyip baştan al
    if (bekliyor && millis() - bitisZamani >= sarkiArasi) {
      bekliyor = false;
      caliyor = true;
      notaIndex = 0;
      notaCal(notaIndex);
    }
  }

  delay(1);
}