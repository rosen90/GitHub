#include "Worker.h"
#ifndef TREEWORKER_H_
#define TREEWORKER_H_

class TreeWorker : public Worker
{
public:
	TreeWorker();
	TreeWorker(string, string, string, string, string, int, string,double, int, bool);
	virtual ~TreeWorker();
	double getBonus() const;
	void setBonus(double bonus);
	double getStavkaForTree() const;
	void setStavkaForTree(double stavkaForTree);
	int getWorkedTrees() const;
	void setWorkedTrees(int workedTrees);

	double calculateSalary();
	bool isInTown() const;
	void setInTown(bool inTown);

private:
	double stavkaForTree;
	int workedTrees;
	double bonus;
	bool inTown;
};

#endif
