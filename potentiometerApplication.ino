#include<LiquidCrystal.h>
int buttonup = 8;
int buttondown = 9;
int buttonzero = 7;
int zeroval;
int pot = A0;
int valup;
int valdown;
int potval;
unsigned int count = 0;
unsigned int potcount = 0;
unsigned int pressed = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  lcd.begin(16,2);
  lcd.print("VOLUME :");
  pinMode(buttonup, INPUT);
  pinMode(buttondown, INPUT);
  pinMode(buttonzero, INPUT);
  pinMode(pot, INPUT);
}

void loop() {
  valup = digitalRead(buttonup);
  valdown = digitalRead(buttondown);
  potval = analogRead(pot);
  zeroval = digitalRead(buttonzero);

  if(valup == HIGH && (count <= 50) && (pressed <= 50)){
    if(pressed >= 0 && pressed <= 50){
      if(count == 50){
          pressed = 50;
      }
      else{
        pressed = ++count;
        delay(25);
      }
    }
  }

  if(valdown == HIGH && (count >= 0)){
    if(pressed >= 0 && pressed <= 50){
      if(count == 0){
          pressed = 0;
      }
      else{
        pressed = --count;
        delay(25);
      }
    }    
  }  
  if(zeroval == HIGH){
    count = pressed = 0;
  }
  
  lcd.setCursor(9,0);
  lcd.print(pressed);
  if(pressed < 10){
    lcd.setCursor(10,0);
    lcd.print("%");
  }
  else{
    lcd.setCursor(11,0);
    lcd.print("%");
  }

  if(pressed < 10){
    lcd.setCursor(11,0);
    lcd.print(" ");
  }
  float potvalue = potval*(5.0 / 1023);
    lcd.setCursor(0,1);
    lcd.print("VOLTAGE : ");
    lcd.print(potvalue);
    lcd.print("v ");
    delay(150);
}
