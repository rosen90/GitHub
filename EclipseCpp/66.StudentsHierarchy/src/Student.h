#include <iostream>

using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class Student
{
	public:
		Student();
		Student(string, string, int);
		virtual ~Student();
		string getFirstName() const;
		void setFirstName(const string&);
		string getLastName() const;
		void setLastName(const string&);
		int getYearOfStudy() const;
		void setYearOfStudy(int);
		void printStudentInfo();

	private:
		string firstName;
		string lastName;
		int yearOfStudy;

};

#endif /* STUDENT_H_ */
