# WiFiHelper-Arduino-IDE-Library-Download


# WiFiHelper 📶
A lightweight Arduino library to simplify WiFi monitoring and network scanning.
WiFiHelper is a wrapper for the standard WiFi library that provides easy-to-use functions for visualizing signal strength, debugging connection errors, and scanning nearby networks.

# ✨ Features
1. Signal bars: Convert raw RSSI values into a human-readable scale (0–4 bars).
2. Error Reporting: Descriptive error messages for failed connections.
3. Network Scanner: Can easily scan for nearby access points.
4. Network Data Scanner: Can scan for all data on the connect network.
5. Lightweight: Minimal overhead, built directly on top of the native WiFi library.

# 🛠 Project Status
Current Version: 0.0.1
Status: Initial Release (Alpha) 

# 🤝 Contributing
Ideas and bug reports are welcome! If you find an issue or have a suggestion we really want that.

# 📜 License
This project is licensed under the MIT License.

# Example Code

#include <WiFi.h>
#include <WiFiHelper.h>

void setup() {
  Serial.begin(115200);
  WiFi.begin("Your_SSID", "Your_Password");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
}

void loop() {
  // Get the full diagnostic report
  Serial.println(WiFiHelper::getUltimateDataString());
  
  delay(10000); // Update every 10 seconds
}
