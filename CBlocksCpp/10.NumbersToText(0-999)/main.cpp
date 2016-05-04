//10. Write a program that converts a number in the
//range [0...999] to a text corresponding to its
//Bulgarian pronunciation. Examples:
//0 "����"
//273 "������ ���������� � ���"
//400 "������������"
//501 "��������� � ����"
//711 "����������� � ����������"


#include <iostream>
#include <windows.h>
#include <locale>
using namespace std;

int main()
{

     setlocale(LC_ALL, "Russian");
     SetConsoleOutputCP(1251);

	 int num;
	 cout << "�������� ��������� �����: ";
	 cin >> num;

	 int hundreds = 0;
	 int decs = 0;
	 int ones = 0;

	        if (num >= 100)
	        {
	            hundreds = (num / 100) % 10;
	            if (num > 120)
	            {
	                decs = (num / 10) % 10;
	                ones = num % 10;
	            }
	            else
	            {
	                ones = num % 100;
	            }

	        }
	        if (num > 20 && num <= 99)
	        {
	            decs = (num / 10) % 10;
	            ones = num % 10;
	        }
	        if (num <= 20)
	        {
	            ones = num;
	        }


	        switch (hundreds)
	        {
	            case 1: cout << "���"; break;
	            case 2: cout << "������"; break;
	            case 3: cout << "������"; break;
	            case 4: cout << "������������"; break;
	            case 5: cout << "���������"; break;
	            case 6: cout << "����������"; break;
	            case 7: cout << "�����������"; break;
	            case 8: cout << "����������"; break;
	            case 9: cout << "�����������"; break;
	        }
	        if (num >= 100)
	        {
	            cout << " ";
	        }
	        if (ones == 0 && num > 100)
	        {
	            cout << "� ";
	        }

	        switch (decs)
	        {
	            case 2: cout << "��������"; break;
	            case 3: cout << "��������"; break;
	            case 4: cout << "�����������"; break;
	            case 5: cout << "�������"; break;
	            case 6: cout << "������"; break;
	            case 7: cout << "����������"; break;
	            case 8: cout << "���������"; break;
	            case 9: cout << "���������"; break;
	        }
	        if (num > 20 && decs == 0 && ones != 0)
	        {
	        	cout << "� ";
	        }
	        else
	        {
	            if (num > 20 && ones != 0)
	            {
	            	cout << " � ";
	            }
	        }
	        if (ones == 0)
	        {
	        	cout << "  ";
	        }

	        switch (ones)
	        {
	            case 0: cout << "����"; break;
	            case 1: cout << "����"; break;
	            case 2: cout << "���"; break;
	            case 3: cout << "���"; break;
	            case 4: cout << "������"; break;
	            case 5: cout << "���"; break;
	            case 6: cout << "����";  break;
	            case 7: cout << "�����"; break;
	            case 8: cout << "����"; break;
	            case 9: cout << "�����"; break;
	            case 10: cout << "�����"; break;
	            case 11: cout << "����������"; break;
	            case 12: cout << "����������"; break;
	            case 13: cout << "����������"; break;
	            case 14: cout << "�������������"; break;
	            case 15: cout << "����������"; break;
	            case 16: cout << "�����������"; break;
	            case 17: cout << "������������"; break;
	            case 18: cout << "�����������"; break;
	            case 19: cout << "������������"; break;
	            case 20: cout << "��������"; break;
	        }

	return 0;
}
