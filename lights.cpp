#include <iostream>
#include "lights.h"
using namespace std;


Lights::Lights(bool b)
{
//	cout<<"The default lights constructor is activated.\n";
	setActive(0);
	setMalfunctionL(b);
}

Lights::~Lights() {
//	cout<<"Class 'Lights' has been destroyed.\n";
}

void Lights::setActive(bool b)
{
//	if (b) cout<<"Set to: the lights are ON - successfully.\n";
//	else cout<<"Set to: the lights are OFF - successfully.\n";
	active=b;
}

void Lights::setMalfunctionL(bool b)
{
//	if (b) cout<<"set to: There is a malfunction - successfully.\n";
//	else cout<<"set to: The lights work perfect (no malfunction) - successfully.\n";
	malfunction=b;
}

void Lights::toggleLights()
{
	if (active)
	{
		active = false;
		cout<<"The lights are off.\n";
	} 
	else
	{
		active = true;
		cout<<"The lights are on.\n";
	}
}
