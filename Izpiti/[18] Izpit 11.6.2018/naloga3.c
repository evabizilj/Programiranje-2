#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

int podmnozice(int* stevila, int stStevil, int trenutnaVsota, int vsota)
{
    // končamo, ko ni več števil
    if (stStevil == 0)
        return abs((vsota - trenutnaVsota) - trenutnaVsota);
    
    int vkljuci = podmnozice(stevila, stStevil - 1, trenutnaVsota + stevila[stStevil], vsota);
    int izkljuci = podmnozice(stevila, stStevil - 1, trenutnaVsota, vsota);

    return min(vkljuci, izkljuci);
}

int main()
{
    int stStevil;
    scanf("%d", &stStevil);
    int vsota = 0;

    int* stevila = (int* ) malloc(stStevil * sizeof(int));
    for (int i = 0; i < stStevil; i++)
    {
        scanf("%d", &stevila[i]);
        vsota += stevila[i];
    }
    
    printf("%d\n", podmnozice(stevila, stStevil, 0, vsota));

    return 0;
}