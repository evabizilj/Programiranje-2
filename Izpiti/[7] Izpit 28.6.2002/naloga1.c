#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int tabeliranje(int n)
{
    if (n <= 2)
        return 1;
    return tabeliranje(n - 1) + tabeliranje(n - 2);
}

int main()
{
    int n;
    scanf("%d", &n);
    printf("%d\n", tabeliranje(n));

    return 0;
}