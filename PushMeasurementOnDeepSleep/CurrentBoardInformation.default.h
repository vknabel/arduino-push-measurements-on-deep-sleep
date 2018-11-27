#define PLATFORM_ARDUINO "Arduino"
#define PLATFORM_ESP32 "ESP32"
#define PLATFORM_ESP8266 "ESP8266"

#define PLATFORM PLATFORM_ESP8266

#define stringify_1(x...) #x
#define stringify(x...) stringify_1(x)

#define EVOLUTION_NAME "whereyouuseit"
#define EVOLUTION_SLEEP 10

#define PUSH_IP "192.168.0.2"
#define PUSH_PORT 8000

#define WIFI_SSID "Your Wi-Fi"
#define WIFI_PASSWORD "passwords123upersafe"

#define BAUD_RATE 115200

#define PIN_LED LED_BUILTIN
#define PIN_DHT22 2
#define PIN_SOIL 0

#define PUSH_PATH "/accessory/" EVOLUTION_NAME
#define PUSH_URL "http://" PUSH_IP ":" stringify(PUSH_PORT) PUSH_PATH

#define INCLUDE_TEMPHUM_CHARACTERISTICS true
#define INCLUDE_MOISTURE_CHARACTERISTICS false
