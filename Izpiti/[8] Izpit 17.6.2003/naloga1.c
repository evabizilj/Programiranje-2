#include <stdio.h>

void presledki(int trenutna)
{
    if (trenutna == 0)
        return;
    printf(" ");
    presledki(trenutna - 1);
}

void zvezdice(int trenutna)
{
    if (trenutna == 0)
    {
        printf("\n");
        return;
    }
    printf("*");
    zvezdice(trenutna - 1);
}

void piramida(int n, int vrstica)
{
    if (vrstica > n)
        return;
    presledki(n - vrstica);
    zvezdice(2 * vrstica - 1);
    piramida(n, vrstica + 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    piramida(n, 1);
}

/*
void trikotnik(int n)
{
    for (int i = 0; i < (n + 1); i++)
    {   
        for (int j = n - i; j > 0; j--)
            printf(" ");
        for (int k = 0; k < 2 * i + 1; k++)
            printf("*");
        printf("\n");
    }
}


*/