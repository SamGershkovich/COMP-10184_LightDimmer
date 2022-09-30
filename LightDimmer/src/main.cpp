/*
 I, Sam Gershkovich, student number 000801766, certify that this material is my original work.
 No other person's work has been used without due acknowledgment and neither have I made my work available to anyone else.
*/

#include <Arduino.h> 
 
void setup() { 
  // configure the USB serial monitor 
  Serial.begin(115200); 
 
  // configure pin D4 as a digital output - this is the LED 
  pinMode(D4, OUTPUT); 
 
  // set default PWM range 
  analogWriteRange(1023); 
 
  // configure pin D5 as digital input - this is the pushbutton 
  pinMode(D5, INPUT_PULLUP); 
 
} 
 
 bool lightOn = false;
 bool buttonReleased = true;
 int brightness = 0;
 
void loop() { 

  if(digitalRead(D5) > 0){
    if( buttonReleased){
      lightOn = !lightOn;
      buttonReleased = false;
    }
  }
  else if(digitalRead(D5) == 0){
    buttonReleased = true;
  }

  brightness = analogRead(A0);

  if(lightOn)
    analogWrite(D4, brightness); 
  else
    digitalWrite(D4, HIGH);

  delay(1);
} 