#include <SoftwareSerial.h>
SoftwareSerial B(10,11);

int x = 5;
int y = 10;


void setup() {
  
  B.begin(9600);

}

void loop() {
  B.print(x);
  B.print(",");
  B.print(y);
  B.print(";");
  delay(100);
}
