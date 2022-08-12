#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

/*
Združitev vrstic tako, da med obe vrstici vstavi ločilo dvopičje 
(znak ‘:’), in rezultat izpiše na zaslon.
*/

int main(int argc, char** argv)
{
    FILE* datoteka1 = fopen(argv[1], "rt");
    FILE* datoteka2 = fopen(argv[2], "rt");
    FILE* izhod = fopen(argv[3], "wt");

    int znak;
    int prejsniZnak;

    // datoteki enako dolgi
    while (!feof(datoteka1) && !feof(datoteka2))
    {
        while (!feof(datoteka1) && ((znak = fgetc(datoteka1)) != '\n') && (znak != EOF))
            putchar(znak);
        putchar(':');
        while (!feof(datoteka2) && ((znak = fgetc(datoteka2)) != '\n') && (znak != EOF))
            putchar(znak);
        putchar('\n');
    }

    // nista enako dolgi
    if (!feof(datoteka1))
    {
        while ((znak = fgetc(datoteka1)) != EOF)
        {
            if (znak == '\n')
                putchar(':');
            putchar(znak);
        }
    }

    if (!feof(datoteka2))
    {
        prejsniZnak = znak;
        while ((znak = fgetc(datoteka2)) != EOF)
        {
            if (prejsniZnak == '\n')
                putchar(':');
            putchar(znak);
            prejsniZnak = znak;
        }
    }

    printf("\n");

    fclose(datoteka1);
    fclose(datoteka2);

    return 0;

}