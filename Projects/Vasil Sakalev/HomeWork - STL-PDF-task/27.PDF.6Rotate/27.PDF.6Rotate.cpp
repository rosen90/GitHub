//6. ����� ��������� ����� � ������ 6 �� 6 ������ �� �������� ��������������
//������� �� 1 �� 36 (��. ����������). �������� � �������� �� ������� ��
//���������� � ������� �� 0 �� 5. ����� ������� ���� ����������� �� ��
//������� ���������� ���������� �� 4 ������� ������, ����� ���������� �
//�Rotate(row,col)�. ��� ����������� � ������� ������� (row, col)
//������������� � ���������� (row, col), (row, col+1), (row+1, col) � (row+1, col+1)
//�� �������� �� ������������� ������� (����� � �������� �� �������� ��-����).
//����� � ������� ����, ����� ������� ���������������� �� ������� ��
//���������. �� �� ������ ��������, ����� ���������� �� ��������� ���������
//�� ������� ��������� �������������� ������ ������� �� ������� ���� �
//��������� ����������� �� �������, ����� �� �������� � ��������.
//�������� ���� game36.txt ������� �� ������ �� ��� ���� ������� N (0 < N
//< 1000), ����� ������ �� ����� ���������. �� ����� �� ���������� N ���� ����
//�� ���� ������� Rotate(row,col), ������ row � col (����� � ��������� [0;
//4]) �� ��������� ����� � ��������, �� ������ ������� �����������. ���������
//�� �������� �������� (�� ������� ����� �������) � �� �������� � ���� ��
//��������� ��� ����� �����������.
//������� ������� ������� � ������ �� �� �������� �� ��������� ��� �� ���.
//�������� ������ ���� game36.txt:
//2
//Rotate(2,4)
//Rotate(1,3)

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void Rotate(int arr[][6], int, int);

int main() {

	ifstream readComand("game36.txt", ios::in);

	int arr[6][6];
	int count = 1;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			arr[i][j] = count;
			count++;
		}
	}

	string word;
	readComand.seekg(2);

	while (readComand >> word) {
		for (unsigned i = 0; i < word.size(); i++) {
			if (isdigit(word.at(i))) {
				char r = word.at(i);
				char c = word.at(i+ 2);
				int row = r - '0';
				int col = c - '0';

				Rotate(arr, row, col);
				break;

			}
		}
	}

	readComand.clear();
	readComand.seekg(0);

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void Rotate(int arr[][6], int row, int col) {
	int temp[2][2];
	temp[0][0] = arr[row][col];
	temp[0][1] = arr[row][col + 1];
	temp[1][0] = arr[row + 1][col];
	temp[1][1] = arr[row + 1][col + 1];

	arr[row][col] = temp[1][0];
	arr[row][col + 1] = temp[0][0];
	arr[row + 1][col] = temp[1][1];
	arr[row + 1][col + 1] = temp[0][1];

}

