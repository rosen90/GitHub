#ifndef BALANCE_H_
#define BALANCE_H_

class Balance
{
public:


	Balance();

	int getCredit() const;
	void calculateWin(int, int, const int[][11]);

	virtual ~Balance();
	void setCredit();

private:
//	int numbersOfSpot;
//	int hits;
	int credit;

};

#endif
