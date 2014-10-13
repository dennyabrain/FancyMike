//Code to Read a Hall effect sensor connected to the digtal pin number 2 of Arduino
//The sensor acts as a switch and sends 1 by default. It goes 0 when a south pole of the magnet approaches.
//We calculate the time difference between consecutive 0s to measure the rotational velocity of the wheel.
//Written by Denny George

volatile unsigned long timePerRotation = 0;
volatile unsigned long lastmillis=0;
volatile unsigned long currentmillis=0;

void setup(){
  Serial.begin(9600);
  attachInterrupt(0,rpm_fan,RISING);
}

void loop(){
  timePerRotation=constrain(timePerRotation,6100,7500);
 // timePerRotation=map(timePerRotation,6100,7000,0,255);
  Serial.println(timePerRotation);
}

void rpm_fan(){
  currentmillis=millis();
  timePerRotation=(lastmillis-currentmillis)%10000;
  lastmillis=currentmillis;
}
