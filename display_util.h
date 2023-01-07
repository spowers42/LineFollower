#pragma once
#include <Arduino.h>
namespace Display{
  void loadCustomCharacters();

  void printBar(uint8_t height);

  void clearDisplay();

  void showReadings(unsigned int lineSensorValues[]);

  void calibrationMessage();

  void displayGo();
}