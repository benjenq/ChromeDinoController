#ifndef BESENSOR_H
#define BESENSOR_H

#include "BeParameter.h"
#include "BeServo.h"

void BeSensor_Setup();
void BeSensor_Loop();

void BeSensor_Setup(){
    //pinMode(PIN_Resistance,INPUT); 
}

void BeSensor_Loop(){
    int Val;
    Val = analogRead(PIN_Resistance);
    //Serial.print("Val = ");
    //Serial.println(Val);

    if(Val >= resistance_PressVal){
        BeServo_StartPressProcess();
    }
}

#endif
