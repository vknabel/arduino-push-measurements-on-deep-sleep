#include "DeepSleep.h"
#include <Arduino.h>

#if PLATFORM == PLATFORM_ESP32
//#include "esp_deep_sleep.h"
#endif

void deepSleepForMinutes(int minutesToSleep) {
  Serial.println((String)"Entering deep sleep mode for " + minutesToSleep + " minutes");
  //#if PLATFORM == PLATFORM_ESP32
  //esp_deep_sleep_enable_timer_wakeup(minutesToSleep * 60 * 1000000);
  //esp_deep_sleep_start();
  //#elif PLATFORM == PLATFORM_ESP8266
  ESP.deepSleep(minutesToSleep * 60 * 1000000);
  delay(100);
  //#elif
  //delay(minutesToSleep * 60 * 1000);
  //#endif
}
