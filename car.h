#ifndef car
#define car
#include <iostream>
#include <cstring>
#include "lights.h"
#include "wheels.h"
#include "engine.h"

class Car			//this class will be used for represent the car. this class uses all the other 3 classes.
{
	char* model=NULL;
	char* brand=NULL;
	char* owner=NULL;
	Engine* motor=NULL;
	Lights* light= NULL;
	Wheels* wheel1 = NULL;
	Wheels* wheel2 = NULL;
	Wheels* wheel3 = NULL;
	Wheels* wheel4 = NULL;
	bool inShop;				//not in the garage =0, inside the garage=1
	
	public:
		Car();
		Car(float volume, float maxFuel,float currFuel, char* name, char* nbrand,char* nowner, int psi, float radius, bool flat);
		Car(const Car& c);		//copy constructor
		~Car();
		void switchOn();		//switch on the car - turn on the lights and the engine.
		void switchOff();		//switch off the car - turn off the lights and the engine.
		void drive();			//check if the car is ready to drive.
		Car& operator=(const Car& c);		//Car assignment operator.
		bool setOwner(char* newOwner);
		char* getOwner() const {return owner;}
		bool getInShop() const {return inShop;}
		void setInShop(bool b);
		void setModel(char* newModel);
		void setBrand(char* newBrand);
		char* getModel() const {return model;}
		char* getBrand() const {return brand;}
		void printCar();		//print all the data of the car.
		int countMalfunction() const;	//counts the malfunctions of the car.
		Engine* getMotor() {return motor;}
		Lights* getLight() {return light;}
		Wheels* getWheel1() {return wheel1;}
		Wheels* getWheel2() {return wheel2;}
		Wheels* getWheel3() {return wheel3;}
		Wheels* getWheel4() {return wheel4;}
};

#endif
