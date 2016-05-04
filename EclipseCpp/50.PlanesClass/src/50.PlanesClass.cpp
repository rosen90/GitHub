//Да се напише клас „Airplane”. Всеки самолет има производител,
//модел, година на производство, среден разход на гориво при полет
//по посока на вятъра и среден разход на гориво при полет срещу вятъра.
//Да се реализират полетата на класа, set и get методи, конструктор по
//подразбиране и поне още един конструктор. Да се реализира метод за
//изчисление на изразходеното гориво за полет по посока на вятъра по подадени
//километри. Да се реализира метод за изчисление на изразходеното гориво за
//полет срещу вятъра по подадени километри. Да се реализира тестово приложение
//(driver class) където да се създадат няколко самолета. Използвайки
//разписаните методи и въведени от клавиатурата километри да се
//изчисли изразходеното гориво за двата типа полети за всеки самолет.

#include <iostream>
#include "Plane.h"
using namespace std;

int main()
{

	string maker;
	cout << "maker: ";
	getline(cin, maker);

	string model;
	cout << "model: ";
	getline(cin, model);

	int year;
	cout << "year: ";
	cin >> year;

	Plane plane1(maker, model, year);

	cout << "plane 2 maker: ";
	getline(cin, maker);

	cout << "plane 2 model: ";
	getline(cin, model);

	cout << "plane 2 year: ";
	cin >> year;

	Plane plane2(maker, model, year);

	int kilometers;
	cout << "How long is the distance for plane 1 <km>: ";
	cin >> kilometers;

	char direction;
	cout << "Against the wind? y/n: ";
	cin >> direction;

	cout << endl << endl;

	cout << "The plane of " << plane1.getMaker() << " model: " << plane1.getModel() << " witch was made in "
			<< plane1.getYear() << " will cost " << plane1.costFuel(kilometers, direction);





	return 0;
}
