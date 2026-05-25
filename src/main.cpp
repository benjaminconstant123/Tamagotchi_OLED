#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Initialisation de l'écran (adresse I2C 0x3C par défaut)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);

  // Démarrage de l'écran à l'adresse 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Écran introuvable, vérifie le câblage !"));
    for(;;); // Boucle infinie, on arrête le programme
  }

  // Nettoyage du buffer mémoire
  display.clearDisplay();
  
  // Paramétrage du texte
  display.setTextSize(0.5); 
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(10, 20); // Position (X, Y)
  
  // Préparation du message
  display.println(F("Hello, Tamagotchi!"));
  
  // Envoi effectif de l'image à l'écran (obligatoire)
  display.display(); 
      
}

void loop() {
  // Rien à faire ici pour le moment
}