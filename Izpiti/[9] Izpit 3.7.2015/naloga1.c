#include <stdio.h>

int main()
{
    int zice[50];
    int steviloZic = 0;
    while (scanf("%d", &zice[steviloZic]) != EOF)
         steviloZic++;
        
    int pravokotnih = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int kandidat = 0;

    for (int i = 0; i < steviloZic + 1; i++)
    {
        for (int j = 0; j < zice[steviloZic] / 2; j++)
        {
            a = j;
            for (int k = 0; k < zice[steviloZic] / 2; k++)
            {
                b = k;
                c = zice[steviloZic] - b - a;
                if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
                    kandidat++;
            }
        }
        if (kandidat == 6)
            pravokotnih++;
            
        kandidat = 0;
    }

    printf("%d\n", pravokotnih);
    return 0;
}