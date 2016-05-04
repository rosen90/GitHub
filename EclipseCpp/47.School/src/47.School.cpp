//1. We are given a school. In the school there are classes of
//students. Each class has a set of teachers. Each teacher
//teaches a set of disciplines. Students have name and
//unique class number. Classes have unique text
//identifier. Teachers have name and title. Disciplines
//have name, number of lectures and number of
//exercises.
//2. Define C++ classes for the school (School, Class,
//Student, Teacher, Discipline). Keep the member fields
//private. Add constructors and accessor methods. Write
//a testing class to construct and print a sample school.

#include <iostream>
#include <string>
#include "School.h"
#include "Student.h"
#include "Classes.h"
#include "Teacher.h"
#include "Discipline.h"
using namespace std;

int main()
{

	string schoolName;
	cout << "Enter School name: ";
	cin >> schoolName;

	string classIdentifier;
	cout << "Enter class identifier: ";
	cin >> classIdentifier;

	string studenftName;
	cout << "Student name: ";
	cin >> studenftName;

	int studentNumber;
	cout << "Student number: ";
	cin >> studentNumber;

	string teacherName;
	cout << "Teacher name: ";
	cin >> teacherName;

	string teacherTitle;
	cout << "Teacher Title: ";
	cin >> teacherTitle;

	string disciplineName;
	cout << "Enter discipline Name: ";
	cin >> disciplineName;

	int disciplineLectures;
	cout << "How many Lectures: ";
	cin >> disciplineLectures;

	int disciplineExercises;
	cout << "How many Exercises: ";
	cin >> disciplineExercises;


	School school1(schoolName);
	Classes class1(classIdentifier);
	Student student1(studenftName, studentNumber);
	Teacher teacher1(teacherName, teacherTitle);
	Discipline discipline1(disciplineName, disciplineLectures, disciplineExercises);

	cout << endl << endl;

	cout << "In a long long time ago... in distant galaxy there is a school named " << school1.getSchoolName()
			<< " and in this school there is a class " << class1.getClass() << " the teacher of the class was "
			<< teacher1.getTeacherName() << " who was teaching the student " << student1.getStudentName()
			<< " he was studying " << discipline1.getDiscliplineName() << " with " << discipline1.getLectures()
			<< " Lectures and " << discipline1.getExercises();

	return 0;
}
