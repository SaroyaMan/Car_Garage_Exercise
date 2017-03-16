#ifndef menu
#define menu
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include "linklists.h"
#include "car.h"
#include "lights.h"
#include "wheels.h"
#include "engine.h"
#include "customer.h"
#include "garage.h"
#include "fileparser.h"

void checkInitSoftware(int x, char* argv1, char* argv2);	//checkes the initialization of the software.
void mainMenu(Garage* g);
void option1(Garage* g);		//the first option of the menu.
void option2(Garage* g);		//the second option of the menu.
void option3(Garage* g);		//the third option of the menu.


#endif
