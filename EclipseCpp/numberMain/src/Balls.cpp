#include "Number.h"
#include "Balls.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Balls::Balls() {
	// TODO Auto-generated constructor stub

}

void Balls::fillPick()
{
	srand(time(0));
	for(int i = 0; i < 20; i++)
	{
		Number numb;

		Pick[i] = numb.getNumber();
		cout << Pick[i] << " ";
	}
}

void Balls::printPicks() {
}

Balls::~Balls() {
	// TODO Auto-generated destructor stub
}

