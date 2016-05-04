#include "Worker.h"
#include "GrassWorker.h"
#include "TreeWorker.h"

#include <iostream>
using namespace std;

int main()
{
	GrassWorker rabotnik1("Ivan", "Ivanov", "Petrov", "9012214540", "Sofia", 8833323, "male", 0.2, 7000);
	cout << "Grass Worker Salary is " << rabotnik1.calculateSalary() << "$" << endl;

	// Ако работника работи в града, то последния аргумент е 1(true), ако работи извън града тряба да се въведе 0(false)
	// Може да те тества ако 1-цата накрая в конструктора се промени на 0;
	TreeWorker rabotnik2("Nikolai", "Georgiev", "Ivanov", "9014254140", "Plovdiv", 8855323, "male", 10.5, 200, 1);
	cout << "Tree Worker Salary is " << rabotnik2.calculateSalary() << "$" << endl;

}
