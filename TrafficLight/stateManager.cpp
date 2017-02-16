#include <Bridge.h>
#include "constants.h"
#include "stateManager.h"
#include "lightSwitcher.h"

// Cumulated times - to determine the next change for each light
int cumulatedTimes[TRAFFIC_LIGHTS_NO] = {0};

// This array keeps the states of the lights in any time. States come from 
lightStates trafficStates[TRAFFIC_LIGHTS_NO] = {};

int createInitialStates() {
  // First light always starts with GREEN...
  trafficStates[0] = GREEN;

  // Set all needed pin modes to OUTPUT!!!
  for (int i=0; i<TRAFFIC_LIGHTS_NO; i++) {
    for ( int j=1; j<=3; j++) {
      pinMode((i * SHIFT) + j, OUTPUT);
    }
  }

  // Calculate cumulated times for each lights
  for (int i = 1; i < TRAFFIC_LIGHTS_NO; i++) {
    // All other lights start with RED...
    trafficStates[i] = RED;
    cumulatedTimes[i] = (cumulatedTimes[i - 1] + LANE_TIMES[i - 1]);
  }

  // Calculate total cycle length = all the GREEN times.
  int cycleLength = cumulatedTimes[TRAFFIC_LIGHTS_NO - 1] + LANE_TIMES[TRAFFIC_LIGHTS_NO - 1];
  return cycleLength;
}

/**
   Checks the states and updates if needed
*/
void checkStates(int timer) {
  for (int i = 0; i < TRAFFIC_LIGHTS_NO; i++) {
//    const int currentState = trafficStates[i];
//    const int cumulatedTime = cumulatedTimes[i];
//    const int roadTime = LANE_TIMES[i];
//
//    const int cycleTimer = timer % cycleLength;
//
//    String phrase = "Switching to: ";
//
//    if ((currentState == 2 && cycleTimer >= (cumulatedTime - CHANGE_PRETIME) && cycleTimer < (cumulatedTime + roadTime)) || (cycleTimer >= (cumulatedTime + cycleLength - CHANGE_PRETIME) && cycleTimer < (cumulatedTime + cycleLength))) { // Switching to RED to YELLOW...
//      Serial.println(phrase + "RY for " + i + ",time: " + timer);
//      trafficStates[i] = YELLOW;
//    } else if (currentState == 3 && cycleTimer >= cumulatedTime  && cycleTimer < (cumulatedTime + roadTime)) { // Switching from YELLOW to GREEN...
//      Serial.println(phrase + "G for " + i + ",time: " + timer);
//      trafficStates[i] = GREEN;
//    } else if (currentState == 0 && cycleTimer >= (cumulatedTime + roadTime - CHANGE_PRETIME) && cycleTimer < (cumulatedTime + roadTime)) { // Switching from GREEN to YELLOW...
//      Serial.println(phrase + "Y for " + i + ",time: " + timer);
//      trafficStates[i] = RED_YELLOW;
//    } else if (currentState == 1 && (cycleTimer >= (cumulatedTime + roadTime) || (cycleTimer >= 0 && cycleTimer < cumulatedTime))) { // Switching from YELLOW to RED
//      Serial.println(phrase + "R for" + i + ",time: " + timer);
//      trafficStates[i] = RED;
//    }
  }
}

/**
 * 
 * Sets crossroads states for all the traffic lights
 * 
*/
void setStates() {
  for (int i = 0; i < TRAFFIC_LIGHTS_NO; i++) {
    setColors(trafficStates[i], i);
  }
}





