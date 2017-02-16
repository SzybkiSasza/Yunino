#include <Bridge.h>
#include "constants.h"
#include "stateManager.h"
#include "lightSwitcher.h"

// Cumulated times - to determine the next change for each light
int cumulatedTimes[TRAFFIC_LIGHTS_NO] = {0};

// This array keeps the states of the lights in any time. States come from 
lightState lightStates[TRAFFIC_LIGHTS_NO] = {};

int createInitialStates() {
  // First light always starts with GREEN...
  lightStates[0] = GREEN;

  // Set all needed pin modes to OUTPUT!!!
  for (int i=0; i<TRAFFIC_LIGHTS_NO; i++) {
    for ( int j=1; j<=3; j++) {
      pinMode((i * SHIFT) + j, OUTPUT);
    }
  }

  // Calculate cumulated times for each lights
  for (int i = 1; i < TRAFFIC_LIGHTS_NO; i++) {
    // All other lights start with RED...
    lightStates[i] = RED;
    cumulatedTimes[i] = (cumulatedTimes[i - 1] + LANE_TIMES[i - 1]);
  }

  // Calculate total cycle length = all the GREEN times.
  int cycleLength = cumulatedTimes[TRAFFIC_LIGHTS_NO - 1] + LANE_TIMES[TRAFFIC_LIGHTS_NO - 1];
  return cycleLength;
}

lightState * currentState = lightStates;
void checkStates(int timer, int cycleLength) {
  for (int i = 0; i < TRAFFIC_LIGHTS_NO; i++) {

    // Get current state information and timings for changing the states
    lightState* currentState = &lightStates[i];
    const int beginGreenTime = cumulatedTimes[i];
    const int roadTime = LANE_TIMES[i];

    // Operate only inside cycle length
    const int cycleTimer = timer % cycleLength;

    // Prepare all the border
    const int nextGreenTime = beginGreenTime > 0 ? beginGreenTime : cycleLength;
    const int beginYellowTime = beginGreenTime + roadTime - CHANGE_PRETIME;
    const int beginRedTime = (beginGreenTime + roadTime) >= cycleLength ? 0 : (beginGreenTime + roadTime);
    const int beginRedYellowTime = nextGreenTime - CHANGE_PRETIME;
    
    // Again - strange quirk of C++. String has to be initialized in advance to concatenate an coerce
    String phrase = "[";
    phrase = phrase + "number: " + i + "][time:" + cycleTimer + "] Switching to: "; 
  
    switch(*currentState) {
      case RED:
        if (cycleTimer >= beginRedYellowTime && cycleTimer <= nextGreenTime) {
          Serial.println(phrase + "RY");
          *currentState = RED_YELLOW;
        }
        break;
      case RED_YELLOW:
        if ((beginGreenTime > beginRedYellowTime && cycleTimer >= beginGreenTime) || (beginGreenTime < beginRedYellowTime && cycleTimer <= beginYellowTime)) {
          Serial.println(phrase + "G");
          *currentState = GREEN;
        }
        break;
      case YELLOW:
        if ((beginRedTime > beginYellowTime && cycleTimer >= beginRedTime) ||(beginRedTime < beginYellowTime && cycleTimer <= beginRedYellowTime)) {
          Serial.println(phrase + "R");
          *currentState = RED;
        }
        break;
      default:
        if (cycleTimer >= beginYellowTime) {
          Serial.println(phrase + "Y");
          *currentState = YELLOW;
        }
        break;
    }
  }
}

/**
 * 
 * Sets crossroads states for all the traffic lights
 * 
*/
void setStates() {
  for (int i = 0; i < TRAFFIC_LIGHTS_NO; i++) {
    setColors(lightStates[i], i);
  }
}





