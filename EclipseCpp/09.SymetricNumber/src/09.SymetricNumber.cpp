#include <iostream>
using namespace std;

int main()
{

	int num,rem,sum=0,numCopy;    //Defining variables.
	    cout <<"Enter a number:";    // Ask user for input.
	    cin>>num;
	    numCopy=num;

	    while(num!=0)    //Loop to reverse the number.
	    {
	        rem=num%10;
	        num=num/10;
	        sum=sum*10+rem;

	    }

	    if(numCopy==sum)
	    {
	        cout<<"The number you entered is symmetric."<<endl;
	    }
	    else

	    {
	        cout<<"The number you entered is not symmetric."<<endl;
	    }

	return 0;
}
