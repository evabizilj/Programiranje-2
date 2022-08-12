#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Knjiga
{
    char naslov[100];
    char avtor[100];
    int letoIzdaje;
} Knjiga;

int main(int argc, char** argv)
{
    FILE* vhod = fopen(argv[1], "rt");
    Knjiga knjiga;

    int stKnjig = 0;

    // preberemo 3 knjige
    for (int i = 1; i <= 3; i++)
    {
        scanf("%s", knjiga.naslov);
        scanf("%s", knjiga.avtor);
        scanf("%d", &knjiga.leto);

        if (knjiga.leto > 0)
            fwrite(&knjiga, sizeof(knjiga), 1, vhod);
    }

    fclose(vhod);

    return 0;
}
