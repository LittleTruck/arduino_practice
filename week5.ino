//#include <Wire.h>
////#include "rgb_lcd.h"
//rgb_lcd lcd;
const int potentiometer = A0;
const int pinButton = 6;
const int pinBuzzer = 5;

int time = 0;
int right = 1;

//const int pinLed = 3;
void setup() {
  Serial.begin(9600);
  pinMode(potentiometer, INPUT);
  pinMode(pinBuzzer, OUTPUT);
}
void loop() {
  check();
}
int check() {
  int ans1 = 0, ans2 = 1, ans3 = 2, ans4 = 3;
  int input = 0;
  int value = analogRead(potentiometer);
  value = (int)value / 102.4;
  if (digitalRead(pinButton)) {
    time = time + 1;
    {
      Serial.print("time:");
      Serial.println(time);
      switch (time) {
        case 1:
          if (value != ans1) {
            right = 0;
            Serial.print("no");
          }
          break;
        case 2:
          if (value != ans2) {
            right = 0;
            Serial.print("no");
          }
          break;
        case 3:
          if (value != ans3) {
            right = 0;
            Serial.print("no");
          }
          break;
        case 4:
          if (value != ans4) {
            right = 0;
            Serial.print("no");
          }
          break;
      }
    }
  }
  if (time == 4) {
    if (right == 1) {
      //    lcd.print("Welcome home!");
      Serial.print("yes");
    } else {
      //    digitalWrite(pinBuzzer,HIGH);
      //    lcd.print("***WRONG!!***");
      Serial.print("no");
    }
  }

  Serial.print(value);
  delay(100);
}
