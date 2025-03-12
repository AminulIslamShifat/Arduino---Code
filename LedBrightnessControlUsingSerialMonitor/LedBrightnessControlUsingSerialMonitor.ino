int ledPin = 9;  
int brightness = 0;  
void setup() {
  Serial.begin(9600);  
  pinMode(ledPin, OUTPUT); 
  Serial.println("Enter a brightness value (0-255) to control the LED:");
}

void loop() {
  if (Serial.available() > 0) {
    brightness = Serial.parseInt();  

    
    brightness = constrain(brightness, 0, 255);

    analogWrite(ledPin, brightness);  

    Serial.print("LED brightness set to: ");
    Serial.println(brightness);  
  }
}