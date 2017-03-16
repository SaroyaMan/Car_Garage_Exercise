#ifndef wheels
#define wheels
class Wheels		//this class will be used to represent the wheels of class car.
{
	int psi;		// psi must be positive number
	float radius;	// radius must be positive number
	bool flat;		// flat = 1, NO flat = 0
	public:
		Wheels();
		Wheels(int newPsi, float newRadius, bool newFlat);
		~Wheels();
		void setPsi(int newPsi);
		int getPsi() {return psi;}
		void setRadi(float newRadius);
		float getRadi() {return radius;}
		void setFlat (bool newFlat);
		bool getFlat() {return flat;}
		bool check();			//check if the wheel has a flat or not.
};
#endif
