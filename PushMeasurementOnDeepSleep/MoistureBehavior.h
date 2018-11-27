#ifndef MoistureBehavior_H
#define MoistureBehavior_H

#include<Arduino.h>
#include "Behavior.h"
#include "MoistureSensor.h"

class MoistureBehavior: public Behavior {
private:
  MoistureSensor _sensor;
public:
  void setup();
  MoistureBehavior(MoistureSensor moistureSensor);
  String characteristics();
};

#endif // MoistureBehavior_H
