#include "MoistureBehavior.h"
#include "StringHelpers.h"

MoistureBehavior::MoistureBehavior(MoistureSensor moistureSensor)
  : Behavior(),
  _sensor(moistureSensor) {
}

void MoistureBehavior::setup() {
  _sensor.setup();
}

String MoistureBehavior::characteristics() {
  return "\"moisture\":" + quote(String(_sensor.moistureValue()))
    + ",\"level\":" + quote(_sensor.stringifiedMoistureLevel());
}
