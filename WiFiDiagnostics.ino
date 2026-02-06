#include <WiFi.h>
#include "WiFiHelper.h"

void setup() {
    Serial.begin(115200);
    WiFi.begin("Your_SSID", "Your_PASS");
    while (WiFi.status() != WL_CONNECTED) delay(500);
}

void loop() {
    // One line of code to get all that data!
    Serial.println(WiFiHelper::getUltimateDataString());
    delay(10000);
}
