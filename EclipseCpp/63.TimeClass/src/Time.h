#ifndef TIME_H_
#define TIME_H_

#include <iostream>

using namespace std;

class Time
{

public:
	Time(); // constructor
	void setTime(int, int, int); // hour, minute, seconds
	void printUniversal(); // print universal time format
	void printStandard(); // print standard time format;

private:
	int hour; // 0-23
	int minute; // 0 - 59
	int second; // 0 - 59
};

#endif /* TIME_H_ */
