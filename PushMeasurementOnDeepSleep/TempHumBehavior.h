#ifndef TempHumBehavior_H
#define TempHumBehavior_H

#include<Arduino.h>
#include "Behavior.h"
#include "TempHumSensor.h"

class TempHumBehavior: public Behavior {
private:
  TempHumSensor _sensor;
public:
  void setup();
  TempHumBehavior(TempHumSensor tempHumSensor);
  String characteristics();
};

#endif // TempHumBehavior_H
