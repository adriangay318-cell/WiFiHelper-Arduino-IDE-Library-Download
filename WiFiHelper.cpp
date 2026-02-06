#include "WiFiHelper.h"

String WiFiHelper::getUptime() {
    unsigned long now = millis();
    int seconds = (now / 1000) % 60;
    int minutes = (now / (1000 * 60)) % 60;
    int hours = (now / (1000 * 60 * 60)) % 24;
    int days = (now / (1000 * 60 * 60 * 24));

    return String(seconds) + " secs, " + 
           String(minutes) + " mins, " + 
           String(hours) + " hours, and " + 
           String(days) + " days";
}

int WiFiHelper::findBars() {
    long r = WiFi.RSSI();
    if (r == 0 || r == -127) return 0;
    if (r > -55) return 4;
    if (r > -70) return 3;
    if (r > -80) return 2;
    if (r > -90) return 1;
    return 0;
}

String WiFiHelper::getEncryptionType() {
    String encType = "Unknown";
    wifi_ap_record_t info;
    if (esp_wifi_sta_get_ap_info(&info) == ESP_OK) {
        switch (info.authmode) {
            case WIFI_AUTH_OPEN:            encType = "Open"; break;
            case WIFI_AUTH_WEP:             encType = "WEP"; break;
            case WIFI_AUTH_WPA_PSK:         encType = "WPA"; break;
            case WIFI_AUTH_WPA2_PSK:        encType = "WPA2"; break;
            case WIFI_AUTH_WPA_WPA2_PSK:    encType = "WPA+WPA2"; break;
            case WIFI_AUTH_WPA3_PSK:        encType = "WPA3"; break;
            default:                        encType = "Protected"; break;
        }
    }
    return encType;
}

String WiFiHelper::getUltimateDataString() {
    if (WiFi.status() != WL_CONNECTED) {
        return "Status: Disconnected (Uptime: " + getUptime() + ")";
    }

    long rssi = WiFi.RSSI();
    int bars = findBars();
    String encType = getEncryptionType();

    String WiFiData = "--- ALL SYSTEM DATA ---\n";
    WiFiData += "Uptime: " + getUptime() + "\n";
    WiFiData += "Hostname: " + String(WiFi.getHostname()) + "\n";
    WiFiData += "SSID: " + String(WiFi.SSID()) + " (Ch: " + String(WiFi.channel()) + ")\n";
    WiFiData += "BSSID: " + WiFi.BSSIDstr() + "\n";
    WiFiData += "MAC: " + WiFi.macAddress() + "\n";
    WiFiData += "Encryption: " + encType + "\n";
    WiFiData += "Signal: " + String(rssi) + "dBm (" + String(bars) + " Bars)\n";
    WiFiData += "IP Address: " + WiFi.localIP().toString() + "\n";
    WiFiData += "Subnet Mask: " + WiFi.subnetMask().toString() + "\n";
    WiFiData += "Gateway IP: " + WiFi.gatewayIP().toString() + "\n";
    WiFiData += "DNS 1: " + WiFi.dnsIP(0).toString() + "\n";
    WiFiData += "DNS 2: " + WiFi.dnsIP(1).toString() + "\n";
    WiFiData += "Status: " + String(WiFi.status()) + " (3=Connected)\n";
    WiFiData += "-----------------------";
    
    return WiFiData;
}
