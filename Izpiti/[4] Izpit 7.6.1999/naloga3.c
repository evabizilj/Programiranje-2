#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
/*
V programskem jeziku C napišite program kopiraj, 
ki prekopira vsebino ene datoteke v drugo. Imeni obeh datotek sta podani kot argumenta ukazne vrstice.
*/

int main(int argc, char** argv)
{
    FILE* vhod = fopen(argv[1], "rt");
    FILE* izhod = fopen(argv[2], "wt");

    char znak;
    while (fscanf(vhod, "%c", &znak) == 1)
    {
        fprintf(izhod, "%c", znak);
    }

    fclose(vhod);
    fclose(izhod);

    return 0;
}