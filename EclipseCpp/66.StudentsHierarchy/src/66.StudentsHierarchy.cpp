#include <iostream>
#include "Student.h"
#include "GraduateStudent.h"
using namespace std;

int main()
{
	Student uchenik1;

	Student uchenik2("Rosen", "Karadinev", 6);

	uchenik1.printStudentInfo();
	uchenik2.printStudentInfo();

	uchenik1.setFirstName("Pesho");
	uchenik1.setLastName("Ivanov");
	uchenik1.setYearOfStudy(4);

	uchenik1.printStudentInfo();

	GraduateStudent zavurshilUchenik;

	zavurshilUchenik.setFirstName("Jordan");
	zavurshilUchenik.setLastName("Jordanov");
	zavurshilUchenik.setYearOfStudy(5);
	zavurshilUchenik.setGpa(4.56);

	zavurshilUchenik.printInfo();





	return 0;
}
