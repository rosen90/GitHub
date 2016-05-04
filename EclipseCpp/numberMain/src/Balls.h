#ifndef BALLS_H_
#define BALLS_H_

#include "Number.h"

class Balls {
public:
	Balls();

	void fillPick();
	void printPicks();

	virtual ~Balls();
private:
	int Pick[20];
	Number numb;
};

#endif /* BALLS_H_ */
