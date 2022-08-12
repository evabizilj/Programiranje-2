#include "naloga2.h"

uchar* preberi(char* imeDatoteke, int* sirina, int* visina, int* stBajtov)
{
    FILE* vhod = fopen(imeDatoteke, "r");

    char* garbage = (char* ) malloc(10 * sizeof(char));
    // P6
    fscanf(vhod, "%s", garbage);
    // vpišemo širino oziroma višino slike
    fscanf("%d %d", &sirina, &visina);
    // 255
    fscanf("%s", garbage);
    free(garbage);

    // število bajtov, ki jih zavzema blok pike
    *stBajtov = 3 * *sirina * *visina;

    // tabela ustrezne velikosti, vanjo prepišemo celoten blok pike 
    // iz datoteke in vrnemo kazalec na začetek tabele

    uchar* tabela = (uchar* ) malloc(*stBajtov * sizeof(uchar));

    unsigned char r;
    fscanf(vhod, "%c", &r);

    int i = 0;
    for (int vrstica = 0; vrstica < *visina; vrstica++)
    {
        for (int stolpec = 0; stolpec < *sirina; stolpec++)
        {
            for (int komponenta = 0; komponenta < 3; komponenta++)
            {
                fscanf(vhod, "%c", &r);
                tabela[i] = r;
                i++;
            }
        }
    }

    fclose(vhod);
    return tabela;
}

int sivina(uchar* pike, int sirina, int visina, int vrstica, int stolpec)
{
    int i = (vrstica * sirina + stolpec) * 3;
    uchar red = pike[i];
    uchar green = pike[i + 1];
    uchar blue = pike[i + 2];
    return (red + green + blue) / 3;
}

int main()
{
    return 0;
}