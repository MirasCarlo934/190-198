#include <Arduino.h>

//Libraries for OLED Display
#include <Wire.h>
#include <Adafruit_BusIO_Register.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

//OLED pins
#define OLED_SDA 21
#define OLED_SCL 22 
#define OLED_RST 16
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

//Screen
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RST);

void displayText(char* text, int textSize, int rotation) {
    display.setTextSize(textSize);
    display.setRotation(rotation);
    display.print(text);
    display.display();
}

void setup() {
    //initialize OLED
    Wire.begin(OLED_SDA, OLED_SCL);
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3c, false, false)) { // Address 0x3C for 128x32
        Serial.println(F("SSD1306 allocation failed"));
        for(;;); // Don't proceed, loop forever
    }
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(0,0);

    // displayText("KAMI", 5, 0);

    // display.setTextSize(4);
    // display.setRotation(2);
    // displayText("NAGPA", 4, 2);

    // displayText("GRAD", 5, 0);

    // display.setTextSize(6);
    // displayText("KAY", 6, 0);

    displayText("CARLO", 4, 2);
}

void loop() {

}