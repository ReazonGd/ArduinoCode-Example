/**
  Simple Pin Password

  This is simple Arduino pin password.
  with a sleep mode! 🗿

  made by Reazon.
*/

#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

int sleep = 0;
boolean backlight = !0; 
boolean isOpen = !1;
String pass = "";
String insert = "";
char keys[4][4] = {
  { '1', '2', '3'},
  { '4', '5', '6'},
  { '7', '8', '9'},
  { 'C', '0', '#'}
};
uint8_t colPins[4] = { 5, 4, 3, 2 };
uint8_t rowPins[4] = { 9, 8, 7, 6 };

Servo myservo;
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, 4, 4);
LiquidCrystal_I2C lcd(0x27, 20, 4);


// displaying message. untuk kemudahan :)
void lcdPrint(String message, boolean seconLine = !1, boolean clearLCD = !0, int delayMSecond = 10, boolean isNext = !1){
  if (clearLCD) lcd.clear();
  if (!isNext){
    if (seconLine) lcd.setCursor(0, 1);
    else lcd.setCursor(0, 0);
  }
  lcd.print(message);
  delay(delayMSecond);
}

void setup() {
  lcd.init();
  lcd.backlight();
  myservo.attach(11);
  myservo.write(0); 

  // set display
  lcdPrint("SET PASSWORD");
}

void loop() {
  delay(10);
  digitalWrite(13, isOpen);

  char key = keypad.getKey();

  // sleep mode when no for 5 seconds
  if (key == NO_KEY) {
    sleep += 10;
    if (sleep > 4950 || isOpen) {
      sleep = 4950;
      if (backlight) {
        lcd.noBacklight();
        lcd.noDisplay();
        backlight = !1;
      }
      
    }
    return;
  };

  // wakeup from sleep
  if (!backlight) {
    if (isOpen) isOpen = !1;
    lcd.backlight();
    lcd.display();
    backlight = !0;
    sleep = 0;
    return;
  }
  sleep = 0;
  insertPass(key);
}

void insertPass(char key) {
  if (key == 'C') insert = "";
  else if (key == '#') {
    if (pass.length() == 0) {
      // Set Password
      pass = insert;
      insert = "";
      myservo.write(180); 
      lcdPrint("LOCKED!", false, true, 700);
    }
    else if (insert == pass) {
      // when the pass is valid
      insert = "";
      pass = "";
      isOpen = !0;
      myservo.write(0); 
      lcdPrint("UNLOCKED!", false, true, 1000);
      return;
    }
    else{
      lcdPrint("PASSWORD");
      lcdPrint("INCORECT!", true, false, 1000);
      insert = "";
      insertPass('C');
    }
  }
  else {
    if (10 != insert.length()) insert += key;
  }
  if (pass.length() == 0) {
    lcdPrint("SET PASSWORD");
    lcdPrint(insert, !0, !1);
  }
  else {
    lcdPrint("ENTER PASSWORD");
    lcdPrint(insert, true, false);
  }
}
