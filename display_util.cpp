#include "display_util.h"
#include <Zumo32U4.h>
#include "config.h"
using namespace Display;

#ifdef OLED
  Zumo32U4OLED display;
#else 
  Zumo32U4LCD display;
#endif


// Sets up special characters for the display so that we can show
// bar graphs.
void Display::loadCustomCharacters()
{
  static const char levels[] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 63, 63, 63, 63, 63, 63, 63
  };
  display.loadCustomCharacter(levels + 0, 0);  // 1 bar
  display.loadCustomCharacter(levels + 1, 1);  // 2 bars
  display.loadCustomCharacter(levels + 2, 2);  // 3 bars
  display.loadCustomCharacter(levels + 3, 3);  // 4 bars
  display.loadCustomCharacter(levels + 4, 4);  // 5 bars
  display.loadCustomCharacter(levels + 5, 5);  // 6 bars
  display.loadCustomCharacter(levels + 6, 6);  // 7 bars
}

void Display::printBar(uint8_t height)
{
  if (height > 8) { height = 8; }
  const char barChars[] = {' ', 0, 1, 2, 3, 4, 5, 6, (char)255};
  display.print(barChars[height]);
}

void Display::clearDisplay(){
  display.clear();
}

// Shows a bar graph of sensor readings on the display.
// Returns after the user presses A.
void Display::showReadings(unsigned int lineSensorValues[])
{
  display.clear();


    display.gotoXY(0, 0);
    for (uint8_t i = 0; i < NUM_SENSORS; i++)
    {
      uint8_t barHeight = map(lineSensorValues[i], 0, 1000, 0, 8);
      printBar(barHeight);
    }
}

void Display::calibrationMessage(){
  display.clear();
  display.print(F("Press A"));
  display.gotoXY(0, 1);
  display.print(F("to calib"));
}

void Display::displayGo(){
  display.clear();
  display.print(F("Go!"));
}