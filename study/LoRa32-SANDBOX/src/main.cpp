#include <Arduino.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//Libraries for LoRa
#include <SPI.h>
#include <LoRa.h>

//define the pins used by the LoRa transceiver module
#define SCK 5
#define MISO 19
#define MOSI 27
#define SS 18
// #define RST 14
#define RST 23
#define DIO0 26

//433E6 for Asia
//866E6 for Europe
//915E6 for North America
#define BAND 433E6

void onReceive(int packetSize) {
    if (packetSize) {
        Serial.printf("Packet received.");
        for (int i = 0; LoRa.available(); ++i) {
            if (i%4 == 0) {
                Serial.println();
            }
            Serial.printf("%i ", LoRa.read());
        }
        Serial.println();
    }
}

void setup() {
    Serial.begin(115200);

    //SPI LoRa pins
    SPI.begin(SCK, MISO, MOSI, SS);
    //setup LoRa transceiver module
    LoRa.setPins(SS, RST, DIO0);

    if (!LoRa.begin(BAND)) {
        Serial.println("Starting LoRa failed!");
        while (1);
    }
    LoRa.onReceive(onReceive);
    LoRa.receive();

    Serial.println("Setup done.");
}

void loop() {
    Serial.println(millis());
    // int packetSize = LoRa.parsePacket();
    // if (packetSize) {
    //     Serial.printf("Packet received.");
    //     for (int i = 0; LoRa.available(); ++i) {
    //         if (i%4 == 0) {
    //             Serial.println();
    //         }
    //         Serial.printf("%i ", LoRa.read());
    //     }
    //     Serial.println();
    // }
}