#ifndef WORKER_H_
#define WORKER_H_

#include <string>
using namespace std;

class Worker
{
public:
	Worker();
	Worker(string, string, string, string, string, int, string);
	virtual ~Worker();
	const string& getAddress() const;
	void setAddress(const string& address);
	const string& getEgn() const;
	void setEgn(const string& egn);
	const string& getFamilyName() const;
	void setFamilyName(const string& familyName);
	const string& getGender() const;
	void setGender(const string& gender);
	const string& getMiddleName() const;
	void setMiddleName(const string& middleName);
	const string& getName() const;
	void setName(const string& name);
	int getPhoneNumber() const;
	void setPhoneNumber(int phoneNumber);

	double calculateSalary();

private:
	string name;
	string middleName;
	string familyName;
	string EGN;
	string address;
	int phoneNumber;
	string gender;

};

#endif /* WORKER_H_ */
