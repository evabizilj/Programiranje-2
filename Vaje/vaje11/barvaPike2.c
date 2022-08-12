#include <stdio.h>
#include <stdlib.h>

int main(int agrc, char* argv[]) {
    FILE* vhod = fopen(argv[1], "rb");
    int vrstica = atoi(argv[2]);
    int stolpec = atoi(argv[3]);

    // preberi glavo datoteke
    char* tmp = malloc (11 * sizeof(char)); // prostor za vrstico
    fgets(tmp, 11, vhod);
    int sirina, visina;
    fscanf(vhod, "%d %d", &sirina, &visina); // ne prebere nove vstice
    fgetc(vhod); // prebere '/n'
    fgets(tmp, 11, vhod); 
    free(tmp);

    // preberi podatke o slikovnih v tabelo pike
    // 0 - 255 --> unsigned char
    unsigned char* pike = malloc(sirina * visina * 3 * sizeof(unsigned char));  
    fread(pike, sizeof(unsigned char), 3 * visina * sirina, vhod);

    // izlušči barvne komponente pike na podanih koordinatih
    int indeks = sirina * vrstica * 3 + stolpec * 3;
    printf("%d %d %d", pike[indeks], pike[indeks + 1], pike[indeks + 2]);

    fclose(vhod);
    return 0;
}
