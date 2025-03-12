int ldrPin = A0;  
int ldrValue = 0; 

void setup() {

  Serial.begin(9600); 
  pinMode(ldrPin, INPUT); 
  
}

void loop() {
  
  ldrValue = analogRead(ldrPin);
  Serial.print("Light Intensity: ");
  Serial.println(ldrValue);
  delay(500);

}
