#include <DHT.h>

// Pin Definitions
#define LDR_PIN A0
#define DHT_PIN 2
#define DHT_TYPE DHT11
#define PIR_PIN 3
#define BUZZER_PIN 4
#define MQ2_PIN A1
#define EXHAUST_PIN 5
#define ULTRASONIC_TRIG 6
#define ULTRASONIC_ECHO 7
#define BULB_PIN 8
#define FAN_PIN 9
#define PUMP_PIN 10

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(EXHAUST_PIN, OUTPUT);
  pinMode(BULB_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(ULTRASONIC_TRIG, OUTPUT);
  pinMode(ULTRASONIC_ECHO, INPUT);
  pinMode(PUMP_PIN, OUTPUT);
  dht.begin();
}

void loop() {
  // Read LDR Sensor
  int ldrValue = analogRead(LDR_PIN);

  // Control Bulb Based on Light Level
  if (ldrValue > 800) {  // Adjust threshold as needed
    digitalWrite(BULB_PIN, LOW);
  } else {
    digitalWrite(BULB_PIN, HIGH);
  }

  // Read DHT11 Sensor
  float temp = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Control Fan Based on Temperature
  if (temp > 30) {  // Adjust temperature threshold as needed
    digitalWrite(FAN_PIN, LOW);
  } else {
    digitalWrite(FAN_PIN, HIGH);
  }

  // Read PIR Sensor
  int pirValue = digitalRead(PIR_PIN);

  // Activate Buzzer on Motion Detection
  if (pirValue == HIGH) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }

  // Read MQ-2 Gas Sensor
  int mq2Value = analogRead(MQ2_PIN);

  // Control Exhaust Fan Based on Gas Detection
  if (mq2Value > 300) {  // Adjust gas threshold as needed
    digitalWrite(EXHAUST_PIN, LOW);
  } else {
    digitalWrite(EXHAUST_PIN, HIGH);
  }
  

  // Ultrasonic Sensor for Water Level
  long duration, distance;
  digitalWrite(ULTRASONIC_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIG, LOW);
  duration = pulseIn(ULTRASONIC_ECHO, HIGH);
  distance = (duration / 2) / 29.1;  // Calculate distance in cm

// Control Water Level
  if (distance <= 3){  // Adjust as water tank size
    digitalWrite(PUMP_PIN, HIGH);
  } if(distance >= 10) {
    digitalWrite(PUMP_PIN, LOW);
  }

  // Print Sensor Data to Serial Monitor
  Serial.print("LDR: ");
  Serial.print(ldrValue);
  Serial.print(" | Temp: ");
  Serial.print(temp);
  Serial.print("C | Humidity: ");
  Serial.print(humidity);
  Serial.print("% | PIR: ");
  Serial.print(pirValue);
  Serial.print(" | MQ-2: ");
  Serial.print(mq2Value);
  Serial.print(" | Water Level: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Delay for stability
  delay(1000);  // 1-second interval
}
