#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main()
{
    int stevilo = 0;
    int sum = 0;

    while (scanf("%d", &stevilo) > 0)
    {
        if (stevilo == 1)
            break;
        else if (stevilo % 100 == 24)
        {
            printf("%d\n", stevilo);
            sum += stevilo;
        }
    }

    printf("Vsota: %d\n", sum);

    return 0;
}