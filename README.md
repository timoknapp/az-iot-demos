# ☁️ 🏭 Azure IoT Demos

## 📒 ToDo's

- Testing Azure IoT Hub Device Provisioning Service (DPS)
- Testing Device Update for IoT Hub
- Testing [IoT Hub device streams](https://learn.microsoft.com/en-us/azure/iot-hub/iot-hub-device-streams-overview)

## 🎯 Features

- Receive temperature data every 30 seconds and push it Azure IoT Hub
- Make use of the Azure IoT Hub Device SDK (Azure SDK for embedded C)

## 🚀 Getting Started

### 📦 Prerequisites

- VS Code with PlatformIO extension
- ESP32 or ESP8266 board
- Temperature sensor (e.g. DHT22, TMP36, etc.)

### 📥 Installing

- Prepare your `src/secrets.h` file
  - Execute the following command in the directory of this project:
    - ```bash
      echo "#ifndef SECRETS_H
      #define SECRETS_H

      #define SECRET_WIFI_SSID \"yourSSID\"
      #define SECRET_WIFI_PASSWORD \"yourWifiPassword\"
      #define SECRET_IOTHUB_FQDN \"yourIoTHubFQDN\"
      #define SECRET_DEVICE_ID \"yourDeviceID\"
      #define SECRET_DEVICE_KEY \"yourDeviceKey\"

      #endif /* SECRETS_H */" > src/secrets.h
      ```
  - Replace all placeholder values (e.g.`yourSSID` and `yourWiFiPassword`) with your data.
