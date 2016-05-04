//9. Write a program that applies bonus scores to given
//scores in the range [1..9] by applying following
//rules: If the score is between 1 and 3, the program
//multiplies it by 10; if it is between 4 and 6,
//multiplies it by 100; if it is between 7 and 9,
//multiplies it by 1000. If it is zero or greater than 9,
//the program must report an error. Use a switch
//statement and at the end print the calculated new
//score in the console.

#include <iostream>

using namespace std;

int main()
{
    int score;
    cout << "Enter your score: ";
    cin >> score;

    if(score < 0 || score > 9)
        {
            cout << "Error invalid score!!!";
        }
    else
        {
            switch(score)
            {
                case 1:
                case 2:
                case 3: score *= 10; break;
                case 4:
                case 5:
                case 6: score *= 100; break;
                case 7:
                case 8:
                case 9: score *= 1000; break;
            }

            cout << "You score + bonus scores is " << score;
        }


    return 0;
}
