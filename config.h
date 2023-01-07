#ifndef CONFIG_H
#define CONFIG_H
// This section defines device characteristics

// Change next line to this if you are using the older Zumo 32U4
// with a black and green LCD display:
//#define OLED

// Uncomment if necessary to correct motor directions:
//#define FLIPMOTORS

#define NUM_SENSORS 5


// Define constants specific to the robot
namespace robotConstants {
  // This is the maximum speed the motors will be allowed to turn.
  // A maxSpeed of 400 lets the motors go at top speed.  Decrease
  // this value to impose a speed limit.
  constexpr uint16_t maxSpeed = 400;
  constexpr float k_p = 0.4;
  constexpr float k_d = 8.5;
  constexpr bool useFastTurn = true;
  constexpr int16_t fastTurnMin = -200;
}

#endif
