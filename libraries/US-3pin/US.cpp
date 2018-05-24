#include "US.h"

//****** US ******//
US::US(){
}

US::US(int pinTrigger, int pinEcho){
  US::init(pinTrigger,pinEcho);
}

void US::init(int pinTrigger, int pinEcho)
{
  //** The 3-pin version of the ultrasonic sensor uses the same
       pin for signaling (trigger) and reading data (echo). We
       accept a two-parameter call for easy compatibility with
       the 4-pin version, but we ignore the echo pin. 
  **//
  _pinTrigger = pinTrigger;
  _pinEcho = pinTrigger;
  pinMode( _pinTrigger , OUTPUT );
  pinMode( _pinEcho , INPUT );
}

long US::TP_init()
{
    digitalWrite(_pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(_pinTrigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(_pinTrigger, LOW);
    long microseconds = pulseIn(_pinEcho,HIGH,40000); //40000
    return microseconds;
}

float US::read(){
  long microseconds = US::TP_init();
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = 999;
  }
  return distance;
}
