int potPin = A2; 
int ledPin = 9;  
int potValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  potValue = analogRead(potPin);           
  int brightness = map(potValue, 0, 1023, 0, 255); 
  analogWrite(ledPin, brightness);       
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" - LED Brightness: ");
  Serial.println(brightness);
  delay(100); 
}
