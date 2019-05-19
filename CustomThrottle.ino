// Program used to test the USB Joystick object on the 
// Arduino Leonardo or Arduino Micro.
//
// Matthew Heironimus
// 2015-03-28
// Updated on 2015-11-18 to use the new Joystick library written for version 1.6.6.
//------------------------------------------------------------

#include "Joystick.h"

// Set to true to test "Auto Send" mode or false to test "Manual Send" mode.
//const bool testAutoSendMode = true;
const bool testAutoSendMode = false;

const unsigned long gcCycleDelta = 1000;
const unsigned long gcAnalogDelta = 25;
const unsigned long gcButtonDelta = 500;
unsigned long gNextTime = 0;
unsigned int gCurrentStep = 0;


void setup() {
  // Initialize Button Pins
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(16, INPUT_PULLUP);
  Joystick.begin();
  
  Joystick.begin(false);
  
}

const int pinToButtonMap = 2;

// Last state of the button
int lastButtonState[8] = {0,0,0,0,0,0,0,0};
int lb16 = 0;


void loop() {
  // Throttle set
  int sum = 0;
  for (int i = 0; i < 20; i++){
    sum += analogRead(A0);
    delay(1);
  }
  int input = sum/20;
  int output = map(input, 0, 195, 0, 255);
  
  Joystick.setThrottle(output);
  Joystick.sendState();

  //X and Y axis set
  int sumX = 0;
  int sumY = 0;
  for (int i = 0; i < 20; i++){
    sumX += analogRead(A1);
    sumY += analogRead(A2);
  }
  int inX = sumX/20;
  int inY = sumY/20;
  int outX = map(inX, 0, 1023, 128, -127);
  int outY = map(inY, 0, 1023, -127, 128);
  Joystick.setXAxis(outY);
  Joystick.setYAxis(outX);
  Joystick.sendState();

  // Read pin values
  for (int index = 0; index < 8; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
  int cb16 = !digitalRead(16);
  if (cb16 != lb16){
    Joystick.setButton(16, cb16);
    lb16 = cb16;
  }


  
}

