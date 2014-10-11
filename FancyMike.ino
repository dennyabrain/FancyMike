//Code to Read a Hall effect sensor connected to the digtal pin number 2 of Arduino
//The sensor acts as a switch and sends 1 by default. It goes 0 when a south pole of the magnet approaches.
//We calculate the time difference between consecutive 0s to measure the rotational velocity of the wheel.
//Written by Denny George

const int buttonPin=2;
int buttonState=1;
volatile int state=LOW;
int ledPin=13;

unsigned long currentOnTime=0, lastOnTime=0;
int rotationalVelocity=0;

void setup(){
  pinMode(ledPin,OUTPUT);
  attachInterrupt(0,blink,CHANGE);
}

void loop(){
    digitalWrite(ledPin,state);
}

void blink(){
  state=!state;
}
