#include "menu.h"
using namespace std;

void checkInitSoftware(int x, char* argv1, char* argv2)
{
	if (x!=3)
	{
		cerr<<"The program should get 2 arguments:\n"
		<<"The first argument is a name file for customers.\nThe second argument is a name file for cars.\n";
		exit(1);
	}
}

void mainMenu(Garage* g)
{
	char s[100];
	cout<<"===================================================Garage funds:"<<g->getgFunds()<<"\n";
	cout<<"Hello! Welcome to the garage!\nPlease select what you want to do:\n"<<
	"[1] Choose a customer from the list and check his car.\n"<<
	"[2] Show a list of the Checked-in cars, and then fix one of it.\n"<<
	"[3] Show a list of the Checked-in customers, and fix one of the customers' car.\n"<<
	"[4] Quit the program.\n";
	while(1)
	{
		cin>>s;
		if (atoi(s)==1 || atoi(s)==2 || atoi(s)==3 || atoi(s)==4) break;
		cout<<"Wrong input! Please try again:";
	}
	if (atoi(s)==1) option1(g);			//NEED TO WORK ON IT
	if (atoi(s)==2) option2(g);
	if (atoi(s)==3) option3(g);	
	if (atoi(s)==4) return;			//this works fine
}

void option1(Garage* g)
{
	int i=0;
	int x;
	customerList* tmp = g->getCustomersList();
	if (tmp == 0)
	{
		cout<<"The customers List is empty, you will be back to main-menu.\n";
		goto endOption1;
	}
	cout<<"Index:\tName:\tID:\t\tFunds:\n";
	while (tmp != NULL)
	{
		cout<<"["<<i<<"]\t"<<tmp->data->getName()<<"\t"<<tmp->data->getID()<<"\t"<<tmp->data->getFunds()<<"\n";
		tmp=tmp->next;
		i++;
	}
	cout<<"Please select the customer you want to check his car:";
	
	tryagain1:
	cin>>x;
	if (x < i && x >= 0)
	{
		tmp=g->getCustomersList();
		while (x > 0)
		{
			tmp=tmp->next;
			x--;
		}
		if (tmp->data->getCar() == NULL)
		{
			cerr<<"The customer "<<tmp->data->getName()<<" - "<<tmp->data->getID()<<" doesnt have a car.\n";
			goto endOption1;
		}
		
		if (tmp->data->getCar()->countMalfunction() == 0)
		{
			cerr<<"The car of "<<tmp->data->getName()<<" - "<<tmp->data->getID()<<" doesnt need a repair.\n";
			goto endOption1;
		}
		else
		{
			cout<<"Do you want to send the car to the garage?\n";
			cout<<"It will cost you:"<<g->calculatePrice(tmp->data->getCar())<<" Funds.\n0=NO, 1=YES\n";
			while(1)
			{
				cin>>x;
				if (x==0)
				{
					cout<<"OK. as you wish. you will be return to main-menu.\n";
					break;
				}
				else if (x==1)
				{
					if (tmp->data->getCar()->getInShop() == 1)
					{
						cerr<<"This car of the customer is already in the garage.\n";
						break;
					}
					else if (tmp->data->getFunds() >= g->calculatePrice(tmp->data->getCar()))
					{
						g->checkInCar(tmp->data->getCar());
						g->checkInCustomer(*tmp->data);
						break;
					}
					else
					{
						cout<<"The customer "<<tmp->data->getName()<<" "<<tmp->data->getID()<<" Does not have enough money.\n";
						break;
					}
				}
				cerr<<"Your input is wrong. Please try again:";
			}
		}
	}
	else
	{
		cerr<<"This index is not exist. Please try again:";
		goto tryagain1;
	}
	endOption1:
	mainMenu(g);	
	
}

void option2(Garage* g)
{
	int i=0;
	int x;
	carList* tmp = g->getcarList();
	if (tmp == 0)
	{
		cout<<"The car-List is empty, you will be back to main-menu.\n";
		goto endOption2;
	}
	cout<<"Index:\tModel:\tBrand:\n";
	while (tmp != NULL)
	{
		cout<<"["<<i<<"]\t"<<tmp->data->getModel()<<"\t"<<tmp->data->getBrand()<<"\n";
		tmp=tmp->next;
		i++;
	}
	cout<<"Please select the car you want to fix:";
	tryagain2:
	cin>>x;
	if (x < i && x >= 0)
	{
		tmp = g->getcarList();
		while ( x > 0)
		{
			tmp=tmp->next;
			x--;
		}
		
		customerList* tmp2 = g->getCheckedInCustomers();
		while (tmp2 != NULL)
		{
			if (strcmp(tmp2->data->getID() , tmp->data->getOwner()) ==0 ) break;
			tmp2 = tmp2->next;
		}
		tmp2->data->setCar(tmp->data);
		g->checkOut(tmp2->data);
	}
	else
	{
		cerr<<"This index is not exist. Please try again:";
		goto tryagain2;
	}
	endOption2:	
	mainMenu(g);
}


void option3(Garage* g)
{
	int i=0;
	int x;
	customerList* tmp = g->getCheckedInCustomers();
	if (tmp == 0)
	{
		cout<<"The Checked-IN customers List is empty, you will be back to main-menu.\n";
		goto endOption3;
	}
	cout<<"Index:\tName:\tID:\t\tFunds:\n";
	while (tmp != NULL)
	{
		cout<<"["<<i<<"]\t"<<tmp->data->getName()<<"\t"<<tmp->data->getID()<<"\t"<<tmp->data->getFunds()<<"\n";
		tmp=tmp->next;
		i++;
	}
	cout<<"Please select the customer you want to fix his car:";
	tryagain3:
	cin>>x;
	if (x < i && x >= 0)
	{
		tmp=g->getCheckedInCustomers();
		while (x > 0)
		{
			tmp=tmp->next;
			x--;
		}
		carList* tmpCar = g->getcarList();
		while (tmpCar != NULL)
		{
		if (strcmp(tmpCar->data->getOwner() ,tmp->data->getID()) ==0) break;
			tmpCar=tmpCar->next;
		}
		tmp->data->setCar(tmpCar->data);
		g->checkOut(tmp->data);
	}
	else
	{
		cerr<<"This index is not exist. Please try again:";
		goto tryagain3;
	}
	
	endOption3:
	mainMenu(g);
}
