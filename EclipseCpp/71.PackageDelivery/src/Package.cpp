#include "Package.h"

Package::Package()
{
	sendName = "";
	recName = "";

	sendAddress = "";
	recAddress = "";

	sendCity = "";
	recCity = "";

	sendState = "";
	recState = "";

	sendZip = 0;
	recZip = 0;

	weight = 0.0;
	costPerOunce = 0.0;

}

Package::Package(string name1, string name2, string address1,
		string address2, string city1, string city2,
		string state1, string state2, int zip1, int zip2,
		double weight, double cost) :
				sendName(name1),
				recName(name2),
				sendAddress(address1),
				recAddress(address2),
				sendCity(city1),
				recCity(city2),
				sendState(state1),
				recState(state2),
				sendZip(zip1),
				recZip(zip2)

{
	setWeight(weight);
	setCostPerOunce(cost);
}


Package::~Package() {
	// TODO Auto-generated destructor stub
}

double Package::getCostPerOunce() const {
	return costPerOunce;
}

void Package::setCostPerOunce(double costPerOunce) {
	this->costPerOunce = costPerOunce;
}

const string& Package::getRecAdress() const {
	return recAddress;
}

void Package::setRecAdress(const string& recAdress) {
	this->recAddress = recAddress;
}

const string& Package::getRecCity() const {
	return recCity;
}

void Package::setRecCity(const string& recCity) {
	this->recCity = recCity;
}

const string& Package::getRecName() const {
	return recName;
}

void Package::setRecName(const string& recName) {
	this->recName = recName;
}

const string& Package::getRecState() const {
	return recState;
}

void Package::setRecState(const string& recState) {
	this->recState = recState;
}

int Package::getRecZip() const {
	return recZip;
}

void Package::setRecZip(int recZip) {
	this->recZip = recZip;
}

const string& Package::getSendAdress() const {
	return sendAddress;
}

void Package::setSendAdress(const string& sendAdress) {
	this->sendAddress = sendAddress;
}

const string& Package::getSendCity() const {
	return sendCity;
}

void Package::setSendCity(const string& sendCity) {
	this->sendCity = sendCity;
}

const string& Package::getSendName() const {
	return sendName;
}

void Package::setSendName(const string& sendName) {
	this->sendName = sendName;
}

const string& Package::getSendState() const {
	return sendState;
}

void Package::setSendState(const string& sendState) {
	this->sendState = sendState;
}

int Package::getSendZip() const {
	return sendZip;
}

void Package::setSendZip(int sendZip) {
	this->sendZip = sendZip;
}

double Package::getWeight() const {
	return weight;
}


void Package::setWeight(double weight)
{
	if(weight > 0)
	{
		this->weight = weight;
	}
	else
	{
		weight = 1;
	}

}

double Package::calculateCost()
{
	return weight * costPerOunce;
}
