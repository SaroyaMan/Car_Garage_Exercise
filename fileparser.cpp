#include "fileparser.h"

using namespace std;

FileParser::FileParser()
{
	fp=NULL;
}

FileParser::~FileParser()
{
	fclose(fp);
}

bool FileParser::stringToBool(char* str)
{
	if (strcmp(str, "false") ==0) return true;
	if (strcmp(str, "true") ==0) return false;
}

int FileParser::CountLines(const char* txt)
{
	int lines=0;
	int ch=0;
	setFile(txt);
	if (fp== NULL) return 0;
	lines++;
	while (!feof(fp))
	{
		ch=fgetc(fp);
		if (ch =='\n') lines++;
	}
	fclose(fp);
	return lines;
}

customerList* FileParser::parseCustomerFile(const char* txt)
{
	int x = CountLines(txt);
	if (x==0)
	{
		cerr<<"The file could not be read.\n";
		return NULL;
	} 
	setFile(txt);
	customerList* customerfileList=NULL;
	Customer* tmp= new Customer[x];
	char* name = new char[30];
	char* sfunds = new char[15];
	float funds=0;
	char*id = new char[30];
	for (int i=0; i<x; i++)
	{
		fscanf(fp, "%s", name);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", id);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", sfunds);
		fgetc(fp);
		funds = atof(sfunds);
		tmp[i].setName(name);
		tmp[i].setID(id);
		tmp[i].setFunds(funds);
		customerfileList = addCustomerToBottom(customerfileList, &tmp[i]);
	}
	cout<<"The file "<<txt<<" scanned successfully.\n";
	return customerfileList;
}

carList* FileParser::parseCarFile(const char* txt)
{
	int x = CountLines(txt);
	if (x==0)
	{
		cerr<<"The file could not be read.\n";
		return NULL;
	} 
	setFile(txt);
	carList* carfileList=NULL;
	Car* tmp= new Car[x];
	
	char* brand = new char[30];
	char* model = new char[30];
	char* owner = new char[15];
	char* booler = new char[10];
	char* tmps = new char[30];
	float volume=0, maxFuel=0, currFuel=0, rad1=0, rad2=0, rad3=0, rad4=0;
	int psi1=0, psi2=0, psi3=0, psi4=0;
	bool lightM, motorM, flat1, flat2,flat3, flat4;
	for (int i=0; i<x; i++)
	{
		fscanf(fp, "%s", brand);
		fgetc(fp);
		fgetc(fp);	
		fscanf(fp, "%s", model);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", booler);
		lightM = stringToBool(booler);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%f", &volume);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%f", &maxFuel);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%f", &currFuel);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", booler);
		motorM = stringToBool(booler);		
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%d", &psi1);		
		fgetc(fp);
		fgetc(fp);		
		fscanf(fp, "%f", &rad1);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", booler);
		flat1= stringToBool(booler);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%d", &psi2);		
		fgetc(fp);
		fgetc(fp);		
		fscanf(fp, "%f", &rad2);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", booler);
		flat2= stringToBool(booler);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%d", &psi3);		
		fgetc(fp);
		fgetc(fp);		
		fscanf(fp, "%f", &rad3);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", booler);
		flat3= stringToBool(booler);		
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%d", &psi4);		
		fgetc(fp);
		fgetc(fp);		
		fscanf(fp, "%f", &rad4);
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", booler);
		flat4= stringToBool(booler);	
		fgetc(fp);
		fgetc(fp);
		fscanf(fp, "%s", owner);		
		fgetc(fp);
		tmp[i].setOwner(owner);
		tmp[i].getLight()->setMalfunctionL(lightM);
		tmp[i].getMotor()->setMalfunctionE(motorM);
		tmp[i].getMotor()->setVolume(volume);
		tmp[i].getMotor()->setMaxFuel(maxFuel);
		tmp[i].getMotor()->setFuel(currFuel);
		tmp[i].getWheel1()->setFlat(flat1);
		tmp[i].getWheel1()->setPsi(psi1);
		tmp[i].getWheel1()->setRadi(rad1);
		tmp[i].getWheel2()->setFlat(flat2);
		tmp[i].getWheel2()->setPsi(psi2);
		tmp[i].getWheel2()->setRadi(rad2);	
		tmp[i].getWheel3()->setFlat(flat3);
		tmp[i].getWheel3()->setPsi(psi3);
		tmp[i].getWheel3()->setRadi(rad3);
		tmp[i].getWheel4()->setFlat(flat4);
		tmp[i].getWheel4()->setPsi(psi4);
		tmp[i].getWheel4()->setRadi(rad4);
		tmp[i].setModel(model);
		tmp[i].setBrand(brand);	
		carfileList = addCarToBottom(carfileList, &tmp[i]);
	}
	cout<<"The file "<<txt<<" scanned successfully.\n";
	return carfileList;	
}

bool FileParser::setFile(const char* txt)
{
	fp = fopen(txt, "r");
	if (fp == NULL)
	{
		cerr<<"The file "<<txt<<" could not be found.\n";
		return false;
	}
	return true;
}
