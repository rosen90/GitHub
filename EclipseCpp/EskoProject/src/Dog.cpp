#include "Dog.h"


Dog::Dog()
{
}

Dog::Dog(int dogAge, string dogType, bool dogGender) {

	this->age = dogAge;
	this->type = dogType;
	this->gender = dogGender;
	this->name = "Unnamed";

}

int Dog::getAge()
{
	return age;
}

void Dog::setAge(int newAge)
{
	this->age = newAge;
}

string Dog::getType()
{
	return type;
}

void Dog::setType(string newType)
{
	this->type = newType;
}

bool Dog::getGender()
{
	return gender;
}

void Dog::setGender(bool newGender)
{
	this->gender = newGender;
}

string Dog::GetName()
{
	return name;
}

void Dog::SetName(string newName)
{
	this->name = newName;
}

void Dog::dogVoice()
{
	cout << "Bau Bau" << endl;
}

void Dog::fuck(Dog doggy)
{
	if(doggy.gender == false)
	{
		doggy.SetIsPregnant(true);
	}
	else
	{
		cout << "Your dog is gay!!" << endl;
		doggy.SetIsPregnant(false);
	}
}


Dog::~Dog() {

}

bool Dog::isIsPregnant() const {
	return isPregnant;
}

void Dog::SetIsPregnant(bool isPregnant) {
	this->isPregnant = isPregnant;
}
