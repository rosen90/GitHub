#ifndef PACKAGE_H_
#define PACKAGE_H_

#include <string>

using namespace std;

class Package
{
public:
	Package();
	Package(string, string, string, string, string, string, string, string,
			int, int, double, double);
	virtual ~Package();
	double getCostPerOunce() const;
	void setCostPerOunce(double costPerOunce);
	const string& getRecAdress() const;
	void setRecAdress(const string& recAdress);
	const string& getRecCity() const;
	void setRecCity(const string& recCity);
	const string& getRecName() const;
	void setRecName(const string& recName);
	const string& getRecState() const;
	void setRecState(const string& recState);
	int getRecZip() const;
	void setRecZip(int recZip);
	const string& getSendAdress() const;
	void setSendAdress(const string& sendAdress);
	const string& getSendCity() const;
	void setSendCity(const string& sendCity);
	const string& getSendName() const;
	void setSendName(const string& sendName);
	const string& getSendState() const;
	void setSendState(const string& sendState);
	int getSendZip() const;
	void setSendZip(int sendZip);
	double getWeight() const;
	void setWeight(double weight);

	virtual double calculateCost() = 0;

private:

	string sendName;
	string recName;

	string sendAddress;
	string recAddress;

	string sendCity;
	string recCity;

	string sendState;
	string recState;

	int sendZip;
	int recZip;

	double weight;
	double costPerOunce;



};

#endif
