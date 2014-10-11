//Code to Read a Hall effect sensor connected to the digtal pin number 2 of Arduino
//The sensor acts as a switch and sends 1 by default. It goes 0 when a south pole of the magnet approaches.
//We calculate the time difference between consecutive 0s to measure the rotational velocity of the wheel.
//Written by Denny George

const int buttonPin=2;
int buttonState=1;

unsigned long currentOnTime=0, lastOnTime=0;
int rotationalVelocity=0;

void setup(){
  pinMode(buttonPin,INPUT);
  Serial.begin(9600);
}

void loop(){
  buttonState=digitalRead(buttonPin);
  if(buttonState==0){
    digitalWrite(13,HIGH);
    currentOnTime=millis();
  }
  if(buttonState==1){
    digitalWrite(13,LOW);
    rotationalVelocity=0;
  }
  
  rotationalVelocity=currentOnTime-lastOnTime;//not inverting this for now.
  rotationalVelocity=map(rotationalVelocity,0,1000,0,255);
  lastOnTime=currentOnTime;

  
  if(buttonState==0){
    Serial.println(rotationalVelocity);
  }
//  delay(5);
}
