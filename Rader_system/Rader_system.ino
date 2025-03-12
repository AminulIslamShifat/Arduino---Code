int led1 = 11;
int led2 = 12;
int led3 = 13;
int buttonstate = 7;
int value;
void setup()
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buttonstate, INPUT);
}
void loop()
{
 value=digitalRead(buttonstate); 
  if (value == 0){
  digitalWrite(led1, HIGH);
  delay(100);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(100); 
  digitalWrite(led2, LOW);
  digitalWrite(led3, HIGH);
  delay(100); 
  digitalWrite(led3, LOW);
  delay(100); 
  }
  else {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  }
}