#ifndef lights
#define lights
class Lights				//this class will be used to represent the lights of class car.
{	
	bool active;			//lights OFF = 0	lights ON = 1
	bool malfunction;		// NO malfunction = 0	malfunction =1
	public:
		Lights(bool b=0);
		~Lights();
		void setActive(bool b);
		bool getActive() {return active;}
		void setMalfunctionL (bool b);
		bool getMalfunctionL () {return malfunction;}
		void toggleLights();				//turn on or off the lights.
};

#endif
