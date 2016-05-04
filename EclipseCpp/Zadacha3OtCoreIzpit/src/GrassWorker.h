#ifndef GRASSWORKER_H_
#define GRASSWORKER_H_

#include "Worker.h"

class GrassWorker : public Worker
{
public:
	GrassWorker();
	GrassWorker(string, string, string, string, string, int, string, double, int);
	~GrassWorker();
	double getStavka() const;
	void setStavka(double stavka);
	int getWorkedArea() const;
	void setWorkedArea(int workedArea);

	double calculateSalary();

private:
	double stavka;
	int workedArea;
};

#endif
