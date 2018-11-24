#include "rider.h"

void rider(int * id)
{
    int *person;
    person = id;
    printf("Person [%i] wants to ride the rollercoaster\n", *person);
    loadCustomers(*person);
    printf("Person [%i] went for a ride.\n", *person);
    unloadCustomers();
    printf("Person [%i] got off the rollercoaster\n", *person);
}
