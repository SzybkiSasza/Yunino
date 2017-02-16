#ifndef LIGHT_SWITCHER
#define LIGHT_SWITCHER

#include "constants.h"

/**
 * 
 * Simple logic for switching between different light states
 * 
 */

// Base pinning for the first traffic lights
const int GREEN_PIN = 1;
const int YELLOW_PIN = 2;
const int RED_PIN = 3;

/**
   Sets the proper traffic light state.
   Refer to enum in Constants for details
   @param state State determining how to switch pins
   @param number Traffic light number
*/
void setColors(lightStates state, int number);

#endif
