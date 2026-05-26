#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Menu.h"

#define BTN_1 3
#define BTN_2 2

Adafruit_SSD1306 mainDisplay(128, 64, &Wire, -1);
Menu monMenu(&mainDisplay);

int etatMenu = 0;
bool lastStateBtn1 = HIGH; 
bool lastStateBtn2 = HIGH;

void setup() {
  Serial.begin(9600);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);

  Serial.println("test-serial");

  mainDisplay.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  mainDisplay.clearDisplay();

  monMenu.yellowSquare();
  delay(1000);
  monMenu.showMenu();
}

void loop() {
  bool currentStateBtn1 = digitalRead(BTN_1);
  bool currentStateBtn2 = digitalRead(BTN_2);

  if (lastStateBtn1 == HIGH && currentStateBtn1 == LOW) {
    etatMenu = (etatMenu + 1) % 5; // Cycle through 0 to 4
    monMenu.setOption(etatMenu);
    monMenu.draw();
    delay(200); // Debounce delay
  }
  
}