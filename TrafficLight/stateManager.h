#ifndef STATE_MANAGER
#define STATE_MANAGER

/**
 * 
 *  Sets the initial state for all the traffic lights and calculates variables
 *  First light - green. Other ones - red
 *  
 */
int createInitialStates();
void checkStates(int timer);
void setStates();

#endif
