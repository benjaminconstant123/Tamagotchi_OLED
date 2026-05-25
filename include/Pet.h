#ifndef PET_H
#define PET_H

#include <Arduino.h>

class Pet {
  private:
    int hunger;
    int happiness;
    unsigned long lastUpdate;

  public:
    Pet(); // Constructor
    
    void update(unsigned long currentTime);
    void feed();
    void play();
    
    int getHunger();
    int getHappiness();
    bool isAlive();
};

#endif