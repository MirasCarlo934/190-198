#include <Arduino.h>
#include "DHT.h"

#define DHT_PIN 33
#define DHT_TYPE 22

#define DHT_CYCLE 3000

DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
    Serial.begin(115200);
    Serial.println("DHT22 and MQ7 test");

    dht.begin();
}

void loop() {

    Serial.println("");

    delay(DHT_CYCLE);

    float h = dht.readHumidity();       
    float t = dht.readTemperature();    // celsius

    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.printf("Humidity: %f\n", h);
    Serial.printf("Temp: %f\n", t);
    Serial.printf("Heat Index: %f\n", hic);
    Serial.printf("Next reading in %u\n", DHT_CYCLE);

}