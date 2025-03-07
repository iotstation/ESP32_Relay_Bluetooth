#include "BluetoothSerial.h"

BluetoothSerial SerialBT; 

#define RELAY_PIN 5 

void setup() {
    Serial.begin(115200);
    SerialBT.begin("ESP32_Relay");  
    pinMode(RELAY_PIN, OUTPUT); 
    digitalWrite(RELAY_PIN, LOW); // Start with relay off
    Serial.println("Bluetooth Started! Waiting for connections...");
}

void loop() {
    if (SerialBT.available()) { // Check if data is received
        String command = SerialBT.readStringUntil('\n'); // read a string of characters from the Bluetooth serial connection
        command.trim(); // Remove spaces and newlines
        Serial.println("Received: " + command);

        if (command == "ON") {
            digitalWrite(RELAY_PIN, HIGH); // Turn relay ON
            SerialBT.println("Relay is ON");
            Serial.println("Relay turned ON");
        } 
        else if (command == "OFF") {
            digitalWrite(RELAY_PIN, LOW); // Turn relay OFF
            SerialBT.println("Relay is OFF");
            Serial.println("Relay turned OFF");
        } 
        else {
            SerialBT.println("Invalid Command. Send 'ON' or 'OFF'");
        }
    }
    delay(100);
}


//esp32 by Espressif Systems