# Arduino Push Measurements on Deep Sleep

This repository includes some Arduino-based projects I use at home. Everything is built for local use only and is unencrypted and quite limited, but simple and works for my use-cases.
The [home-logger](./home-logger) is a small ruby server which stores all data in Sqlite. Use PushMeasurementOnDeepSleep for your client code and fetch all data using homebridge-http-temperature-humidity from your home-logger.

1. Clone this repo: `git clone https://github.com/vknabel/arduino-push-measurements-on-deep-sleep && cd arduino-push-measurements-on-deep-sleep`
2. Copy `PushMeasurementOnDeepSleep/CurrentBoardInformation.default.h` to `PushMeasurementOnDeepSleep/CurrentBoardInformation.h` and fill in your board's information.
3. Open `PushMeasurementOnDeepSleep/PushMeasurementOnDeepSleep.ino` inside your Arduino IDE.
4. Install SimpleDHT 1.0.12
5. Deploy on your Arduino.
6. Used in conjunction with homebridge, [home-logger](./home-logger) and [homebridge-http-temperature-humidity](https://github.com/vknabel/homebridge-http-temperature-humidity).

# License

This project is available under the [MIT](./LICENSE) license
