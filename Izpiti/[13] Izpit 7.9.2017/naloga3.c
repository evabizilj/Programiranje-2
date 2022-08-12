#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int pike[256][256][256];

int main()
{
    // ime.ppm
    char* imeDatoteke = (char* ) malloc(21 * sizeof(char));
    scanf("%s", imeDatoteke);
    FILE* vhod = fopen(imeDatoteke, "r");

    char* garbage = (char* ) malloc(21 * sizeof(char));
    fgets(garbage, 10, imeDatoteke); // P6

    int sirina;
    int visina;
    fscanf("%d %d\n", &sirina, &visina);

    // 255
    fgets(garbage, 10, vhod);

    free(garbage);

    // vsebina
    int dolzina = visina * sirina;
    unsigned char red, green, blue;
    unsigned char rgb[3];
    int stRazlicnih = 0;
    int najvecEnakih;

    for (int i = 0; i < dolzina; i++)
    {
        fread(rgb, sizeof(unsigned char), 3, vhod);
        red = rgb[0];
        green = rgb[1];
        blue = rgb[2];

        if (pike[r][g][b] == 0)
            stRazlicnih++;
        pike[r][g][b]++;
        if (pike[r][g][b] > najvecEnakih)
            najvecEnakih++;
    }

    fclose(vhod);

    printf("%d\n %d\n", stRazlicnih, najvecEnakih);
    return 0;
}
