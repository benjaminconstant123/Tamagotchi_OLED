#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class Menu {
  private:
    int currentOption;
    unsigned long lastUpdate;
    Adafruit_SSD1306* display;

  public:
    Menu(Adafruit_SSD1306* displayPtr); // Constructor
    void yellowSquare();
};

#endif