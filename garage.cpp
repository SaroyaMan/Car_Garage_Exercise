#include "garage.h"
using namespace std;

Garage::Garage()				//The default garage constructor.
{
	gFunds=0;
	carList* carsInGarage=NULL;
	customerList* customers=NULL;
	customerList* checkedInCustomers=NULL;
}

Garage::~Garage()				// the destructor of class garage.
{
	carsInGarage = freeCarList(carsInGarage);
	customers = freeCustomerList(customers);
	checkedInCustomers = freeCustomerList(checkedInCustomers);
}

void Garage::setgFunds(double money)
{
//	cout<<"Set to: funds in the garage = "<<money<<"\n";
	gFunds = money;
}

double Garage::calculatePrice(const Car* v)		// Calculate the price of fixing the car.
{
		double money=500 * (v->countMalfunction());
		return money;
}

void Garage::fixCar(Car* v)
{
	v->getMotor()->setMalfunctionE(0);
	v->getMotor()->setMaxFuel(500);
	v->getMotor()->setFuel(400);
	v->getLight()->setMalfunctionL(0);
	v->getWheel1()->setFlat(0);
	v->getWheel2()->setFlat(0);
	v->getWheel3()->setFlat(0);
	v->getWheel4()->setFlat(0);
	cout<<"The car "<<v->getModel()<<" "<<v->getBrand()<<" fixed sucessfully.\n";
}

bool Garage::checkOut(Customer* c)				// remove the customer and his car from the checkedIN list.
{
		c->getCar()->setInShop(0);
		c->setFunds(c->getFunds() - calculatePrice(c->getCar()));
		gFunds += calculatePrice(c->getCar());
		fixCar(c->getCar());
		carsInGarage = deleteCar(carsInGarage, c->getCar());
		checkedInCustomers = deleteCustomer(checkedInCustomers , c);
		cout<<"The car of the customer has fixed and returned to his owner.\n";
		return true;
//	cout<<"The customer has not been found in the list\n";
//	return false;
}

bool Garage::checkInCar(Car* c)			//this function adds a car to the carList.
{
	if (c->getInShop() == 1)
	{
		cerr<<"The car"<<c->getBrand()<<" "<<c->getModel()<<" is already in the garage!\n";
		return false;
	}
	c->setInShop(1);
	carsInGarage = addCarToBottom(carsInGarage, c );
	cout<<"The car "<<c->getModel()<<" "<<c->getBrand()<<" got inside the Car-List.\n";
	return true;
}

bool Garage::addCustomer(Customer* c)		//add a single customer to customers list.
{
	customerList* tmp = NULL;
	tmp = customers;
	while (tmp != NULL)
	{
		if (strcmp(tmp->data->getID() , c->getID()) ==0)
		{
			cerr<<"This customer "<<tmp->data->getName()<<" - "<<tmp->data->getID()<<" is already in the list.\n";
			return false;
		}
		tmp = tmp->next;
	}
	
	tmp = checkedInCustomers;
	while (tmp != NULL)
	{
		if (strcmp(tmp->data->getID() , c->getID()) ==0)
		{
			cerr<<"This customer is already in the list.\n";
			return false;
		}
		tmp = tmp->next;
	}
	customers = addCustomerToBottom(customers, c);
	return true;
}

bool Garage::dissListCustomer(Customer* c)	//delete a single customer from the customers list.
{
	int x = listCountCustomer(customers);
	customers = deleteCustomer(customers , c);
	int y = listCountCustomer(customers);
	if (x == (y+1))
	{
		cout<<"The customer has been deleted sucessfully from the customers list.\n";
		return true;
	} 
	return false;
}

bool Garage::checkInCustomer(Customer& c)		//adds a customer and his car to the checked-IN list.
{
	customerList* tmp = NULL;
	tmp = customers;
	while (tmp != NULL)
	{
		if (strcmp(tmp->data->getID() ,c.getID()) ==0)
		{
			if (c.getFunds() >= calculatePrice(c.getCar()) )
			{
					c.setCar(0);
					checkedInCustomers = addCustomerToBottom(checkedInCustomers, &c);
					cout<<"The customer "<<c.getName()<<" "<<c.getID()<<" added to checked-in lists.\n";
					return true;
			}
			else
			{
				cerr<<"You dont have enough money to pay for the fix.\n";
				return false;
			}
		}
		tmp=tmp->next;
	}
	cerr<<"The customer has not found in the customer-list.\n";
	return false;
}
