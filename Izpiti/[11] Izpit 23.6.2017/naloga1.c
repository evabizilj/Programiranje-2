#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

int main()
{
    int stevke = 0;
    int vsota = 0;
    char* niz = (char* ) malloc(100000 * sizeof(char));
    gets(niz);

    char* beseda;

    // 1. beseda
    // strtok ... breaks string str into a series of tokens using the delimiter delim.
    beseda = strtok(niz, " ");
    for (int i = 0; i < strlen(beseda); i++)
        if (isdigit(beseda[i]))
            stevke++;
    // če je številka samostojna
    if (stevke == strlen(beseda))
        vsota += atoi(beseda);
    
    // preostale besede
    while (beseda != NULL)
    {
        for (int i = 0; i < strlen(beseda); i++)
            if (isdigit(beseda[i]))
                stevke++;
        if (stevke == strlen(beseda))
            vsota += atoi(beseda);
        beseda = strtok(NULL, " ");
        stevke = 0;
    }

    printf("%d\n", vsota);
    return 0;
}

