#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

long stej(int n, int visina)
{
    if (visina < 0)
        return 0;

    if (n == 0)
    {
        if (visina == 0)
            return 1;
        else
            return 0;
    }

    // visina se lahko zniža ali zviša
    return stej(n - 1, visina + 1) + stej(n - 1, visina - 1);
        
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("%ld\n", stej(n, 0));
}