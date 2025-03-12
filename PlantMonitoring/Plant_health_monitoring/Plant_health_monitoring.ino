#include "DHT.h"
#include <LiquidCrystal_I2C.h>

int moisture_1 ;
int moisture_2 ;
int pump_1 = 3;
int pump_2 = 4;

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(pump_1, OUTPUT);
  pinMode(pump_2, OUTPUT);
  dht.begin();
  lcd.init();     
  lcd.backlight();
}

void loop() {
  
  delay(2000); 

  float humi  = dht.readHumidity(); 
  float tempC = dht.readTemperature();
  lcd.clear();

  moisture_1=analogRead(A0);
  moisture_2=analogRead(A1);

if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  }

  else {
    lcd.setCursor(0, 0); 
    lcd.print("Temp: ");
    lcd.print(tempC);  
    lcd.print((char)223); 
    lcd.print("C");
    Serial.print("temp");
    Serial.println(tempC);
    
    lcd.setCursor(0, 1);  
    lcd.print("Humi: ");
    lcd.print(humi);   
    lcd.print("%");
    Serial.print("humi");
    Serial.println(humi);
  }
if (moisture_1 > 300){
  digitalWrite(pump_1, LOW);
  }
  else{
  digitalWrite(pump_1, HIGH);
  }


if (moisture_2 > 300){
  digitalWrite(pump_2, LOW);
  }
  else{
  digitalWrite(pump_2, HIGH);
  }
}