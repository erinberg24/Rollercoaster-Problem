#include "pp6functions.h"
#include <unistd.h>

void createCoaster(int seatNum, int riderNum) {
  seats = 0;
  x = 0;
  totalSeats = 0;
  numPassengers = 0;
  riding = 0;
  sleeping = 1;
  totalSeats = seatNum;
  seats = totalSeats;
  RIDE_TIME = 4;
  WAIT_TIME = 3;
  numPassengers = riderNum;
  pthread_mutex_init(&ride, NULL);
  pthread_mutex_init(&seat, NULL);
  pthread_mutex_init(&wakeupcar, NULL);
  pthread_cond_init(&chairs, NULL);
  pthread_cond_init(&waittoride, NULL);
  pthread_cond_init(&carWaits, NULL);
  int c;
  for (c = 0; c < totalSeats; c++){
    seatUsage[c] = (char *) malloc(sizeof(char)*10);
    strcpy(seatUsage[c],"empty");
  }
}
int getSeats() {
  return totalSeats;
}
int getNumPassenger() {
  return numPassengers;
}
void loadCustomers(int passengerID) {
  pthread_mutex_lock(&seat);
  while (seats == 0){
    pthread_cond_wait(&chairs, &seat);
  }
  sprintf(seatUsage[seats - 1], "%i", passengerID);
  seats--;
  numPassengers--;
  if ((seats == 0) || (numPassengers == 0))
  {
    sleeping=0;
    pthread_cond_broadcast(&carWaits);
  }
  pthread_mutex_unlock(&seat);
  riding = 1;
  goForRide();
}
void unloadCustomers() {
  pthread_cond_broadcast(&chairs);
}
void goForRide() {
  pthread_mutex_lock(&ride);
  while (riding){
    pthread_cond_wait(&waittoride, &ride);
  }
  pthread_mutex_unlock(&ride);
}
void waitForFullCar() {
  pthread_mutex_lock(&wakeupcar);
  while (sleeping){
    pthread_cond_wait(&carWaits, &wakeupcar);
  }
  sleeping = 1;
  pthread_mutex_unlock(&wakeupcar);
}
void finishRide() {
  int y;
  y = totalSeats - seats;
  seats = totalSeats;
  for (x = 0; x < totalSeats; x++)
    strcpy(seatUsage[x],"empty");
  riding = 0;
  pthread_cond_broadcast(&waittoride);
}

void rideCoaster() {
  int x, y;
  y = getSeats();

  for (x = 0; x < y; x++) {
    printf("Person [%s] was seated in seat %i.\n", seatUsage[x], x);
  }
  int sleepTime = rand() % RIDE_TIME;
  sleep(sleepTime);
}
