
#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <string>
#include <vector>

#include "Car.h"

using namespace std;

class Functions {
public:
	Functions();

	void loadDataFromFile();
	void addStudent();
	void deleteStudent();
	void displayStudentData();
	void displayAverageScore();
	void saveAndExit();

private:
	vector<Car> cars;
};

#endif /* FUNCTIONS_H_ */
