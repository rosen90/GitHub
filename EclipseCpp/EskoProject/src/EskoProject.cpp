#include <iostream>
#include "Dog.h"


using namespace std;

void printInfo(Dog);

int main() {

	Dog dog1(5, "Hyski", true);
	Dog dog2(3, "Hyski", false);
	dog1.SetName("Bobi");
	dog2.SetName("Alex");

	dog1.dogVoice();
	dog2.dogVoice();

	dog1.fuck(dog2);


	cout << "Is " << dog2.GetName() <<  " Pregnant " << boolalpha << dog2.isIsPregnant() << endl;

	//printInfo(dog1);



	return 0;
}

void printInfo(Dog doggy)
{
	cout << "Name: " << doggy.GetName() << endl;
	cout << "Age: " << doggy.getAge() << endl;
	cout << "Type: " << doggy.getType() << endl;
	cout << "Gender: " << boolalpha << doggy.getGender() << endl;
}
