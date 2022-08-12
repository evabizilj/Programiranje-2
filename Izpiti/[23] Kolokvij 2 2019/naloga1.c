#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// 1000 vrstic, 1000 znakov
int main(int argc, char** argv)
{
    int maxBesed = 0;
    int stBesed = 0;

    char* vhod = (char* ) malloc(101 * sizeof(char));
    char* izhod = (char* ) malloc(101 * sizeof(char));
    scanf("%s", vhod);
    scanf("%s", izhod);

    FILE* in = fopen(vhod, "rt");
    FILE* out = fopen(izhod, "wt");

    char* vrstica = (char* ) malloc(1001 * sizeof(char));

    while ((fgets(vrstica, 1000, in) != NULL))
    {
        int i = 0; 
        while (vrstica[i] != '\n')
        {
            if (vrstica[i] == ' ')
                stBesed++;
            i++;
        }
        if (stBesed > maxBesed)
            maxBesed = stBesed;
        stBesed = 0;
    }

    fprintf(stdout, "%d\n", maxBesed + 1);

    free(vhod);
    free(izhod);
    fclose(in);
    fclose(out);
}