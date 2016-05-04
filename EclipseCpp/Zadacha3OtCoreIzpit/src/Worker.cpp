/*
 * Worker.cpp
 *
 *  Created on: Aug 21, 2014
 *      Author: Rosen
 */

#include "Worker.h"

Worker::Worker()
{
	name = "";
	middleName = "";
	familyName = "";
	EGN = "";
	address = "";
	phoneNumber = 0;
	gender = "";

}

Worker::Worker(string wName, string wMidName, string wFamName,
		string wEGN, string wAddress, int wPhoneNumber, string wGender)
		:name(wName),
		 middleName(wMidName),
		 familyName(wFamName),
		 EGN(wEGN),
		 address(wAddress),
		 phoneNumber(wPhoneNumber),
		 gender(wGender)
{


}

Worker::~Worker() {
	// TODO Auto-generated destructor stub
}

const string& Worker::getAddress() const {
	return address;
}

void Worker::setAddress(const string& address) {
	this->address = address;
}

const string& Worker::getEgn() const {
	return EGN;
}

void Worker::setEgn(const string& egn) {
	EGN = egn;
}

const string& Worker::getFamilyName() const {
	return familyName;
}

void Worker::setFamilyName(const string& familyName) {
	this->familyName = familyName;
}

const string& Worker::getGender() const {
	return gender;
}

void Worker::setGender(const string& gender) {
	this->gender = gender;
}

const string& Worker::getMiddleName() const {
	return middleName;
}

void Worker::setMiddleName(const string& middleName) {
	this->middleName = middleName;
}

const string& Worker::getName() const {
	return name;
}

void Worker::setName(const string& name) {
	this->name = name;
}

int Worker::getPhoneNumber() const {
	return phoneNumber;
}

void Worker::setPhoneNumber(int phoneNumber) {
	this->phoneNumber = phoneNumber;
}
