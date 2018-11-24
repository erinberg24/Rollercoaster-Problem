#include "car.h"

void car() {
  while (1) {
    waitForFullCar();
    rideCoaster();
    finishRide();
    if (getNumPassenger() == 0)
      break;
  }
}
