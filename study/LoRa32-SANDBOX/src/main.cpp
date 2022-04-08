#include <Arduino.h>
#include "MQ7.h"

#define RELAY_PIN 25
#define DATA_PIN 34
#define MQ7_VCC 5.0

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

MQ7 mq7(DATA_PIN, MQ7_VCC);

void setup() {
    Serial.begin(115200);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(DATA_PIN, INPUT);
}

void loop() {
    // Serial.println("HIGH");
    // digitalWrite(RELAY_PIN, HIGH);
    // delay(5000);
    // Serial.println("LOW");
    // digitalWrite(RELAY_PIN, LOW);
    // delay(5000);
    float co = 0;

    Serial.print("HEATING");
    digitalWrite(RELAY_PIN, HIGH);
    for (int i = 0; i < 60; ++i) {
        Serial.print(".");
        delay(1000);
    }

    Serial.printf("\nREADING");
    digitalWrite(RELAY_PIN, LOW);
    for (int i = 0; i < 90; ++i) {
        Serial.print(".");
        float co_ppm = mq7.getPPM();
        if (!isnan(co_ppm)) {
            co += co_ppm;
        }
        // Serial.println(co_ppm);
        delay(1000);
    }
    Serial.printf("\nAVERAGE CO: %f\n\n", co/90);
}