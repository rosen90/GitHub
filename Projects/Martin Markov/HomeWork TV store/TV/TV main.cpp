//============================================================================
// Name        : TV.cpp
// Author      : Martin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "televisors.h"
#include <fstream>
#include <cstdlib>
#include <sstream>
using namespace std;

int pickChoice();
void addTV(vector<televisors> &);
void saveTV(ofstream& output,vector<televisors>& vect);
void print(ifstream &input);
void findBrand(ifstream& in);
void findInch(ifstream& in);

int main() {

	ofstream out("TV.txt",ios::out);
			if(!out)
			{
				cout<<"file not found";
				return -1;
			}


	ifstream in("TV.txt",ios::in);
	if(!in)
	{
		cout<<"file not found";
		return -1;
	}


	vector<televisors> newTV;
		int choice;
		while((choice = pickChoice()) !=6)
		{
			switch(choice)
			{
			case 1:
				addTV(newTV);
				break;
			case 2:
				saveTV(out,newTV);
				out.close();
				break;
			case 3:
				print(in);
				break;
			case 4:
				findBrand(in);
				break;
			case 5:
				findInch(in);
				break;
			default:cout<<"ERROR"<<endl;
			break;
			}
		}


	return 0;
}
	int pickChoice()
	{
		int number;
		cout<<"��������� 1 �� ��������� �� ��� �����"<<endl;
		cout<<"��������� 2 �� �� �� �������� � ������ �����"<<endl;
		cout<<"��������� 3 �� �� ������ ��������� ������ "<<endl;
		cout<<"��������� 4 �� ����� �� ��������� �� �����"<<endl;
		cout<<"��������� 5 �� ����� �� ��������� �� ������"<<endl;
		cout<<"��������� 6 �� ����� �� ����������"<<endl;
		cin>>number;
		return number;

	}

void addTV(vector<televisors> &myVector)
	{
	string marka;
	string model;
	string cvqt;
	int hertz;
	double inch;


	televisors *TV;
cout<<"���� �������� �����: ";
cin>>marka;
cout<<"���� �������� �����: ";
cin>>model;
cout<<"���� �������� ����: ";
cin>>cvqt;
cout<<"���� �������� �������: ";
cin>>hertz;
cout<<"���� �������� ������: ";
cin>>inch;
cout<<endl;

TV = new televisors;
TV->setBrand(marka);
TV->setModel(model);
TV->setColor(cvqt);
TV->setHertz(hertz);
TV->setInch(inch);


myVector.push_back(*TV);
	}
void saveTV(ofstream& output,vector<televisors>& vect)
{
	string test = "";
	vector<televisors>::iterator it;
	for(it = vect.begin();it != vect.end();it++)
	{
		test=(it->printTV());
		output<<test;
		test = "";
	}

}
void print(ifstream &input)
{
	while(!input.eof())
	{
		string temp;
	  getline(input,temp);
	  cout<<temp<<endl;
	   temp="";
	}
}
void findBrand(ifstream& in)
{
	string brand;
	cout<<"����� ��������� ������� ";
	cin>>brand;
	in.clear();
	in.seekg(ios::beg);
	while(!in.eof())
	{
		string temp;
		getline(in,temp);
		int unsigned index = temp.find(brand);
		if(index != string::npos)
		{
			cout<<"��������� �� ���������� �� ���� ����� ��: "<<endl<<temp<<endl;
			break;

		}
		temp= "";
	}
}
void findInch(ifstream& in) //��� ����������� ������ ������ �����
{
	vector<string> allObj;
	in.clear();
	in.seekg(ios::beg);

	while(!in.eof())
	{
		string temp;
		getline(in,temp);
		allObj.push_back(temp);
		temp="";
	}


	in.clear();
	in.seekg(ios::beg);
	int doublePosition=0;
	int whoRow=0;
	while(!in.eof())
	{
		string temp;
		in >> temp;
		doublePosition++;
		if(doublePosition==5)
		{
			whoRow++;
			doublePosition=0;
		}
				if(doublePosition==4)
						{
					double number;
					double inch;
					cout<<"����� ����� ��������� �������"<<endl;
					cin>>inch;
					number = atof(temp.c_str());
						if (number==inch)
						{
							cout<<"��������� "<<inch<<"-������ ���������� ��: "<<endl<<allObj[whoRow]<<endl;
							break;
						}


		}
	}
}

