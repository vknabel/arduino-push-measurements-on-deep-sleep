#ifndef TempHumSensor_H
#define TempHumSensor_H

#include <Arduino.h>
#include <SimpleDHT.h>
#include "Sensor.h"

class TempHumSensor : public Sensor
{
private:
  SimpleDHT22 dht;
  uint8_t pin;

public:
  TempHumSensor(const uint8_t forPin);
  void setup();
  bool read(float *temperature, float *humidity);
};

#endif // TempHumSensor_H
