/*
 - lampu lalulintas dan hitung mundur + tombol reset -
 Note: gini aj lu pusing? lemah.

*/ 

const byte digitPatterns[] = {
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

       // 7segmen config: dp, g, f, e, d, c, b, a
const int segmenPins[] = { 5, 9, 8, 7, 6, 4, 3, 2 },
          lamp[] = { 12, 11, 10}, // trafic light
          urutan[] = {9, 2, 7}, // 
          buttonPins = 13;

int index = 0,
    show = 0;

void turnOn(int index) {
  for(int pin : lamp){
    digitalWrite(pin, pin == lamp[index]);
  }
}
void setup() {
  for (int i = 2; i <= 12; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(buttonPins, INPUT_PULLUP);
  turnOn(index);
}

void loop() {
  int show_number = urutan[index] - show;

  // showing numbers in 7segmen 
  for (int i = 1; i < 8; i++) {
    // note: a bitRead reading bit from right to left,
    digitalWrite(segmenPins[i], !bitRead(digitPatterns[show_number], i));
  }
  
  // calculate next displaying numbers
  show++;
  if ((urutan[index] - show) < 0) {
    show = 0;
    index++;
    if (index >= 3) index = 0;
  }

  // delay the number and cehking if reset button is pressed. 
  int time = 0;
  while (time < 990) {
    if (digitalRead(buttonPins) == !1) {
      index = 0;
      show = 0;
      time = 1000;
      turnOn(index);
    }
    delay(10);
    time += 10;
  }


  // refresh the trafic light when show number has reseted.
  if (show == 0) turnOn(index);
}
