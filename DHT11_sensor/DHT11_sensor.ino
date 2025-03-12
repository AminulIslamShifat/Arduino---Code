#include <LiquidCrystal_I2C.h>
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(DHTPIN, DHTTYPE);
int fan =5;
int light =6;

void setup()
{
  Serial.begin(9600);     
  dht.begin();
  pinMode(fan,OUTPUT);
  pinMode(light,OUTPUT);
  lcd.init();     
  lcd.backlight();
}

void loop()
{
  delay(2000); 

  float humi  = dht.readHumidity(); 
  float tempC = dht.readTemperature();
  lcd.clear();
 
  if (isnan(humi) || isnan(tempC)) {
    lcd.setCursor(0, 0);
    lcd.print("Failed");
  } else {
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
 if (tempC>44.50) 
 {
 digitalWrite(5,HIGH);

 }
 else {

  digitalWrite(5,LOW);
}
  if (humi>70.00)
  {
  digitalWrite(6,LOW);
  }
  else{
    digitalWrite(6,HIGH);
  }
}