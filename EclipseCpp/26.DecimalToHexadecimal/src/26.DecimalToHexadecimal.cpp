#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
     char response;

         cout << "Enter positive integer to convert to Hexadecimal:\n\n";
         int number;
         cin >> number;
         cout << "Hexadecimal representation of "<< number << " is "
                    << hex << uppercase << number << dec << '\n'
                    << "\nMore (Y or N)? ";
         cin >> response;


}
