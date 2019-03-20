#include <arduino.h>
int switchPin=8;
int ledPin=13;
boolean lastButton=false;
boolean currentButton=false;
int ledLevel=0;
//changing the brightness of the led
void setup() {
  // initaliaze pins as outputs
  pinMode(ledPin,OUTPUT);
  pinMode(switchPin,INPUT);

}
boolean debouce(boolean last){
  boolean current=digitalRead(switchPin);
  if(last!=current){
    delay(5);
    current=digitalRead(switchPin);
    }
    return current;
}

void loop() {
currentButton=debouce(lastButton);
  if (currentButton==HIGH  && lastButton==false){
    ledLevel = ledLevel+51;
  }
      lastButton==currentButton;
      if(ledLevel>255) ledLevel=0;
  analogWrite(ledPin,ledLevel);
}
