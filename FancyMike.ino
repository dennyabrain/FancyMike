
const int buttonPin = 2;    
const int ledPin = 13;      

// Variables will change:
int ledState = HIGH;         
int buttonState;             
int lastButtonState = LOW;   

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long lastDebounceTime = 0;  
long debounceDelay = 10;    
long lastOnTime=0;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        ledState = LOW ;
        //Serial.println("Magnet Near");
        //Serial.print(5);
        long currentOnTime=millis();
        long timeDiff=currentOnTime-lastOnTime;
        lastOnTime=currentOnTime;
        timeDiff=constrain(timeDiff,1500,2500);
        timeDiff=timeDiff/10;
        Serial.write(timeDiff);
        //Serial.println(timeDiff);
        /*
        if(timeDiff>2500){
          Serial.print(5);
        }
        else if(timeDiff<2500 && timeDiff>2000){
          Serial.print(4);
        }
        else if(timeDiff<2000 && timeDiff>1500){
         Serial.print(3);
        }
        else if(timeDiff<1500 && timeDiff>1250){
          Serial.print(2);
        }
        else if(timeDiff<1250 && timeDiff>1000){
          Serial.print(1);
        }
        else if(timeDiff<1000 && timeDiff>0){
          Serial.print(0);
        }*/        
      }
      else{
        ledState = HIGH;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}

