#include <iostream>
#include <stdlib.h>
#include "menu.h"
using namespace std;

//All rights reserved to ®Yoav Saroya - 304835887

int main (int argc, char* argv[])
{
	checkInitSoftware(argc, argv[1], argv[2]);		//checks the initialization of the software.
	Garage* myGarage = new Garage;
	FileParser filer;
	
	customerList* cusList = filer.parseCustomerFile(argv[1]);	//argv[1] - "Customers.txt"
	carList* caList = filer.parseCarFile(argv[2]);				//argv[2] - "Cars.txt"
	customerList* tmp = cusList;
	carList* tmp2 = caList;	
	while (tmp != NULL)		//attributes the cars to the customers.
	{
		tmp2 = caList;
		while (tmp2 != NULL)
		{
			if (strcmp(tmp->data->getID(), tmp2->data->getOwner()) ==0)
				tmp->data->assignCar(*tmp2->data);
			tmp2=tmp2->next;
		}
		tmp=tmp->next;
	}
	tmp = cusList;			//adds all the customers from the file to the customers-list of the garage.
	while (tmp != NULL)
	{
		myGarage->addCustomer(tmp->data);
		tmp=tmp->next;
	}
	
	mainMenu(myGarage);		//enter the menu of the garage.
	
	delete myGarage;
	
	return 0;
}
