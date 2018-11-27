#include<Arduino.h>
#include "Sensor.h"

Sensor::Sensor(const uint8_t forPin) {
  _pin = forPin;
}

uint8_t Sensor::pin() const {
  return _pin;
}

void Sensor::setup() {}
