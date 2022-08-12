#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void odstraniDuplikate(FILE* vhod, FILE* izhod)
{
    char znak;
    char prejsnjiZnak;
    znak = fgetc(vhod);
    prejsnjiZnak = znak;
    fputc(znak, izhod);

    while ((znak = fgetc(vhod)) != EOF)
    {
        if (isalpha(znak))
        {
            if (znak != prejsnjiZnak)
            {
                fputc(znak, izhod);
                prejsnjiZnak = znak;
            }

        }
        else
            fputc(znak, izhod);
    }
}

int main(int argc, char** argv)
{
    FILE* vhod = fopen(argv[1], "rt");
    FILE* izhod = fopen(argv[2], "wt");

    odstraniDuplikate(vhod, izhod);

    fclose(vhod);
    fclose(izhod);

    return 0;

}