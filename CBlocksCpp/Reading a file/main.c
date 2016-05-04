#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file = fopen("C:\\Users\\karad_000\\Desktop\\Example.txt", "r");

    char c;

    do
    {
        c = fgetc(file);
        printf("%c", c);
    }
    while(c != EOF);

    fclose(file);

    return 0;
}
