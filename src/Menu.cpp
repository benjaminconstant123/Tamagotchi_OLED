#include "Menu.h"

Menu::Menu(Adafruit_SSD1306* displayPtr){
    this->display = displayPtr;
    
}

void Menu::initPixel() {
  // Initialisation du menu
  display->fillRect(0, 0, 128, 16, SSD1306_WHITE);
  display->setTextSize(1);
  display->setTextColor(SSD1306_BLACK);
  display->setCursor(4, 4);
  display->print("TAMAGOTCHI");
  display->display();
}