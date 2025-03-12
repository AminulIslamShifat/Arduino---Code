#define FLAME 2 
#define ALARM 7
#define LED 6

void setup() {
  Serial.begin(9600);
  pinMode(FLAME, INPUT);
  pinMode(ALARM, OUTPUT);
  pinMode(LED, OUTPUT);
  
}

void loop() {

  int fire = digitalRead(FLAME);
  if( fire == LOW)
  {
    digitalWrite(ALARM,HIGH);
    digitalWrite(LED,HIGH);
    Serial.println("Fire! Fire!");
  }
  
  else{
    digitalWrite(ALARM,LOW); 
    digitalWrite(LED,HIGH);
    Serial.println("Peace");
  }

  delay(200);
}