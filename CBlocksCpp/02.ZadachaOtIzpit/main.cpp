#include <iostream>
using namespace std;

int main()
{

	int N, M, prosto, ostatuk, suma = 0, x;

	cout << "N= ";
	cin >> N;

	cout << "M= ";
	cin >> M;

    for(int i = N+1; i < M; i++)
        {
            prosto = 1;
            for(int j = 2; j < i; j++)
                {
                    if(i % j == 0)
                        {
                            prosto = 0;
                            break;
                        }
                }

                if(prosto == 1)
                    {

                       x = i;

                       while (x != 0)
                        {
                            ostatuk = x%10;
                            x = x/10;
                            suma = suma * 10 + ostatuk;
                        }

                        if (suma == i)
                            {
                                cout << i << ", ";
                            }
                    }
                    suma = 0;
        }


	return 0;
}
