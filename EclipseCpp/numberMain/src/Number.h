#ifndef NUMBER_H_
#define NUMBER_H_

class Number 
{
public:
	Number();
	
	virtual ~Number();
	int getNumber() const;
	void setNumber();

private:
	int number;
};

#endif /* NUMBER_H_ */
