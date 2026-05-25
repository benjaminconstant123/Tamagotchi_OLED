#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BTN_1 3
#define BTN_2 2

// Initialisation de l'écran (adresse I2C 0x3C par défaut)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(9600);
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);

  // Démarrage de l'écran à l'adresse 0x3C
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Écran introuvable, vérifie le câblage !"));
    for(;;); // Boucle infinie, on arrête le programme
  }

  // Nettoyage du buffer mémoire au démarrage
  display.clearDisplay();
  
  // Paramétrage du texte (Taille 1 est le minimum)
  display.setTextSize(1); 
  display.setTextColor(SSD1306_WHITE);
  
  // Envoi effectif de l'écran noir initial
  display.display(); 
}

void loop() {
  //On efface l'ancienne image
  display.clearDisplay();
  
  // On replace le curseur pour que le texte ne descende pas à l'infini
  display.setCursor(10, 20);

  // On lit le bouton et on prépare la nouvelle image
  if (digitalRead(BTN_1) == LOW) {
    delay(200); // Anti-rebond basique
    display.println("UwU");
  } else {
    delay(200); // Anti-rebond basique
    display.println("OwO");
  }

  if (digitalRead(BTN_2) == LOW) {
    delay(200); // Anti-rebond basique
    display.println("Tamagotchi");
  } else {
    delay(200); // Anti-rebond basique
    display.println("Benjamin");
  }
  
  //On demande à l'écran d'afficher physiquement le résultat
  display.display(); 
}