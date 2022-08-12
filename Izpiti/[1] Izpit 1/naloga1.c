#include <stdio.h>

int najBlok(int z[][6], int m, int n)
{
    int velikostKvadrata, poln = 1;

    if (m > n)
        velikostKvadrata = n;
    else
        velikostKvadrata = m;
    
    for (int velikost = velikostKvadrata; velikost > 1; velikost--)
    {
        // zacetne tocke
        for (int i = 0; i <= (m - velikost); i++)
        {
            for (int j = 0; j <= (n - velikost); j++)
            {
                // ce je zacetka tocka 0, ni potrebno preverjati
                if (z[i][j] == 0)
                    continue;
                for (int k = 0; k < velikost; k++)
                {
                    for (int l = 0; l < velikost; l++)
                    {
                        if (z[i + k][j + l] == 1)
                            poln = 1;
                        else
                        {
                            poln = 0;
                            break;
                        }
                    }
                }
                if (poln == 1)
                    return velikost;

            }
        }
    }
    return 1;
}

int main()
{
    int z[5][6] = {{0, 1, 0, 1, 0, 0}, 
                   {0, 1, 1, 1, 1, 0},
                   {0, 1, 1, 1, 1, 1},
                   {0, 0, 1, 1, 1, 1},
                   {1, 0, 0, 1, 0, 1}};
    printf("%d\n", najBlok(z, 5, 6));
    return 0;
}
