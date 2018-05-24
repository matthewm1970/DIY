/*
 3-pin Ultrasonic Sensor Ping distance test
 VCC to arduino 5v 
 GND to arduino GND
 SIG (Trigger/Echo) to Arduino pin 13
 Red POS to Arduino pin 11
 Green POS to Arduino pin 10
 560 ohm resistor to both LED NEG and GRD power rail
 Based on the 4-pin US test by cparrapa
*/

#define trigPin 13
#define led 11  // Red
#define led2 10 // Green

#include <US.h>

void setup() {
  Serial.begin (9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  us.init(trigPin,trigPin);
}

void loop() {
  long duration, distance;
  distance = us.read();
  if (distance < 4) {  // This is where the LED On/Off happens
    digitalWrite(led,HIGH); // When the Red condition is met, the Green LED should turn off
    digitalWrite(led2,LOW);
  } else {
    digitalWrite(led,LOW);
    digitalWrite(led2,HIGH);
  }
  if (distance >= 200 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}
