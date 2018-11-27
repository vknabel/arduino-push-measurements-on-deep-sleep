#include "TempHumSensor.h"

TempHumSensor::TempHumSensor(const uint8_t forPin) : Sensor(forPin) {
  pin = forPin;
}

void TempHumSensor::setup() {
  delay(2500);
}

bool TempHumSensor::read(float *temperature, float *humidity) {
  Serial.println("Reading");
  int err = SimpleDHTErrSuccess;
  if ((err = dht.read2(pin, temperature, humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.println((String)"Read DHT22 failed with error " + (int)err + " on pin " + pin);
    return false;
  }
  return true;
}
