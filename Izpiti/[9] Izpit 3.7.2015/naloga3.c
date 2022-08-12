#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int piramida(int** tabela, int visina, int i, int j, int vsota)
{
    if (visina == 1)
        return vsota + tabela[i][j];
    else
    {
        int levo = piramida(tabela, visina - 1, i + 1, j, vsota + tabela[i][j]);
        int desno = piramida(tabela, visina - 1, i + 1, j + 1, vsota + tabela[i][j]);

        if (levo > desno)
            return levo;
        return desno;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int** tabela = (int** ) calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++)
    {
        tabela[i] = (int* ) calloc(n, sizeof(int));
        for (int j = 0; j <= i; j++)
            scanf("%d", &tabela[i][j]);
    }

    printf("%d\n", piramida(tabela, n, 0, 0, 0));
}