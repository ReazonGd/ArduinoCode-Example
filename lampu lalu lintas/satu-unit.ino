const int pin = { 1, 2, 3};
// ubah konfigurasi pin di atas.


void hidupkan(int pins) {
  for (int i = 11; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(pins, HIGH);
  // dengan begini lampu yang hidup sebelumnya akan otomatis mati
}

void setup() {
  for (int i = 0; i <= 2; i++) {
    pinMode(pin[i], OUTPUT);
  }
}


void loop() {
    hidupkan(pin[0]); //lampu Merah hidup
    delay(2000);
    hidupkan(pin[1]); //lampu Kuning hidup
    delay(700);
    hidupkan(pin[2]); //lampu Hijau hidup
    delay(1000);
    hidupkan(pin[1]); //lampu Kuning hidup
    delay(700);
}

