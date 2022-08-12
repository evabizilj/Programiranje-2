#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

unsigned long long pow2(unsigned long long st, int base) 
{
    for (int i = 0; i < base; i++) 
        st *= 2;
    return st;
}


int main() 
{
    int n;
    scanf("%d", &n);

    int matrika[8][8];

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            matrika[i][j] = 0;
            if (i == 8 - 1 && j== 8 - 1) 
                matrika[i][j] = 1;
        }
    }

    int ukazi[n];

    for (int i = 0; i < n; i++) 
        scanf("%d", &ukazi[i]);

    int x = 7;
    int y = 7;

    for (int i = 0; i < n; i++) 
    {
        // levo
        if (ukazi[i] == 0) 
        { 
            if (x - 1 >= 0) // znotraj mej
            {
                x = x - 1;
                matrika[y][x] = 1;
            }
        }
        // gor
        else if (ukazi[i] == 1) 
        {
            if (y - 1 >= 0) 
            { 
                y = y - 1;
                matrika[y][x] = 1;
            }
        }
        // desno
        else if (ukazi[i] == 2) 
        {
            if (x + 1 <= 7) 
            {
                x = x + 1;
                matrika[y][x] = 1;
            }
        }
        // dol
        else if (ukazi[i] == 3) 
        {
            if (y + 1 <= 7) 
            {
                y = y + 1;
                matrika[y][x] = 1;
            }
        }
    }

    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
            printf("%d", matrika[i][j]);
        printf("\n");
    }
    
    printf("\n");
    unsigned long long rezultat = 0;
    int base = 63;
    for (int i = 0; i < 8; i++) 
    {
        for (int j = 0; j < 8; j++) 
        {
            if (matrika[i][j] == 1) 
                rezultat += matrika[i][j] * pow2(1,base);
            base--;
        }
    }

    printf("%lld", rezultat);

    return 0;
}