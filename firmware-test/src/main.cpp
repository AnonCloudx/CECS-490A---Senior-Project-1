
#include <Arduino.h>
#include "event_classifier.h"

// Sensor configuration
#define MOISTURE_PIN 34

// Initial test threshold.
// Calibrate using actual sensor readings.
#define MOISTURE_THRESHOLD 2000

unsigned long lastReading = 0;

void setup()
{
    Serial.begin(115200);

    pinMode(MOISTURE_PIN, INPUT);

    Serial.println();
    Serial.println("================================");
    Serial.println("     CLEAN PAWS SMART SYSTEM");
    Serial.println("================================");

    Serial.println("ESP32 initialized.");
    Serial.println("Moisture monitoring started.");
}

void loop()
{
    if (millis() - lastReading >= 1000)
    {
        lastReading = millis();

        int moistureValue = analogRead(MOISTURE_PIN);

        PottyEvent event = classify_moisture(
            moistureValue,
            MOISTURE_THRESHOLD
        );

        Serial.print("Moisture Reading: ");
        Serial.println(moistureValue);

        if (event == EVENT_POTTY)
        {
            Serial.println("POTTY EVENT DETECTED");

            // Future:
            // 1. Check pet location.
            // 2. Log event.
            // 3. Send notification.
        }
        else
        {
            Serial.println("DRY");
        }

        Serial.println("----------------------------");
    }
}