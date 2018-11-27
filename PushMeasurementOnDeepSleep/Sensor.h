#ifndef Sensor_H
#define Sensor_H

#include <Arduino.h>

class Sensor
{
private:
  uint8_t _pin;

protected:
  Sensor(const uint8_t forPin);
  uint8_t pin() const;

public:
  void setup();
};

#endif
