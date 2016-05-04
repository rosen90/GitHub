// (Sales Commissions) Use a one-dimensional array to solve the
//following problem: A company pays its salespeople on a commission
//basis. The salespeople receive $200 per week plus 9% of their gross
//sales for that week. For example, a salesperson who grosses $5000 in
//sales in a week receives $200 plus 9% of $5000, or a total of $650.
//Write an application (using an array) that determines how many of the
//salespeople earned salaries in each of the following ranges (assume
//that each salesperson’s salary is truncated to an integer amount):
//a) $200–299 b) $300–399 c) $400–499 d) $500–599 e) $600–699 f) $700–799
//g) $800–899 h) $900–999 i) $1000 and over
//Summarize the results in tabular format.

#include <iostream>

using namespace std;

int main() {
	int salary[10];
	int hard = 200, gross, sum = 0;
	double percent = 0.09;
	int counter2 = 0, counter3 = 0, counter4 = 0, counter5 = 0, counter6 = 0;
	int counter7 = 0, counter8 = 0, counter9 = 0, counter10 = 0;

	for (int i = 0; i <= 9; i++) {
		cout << "Enter Gross: ";
		cin >> gross;
		salary[i] = hard + (percent * gross);
	}

	for (int i = 0; i <= 9; i++) {
		sum += salary[i];

		if (200 < salary[i] && 299 > salary[i]) {
			counter2++;
		}

		if (300 < salary[i] && 399 > salary[i]) {
			counter3++;
		}

		if (400 < salary[i] && 499 > salary[i]) {
			counter4++;
		}

		if (500 < salary[i] && 599 > salary[i]) {
			counter5++;
		}

		if (600 < salary[i] && 699 > salary[i]) {
			counter6++;
		}

		if (700 < salary[i] && 799 > salary[i]) {
			counter7++;
		}

		if (800 < salary[i] && 899 > salary[i]) {
			counter8++;
		}

		if (900 < salary[i] && 999 > salary[i]) {
			counter9++;
		}

		if (salary[i] >= 1000) {
			counter10++;
		}
	}

	cout << "Earnings between 200-299$ are: " << counter2 << endl;
	cout << "Earnings between 300-399$ are: " << counter3 << endl;
	cout << "Earnings between 400-499$ are: " << counter4 << endl;
	cout << "Earnings between 500-599$ are: " << counter5 << endl;
	cout << "Earnings between 600-699$ are: " << counter6 << endl;
	cout << "Earnings between 700-799$ are: " << counter7 << endl;
	cout << "Earnings between 800-899$ are: " << counter8 << endl;
	cout << "Earnings between 900-999$ are: " << counter9 << endl;
	cout << "Earnings of 1000 and more $ are: " << counter10 << endl;
	cout << "Total earnings are: " << sum << endl;
	return 0;
}

