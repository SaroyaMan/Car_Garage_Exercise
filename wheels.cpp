#include <iostream>
#include "wheels.h"
using namespace std;

Wheels::Wheels()
	{
//		cout<<"The default wheels constructor is activated.\n";
		setPsi(0);
		setRadi(0);
		setFlat(0);
	}

Wheels::Wheels(int newPsi, float newRadius, bool newFlat)
	{
//		cout<<"The user-defined wheels constructor is activated.\n";
		setPsi(newPsi);
		setRadi(newRadius);
		setFlat(newFlat);
	}

Wheels::~Wheels(){
//	cout<<"Class 'Wheels' has been destroyed.\n";
}

void Wheels::setPsi(int newPsi)
{
	psi=0;
	if (newPsi >= 0)
	{
//		cout<<"Set to: PSI of the wheel = "<<newPsi<<" successfully.\n";
		psi=newPsi;
	}
	else cerr<<"The setter failed. PSI has to be a positive value. PSI=0\n";
}

void Wheels::setRadi(float newRadius)
{
	radius=0;
	if (newRadius >=0)
	{
//		cout<<"Set to: radius of the wheel = "<<newRadius<<" successfully.\n";
		radius=newRadius;
	}
//	else cerr<<"The setter failed. radius has to be a positive value. radius=0\n";

}

void Wheels::setFlat(bool newFlat)
{
//	if (newFlat) cout<<"Set to: there is a flat in the wheel - successfully.\n";
//	else cout<<"Set to: the wheel is great (no flat) - successfully.\n";
	flat=newFlat;
}

bool Wheels::check()
{
	if (flat) cout<<"There is a flat in the wheel.\n";
	else cout<<"Wheel is ready.\n";
	return flat;
}
