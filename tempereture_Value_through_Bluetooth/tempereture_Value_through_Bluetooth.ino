#include <SoftwareSerial.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht (DHTPIN, DHTTYPE);

SoftwareSerial B(10,11);

void setup() {
  B.begin(9600);
  dht.begin();

}

void loop() {
    delay(2000); 

  float humi  = dht.readHumidity(); 
  float tempC = dht.readTemperature();

  B.print(humi);
  B.print("%");
  B.print(",");
  B.print(tempC);
  B.print(" C");
  B.print(";");

}
