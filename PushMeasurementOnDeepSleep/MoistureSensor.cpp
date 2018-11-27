#include "MoistureSensor.h"

MoistureSensor::MoistureSensor(const uint8_t forPin, int air, int water) : Sensor(forPin) {
  pin = forPin;
  airThreshold = air;
  waterThreshold = water;
}

void MoistureSensor::setup() {
  if (airThreshold <= waterThreshold) {
    Serial.println("[MoistureSensor] Air level may not be smaller than water.");
    Serial.print(airThreshold);
    Serial.print(" <= ");
    Serial.println(waterThreshold);
  }
}

int MoistureSensor::moistureValue() {
  return analogRead(pin);
}

MoistureLevel MoistureSensor::moistureLevel() {
  const int value = moistureValue();
  const int interval = (airThreshold - waterThreshold)/3;
  if (value >= airThreshold) {
    return MoistureLevel::air;
  } else if (value >= airThreshold - interval) {
    return MoistureLevel::dry;
  } else if (value >= airThreshold - interval * 2) {
    return MoistureLevel::wet;
  } else {
    return MoistureLevel::water;
  }
}


String MoistureSensor::stringifiedMoistureLevel() {
  switch (moistureLevel()) {
  case MoistureLevel::air:
    return "air";
  case MoistureLevel::dry:
    return "dry";
  case MoistureLevel::wet:
    return "wet";
  case MoistureLevel::water:
    return "water";
  default:
    return "unknwon";
  }
}
