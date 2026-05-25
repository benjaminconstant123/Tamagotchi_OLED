#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Menu.h"

#define BTN_1 3
#define BTN_2 2

Adafruit_SSD1306 mainDisplay(128, 64, &Wire, -1);

Menu monMenu(&mainDisplay);

void setup() {
  Serial.begin(9600);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);

  Serial.println("test-serial");

  mainDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  mainDisplay.clearDisplay();
  monMenu.initPixel();
}

void loop() {
 
}