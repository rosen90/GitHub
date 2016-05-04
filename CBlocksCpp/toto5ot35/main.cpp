#include <iostream>

using namespace std;

int main()
{
    int counter = 0;
            for (int i1 = 1; i1 <=31; i1++)
                for (int i2 = i1 + 1; i2 <= 32; i2++)
                    for (int i3 = i2 + 1; i3 <=33; i3++)
                        for (int i4 = i3 + 1; i4 <= 34; i4++)
                            for (int i5 = i4 + 1; i5 <=35; i5++)
                                {
                                    cout << i1 << " " << i2 << " " << i3 << " " << i4 << " " << i5 << endl;
                                    counter++;
                                }
            cout << counter << " combinations";
    return 0;
}
