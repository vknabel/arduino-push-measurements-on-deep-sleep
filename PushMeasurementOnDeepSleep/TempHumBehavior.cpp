#include "TempHumBehavior.h"
#include "StringHelpers.h"

TempHumBehavior::TempHumBehavior(TempHumSensor tempHumSensor)
  : Behavior(),
  _sensor(tempHumSensor) {
}

void TempHumBehavior::setup() {
  _sensor.setup();
}

String TempHumBehavior::characteristics() {
  float temperature = 0.0;
  float humidity = 0.0;
  if (_sensor.read(&temperature, &humidity)) {
    return "\"temperature\":" + quote(String(temperature))
      + ",\"humidity\":" + quote(String(humidity));
  } else {
    return "\"error\":\"Reading from TempHumSensor failed\"";
  }
}
