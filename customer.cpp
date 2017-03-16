#include "customer.h"
using namespace std;

Customer::Customer()
{
	name = strdup("Customer");
	id = strdup("000000001");
	funds = 100;
	currentCar = NULL;
	if (name ==0 || id ==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
}

Customer::Customer(char* _name, char* _id, float _funds, Car* _car)
{
	name = strdup(_name);
	id = strdup(_id);
	setFunds(_funds);
	currentCar = _car;
	currentCar->setOwner(id);
	if (name ==0 || id ==0 || currentCar ==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
}

Customer::Customer(const Customer& c)
{
	//cout<<"The copy Customer constructor is activated\n";
	funds = c.funds;
	name = strdup(c.name);
	id = strdup(c.id);
	currentCar = c.getCar();
}

Customer::~Customer()
{
	//	cout<<"Class 'Customer' has been destroyed (name:"<<name<<", id:"<<id<<").\n";
	delete[] name;
	delete[] id;
}


Customer& Customer::operator=(const Customer& c)
{
	if (this == &c) return *this;
	funds = c.funds;
	name = strdup(c.name);
	id = strdup(c.id);
	currentCar = c.currentCar;
	if (currentCar != 0) currentCar->setOwner(id);
	return *this;
}


void Customer::setName(char* _name)
{
//	cout<<"Set to: "<<_name<<" Sucessfully\n";
	name = strdup(_name);
	if (name ==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
}

void Customer::setID(char* _id)
{
	//	cout<<"Set to: "<<_id<<" Sucessfully\n";
	id = strdup(_id);
	if (id ==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
}

void Customer::setFunds(float _funds)
{
	//	cout<<"Set to: funds = "<<_funds<<" Sucessfully\n";
	funds=_funds;
}

void Customer::setCar(Car* _car)
{
	//	cout<<"Set to: Car model = "<<_car->getModel() << "Car brand = "<<_car->getModel()<<" Sucessfully\n";
	if (_car == 0) 
	{
		currentCar = 0;
		return;
	}	
	currentCar = new Car(*_car);
	currentCar->setOwner(id);
}

bool Customer::assignCar(const Car& c)
{
	if (currentCar != NULL)
	{
		cout<<"The customer "<<getName()<<" already has a car.\n";
		return false;
	}
	currentCar = new Car(c);
	return true;
}
