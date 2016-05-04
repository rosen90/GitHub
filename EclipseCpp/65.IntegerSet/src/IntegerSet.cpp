
#include "IntegerSet.h"
#include <iostream>
using namespace std;

int IntegerSet::set[100];
IntegerSet::IntegerSet()
{

}

void IntegerSet::insertElement(int number)
{
	if (number >= 0 && number < 100)
	{
		set[number] = 1;
	}
}

void IntegerSet::deleteElement(int number)
{
	if (number >= 0 && number < 100)
	{
		set[number] = 0;
	}
}

void IntegerSet::printSet()
{
	for (int i = 0; i < 100; i++)
	{
		cout << set[i] << " " ;
	}

}



bool IntegerSet::isEmpty(){
    for(int i = 0 ; i < 100 ; i++) {
        if(set[i] == 1) {
            return false;
        }
    }
    return true;
}





IntegerSet::~IntegerSet() {
    delete[] set;
}
