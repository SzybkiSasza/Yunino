#ifndef STATE_MANAGER
#define STATE_MANAGER

/**
 * 
 *  Sets the initial state for all the traffic lights and calculates variables
 *  First light - green. Other ones - red
 *  
 */
int createInitialStates();

/**
 * 
 * Checks the states, based on current time and traffic cycle length
 * Updates the internal states array that is used to change traffic light colors
 * 
 * @param timer         Current cycle time
 * @param cycleLength   Total cycle length
 */
void checkStates(int timer, int cycleLength);

/**
 * 
 * Sets the light states based on the internal array
 * 
 */
void setStates();

#endif
