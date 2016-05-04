#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{

	string companyName;
	string companyAdress;
	int phoneNumber;
	int faxNumber;
	string webSite;

	string managerFirstName;
	string managerSecondName;

	int managerPhoneNumber;

	cout << "Enter the company name: ";
	cin >> companyName;
	system("cls");

	cout << "Enter company adress";
	cin >> companyAdress;
	system("cls");

	cout << "Enter phone number: ";
	cin >> phoneNumber;
	system("cls");

	cout << "Enter fax number: ";
	cin >> faxNumber;
	system("cls");

	cout << "Enter the web site";
	cin >> webSite;
	system("cls");

	cout << "Manager first name: ";
	cin >> managerFirstName;
	system("cls");

	cout << "Manager last name: ";
	cin >> managerSecondName;
	system("cls");

	cout << "Enter the manager phone number: ";
	cin >> managerPhoneNumber;
	system("cls");

	cout << "-----------------------" << endl;
	cout << "Name: " << companyName << endl;
	cout << "Adress: " << companyAdress << endl;
	cout << "Phone Number: " << phoneNumber << endl;
	cout << "Fax Number: " << faxNumber << endl;
	cout << "Website: " << webSite << endl;
	cout << "Manager: " << managerFirstName << " " << managerSecondName << endl;
	cout << "Manager`s phone: " << managerPhoneNumber << endl;
	cout << "----------------------------" << endl;


	return 0;
}
