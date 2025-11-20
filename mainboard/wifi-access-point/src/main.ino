#include <WiFi.h>

void setup() {
    Serial.begin(115200);

    // Start the Access Point with a default SSID and password
    WiFi.softAP("ESP32_AP", "12345678");

    Serial.println("Access Point Started");
    Serial.print("IP Address: ");
    Serial.println(WiFi.softAPIP());
}

void loop() {}
