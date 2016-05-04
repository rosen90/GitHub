#ifndef GRADUATESTUDENT_H_
#define GRADUATESTUDENT_H_

#include "Student.h"

class GraduateStudent : public Student
{

	public:
		GraduateStudent();
		GraduateStudent(double);
		virtual ~GraduateStudent();
		double getGpa() const;
		void setGpa(double);
		void printInfo();

	private:
		double GPA;

};

#endif /* GRADUATESTUDENT_H_ */
