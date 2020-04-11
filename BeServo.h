#ifndef BESERVO_H
#define BESERVO_H

#include <Servo.h>
#include <Ticker.h>
#include "BeParameter.h"

Ticker pressTicker;
Servo beservo;

void BeServo_Setup();
void BeServo_Loop();
void BeServo_StartPressProcess();

void BeServo_Press();
void BeServo_Release();

boolean inPressProcess = false;
unsigned long delayMs = 0;

void BeServo_Setup(){
    beservo.attach(PIN_BeServo);
    beservo.write(90);
}

void BeServo_Loop(){
  if(!inPressProcess){
    return;
  }
  delayMs ++;
  if(delayMs >= pressDelayMs){
    if(isServoPress){
        return;
    }
    BeServo_Press();
  }
}

void BeServo_StartPressProcess(){
  if(!inPressProcess){
    inPressProcess = true;
  }
}

void BeServo_Press(){
    Serial.print("Press");
    isServoPress = true;
    beservo.write(pressAngle);
    pressTicker.attach_ms(pressDurationMs,BeServo_Release);
}

void BeServo_Release(){
    pressTicker.detach();
    beservo.write(90);
    isServoPress = false;
    inPressProcess = false;
    delayMs = 0;
}

#endif
