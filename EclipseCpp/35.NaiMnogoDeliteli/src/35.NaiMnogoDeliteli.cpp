#include <iostream>

using namespace std;

int divisor_count (int n);

int main()
{
     int n=0,m;
     cout << "Enter Number N: ";
     cin >> n;
     cout << "Enter Number M: ";
     cin >> m;

     int divisors;
     int max_divs = 0;
     int max_num = 0;

      for (n = 0; n <= m; n++)
      {
          divisors = divisor_count(n);
          if (divisors > max_divs)
          {
             max_num = n;
             max_divs = divisors;
          }
      }
      cout << "The number with the most divisors is: " << max_num << endl;
      return 0;
}

int divisor_count (int n)
{
    int count = 1;

    for ( int i = 2; i <= n; i++ )
    {
        if ( n % i == 0 )
            ++count;
    }
    return count;
}
