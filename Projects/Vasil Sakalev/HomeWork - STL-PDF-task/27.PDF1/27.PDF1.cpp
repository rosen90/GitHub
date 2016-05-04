//1. �� �� ������ �������� ����� ������� ������������ �� ������� ����
//input.txt � ���� ���� ������ ������ ���� ����� ���� ����� ������� � ������ �����
//� ������� ���� ������� ������� ����� � ����� ������� � �������� � �*� (������).
//�������� ����� �� �� ������� ��� ���� output.txt.
//������:
//����:
//�� ������ Java � Microsoft.
//�����:
//�* ������ J*** � M********.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main() {

	ifstream readText("text.txt", ios::in);
	ofstream writeText("output.txt", ios::out);

	if (!readText) {
		cerr << "The file can not be opened !!! ";
		exit(1);
	}
	string word;
	while (readText >> word) {
		if (isupper(word.at(0))) {
			for (unsigned i = 1; i < word.size(); i++) {
				word.at(i) = '*';
			}
		}
		writeText << word << " ";
	}
	readText.clear();
	readText.seekg(0);
	return 0;
}
