#include "pp6functions.h"
#include "pp6functions.c"
#include "car.c"
#include "rider.c"
#include "car.h"
#include "rider.h"
#include <pthread.h>

int main(int argc, char *argv[]) {
  int sleeptime = 1;
  int riderID = 0;

  int i, *x;
  if (argc != 3) {
    printf("Please give the capacity of the car, c, and the number of riders, n.\n");
    exit(-1);
  }
  srand(time(NULL));
  int c = atoi(argv[1]);
  int n = atoi(argv[2]);
  pthread_t car1, riders[n];
  createCoaster(c, n);
  pthread_create(&car1, NULL, (void *)car, NULL);
  while (riderID < n) {
    x = (int *)malloc(sizeof(int));
    *x = riderID;
    if (pthread_create(&(riders[riderID]), NULL, (void *)rider, x) != 0) {
      perror("pthread_create");
      exit(1);
    }
    riderID++;
    sleeptime = rand() % WAIT_TIME;
    sleep(sleeptime);
  }
  for (i = 0; i < n; i++)
    pthread_join(riders[i], NULL);
  puts("There aren't any more people who want to ride the rollercoaster");
}
