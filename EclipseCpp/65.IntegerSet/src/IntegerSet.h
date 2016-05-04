#include <iostream>

using namespace std;

#ifndef INTEGERSET_H_
#define INTEGERSET_H_

class IntegerSet
{
	public:
		IntegerSet();
		void unionOfSets();
		void intersectionOfSets();
		void insertElement(int);
		void deleteElement(int);
		void printSet();
		void isEqualTo();
		bool isEmpty();
		~IntegerSet();

	private:

		static int set[100];

};

#endif /* INTEGERSET_H_ */
