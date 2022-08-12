#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char* argv[]) {
    FILE* vhod = fopen(argv[1], "rb");
    FILE* izhod = fopen(argv[2], "wb");

    // preberi glavo datoteke
    char* tmp = malloc (11 * sizeof(char)); // prostor za vrstico
    fgets(tmp, 11, vhod);
    int sirina, visina;
    
    fgets(tmp, 11, vhod); 
    sscanf(tmp, "%d %d", &sirina, &visina);

    fgets(tmp, 11, vhod);
    free(tmp);
    printf("%d %d", sirina, visina);
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    unsigned char* barve = malloc(sirina * visina * 3 * sizeof(unsigned char));  
    fread(barve, sizeof(unsigned char), 3 * visina * sirina, vhod);

    // pretvori barve v sivine
    char* sivine = malloc(sirina * visina * sizeof(unsigned char));  
    int s = 0;
    for (int i = 0; i < sirina * visina * 3; i += 3) {
        int r = barve[i];
        int g = barve[i + 1];
        int b = barve[i + 2];
        sivine[s] = (30 * 4 + 59 * g + 11 * b) / 100;
    }

    fprintf(izhod, "P5\n%d %d\n255\n", sirina, visina);
    fwrite(sivine, 1, visina * sirina, izhod);
    fclose(vhod);
    fclose(izhod);

    fclose(vhod);
    return 0;
}
