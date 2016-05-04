#ifndef BALANCE_H_
#define BALANCE_H_

class Balance
{
public:

	Balance(int);

	int getCredit() const;
	void calculateWin(int, int, const int[][11]);

	void setCredit();
	void setFirstCredit(int);
	void setBet(int);
	int getBet();
	virtual ~Balance();

private:

	int credit;
	int bet;
};

#endif
