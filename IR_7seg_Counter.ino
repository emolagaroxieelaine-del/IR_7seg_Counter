/*===============================================================================
                             IR_7SEGMENT_COUNTER
=================================================================================
Description:
  This is IR 7Segment counter with a two-digit display. 
  It counts one object each time the IR sensor on GPIO34 changes from LOW to HIGH,
  wraps back to 0 after 99, and shows the count on two 7-segment displays
  while also printing it to the Serial Monitor.

Programmer: 
  Roxie Elaine Emolaga

Date:
  16 Oct 2026

===========================================================================*/

#include "decoder.h"
const int OUT = 34; 

int Number_of_Objects = 0;
int lastSensorState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(OUT, INPUT);
  setupDecoder();
  
  
  lastSensorState = digitalRead(OUT); 
}

void loop() {
  int sensorState = digitalRead(OUT); 
  if (sensorState == HIGH && lastSensorState == LOW) {  
    Number_of_Objects++;
    
    if (Number_of_Objects > 99) {
      Number_of_Objects = 0;      // if it reaches 100, matic back to zero
    }
    
    Serial.print("Object Count: ");
    Serial.println(Number_of_Objects);
  }
  
  lastSensorState = sensorState;
  displayTwoDigits(Number_of_Objects); 
  delay(50); 
}