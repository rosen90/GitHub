#include <iostream>
using namespace std;

template<typename T>
bool isEqualTo(T, T);

int main()
{

	int num1 = 5, num2 = 6;

	double num3 = 5.4, num4 = 5.4;
	string name = "Rosen", name2 = "Ivan";

	cout << boolalpha << isEqualTo(num1, num2) << endl;

	cout << boolalpha << isEqualTo(num3, num4) << endl;

	cout << boolalpha << isEqualTo(name, name2) << endl;


	return 0;
}

template<typename T>
bool isEqualTo(T object1, T object2)
{
	return object1 == object2;
}
