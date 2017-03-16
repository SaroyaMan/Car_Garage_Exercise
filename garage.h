#ifndef garage
#define garage
#include "wheels.h"
#include <iostream>
#include <cstring>
#include "car.h"
#include "customer.h"
#include "linklists.h"

class Garage		//this class will be used to represent the garage.
{
	double gFunds;
	carList* carsInGarage=NULL;
	customerList* customers=NULL;
	customerList* checkedInCustomers=NULL;
	
	public:
		double getgFunds() {return gFunds;}
		void setgFunds(double money);
		double calculatePrice(const Car* v);	//calculates the price of the fix.
		bool checkOut(Customer* c);			//fix the car + remove the customer+car from the garage.
		bool checkInCar(Car* c);			//adds the car to the garage and to the carsInGarage list.
		bool addCustomer(Customer* c);		//adds a single customer the the customers list.
		bool dissListCustomer(Customer* c);	
		bool checkInCustomer(Customer& c);	//adds a customer to the checked-IN customers.
		void fixCar(Car* v);				//fix the car.
		Garage();
		~Garage();
		carList* getcarList() {return carsInGarage;}
		customerList* getCustomersList() {return customers;}
		customerList* getCheckedInCustomers() {return checkedInCustomers;}
};
#endif
