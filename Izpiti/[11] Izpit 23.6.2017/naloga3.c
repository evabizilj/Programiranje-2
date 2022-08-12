#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Pair
{
    int m;
    int M;
} Pair;

int* stevila;

void izpisi(Pair* intervali, int n, int i)
{
    if (i >= n)
    {
        for (int i = 0; i < n; i++)
            printf("%d", stevila[i]);
        printf("\n");
        return;
    }

    for (int j = intervali[i].m; j <= intervali[i].M; j++)
    {
        stevila[i] = j;
        izpisi(intervali, n, i + 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    Pair* intervali = (Pair* ) malloc(n * sizeof(Pair));
    for (int i = 0; i < n; i++)
        scanf("%d %d", &intervali[i].m, &intervali[i].M);

    stevila = (int* ) calloc(n, sizeof(int));

    izpisi(intervali, n, 0); 

    return 0;
}