#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>

/*
V programskem jeziku C napišite program, ki kopira eno 
tekstovno datoteko v drugo in hkrati poskrbi, da se vse 
besede začnejo z veliko črko, kateri sledijo same male crke. 

*/

int main(int argc, char** argv)
{
    FILE* vhod = fopen(argv[1], "rt");
    FILE* izhod = fopen(argv[2], "wt");

    int znak;
    int prejsnjiZnak = 0;

    // 1. znak
    znak = fgetc(vhod);
    if (isalpha(znak))
        fputc(toupper(znak), izhod);

    while ((znak = fgetc(vhod)) != EOF)
    {
        if (isalpha(znak) && ((prejsnjiZnak == ' ' ) || (prejsnjiZnak == '\n') || (prejsnjiZnak == '\t')))
            fputc(toupper(znak), izhod);
        else
            fputc(tolower(znak), izhod);
        prejsnjiZnak = znak;
    }

    fclose(vhod);
    fclose(izhod);

    return 0;
}


