//============================================================================
// Name        : Domashni.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>
#include <iomanip>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <map>
using namespace std;

//zadacha1
void printSumAndAverageInList();
//printSumAndAverage - calculate sum and average of elements in list;


//zadacha2
void longestSequenceInList(int[], int);
//longestSequenceInList - this function find longest sequence from same numbers in array!
//@param int[] - array elements
//@param int - how many elements in the array;


//zadacha3
void reverseWithStack();
//reverseWithStack - read some numbers from user and print them in reverse order;


//zadacha4
void sequenceUsingQueue();
//sequenceUsingQueue - function to print first 100 elements from a given N;


//zadacha5
void sortWithList();
//sortWithList - function which print sequence of numbers in ascending order with list;


//zadacha6
void elementsPresentInArray(int [], int);
//elementPresentInArray - function which count how much a element is into array;
//@param int [] - passing array elements to function;
//@param int - array size;

//zadacha7
void removeNegativeElements(int [], int);
//removeNegativeElements - function which remove all negative numbers from a given array;
//@param int [] - passing elements of the array to a function;
//@param int - array size;


//zadacha8
void removeOddSequence(int [], int);
//removeOddSequence - remove all elements which are the same and on odd position in array;
//@param int [] - passing array element to function;
//@param int - array size;


//zadacha9
void majorantInArray(int[], int);
//majorantInArray - search through array and return element which is contain in more then a half from the element of the array;
//@param int [] - pass array elements;
//@param int - array size;

//zadacha10
void bestOperations();

//zadacha12
void wordsCount(string);
//wordsCount - function which return how many times each words is found in a text;
//@param string - pass a string to the function;

int main() {
	cout<< fixed<< setprecision(2);

	const int SIZE = 54;
	int arr[SIZE] = {13,58,2,2,2,21,20,2,2,2,11,-8,2,2,2,-7,2,2,2,5,
			-89,2,2,2,50,50,50,50,50,50,15,2,2,2,-4,
			-78,2,15,10,13,58,21,20,11,-8,-7,5,-89,50,15,-4,-78,15,10};

	//zadacha8
	const int ASIZE = 11;
		int a[ASIZE] = {4, 2, 2, 5, 2, 3, 2, 3, 1, 5, 2};

	//zadacha9
	const int MSIZE = 9;
	int m[MSIZE] = {2, 2, 3, 3, 2, 3, 4, 3, 3};


	//zadacha1

//	cout<<"Task 1"<<endl;
//	printSumAndAverageInList();
//	cout<<endl;
//	cout<<endl;



	//zadacha2

//	cout<<"Task 2"<<endl;
//	longestSequenceInList(arr,SIZE);
//	cout<<endl;
//	cout<<endl;



	//zadacha3

//	cout<<"Task 3"<<endl;
//	reverseWithStack();
//	cout<<endl;
//	cout<<endl;



	//zadacha4

//	cout<<"Task 4"<<endl;
//	sequenceUsingQueue();
//	cout<<endl;
//	cout<<endl;


	//zadacha5

//	cout<<"Task 5"<<endl;
//	sortWithList();
//	cout<<endl;
//	cout<<endl;


	//zadacha6

//	cout<<"Task 6"<<endl;
//	elementsPresentInArray(arr, SIZE);
//	cout<<endl;
//	cout<<endl;



	//zadacha7

//	cout<<"Task 7"<<endl;
//	removeNegativeElements(arr, SIZE);
//	cout<<endl;
//	cout<<endl;



	//zadacha8 - ne e napravena!

//	cout<<"Task 8"<<endl;
//	removeOddSequence(a, ASIZE);
//	cout<<endl;
//	cout<<endl;



	//zadacha9

//		cout<<"Task 9"<<endl;
//		majorantInArray(m,MSIZE);
//		cout << endl;
//		cout << endl;



	//zadacha12

//	cout<<"Task 12"<<endl;
//
//	cout<<endl;
//	cout<<endl;
	return 0;
}


//zadacha1
void  printSumAndAverageInList() {
	int sum = 0;
	double average;
	double count = 0;

	list<int> sequence;

	cout<<"Input numbers in list: ";
	int input;
	while(input != 0) {
		cin>>input;
		sequence.push_back(input);
		count++;
	}

	list<int>::iterator it;
	for(it = sequence.begin(); it != sequence.end(); ++it) {
		sum += *it;
	}

	average = sum / (count - 1);

	cout<<"Sum = " << sum << "\nAverage = " <<average <<endl;
}


//zadacha2
void longestSequenceInList(int a[], int size) {
	int temp;
	int count = 0;
	int max = 0;
	int sequence;

	list<int> myList(a,a + size);
	list<int>::iterator it;
	it = myList.begin();

	while(it != myList.end()) {
		temp = *it;
		while((temp == *it) && (it != myList.end())) {
			count++;
			it++;
		}
		if(max < count) {
			max = count;
			sequence = temp;
		}
		count = 0;
	}
	cout<<"Number: "<<sequence <<" Times: "<< max<<endl;
}


//zadacha3
void reverseWithStack(){
	stack<int> myStack;

	cout<<"Input how many integers you want to store: ";
	int numbers;
	cin >> numbers;

	cout<<"Input integers: ";
	int input;
	for(int i = 0; i < numbers; i++){
		cin >> input;
		myStack.push(input);
	}
	while(!myStack.empty()) {
		cout<<" "<<myStack.top();
		myStack.pop();
	}
}


//zadacha4
void sequenceUsingQueue() {
	queue<int> myQueue;


	cout<<"Enter a number: ";
	int N;
	cin >> N;


	myQueue.push(N);
	for(int i = 0; i < 100; i++) {

		myQueue.push(myQueue.front() + 1);
		myQueue.push((2 * myQueue.front()) + 1);
		myQueue.push(2 + myQueue.front());



		cout<<myQueue.front()<<", ";
		myQueue.pop();
	}
}

//zadacha5
void sortWithList() {
	list<int> myList;

	cout<<"Input integers into list: ";
	int input;
	while(input != 0) {
		cin >> input;
		myList.push_back(input);
	}

	myList.sort();
	cout<<"Sorted list: ";
	list<int>::iterator it;
	for(it = myList.begin(); it != myList.end(); ++it) {
		cout << *it <<", ";
	}
}


//zadacha6
void elementsPresentInArray(int a[], int size) {

	map<int,int> myMap;

	for(int i = 0; i < size; i++) {
		if(myMap.find(a[i]) == myMap.end()) {
			myMap.insert(pair<int,int>(a[i], 0));
		}
		myMap[a[i]]++;
	}
	map<int,int>::iterator it;
	for(it = myMap.begin(); it != myMap.end(); ++it) {
		cout<< it->first <<" -> " << myMap[it->first]<<endl;
	}
}

//zadacha7
void removeNegativeElements(int a[], int size) {
	int temp;
	list<int> myList(a,a + size);

	list<int>::iterator it;


	it = myList.begin();
	for(it = myList.begin(); it != myList.end(); ++it) {
		temp = *it;
		if(temp > 0) {
			cout << *it <<", ";
		}
	}
}


//zadacha8
void removeOddSequence(int a[], int size) {

	multiset<int> mySet;
	multiset<int>::iterator it;

	for(int i = 0; i < size; i++) {
		mySet.insert(a[i]);
	}

	for(it = mySet.begin(); it != mySet.end(); ++it){
		cout<<*it <<", ";
	}
}


//zadacha9
void majorantInArray(int a[], int size) {
	int major;

	set<int> mySet(a, a + size);
	set<int>::iterator it;
	list<int> myList(a, a+size);

	for(it = mySet.begin(); it != mySet.end(); ++it){
		if(count(myList.begin(), myList.end(), *it) > (size / 2)) {
			major = *it;
		}
	}
	cout << "Major: " << major;
}
