#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int seats;
int x;
int totalSeats;
int numPassengers;
char * seatUsage[100];
pthread_mutex_t seat;
pthread_mutex_t ride;
pthread_mutex_t wakeupcar;
pthread_cond_t chairs;
pthread_cond_t waittoride;
pthread_cond_t carWaits;
int riding,sleeping;
int  RIDE_TIME;
int WAIT_TIME;

void createCoaster(int seatNum, int riderNum) ;
int getSeats() ;
int getNumPassenger() ;
void rideCoaster();
void loadCustomers(int passengerID) ;
void unloadCustomers();
void goForRide();
void waitForFullCar();
void finishRide();
