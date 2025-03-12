#include <LiquidCrystal_I2C.h>;
int IR = 13;
LyquidCrystal_I2C lcd(ox27 , 16, 2);
int count_value = 0;

void setup(){
  lcd.begin();
  lcd.backlight();
  pinMode(IR, INPUT);
  pinMode(8, OUTPUT);
}

Void loop(){
  int x = digitalRead(IR);
  
  if (x == LOW){
    count_value++;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("object");
    lcd.setCursor(11,0);
    lcd.print(count_value);
    
  }
  if (count_value == 5){
    lcd.print("done");
    digitalWrite(8, HIGH);

  }
  delay(200);
}
