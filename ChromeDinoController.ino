/** Google 
 * Parts:
 *   A photoresistance module
 *   A Servo
 * 
 * */

#include "BeParameter.h"
#include "BeServo.h"
#include "BeSensor.h"

void setup() {
  //Serial.begin(115200);
  BeSensor_Setup(); 
  BeServo_Setup();
}

void loop() {
  BeSensor_Loop();
  BeServo_Loop();
}
