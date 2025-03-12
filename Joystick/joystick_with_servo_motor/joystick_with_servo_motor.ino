#include <Servo.h>

int xpin=A0;
int ypin=A1;
int button=2;
int led=13;

int xval;
int yval;
int buttonstate;

int xServoPosition;
int yServoPosition;

Servo xServo;
Servo yServo;

void setup() {
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(button, INPUT);
  pinMode(led, OUTPUT);

xServo.attach(8);
yServo.attach(9);

}

void loop() {
xval=analogRead(xpin);
yval=analogRead(ypin);
buttonstate=analogRead(button);

//map() Function Use map(a value that is input, lowest value of input, highest value of input,lowest value of output, highest value of output)

xServoPosition=map(xval,0,1023,0,180);
yServoPosition=map(yval,0,1023,0,180);

xServo.write(xServoPosition);
yServo.write(yServoPosition);

if (buttonstate==HIGH){
  digitalWrite(led, HIGH);
}
else{
  digitalWrite(led, LOW);
}

}
