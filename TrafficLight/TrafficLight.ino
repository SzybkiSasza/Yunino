#include "constants.h"
#include "lightSwitcher.h"
#include "stateManager.h"

/**
 * 
 * Simple sequential script for simulating traffic lights
 * Each light is run in sequence and has dedicated "green light" window.
 * Yellow operates as in real life - is light together with red when switching to green
 * All the interim "yellow" states are displayed for the same amount of time
 * 
 */

// Timer that depicts current crossroads state. All the functions used to calculate switching times.
// Timer is increased by the value of TICK_TIME in every single loop iteration
int timer = 0;

// Keeps the information about total cycle length. Used for resetting the timer
int cycleLength = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial); // Remember to open the Serial to start the simulation!

  Serial.println("*** Setting the initial state ***");
  String phrase = "Total number of lights: "; // Hacky hack. I don't like this C++ gimmick...
  Serial.println(phrase + TRAFFIC_LIGHTS_NO);
  Serial.println("******");
  
  cycleLength = createInitialStates();
}

/**
 * 
 * Runs the loop.
 * The sequence is always the same:
 * 
 * 1. Check current states and change state array if needed
 * 2. Set new states based on state array (that could be changed on previous step)
 * 3. Wait for the next tick
 * 4. Update the timer value
 * 3. Reset timer if the cycle is finished
 * 
 */
void loop() {
  checkStates(timer);
  setStates();

  delay(TICK_TIME);
  timer += TICK_TIME;

  if (timer >= cycleLength) {
    timer = 0;
  }
}
