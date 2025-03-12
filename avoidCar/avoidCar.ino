#include <NewPing.h>

// Motor control pins
const int in1 = 8;
const int in2 = 9;
const int in3 = 10;
const int in4 = 11;

// Ultrasonic sensor pins
const int trig = A0;
const int echo = A1;

NewPing sonar(trig, echo);

// Minimum distance for movement decisions
int minForward = 45;

void setup() {
Serial.begin(9600);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
}

void loop() {
    int distance = sonar.ping_cm();
    delay(100);
    if (distance == 0) {
        distance = 1000;
    }
    avoid(distance);
    Serial.println(distance);

}

void forward(int time) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(time);
}

void backward(int time) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(time);
}

void spinLeft(int time) {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    delay(time);
}

void spinRight(int time) {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    delay(time);
}

void stop() {
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void avoid(int distance) {
    if (distance < minForward) {
        spinLeft(random(300, 800));
    } else {
        forward(0);
        return;
    }
    stop();
    delay(200);
}
