#include <stdio.h>
#include <stdlib.h>

int preveri(long stevili[2]);

int main()
{
    int m;
    scanf("%d", &m);
    
    long x = 1;
    long stevili[2];

    while (1)
    {
        stevili[0] = x;
        stevili[1] = m * x;    
        if (preveri(stevili))
            break;
        x++;
    }
    printf("%ld\n", x);
    return 0;
}

int preveri(long stevili[2])
{
    int tabelaX = calloc(10, sizeof(int));
    int tabelaMX = calloc(10, sizeof(int));
    long x = stevili[0];
    long mx = stevili[1];

    while (x != 0)
    {
        tabelaX[x % 10] = 1;
        x = (x - (x % 10)) / 10;
    }

    while (mx != 0)
    {
        tabelaMX[mx % 10] = 1;
        mx = (mx - (mx % 10)) / 10;
    }

    // primerjava tabel (ce je na kaksnem indeksu drugacna, vrnem 0)
    for (int i = 0; i < 10; i++)
        if (tabelaMX[i] != tabelaX[i])
            return 0;
    return 1;
}
