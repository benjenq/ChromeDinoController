#ifndef BEPARAMETER_H
#define BEPARAMETER_H

#define PIN_BeServo D0 //for NodeMCU or Wemos D1 mini
#define PIN_Resistance A0 //for NodeMCU or Wemos D1 mini

int resistance_PressVal = 470; //0-1024, must be adjust for your own case.

boolean isServoPress = false;
unsigned long pressDurationMs = 170; //Trigger servo duration
unsigned long pressDelayMs = 80; //Trigger servo delay

int pressAngle = 65; //Servo angle to press space-key 


#endif
