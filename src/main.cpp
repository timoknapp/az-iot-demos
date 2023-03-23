#include <Arduino.h>

const int tempPin = 34; // the analog pin the TMP36's Vout (sense) pin is connected to
int tempVal = 0;        // variable to store the value coming from the sensor
float volts = 0.0;      // variable to store the voltage coming from the sensor
float temp = 0.0;       // variable to store the temperature in celsius

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the temp sensor and store it in tempVal
  tempVal = analogRead(tempPin);
  // normalize by the maximum temperature raw reading range
  volts = tempVal/1024.0;             
  // calculate temperature celsius from voltage as per the equation found on the sensor spec sheet.
  temp = (volts - 0.5) * 100;         
  Serial.println("Current time: " + String(__DATE__) + " " + String(__TIME__) + ", Temperature is: " + String(temp) + " degrees C°");
  // wait for 30 seconds or 30000 milliseconds before taking the next reading.
  delay(30000);    
  // delay(30000);                  
}
