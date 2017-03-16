#include "engine.h"
using namespace std;

Engine::Engine()			
	{
//		cout<<"The default engine constructor is activated.\n";
		setVolume(0);
		setMaxFuel(0);
		setFuel(0);
		setActivated(0);
		setMalfunctionE(0);	
	}

Engine::Engine(float newVolume, float fuelAmount, float newMaxFuel)
	{
//		cout<<"The user-defined engine constructor is activated.\n";
		currentFuel=0;
		setVolume(newVolume);
		setMaxFuel(newMaxFuel);
		setFuel(fuelAmount);
		setActivated(0);
		setMalfunctionE(0);
	}

Engine::~Engine(){
//	cout<<"Class 'Engine' has been destroyed.\n";
}

void Engine::setFuel(float newFuel)
{
	currentFuel=0;
	if (newFuel>=0 && newFuel<=maxFuel)
	{
//		cout<<"Set to: Current fuel of the engine = "<<newFuel<<" successfully.\n";
		currentFuel=newFuel;
	}
//	else cerr<<"The setter failed. currentFuel >=0 && currentFuel<=maxFuel. currentFuel=0\n";
}


void Engine::setMaxFuel(float newMaxFuel)
{
	maxFuel=0;
	if (newMaxFuel>=0 && newMaxFuel>=currentFuel)
	{
//		cout<<"Set to: Max fuel of the engine = "<<newMaxFuel<<" successfully.\n";
		maxFuel=newMaxFuel;
	}
//	else cerr<<"The setter failed. maxFuel >=0 && currentFuel>=maxFuel. maxFuel=0\n";	
}


void Engine::setVolume(float newVolume)
{
	volume=0;
	if (newVolume>=0)
	{
//		cout<<"Set to: Volume of the engine = "<<newVolume<<" successfully.\n";
		volume=newVolume;
	}
//	else cerr<<"The setter failed. volume has to be a positive value. Volume=0\n";
}


void Engine::setActivated(bool a)
{
//	if (a) cout<<"Set to: Engine is ON - Successfully.\n";
//	else cout<<"Set to: Engine is OFF - Successfully.\n";
	activated=a;
}

void Engine::activate(bool a)
{
	if (a) cout<<"The engine is now ON.\n";
	else cout<<"The engine is now OFF.\n";
}

void Engine::setMalfunctionE (bool b)
{
//	if (b) cout<<"Set to: Engine has malfunction - Successfully.\n";
//	else cout<<"Set to: Engine works fine - Sucessfully.\n";
	malfunction=b;
}
