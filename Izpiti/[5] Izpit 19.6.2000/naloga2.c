#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

int main(int argc, char** argv)
{
    FILE* vhod = fopen(argv[1], "rt");
    char* vrstica = (char* ) malloc(1000 * sizeof(char));
    int steviloVrstic = 1;

    while (fgets(vrstica, 1000, vhod) != NULL)
    {
        printf("%d %s", steviloVrstic, vrstica);
        steviloVrstic++;
    }
    printf("\n");

    fclose(vhod);
    free(vrstica);

    return 0;
}