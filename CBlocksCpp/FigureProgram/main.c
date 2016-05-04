#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Choose which figure yuo want to drow!\n");
    printf("a) Triangle\n");
    printf("b) Rectangle\n");
    printf("c) Square\n");

    char choice;
    char a = "a";
    char b = "b";
    char c = "c";

    scanf("%c", &choice);

    if(choice == a)
        {
            printf("Enter the size of the triangle\n");
        }
    else if (choice == b)
        {
            printf("Enter the size of the rectangle\n");
        }
    else if (choice == c)
        {
            printf("Enter the size of the square\n");
        }
    else
        {
            printf("Invalid input\n");
        }

    return 0;
}
