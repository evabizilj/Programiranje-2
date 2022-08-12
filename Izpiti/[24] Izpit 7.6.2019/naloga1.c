#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX 21

/*
Napišite program, ki v podani vhodni datoteki poišče zadnjo vrstico, ki vsebuje podani znak, in 
celotno vrstico (vključno z znakom \n) 
prepiše v podano izhodno datoteko. V vseh testnih primerih obstaja vsaj ena taka vrstica.
*/

int main()
{
    char* vhod = (char* ) malloc(MAX * sizeof(char));
    char* izhod = (char* ) malloc(MAX * sizeof(char));
    char znak;

    scanf("%s%s %c", vhod, izhod, &znak);

    FILE* in = fopen(vhod, "rt");
    FILE* out = fopen(izhod, "wt");

    char* vrstica = (char* ) malloc(1001 * sizeof(char));
    char* zadnjaVrstica = (char* ) malloc(1001 * sizeof(char));

    while (fgets(vrstica, 1001, in) != NULL)
        if (strchr(vrstica, znak) != NULL)
            strcpy(zadnjaVrstica, vrstica);
    
    fprintf(out, "%s", zadnjaVrstica);

    fclose(in);
    fclose(out);
    free(vhod);
    free(izhod);

    return 0;

}
}