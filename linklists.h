#ifndef linklists
#define linklists
#include "car.h"
#include "customer.h"

typedef struct carList
{
	Car* data;
	struct carList* next;
} carList;

typedef struct customerList
{
	Customer* data;
	struct customerList* next;
} customerList;

carList* addCarToBottom(carList* head, Car* newCar);
carList* deleteCar(carList* head, Car* deleteCar);
void printCarList(carList* head);
carList* freeTopCar(carList* head);
carList* freeCarList(carList* head);
int listCountCars(carList* head);


customerList* addCustomerToBottom(customerList* head, Customer* newCustomer);
customerList* deleteCustomer(customerList* head, Customer* deleteCustomer);
void printCustomerList(customerList* head);
customerList* freeTopCustomer(customerList* head);
customerList* freeCustomerList(customerList* head);
int listCountCustomer(customerList* head);

#endif
