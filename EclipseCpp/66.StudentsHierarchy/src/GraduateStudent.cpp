/*
 * GraduateStudent.cpp
 *
 *  Created on: Aug 12, 2014
 *      Author: Rosen
 */

#include "GraduateStudent.h"

GraduateStudent::GraduateStudent()
{
	this->GPA = 0;
}

GraduateStudent::GraduateStudent(double gpa)
{
	this->setGpa(gpa);
}


double GraduateStudent::getGpa() const {
	return GPA;
}

void GraduateStudent::setGpa(double gpa) {
	this->GPA = gpa;
}

void GraduateStudent::printInfo()
{
	Student::printStudentInfo();
	cout << "GPA: " << getGpa();

};

GraduateStudent::~GraduateStudent() {
	// TODO Auto-generated destructor stub
}
