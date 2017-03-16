#ifndef engine
#define engine
#include <iostream>

class Engine								//this class will be used to represent the engine of class car.
{
	float volume, currentFuel, maxFuel;		//All must be positive numbers
	bool activated;							//engine is OFF = 0, engine is ON = 1
	bool malfunction;						// NO malfunction = 0, malfunction = 1	
	public:
		Engine();
		Engine(float newVolume, float fuelAmount, float newMaxFuel);
		~Engine();
		void setFuel(float newFuel);
		float getFuel() {return currentFuel;}
		void setMaxFuel(float newMaxFuel);
		float getMaxFuel(){return maxFuel;}
		void setVolume(float newVolume);
		float getVolume() {return volume;}
		void setActivated(bool a);
		bool getActivated() {return activated;}
		void activate(bool a);			//turn ON or off the engine.
		bool getMalfunctionE() {return malfunction;}
		void setMalfunctionE(bool b);
};

#endif
