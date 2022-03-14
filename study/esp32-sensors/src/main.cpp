#include <Arduino.h>
#include "DHT.h"
#include "MQ7.h"

#define DHT_PIN 33
#define DHT_TYPE 22

#define MQ7_PIN 32
#define MQ7_VCC 5.0

#define SENSOR_CYCLE 3000

DHT dht(DHT_PIN, DHT_TYPE);
MQ7 mq7(MQ7_PIN, MQ7_VCC);

void setup() {
    Serial.begin(115200);
    Serial.println("DHT22 and MQ7 test");

    dht.begin();
}

void loop() {

    Serial.println("");

    delay(SENSOR_CYCLE);

    float co = mq7.getPPM();
    float h = dht.readHumidity();       
    float t = dht.readTemperature();    // celsius

    if (isnan(h) || isnan(t)) {
        Serial.println("Failed to read from DHT sensor!");
        return;
    }

    // Compute heat index in Celsius (isFahreheit = false)
    float hic = dht.computeHeatIndex(t, h, false);

    Serial.printf("CO: %f\n", co);
    Serial.printf("Humidity: %f\n", h);
    Serial.printf("Temp: %f\n", t);
    Serial.printf("Heat Index: %f\n", hic);
    Serial.printf("Next reading in %u\n", SENSOR_CYCLE);

}