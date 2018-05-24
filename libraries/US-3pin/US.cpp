#include "US.h"

//****** US ******//
US::US(){
}

US::US(int pinTrigger, int pinEcho){
  US::init(pinTrigger,pinEcho);
}

void US::init(int pinTrigger, int pinEcho)
{
  // The 3-pin version of the ultrasonic sensor uses the same
  // pin for signaling (trigger) and reading data (echo). We
  // accept a two-parameter call for easy compatibility with
  // the 4-pin version, but we ignore the echo pin. 
  _pinTrigger = pinTrigger;
}

long US::TP_init()
{
    // First, trigger the US with a LOW pulse, to clear any signal out
    // then a HIGH signal longer than 2 microseconds.
    pinMode(pinTrigger, OUTPUT);
    digitalWrite(_pinTrigger, LOW);
    delayMicroseconds(2);
    digitalWrite(_pinTrigger, HIGH);
    delayMicroseconds(5);
    digitalWrite(_pinTrigger, LOW);
    // Next, read the pin for input, waiting a maximum of .03 seconds for
    // a pulse to start (for return of responsiveness, if nothing happens).
    pinMode(_pinTrigger, INPUT);
    long microsecondsDuration = pulseIn(_pinTrigger,HIGH,30000);
    return microsecondsDuration;
}

float US::read(){
  // Read the 
  long microseconds = US::TP_init();
  long distance;
  distance = microseconds/29/2;
  if (distance == 0){
    distance = 999;
  }
  return distance;
}
