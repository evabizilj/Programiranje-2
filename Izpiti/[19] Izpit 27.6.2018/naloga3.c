#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int kovanci(int stKovancev, int kovanec1, int vsota)
{
    if (kovanec1 < 0)
        return 0;

    if (stKovancev == vsota)
        return 1;
    
    int da = kovanci(stKovancev, kovanec1 + 1, vsota + 1);
    int ne = kovanci(stKovancev, kovanec1 - 1, vsota + 1);
    return da + ne;
}

int main()
{
    int stKovancev;
    int kovanec1;
    scanf("%d %d", &stKovancev, &kovanec1);

    printf("%d\n", kovanci(stKovancev, kovanec1, 0));

    return 0;
}