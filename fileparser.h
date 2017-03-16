#ifndef fileparser
#define fileparser
#include <iostream>
#include <cstring>
#include "linklists.h"
#include "stdlib.h"
#include "linklists.h"
#include "car.h"
#include "customer.h"
using namespace std;

class FileParser
{
	FILE* fp;
	public:
		FileParser();			//Default fileparser constructor.
		~FileParser();			//fileparser destructor.
		int CountLines(const char* txt);	//counts the lines of the file.
		customerList* parseCustomerFile(const char* txt);	//returns a list of all the customers from the file.
		carList* parseCarFile(const char* txt);		//returns a list of all the cars from the file.
		bool setFile(const char* txt);	//opens a file.
		bool stringToBool(char* str);	//converts a string to a bool type.
};

#endif
