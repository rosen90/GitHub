#include <iostream>
using namespace std;

int main()
{
	 int num;
	 cout << "Напишете позитивно число: ";
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
	            case 1: cout << "сто"; break;
	            case 2: cout << "двеста"; break;
	            case 3: cout << "триста"; break;
	            case 4: cout << "четиристотин"; break;
	            case 5: cout << "петстотин"; break;
	            case 6: cout << "шестстотин"; break;
	            case 7: cout << "седемстотин"; break;
	            case 8: cout << "осемстотин"; break;
	            case 9: cout << "деветстотин"; break;
	        }
	        if (num >= 100)
	        {
	            cout << " ";
	        }
	        if (ones == 0 && num > 100)
	        {
	            cout << "и ";
	        }

	        switch (decs)
	        {
	            case 2: cout << "двадесет"; break;
	            case 3: cout << "тридесет"; break;
	            case 4: cout << "четиридесет"; break;
	            case 5: cout << "педесет"; break;
	            case 6: cout << "щейсет"; break;
	            case 7: cout << "седемдесет"; break;
	            case 8: cout << "осемдесет"; break;
	            case 9: cout << "деведесет"; break;
	        }
	        if (num > 20 && decs == 0 && ones != 0)
	        {
	        	cout << "и ";
	        }
	        else
	        {
	            if (num > 20 && ones != 0)
	            {
	            	cout << " и ";
	            }
	        }
	        if (ones == 0)
	        {
	        	cout << "  ";
	        }

	        switch (ones)
	        {
	            case 0: cout << "нула"; break;
	            case 1: cout << "едно"; break;
	            case 2: cout << "две"; break;
	            case 3: cout << "три"; break;
	            case 4: cout << "четери"; break;
	            case 5: cout << "пет"; break;
	            case 6: cout << "шест";  break;
	            case 7: cout << "седем"; break;
	            case 8: cout << "осем"; break;
	            case 9: cout << "девет"; break;
	            case 10: cout << "десет"; break;
	            case 11: cout << "единадесет"; break;
	            case 12: cout << "дванадесет"; break;
	            case 13: cout << "тринадесет"; break;
	            case 14: cout << "четеринадесет"; break;
	            case 15: cout << "петнадесет"; break;
	            case 16: cout << "шестнадесет"; break;
	            case 17: cout << "седемнадесет"; break;
	            case 18: cout << "осемнадесет"; break;
	            case 19: cout << "деветнадесет"; break;
	            case 20: cout << "двадесет"; break;
	        }

	return 0;
}
