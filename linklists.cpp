#include <iostream>
#include <cstring>
#include "linklists.h"
using namespace std;

carList* addCarToBottom(carList* head, Car* newCar)
{
	carList* new_item=NULL;
	new_item = new carList;
	if (new_item==0) exit(1);
	
	new_item->data = newCar;
	new_item->next = NULL;
	
	if (head==0)
		head=new_item;
	
	else
	{
		carList* temp=NULL;
		temp=head;
		while (temp->next != NULL)
			temp= temp->next;
		temp->next=new_item;	
	}
	return head;
}

carList* deleteCar(carList* head, Car* deleteCar)
{
	carList* current = head;
	carList* previus = head;
	if (head==0) return head;
	
	
	if (strcmp(current->data->getBrand(), deleteCar->getBrand()) ==0  && strcmp(current->data->getModel(), deleteCar->getModel()) == 0 && head->next == NULL)
	{
		delete current;
		return NULL;
	}
	
	if (strcmp(current->data->getBrand(), deleteCar->getBrand()) ==0  && strcmp(current->data->getModel(), deleteCar->getModel()) == 0)
	{
		return freeTopCar(head);
	}
	
	while (strcmp(current->data->getBrand(), deleteCar->getBrand()) !=0  && strcmp(current->data->getModel(), deleteCar->getModel()) !=0)
	{
		previus=current;
		current= current->next;
	}
	if (current == 0)
	{
		cout<<"The car has not found in the list.\n";
		return head;
	}
	previus->next=current->next;
	delete current;
	return head;
}

void printCarList(carList* head)
{
	carList* temporary = head;
	if (temporary == 0)
		cout<<"the list is empty\n";
	else
	{
		while (temporary != NULL)
		{
			cout<<temporary->data->getModel()<< ", "<<temporary->data->getBrand()<<"\n";
			temporary = temporary->next;
		}
	}
}

carList* freeTopCar(carList* head)
{
	carList* temp = head;
	head= head->next;
	delete temp;
	return head;
}

carList* freeCarList(carList* head)
{
	while (head != NULL)
		head = freeTopCar (head);
	return head;
}

int listCountCars(carList* head)
{
	int n=0;
	carList* tmp=head;
	while (tmp != NULL)
	{
		n++;
		tmp=tmp->next;
	}
	return n;	
}

customerList* addCustomerToBottom(customerList* head, Customer* newCustomer)
{
	customerList* new_item=NULL;
	new_item = new customerList;
	if (new_item==0) exit(1);
	
	new_item->data = newCustomer;
	new_item->next = NULL;
	
	if (head==0)
		head=new_item;
	
	else
	{
		customerList* temp=NULL;
		temp=head;
		while (temp->next != NULL)
			temp= temp->next;
		temp->next=new_item;	
	}
	return head;
}

customerList* deleteCustomer(customerList* head, Customer* deleteCustomer)
{
	customerList* current = head;
	customerList* previus = head;
	if (head==0) return head;
	
	if (strcmp(current->data->getID() , deleteCustomer->getID()) == 0 && head->next == NULL)
	{
		delete current;
		return NULL;
	}
	
	if(strcmp(current->data->getID() , deleteCustomer->getID()) == 0 )
	{
		return freeTopCustomer(head);
	}
	
	while (strcmp(current->data->getID() , deleteCustomer->getID()) != 0)
	{
		previus=current;
		current= current->next;
	}
	if (current == 0)
	{
		cout<<"The customer has not found in the list.\n";
		return head;
	}
	previus->next=current->next;
	delete current;
	return head;
}

void printCustomerList(customerList* head)
{
	customerList* temporary = head;
	if (temporary == 0)
		cout<<"the list is empty\n";
	else
	{
		while (temporary != NULL)
		{
			cout<<temporary->data->getName()<<", "<<temporary->data->getID()<<"\n";
			temporary = temporary->next;
		}
	}
}

customerList* freeTopCustomer(customerList* head)
{	
	customerList* temp = head;
	head= head->next;
	delete temp;
	return head;
}

customerList* freeCustomerList(customerList* head)
{
	while (head != NULL)
		head = freeTopCustomer (head);
	return head;	
}

int listCountCustomer(customerList* head)
{
	int n=0;
	customerList* tmp=head;
	while (tmp != NULL)
	{
		n++;
		tmp=tmp->next;
	}
	return n;
}
