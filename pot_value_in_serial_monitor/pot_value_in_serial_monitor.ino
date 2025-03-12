int pot=A0;
int x;

void setup() {
  serial.begin(9600);
  pinMode(A0,INPUT);  
}

void loop() {
  x=analogread(pot);
  Serial.printIn(x)
  delay(100)
  

}
