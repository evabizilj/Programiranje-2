#include <stdio.h>

void izpisi(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = n; j >= i; j--)
            printf("%2d", i);
        printf("\n");
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    izpisi(n);
    return 0;
}