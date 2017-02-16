#ifndef TRAFFIC_CONSTANTS
#define TRAFFIC_CONSTANTS

/**
 * 
 * Contains constants that are used to run the Sketch.
 * Modify at will to change the program behaviour
 * 
 */

 // Light states as enum
enum lightStates
{
  GREEN,
  YELLOW,
  RED,
  RED_YELLOW
};


// Single "tick" time for simulation
const int TICK_TIME = 50;

// Number of pins to shift for each traffic light. 
// Means that the next traffic light will start at 4,5,6 then 8,9,10 etc.
const int SHIFT = 4;

// Time for which yellow will be shown
const int CHANGE_PRETIME = 2000;

// Time for "GREEN" for each lane/road, starting with the first traffic light - cutomize here!!!
const int LANE_TIMES[] = {5 * 1000, 10 * 1000, 5 * 1000};

// Computed total number of lights
const int TRAFFIC_LIGHTS_NO = sizeof(LANE_TIMES) / sizeof(int);

#endif
