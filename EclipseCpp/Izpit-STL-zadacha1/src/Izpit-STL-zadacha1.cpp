//Да се направи малка система за фирма за коли под наем. Да се реализира меню със следните опции..
//Rosen Karadinev

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cctype>
#include <cstdlib>
#include "Car.h"
#include <vector>

using namespace std;

void writeCarToFile(fstream &, vector<Car> &);
void createCar(vector<Car>&, int );
void listCars( fstream &, int);
void searchBrand(fstream &, int);
void searchCost(fstream &, int);
int menu( void );


int main()
{

	cout << "How many cars you company will have? : ";
	int cars;
	cin >> cars;

	int choice;

	vector<Car> storeCars;
	fstream file("Cars.txt", ios::in | ios::out);

	if ( !file )
	{
		cerr << "File could not be opened.\n";
		exit( 1 );
	}


	while ( ( choice = menu() ) != 6 )
	{
		switch(choice)
		{
		case 1: createCar(storeCars, cars); break;
		case 2: writeCarToFile(file, storeCars); break;
		case 3: listCars(file, cars); break;
		case 4: searchBrand(file, cars); break;
		case 5: searchCost(file, cars); break;
		}
	}


	return 0;
}


void createCar( vector<Car> &store, int cars )
{
	Car temp;

	int number;
	string brand;
	string model;
	int year;
	double cost;
	string color;

	cout << "Enter the number of current car (0 - " << cars <<", -1 to end input): ";
	cin >> number;

	while(number != -1)
	{
		cout << "Enter the car brand: ";
		cin.ignore();
		getline(cin, brand);

		temp.setBrand(brand);
		temp.setCarNumber(number);

		cout << "Car model: ";
		getline(cin, model);
		temp.setModel(model);

		cout <<"Car year: ";
		cin >> year;
		temp.setYear(year);

		cout <<"Cost per 100/km: ";
		cin >> cost;
		temp.setCostPerKm(cost);

		cout<< "Car Color: ";
		cin >> color;
		temp.setColor(color);

		store.push_back(temp);

		cout << "Enter the number of next car (0 -" << cars <<", -1 to end input): ";
		cin >> number;
	}
}


void writeCarToFile(fstream &fRef, vector<Car> &store)
{
	for(unsigned int i = 0; i < store.size(); i++)
	{
		fRef.seekp(i * sizeof(Car));
		fRef.write( reinterpret_cast< char * >( &store[i] ), sizeof( Car ));
	}

	cout << "The cars are successfuly write!" << endl;
}

void listCars( fstream &fRef, int cars )
{
	Car temp;

	cout << left << setw(10) << "№"  << left
		<< setw(20) << "   Brand" << left
		<< setw(20) << "  Model" << left << setw(20) << "  Year"
		<< left << setw(20) << "Fuel Cost" << left << setw(20) << "  Color"<< endl;

	for(int count = 0; count < cars && !fRef.eof(); count++)
	{

		fRef.seekg(count * sizeof(Car));
		fRef.read(reinterpret_cast<char *>(&temp), sizeof(Car));


		if(temp.getCarNumber() >= 0 && temp.getCarNumber() < 100)
		{

			cout << left << setw(10) << temp.getCarNumber() << left
				<< setw(20) << temp.getBrand() << left
				<< setw(20) << temp.getModel() << left
				<< setw(20) <<  temp.getYear() << left
				<< setw(20) << temp.getCostPerKm() << left
				<< setw(20) << temp.getColor()<< '\n';
		}
	}
}

int menu()
{
	int choice;

	cout << "\nMenu:" << endl;
	cout << "1  Create a car." << endl;
	cout << "2. Write all cars to file. " << endl;
	cout << "3. List all cars." << endl;
	cout << "4  Search per brand." << endl;
	cout << "5. Search per cost." << endl;
	cout << "6  End program.\n";

	do
	{
		cout << "? ";
		cin >> choice;
	}
	while(choice < 1 || choice > 6);

	return choice;
}

void searchBrand(fstream &fRef, int cars)
{

	string brand;

	cout << "Write the brand name of car: ";
	cin >> brand;

	Car temp;

	for (int count = 0; count < cars && !fRef.eof(); count++)
	{

		fRef.seekg(count * sizeof(Car));
		fRef.read(reinterpret_cast<char *>(&temp), sizeof(Car));

		if (brand == temp.getBrand())
		{

			cout << left << setw(10) << "№"  << left
					<< setw(20) << "   Brand" << left
					<< setw(20) << "  Model" << left << setw(20) << "  Year"
					<< left << setw(20) << "Fuel Cost" << left << setw(20) << "  Color"<< endl;

			cout << fixed << showpoint;

			cout << left << setw(10) << temp.getCarNumber() << left
				<< setw(20) << temp.getBrand() << left
				<< setw(20) << temp.getModel() << left
				<< setw(20) <<  temp.getYear() << left
				<< setw(20) << temp.getCostPerKm() << left
				<< setw(20) << temp.getColor()<< '\n';
		}
	}
}

void searchCost(fstream &fRef, int cars)
{

	double cost;
	cout << "Write the average cost per 100 km for cars: ";
	cin >> cost;

	Car temp;
	double minimalCost;
	for (int count = 0; count < cars && !fRef.eof(); count++)
	{

		fRef.seekg(count * sizeof(Car));
		fRef.read(reinterpret_cast<char *>(&temp), sizeof(Car));
		if (minimalCost == cost) {
			break;
		}
		if (minimalCost < temp.getCostPerKm())
		{
			minimalCost = temp.getCostPerKm();
		}

		for (int count = 0; count < cars && !fRef.eof(); count++)
		{

			fRef.seekg(count * sizeof(Car));
			fRef.read(reinterpret_cast<char *>(&temp), sizeof(Car));

			if (minimalCost == temp.getCostPerKm())
			{

				cout << left << setw(10) << "№"  << left
					<< setw(20) << "   Brand" << left
					<< setw(20) << "  Model" << left << setw(20) << "  Year"
					<< left << setw(20) << "Fuel Cost" << left << setw(20) << "  Color"<< endl;

				cout << fixed << showpoint;

			cout << left << setw(10) << temp.getCarNumber() << left
				<< setw(20) << temp.getBrand() << left
				<< setw(20) << temp.getModel() << left
				<< setw(20) <<  temp.getYear() << left
				<< setw(20) << temp.getCostPerKm() << left
				<< setw(20) << temp.getColor()<< '\n';
				break;
			}
		}
	}
}
