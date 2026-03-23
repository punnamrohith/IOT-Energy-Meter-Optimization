#include <WiFi.h>

const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

int sensorPin = 34;
float voltage = 0;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  voltage = sensorValue * (3.3 / 4095.0);

  Serial.print("Energy Value: ");
  Serial.println(voltage);

  if (voltage > 2.5) {
    Serial.println("⚠️ Threshold Exceeded!");
  }

  delay(2000);
}
