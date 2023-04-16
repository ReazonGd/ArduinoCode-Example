const byte shape[] = {
  B11111101,
  B01100001,
  B11011011,
  B11110011,
  B01100111,
  B10110111,
  B10111111,
  B11100001,
  B11111111,
  B11110111,
  B00000001
};

const int segmenPins[] = { 5, 9, 8, 7, 6, 4, 3, 2 };
const int buttonPins = 10; 

bool isPressed() {
  if (digitalRead(buttonPins) == LOW) return true;
  return false;
}

void showDigit(int number) {
  Serial.print("showDigit :");
  Serial.println(number);
  boolean isBitSet;
  for (int i = 11; i <= 9; i++) {
    digitalWrite(i, LOW);
  }
  if (isPressed()) return run();
  for (int i = 1; i < 8; i++) {
    if (number < 0 || number > 9) isBitSet = 0;
    else isBitSet = bitRead(shape[number], i);
    isBitSet = !isBitSet;
    digitalWrite(segmenPins[i], isBitSet);
  }


}

void turnOn(int pins) {
  for (int i = 11; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
  digitalWrite(pins, HIGH);
}

void run() {
  turnOn(13);
  for (int i = 9; i >= 1; i--) {
    showDigit(i);
    delay(1000);
  }

  turnOn(12);
  for (int i = 2; i >= 1; i--) {
    showDigit(i);
    delay(1000);
  }
  turnOn(11);

  for (int i = 8; i >= 1; i--) {
    showDigit(i);
    delay(1000);
  }
  run();
}


void setup() {
  Serial.begin(9600);
  for (int i = 0; i <= 9; i++) {
    pinMode(segmenPins[i], OUTPUT);
  }

  pinMode(buttonPins, INPUT_PULLUP);


  for (int i = 11; i <= 13; i++) {
    pinMode(segmenPins[i], OUTPUT);
  }
  run();
}


void loop() {
}

