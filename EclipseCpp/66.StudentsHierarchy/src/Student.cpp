/*
 * Student.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: Rosen
 */

#include "Student.h"

Student::Student() // default constructor
{
	this->firstName = "";
	this->lastName = "";
	this->yearOfStudy = 0;
}

Student::Student(string firstName, string lastName, int yearOfStudy)
{
	this->setFirstName(firstName);
	this->setLastName(lastName);
	this->setYearOfStudy(yearOfStudy);

}



string Student::getFirstName() const
{
	return this->firstName;
}

void Student::setFirstName(const string& firstName)
{
	this->firstName = firstName;
}

string Student::getLastName() const
{
	return lastName;
}

void Student::setLastName(const string& lastName)
{
	this->lastName = lastName;
}

int Student::getYearOfStudy() const
{
	return yearOfStudy;
}

void Student::setYearOfStudy(int yearOfStudy)
{
	this->yearOfStudy = yearOfStudy;
}

void Student::printStudentInfo()
{
	cout << "Student: " << getFirstName() << " " << getLastName() << endl;
	cout << "Year: " << getYearOfStudy() << endl;
}

Student::~Student() {
	// TODO Auto-generated destructor stub
}
