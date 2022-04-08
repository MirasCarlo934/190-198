#include <Arduino.h>

#define RELAY_PIN 25
#define DATA_PIN 34

const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;

void setup() {
    Serial.begin(115200);

    pinMode(RELAY_PIN, OUTPUT);
    pinMode(DATA_PIN, INPUT);
}

void loop() {
    Serial.println("HIGH");
    digitalWrite(RELAY_PIN, HIGH);
    delay(5000);
    Serial.println("LOW");
    digitalWrite(RELAY_PIN, LOW);
    delay(5000);

    // Serial.print("HEATING");
    // digitalWrite(RELAY_PIN, HIGH);
    // for (int i = 0; i < 60; ++i) {
    //     Serial.print(".");
    //     delay(1000);
    // }

    // Serial.println("\nREADING");
    // digitalWrite(RELAY_PIN, LOW);
    // for (int i = 0; i < 90; ++i) {
    //     Serial.println(analogRead(DATA_PIN));
    //     delay(1000);
    // }
}