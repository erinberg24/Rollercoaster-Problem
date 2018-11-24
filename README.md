# Rollercoaster-Problem
The Famous Roller Coaster Problem. 
Suppose there are n passengers and one roller coaster car. The passengers repeatedly wait to take rides on the car. The car has a capacity of C seats, C &lt; n, but the cheapskate owners won't let the car leave the station until it is full. This program simulates a solution to this problem. 
Each passenger is a thread that waits to take a ride, waits until the ride completes, disembarks from the ride and exits.  
The car is thread that waits until C passengers enter the car for a ride, then goes around the track for some fixed amount of time (some fixed sleep time), then lets the passengers disembark. 
It does this until there are no more passengers wanting rides.  
Main() thread performs a pthread_join() on the car thread. When there are no more waiting passenger threads, the car thread exits and thus the main() thread prints something informative and exits.  
This program simulates this system and fulfill the following requirements:  
  1. The car always rides with exactly C passengers;  
  2. No passengers will jump off the car while the car is running;  
  3. No passengers will jump on the car while the car is running.
