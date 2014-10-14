
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
        long timeDiff=millis()-lastOnTime;
        if(timeDiff>5){
          Serial.write(5);
        }
        else if(timeDiff<5 && timeDiff>4){
          Serial.write(4);
        }
        else if(timeDiff<4 && timeDiff>3){
          Serial.write(3);
        }
        else if(timeDiff<3 && timeDiff>2){
          Serial.write(2);
        }
        else if(timeDiff<2 && timeDiff>1){
          Serial.write(1);
        }
        else if(timeDiff<1 && timeDiff>0){
          Serial.write(0);
        }        
      }
      else{
        ledState = HIGH;
      }
    }
  }
  digitalWrite(ledPin, ledState);
  lastButtonState = reading;
}

