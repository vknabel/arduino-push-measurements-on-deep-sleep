#include "CurrentBoardInformation.h"

#include <ESP8266WiFi.h>
#include "DeepSleep.h"
#if INCLUDE_MOISTURE_CHARACTERISTICS
#include "MoistureBehavior.h"
#endif
#if INCLUDE_TEMPHUM_CHARACTERISTICS
#include "TempHumBehavior.h"
#endif

#if INCLUDE_TEMPHUM_CHARACTERISTICS
TempHumBehavior tempHum = TempHumBehavior(TempHumSensor(PIN_DHT22));
#endif
#if INCLUDE_MOISTURE_CHARACTERISTICS
MoistureBehavior moisture = MoistureBehavior(MoistureSensor(PIN_SOIL, 2500, 1300));
#endif

void setup()
{
  // WiFi.hostname(EVOLUTION_NAME);

  // put your setup code here, to run once:
  Serial.begin(BAUD_RATE);
#if INCLUDE_MOISTURE_CHARACTERISTICS
  //moisture.setup();
#endif
#if INCLUDE_TEMPHUM_CHARACTERISTICS
  tempHum.setup();
#endif

  //pinMode(ledPin, OUTPUT);
  //pinMode(pirPin, INPUT);

  //digitalWrite(ledPin, LOW);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  // put your setup code here, to run once:
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

  // Print the IP address
  Serial.print("Running ");
  Serial.print(EVOLUTION_NAME);
  Serial.print(" on ");
  Serial.println(WiFi.localIP());

  // put your main code here, to run repeatedly:
  // Check if a client has connected
  WiFiClient client;
  Serial.println("Trying to connect");
  if (client.connect(PUSH_IP, PUSH_PORT))
  {
    Serial.println("Connected");
    String postData = (String) "{" +
#if INCLUDE_TEMPHUM_CHARACTERISTICS
                      tempHum.characteristics()
#endif
#if INCLUDE_MOISTURE_CHARACTERISTICS
                      + "," + moisture.characteristics()
#endif
                      + "}";
    Serial.println(postData);
    client.println((String) "POST " + PUSH_PATH + " HTTP/1.1");
    client.println("Host: test.com");
    client.println("Cache-Control: no-cache");
    client.println("Content-Type: application/json");
    client.print("Content-Length: ");
    client.println(postData.length());
    client.println();
    client.print(postData);
  }
  else
  {
    Serial.println("Could not connect");
    Serial.println(PUSH_URL);
  }

  long interval = 2000;
  unsigned long currentMillis = millis(), previousMillis = millis();

  while (!client.available())
  {
    if ((currentMillis - previousMillis) > interval)
    {
      client.stop();
    }
    currentMillis = millis();
  }

  while (client.connected())
  {
    if (client.available())
    {
      client.read();
    }
  }

  deepSleepForMinutes(EVOLUTION_SLEEP);
}

void loop()
{
  deepSleepForMinutes(EVOLUTION_SLEEP);
}
