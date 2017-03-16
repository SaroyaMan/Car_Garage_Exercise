#include "car.h"
using namespace std;

Car::Car()
{
//	cout<<"The default car constructor is activated.\n";
	model= new char[9];
	brand= new char[9];
	owner= new char[6];
	if (model==0 || brand==0 || owner==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	strcpy(model, "Default");
	strcpy(brand, "Defaulty");
	strcpy(owner, "Owner");
	motor = new Engine;
	if (motor==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	light = new Lights;
	if (light==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	wheel1 = new Wheels;
	wheel2 = new Wheels;
	wheel3 = new Wheels;
	wheel4 = new Wheels;
	if (wheel1==0 || wheel2==0 || wheel3==0|| wheel4==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	setInShop(0);
}

Car::Car(float volume, float maxFuel,float currFuel, char* name, char* nbrand, char* nowner, int psi, float radius, bool flat)
{
//	cout<<"The user-defined car constructor is activated.\n";
	model= new char[strlen(name)+1];
	brand= new char[strlen(nbrand)+1];
	owner= new char[strlen(nowner)+1];
	if (model==0 || brand==0 || owner==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	strcpy(owner, nowner);
	strcpy(model, name);
	strcpy(brand, nbrand);
	motor = new Engine(volume, currFuel, maxFuel);
	if (motor==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	light = new Lights;
	if (light==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	wheel1 = new Wheels(psi, radius, flat);
	wheel2 = new Wheels(psi, radius, flat);
	wheel3 = new Wheels(psi, radius, flat);
	wheel4 = new Wheels(psi, radius, flat);
	if (wheel1==0 || wheel2==0|| wheel3==0|| wheel4==0)
	{
		cerr<<"Not enough memory\n";
		exit(1);
	}
	setInShop(0);
}

Car::Car(const Car& c)
{	
	//	cout<<"The copy car constructor is activated.\n";
	inShop=c.inShop;
	model = new char[strlen(c.model)+1];
	brand = new char[strlen(c.brand)+1];
	owner = new char[strlen(c.owner)+1];
	strcpy(model, c.model);
	strcpy(brand, c.brand);
	strcpy(owner, c.owner);
	motor = new Engine(c.motor->getVolume(), c.motor->getFuel(), c.motor->getMaxFuel());
	motor->setActivated(c.motor->getActivated());
	motor->setMalfunctionE(c.motor->getMalfunctionE());
	light = new Lights;
	light->setActive(c.light->getActive());
	light->setMalfunctionL(c.light->getMalfunctionL());

	wheel1 = new Wheels(c.wheel1->getPsi(), c.wheel1->getRadi(), c.wheel1->getFlat());
	wheel2 = new Wheels(c.wheel2->getPsi(), c.wheel2->getRadi(), c.wheel2->getFlat());
	wheel3 = new Wheels(c.wheel3->getPsi(), c.wheel3->getRadi(), c.wheel3->getFlat());
	wheel4 = new Wheels(c.wheel4->getPsi(), c.wheel4->getRadi(), c.wheel4->getFlat());
	
	if (motor==0 ||light==0||wheel1==0||wheel2==0||wheel3==0||wheel4==0||model==0 ||brand==0 ||owner==0)
	{
		cerr<<"Not enough memory.\n";
		exit(1);
	}	
}

Car::~Car()
{
//	cout<<"Class 'Car' has been destroyed (model:"<<model<<", brand:"<<brand<<").\n";
	delete[] model;
	delete[] brand;
	delete[] owner;
	delete motor;
	delete light;
	delete wheel1;
	delete wheel2;
	delete wheel3;
	delete wheel4;
}

void Car::switchOn()
{
	cout<<"Switch ON:\n";
	motor->setActivated(1);
	light->setActive(1);
}

void Car::switchOff()
{
	cout<<"Switch OFF:\n";
	light->setActive(0);
	motor->setActivated(0);
}

void Car::drive()
{
	cout<<"Start driving:\n";
		if (wheel1->getFlat() ==1 ||wheel2->getFlat() ==1||wheel3->getFlat() ==1||wheel4->getFlat() ==1 )
		{
			cout<<"There is a flat in one of the wheels. You can't drive like that.\n";
			return;
		}
	if (light->getActive()==1 && motor->getActivated()==1)
	{
		if (motor->getFuel() > 0 && motor->getFuel()<=motor->getMaxFuel())
			cout<<"Your car (model:"<<model<<", brand:"<<brand<<") is driving. \n";
		else	cerr<<"You don't have enough fuel to drive.\n";
	
	}
	else	cerr<<"If you want to drive - please switch on the car.\n";
}

bool Car::setOwner(char* newOwner)
{
	owner = strdup(newOwner);
	if (owner==0)
	{
		cerr<<"The setter failed\n";
		return false;
	}
//	cout<<"Set to: Owner:"<<owner<< "Successfully\n";
	return true;
}

Car& Car::operator=(const Car& c)
{
	if (this == &c) return *this;

	delete motor;
	delete light;
	delete wheel1;
	delete wheel2;
	delete wheel3;
	delete wheel4;
	inShop=c.inShop;
	motor = new Engine(c.motor->getVolume(), c.motor->getFuel(), c.motor->getMaxFuel());
	motor->setActivated(c.motor->getActivated());
	motor->setMalfunctionE(c.motor->getMalfunctionE());
	light = new Lights;
	light->setActive(c.light->getActive());
	light->setMalfunctionL(c.light->getMalfunctionL());
	model = strdup(c.model);
	brand = strdup(c.brand);
	owner = strdup(c.owner);

	wheel1 = new Wheels(c.wheel1->getPsi(), c.wheel1->getRadi(), c.wheel1->getFlat());
	wheel2 = new Wheels(c.wheel2->getPsi(), c.wheel2->getRadi(), c.wheel2->getFlat());
	wheel3 = new Wheels(c.wheel3->getPsi(), c.wheel3->getRadi(), c.wheel3->getFlat());
	wheel4 = new Wheels(c.wheel4->getPsi(), c.wheel4->getRadi(), c.wheel4->getFlat());

	if (motor==0||light==0||wheel1==0||wheel2==0||wheel3==0||wheel4==0||model==0||brand==0||owner==0)
	{
		cerr<<"Not enough memory.\n";
		exit(1);
	}
	
	return *this;
}

void Car::setInShop(bool b)
{
//	if (b) cout<<"Set to: The car is in the shop - Sucessfully\n";
//	else cout<<"Set to: The car is NOT in the shop - Sucessfully\n";
	inShop=b;
}

void Car::printCar()
{
	cout<<"Model: "<<model<<"\n";
	cout<<"Brand: "<<brand<<"\n";
	cout<<"Owner: "<<owner<<"\n";
	if (light->getMalfunctionL()) cout<<"The lights has malfunction\n";
	else cout<<"The lights is fine\n";
	if (motor->getMalfunctionE()) cout<<"The engine of the car has malfunction\n";
	else cout<<"The engine of the car is fine\n";
	cout<<"Volume: "<<motor->getVolume()<<"\n";
	cout<<"Current Fuel: "<<motor->getFuel()<<"\n";
	cout<<"Max Fuel: "<<motor->getMaxFuel()<<"\n";
	cout<<"PSI1: "<<wheel1->getPsi()<<"\n";
	cout<<"Radius1: "<<wheel1->getRadi()<<"\n";
	cout<<"PSI2: "<<wheel2->getPsi()<<"\n";
	cout<<"Radius2: "<<wheel2->getRadi()<<"\n";	
	cout<<"PSI3: "<<wheel3->getPsi()<<"\n";
	cout<<"Radius3: "<<wheel3->getRadi()<<"\n";
		cout<<"PSI4: "<<wheel4->getPsi()<<"\n";
	cout<<"Radius4: "<<wheel4->getRadi()<<"\n";	
	if (wheel1->getFlat() ==0 && wheel2->getFlat() ==0 && wheel3->getFlat() ==0 && wheel4->getFlat() ==0 ) cout<<"There is no flat in one of the wheels\n";
	else cout<<"There is a flat in one of the wheels\n";
}

int Car::countMalfunction() const
{
	int count=0;
	if (motor->getMalfunctionE()) 
	count++;
	if (light->getMalfunctionL())
	 count++;
	if (wheel1->getFlat()) 
	count++;
	if (wheel2->getFlat())
	 count++;
	if (wheel3->getFlat()) 
	count++;
	if (wheel4->getFlat())
	 count++;
	return count;
}

void Car::setModel(char* newModel)
{
	strcpy(model, newModel);
}

void Car::setBrand(char* newBrand)
{
	strcpy(brand, newBrand);
}
