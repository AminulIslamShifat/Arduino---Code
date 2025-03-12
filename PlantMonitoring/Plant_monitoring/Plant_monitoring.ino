int moisture_1 ;
int moisture_2 ;
int pump_1 = 3;
int pump_2 = 4;

void setup() {
  
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(pump_1, OUTPUT);
  pinMode(pump_2, OUTPUT);

}

void loop() {
  moisture_1=analogRead(A0);
  moisture_2=analogRead(A1);

if (moisture_1 > 300){
  digitalWrite(pump_1, LOW);
  }
  else{
  digitalWrite(pump_1, HIGH);
  }


if (moisture_2 > 300){
  digitalWrite(pump_2, LOW);
  }
  else{
  digitalWrite(pump_2, HIGH);
  }
}