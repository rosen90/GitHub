//17. Дадена е шахматна дъска. На нея има кон и една друга фигура.
//Да се провери дали конят може да вземе другата фигура с един ход.

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
using namespace std;

string solveTags(string str, string openTag, string closeTag) {

 int start = str.find(openTag);
 int end = str.find(closeTag, start);

 while (end != -1 && start != -1)
    {

        int ch = start + openTag.length();

        while (ch < end)
            {
                str[ch] = toupper(str[ch]);
                ch++;
            }

        str = str.erase(end, closeTag.length());
        str = str.erase(start, openTag.length());
        start = str.find(openTag);
        end = str.find(closeTag, start);
    }

 return str;
}

int main ()
{

    string text = "We are living in a <upcase>yellow submarine</upcase>. We don't have <upcase>anything</upcase> else.";
    string openTag = "<upcase>";
    string closeTag = "</upcase>";


   cout << solveTags(text, openTag, closeTag);


    return 0;
}
