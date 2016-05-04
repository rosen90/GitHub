#include "TreeWorker.h"

TreeWorker::TreeWorker()
{
	this->stavkaForTree = 0;
	this->workedTrees = 0;
	this->bonus = 0;
	this->inTown = true;

}

TreeWorker::TreeWorker(string name, string middleName, string familyName, string EGN, string address,
		int phoneNumber, string gender, double stavkaForTree, int workedTrees, bool inTown)
		: Worker(name, middleName, familyName, EGN, address, phoneNumber, gender)
{
	setStavkaForTree(stavkaForTree);
	setWorkedTrees(workedTrees);
	setInTown(inTown);

}

TreeWorker::~TreeWorker() {
	// TODO Auto-generated destructor stub
}

double TreeWorker::getBonus() const {
	return bonus;
}

void TreeWorker::setBonus(double bonus) {
	this->bonus = bonus;
}

double TreeWorker::getStavkaForTree() const {
	return stavkaForTree;
}

void TreeWorker::setStavkaForTree(double stavkaForTree) {
	this->stavkaForTree = stavkaForTree;
}

int TreeWorker::getWorkedTrees() const {
	return workedTrees;
}

void TreeWorker::setWorkedTrees(int workedTrees) {
	this->workedTrees = workedTrees;
}

double TreeWorker::calculateSalary()
{
	if(workedTrees < 150)
	{
		return stavkaForTree * workedTrees * bonus - 250;
	}
	if(workedTrees > 300)
	{
		return stavkaForTree * workedTrees * bonus + 650;
	}

	return stavkaForTree * workedTrees * bonus + 650;
}

bool TreeWorker::isInTown() const
{
	return inTown;
}

void TreeWorker::setInTown(bool inTown)
{
	if(inTown == true)
	{
		this->inTown = inTown;
		bonus = 0.6;
	}
	else
	{
		this->inTown = inTown;
		bonus = 0.3;
	}

}
