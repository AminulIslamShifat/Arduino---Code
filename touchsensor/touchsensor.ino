#include <Servo.h>
Servo s1;
int led = 8;
int touch = 2;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(touch, INPUT);
  s1.attach(9);
}

void loop() {
  int x = digitalRead(touch);
  Serial.println(x);
  delay(100);
if(x==-0){
  digitalWrite(led, HIGH);
  s1.write(90);
}
else{
  digitalWrite(led, LOW);
  s1.write(0);
}

}
