#ifndef WIFI_HELPER_H
#define WIFI_HELPER_H

#include <Arduino.h>
#include <WiFi.h>
#include <esp_wifi.h>

class WiFiHelper {
public:
    static int findBars();
    static String getUptime();
    static String getUltimateDataString();

private:
    static String getEncryptionType();
};

#endif
