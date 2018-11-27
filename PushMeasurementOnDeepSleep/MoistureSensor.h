#ifndef MoistureSensor_H
#define MoistureSensor_H

#include<Arduino.h>
#include "Sensor.h"

enum MoistureLevel {
  air, dry, wet, water
};

class MoistureSensor: public Sensor {
private:
  uint8_t pin;
  int airThreshold;
  int waterThreshold;
public:
  MoistureSensor(const uint8_t forPin, int air = 520, int water = 260);
  void setup();
  int moistureValue();
  MoistureLevel moistureLevel();
  String stringifiedMoistureLevel();
private:
  void validateConfig();
};

#endif // MoistureSensor_H
