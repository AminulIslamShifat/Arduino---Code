int led = 13;
int data;    

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {

while(Serial.available() > 0 ) {   
  data = Serial.read();     
  Serial.println(data);      
}    

if (data == 'A'){
  digitalWrite(led, HIGH);
}

if (data == 'B'){
  digitalWrite(led, LOW);
}

}
