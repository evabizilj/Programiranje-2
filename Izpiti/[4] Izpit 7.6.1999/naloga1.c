#include <stdio.h>

int main()
{
    char poz[3];
    int iks = 0;

    printf("Vpisi figuro in pozicijo: ");
    scanf("%s", poz);

    for (char i = '8'; i >= '1'; i--)
    {
        for (char j = 'a'; j <= 'h'; j++)
        {
            if ((j == poz[1]) && (i == poz[2]))
                printf("%c", poz[0]);
            else if (iks)
                printf("X");
            else
                printf("_");
            iks = !iks;
        }
        printf("\n");
        iks = !iks;
    }
    return 0;
}