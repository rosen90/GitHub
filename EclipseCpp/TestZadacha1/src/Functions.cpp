

#include "Functions.h"

Functions::Functions() {

		string firstN, lastN;
		double ex1, ex2, ex3;

		ifstream studentData;
		studentData.open("studentData.txt");     // open the file

		if (studentData.is_open())
		{
			while (studentData >> firstN >> lastN >> ex1 >> ex2 >> ex3)
			{

				Student student(firstN, lastN, ex1, ex2, ex3); // create aStudent object
				entries.push_back(student);
			}
		}
		cout << entries.size() << " Total students entered " << endl << endl;
		studentData.close();

}


