#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <ESP32Ping.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include "secrets.h"

#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
#define DHTPIN 4        // DHT 22 digital pin

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

const char* host = "timoknapp.com";

static void pingHost(const char* host) {
  Serial.println("Pinging host " + String(host) + "...");

  if(Ping.ping(host)) {
    Serial.println("Success");
  } else {
    Serial.println("Error");
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  dht.begin();

  Serial.println();
  Serial.print("Connecting to WiFi");

  WiFi.begin(SECRET_WIFI_SSID, SECRET_WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    // Serial.print(String(WiFi.status()));
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected to WiFi with IP: ");
  Serial.println(WiFi.localIP());

  pingHost(host);
}

void loop() {
  // put your main code here, to run repeatedly:

  // DHT22 sensor
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(String(__TIMESTAMP__)+" - ");
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%, Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print("("+String(f));
  Serial.print(F("°F), Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print("("+String(hif));
  Serial.println(F("°F)"));

  // wait for 30 seconds or 30000 milliseconds before taking the next reading.
  delay(30000);
}
