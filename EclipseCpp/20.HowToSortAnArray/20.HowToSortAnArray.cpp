//Сортиране на масив

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{

   int array[10] = {0,4,2,3,5,6,7,1,8,9};

   sort(array, array+10);

   for(int i = 0; i < 10; i++)
   {
	   cout << array[i] << " ";
   }


	return 0;
}
