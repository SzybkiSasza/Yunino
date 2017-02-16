#include <Bridge.h>
#include "lightSwitcher.h"

void setColors(lightStates state, int number) {
  int firstPinNo = number * SHIFT; //  Real first pin position used to calculate pins for given traffic no. number

  switch (state) {
    case YELLOW:
      digitalWrite(GREEN_PIN + firstPinNo, LOW);
      digitalWrite(YELLOW_PIN + firstPinNo, HIGH);
      digitalWrite(RED_PIN + firstPinNo, LOW);
      break;
    case RED:
      digitalWrite(GREEN_PIN + firstPinNo, LOW);
      digitalWrite(YELLOW_PIN + firstPinNo, LOW);
      digitalWrite(RED_PIN + firstPinNo, HIGH);
      break;
    case RED_YELLOW:
      digitalWrite(GREEN_PIN + firstPinNo, LOW);
      digitalWrite(YELLOW_PIN + firstPinNo, HIGH);
      digitalWrite(RED_PIN + firstPinNo, HIGH);
      break;
    default:
      digitalWrite(GREEN_PIN + firstPinNo, HIGH);
      digitalWrite(YELLOW_PIN + firstPinNo, LOW);
      digitalWrite(RED_PIN + firstPinNo, LOW);
      break;
  }
}

