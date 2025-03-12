int irSensorPin = 7;  
int irSensorValue = 0; 

void setup() {
  pinMode(irSensorPin, INPUT);  
  Serial.begin(9600);  
}

void loop() {
  irSensorValue = digitalRead(irSensorPin);
  if (irSensorValue == LOW) {
    Serial.println("Object detected!");
  } else {
    Serial.println("No object detected.");
  }
  delay(500);  
}
