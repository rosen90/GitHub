///*
// * Exerciese8.cpp
// *
// *  Created on: 6.09.2014 �.
// *      Author: �����
// */
//
//#include <iostream>
//#include <list>
//#include <algorithm>
//#include<set>
//#include <iterator>
//
//using namespace std;
//
//int main() {
//	int array[] = { 4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2 };
//	list<int> presentsNums(array, array + 11);
//	set<int> uniqueNums(array, array + 11);
//	set<int>::iterator it;
//	for (it = uniqueNums.begin(); it != uniqueNums.end(); it++) {
//		if (count(array, array + 11, *it) % 2 == 1) {
//			presentsNums.remove(*it);
//		}
//	}
//	ostream_iterator<int> out(cout, " ");
//	copy(presentsNums.begin(), presentsNums.end(), out);
//
//	return 0;
//}
//
