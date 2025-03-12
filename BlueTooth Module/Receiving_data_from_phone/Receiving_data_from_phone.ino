int led = 13;
int data;    //Indentifing the data found from the Bluetooth module

void setup() {

  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {

while(Serial.available() > 0 ) {   //to check if the data is greater than the data 0
  data = Serial.read();      // to store the data from bluetooth module to the variable(data)
  Serial.println(data);      //print the data stored in data will be print in serial monitor
}    

}
