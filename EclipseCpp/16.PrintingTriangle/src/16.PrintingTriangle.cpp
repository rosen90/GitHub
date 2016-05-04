#include <iostream>
using namespace std;

int main()
{
//	cout << "n= ";
//	int n = 0;
//	cin >> n;
//
//	for (int i = 1; i <= n; i++)
//	{
//		for(int j = 1; j <=i; j++)
//		{
//			cout << j << " ";
//		}
//
//		cout << endl;
//	}

	int i,j,rows,k=0,count=0,count1=0;

	cout<<"Enter the number of rows: ";
	cin>>rows;
	cout << endl;

	   for(i=1;i<=rows;++i)
	   {
	      for(j=1; j<=rows-i; ++j)
	      {
	         cout<<"  ";
	         ++count;
	      }
	      while(k!=2*i-1)
	      {
	            if (count <= rows-1)
	            {
	              cout<< i + k<<" ";
	              ++count;
	            }
	            else
	            {
	               ++count1;
	               cout << i + k - 2*count1 <<" ";
	            }
	           ++k;
	        }
	      count1=count=k=0;
	      cout<<"\n";
	    }

	return 0;
}
