#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

char* poisci(char* niz, char* podniz)
{
    int j = 0;
    for (int i = 0; i < strlen(niz); i++)
    {
        j = 0;
        if (niz[i] == podniz[j])
        {
            for ( ; (i < strlen(niz)) && (niz[i] == podniz[j]); i++, j++)
                if (j == strlen(podniz))
                    return niz + i - strlen(podniz);
        }
    }
    return NULL;
}


int main()
{
    char niz[10000];
    char podniz[10000];
    char rezultat[10000]; 

    scanf("%s %s", niz, podniz);

    printf("%s\n", poisci(niz, podniz));

    return 0;


}