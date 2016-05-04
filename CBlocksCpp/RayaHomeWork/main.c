#include <stdio.h>
#include <stdlib.h>

int main()
{
    int f;
    float a,r, b, c,s;
    printf("Vyvedete chislo ot 1 do 4: ");
    scanf("%d", &f);

    switch(f)
    {
        case 1: printf("\nKvadrat"); break;
        case 2: printf("\nPravoygylnik"); break;
        case 3: printf("\nPravoygylen triygylnik"); break;
        case 4: printf("\nOkryjnost"); break;
    }

    if (f==1)
    {
        printf("\nVyvedete strana na kvadrata: ");
        scanf("%f", &a);
        s = a*a;
        printf("Liceto na kvadrata e: %f", s);
        scanf("%f", &s);
    }

    if(f==2)
    {
        printf("\nVyvedete stranite na pravoygylnika: ");
        scanf("%f %f",&b,&c);
        s = b*c;
        printf("Liceto na pravoygylnika e : %f ", s);
        scanf("%f", &s);

    }
     if (f==3)
     {
         printf("\nVyvedete stranite na triygylnika: ");
         scanf("%f %f",&b,&c);
         s = (b*c)/2;
         printf("Liceto na pravoygylniq triygylnik e: %f", s);
         scanf("%f", &s);

     }

     if (f==4)
     {
         printf("\nVyvedete radius na okryjnostta: ");
         scanf("%f", &r);
         s = 2*3.14*r*r;
         printf("Liceto na okryjnostta e: %f", s);
         scanf("%f",&s);

     }

        return 0;

}
