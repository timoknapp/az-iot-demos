# ☁️ 🏭 Azure IoT Demos

## 📒 ToDo's

- Receive temperature data every 30 seconds and push it Azure IoT Hub
- Make use of the Azure IoT Hub Device SDK (Azure SDK for embedded C)
- Testing Azure IoT Hub Device Provisioning Service (DPS)
- Testing Device Update for IoT Hub
- Testing [IoT Hub device streams](https://learn.microsoft.com/en-us/azure/iot-hub/iot-hub-device-streams-overview)

## 🚀 Getting Started

### Prerequisites

- VS Code with PlatformIO extension
- ESP32 or ESP8266 board
- Temperature sensor (e.g. DHT22, TMP36, etc.)

### Installing

- Prepare your `src/secrets.h` file
  - Execute the following command in the directory of this project:
    - `echo "#define SECRET_WIFI_SSID \"yourSSID\"\n#define SECRET_WIFI_PASSWORD \"yourWiFiPassword\"" > src/secrets.h`
  - Replace `yourSSID` and `yourWiFiPassword` with your WiFi credentials.
