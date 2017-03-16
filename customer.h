#ifndef customer
#define customer
#include "car.h"
#include <iostream>
#include <cstring>
class Customer		//this class will be used to represent the customer of the garage.
{
	char* name;	
	char* id;
	float funds;
	Car* currentCar;
	public:
		Customer();						//Default customer constructor
		Customer(char* _name, char* _id, float _funds, Car* _car);	//User-defined customer constructor
		Customer(const Customer& c);	//Copy customer constructor
		~Customer();		//Destructor for customer
		Customer& operator=(const Customer& c);		//Customer assignment operator
		char* getName() const {return name;}
		void setName(char* _name);
		char* getID() const {return id;}
		void setID(char* _id);
		float getFunds() const {return funds;}
		void setFunds(float _funds);
		Car* getCar() const {return currentCar;}
		void setCar(Car* _car);
		bool assignCar(const Car& c);			//assign a car to the customer
};
#endif
