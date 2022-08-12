/*

Primer:
6
0 1 0 0 1 0
1 0 0 1 0 0
1 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 1
0 1 0 1 0 1
2 3

2013
204513
20453
*/


#include <stdio.h>
#include <stdlib.h>

void pot(int stVozlisc, int zacetnoVozlisce, int koncnoVozlisce, int** matrikaObiskanosti, int* obiskano, int* celotnaPot, int stClenov)
{
    if (obiskano[zacetnoVozlisce] == 1)
        return;
    
    if (zacetnoVozlisce == koncnoVozlisce)
    {
        celotnaPot[stClenov] = zacetnoVozlisce;
        for (int i = 0; i <= stClenov; i++)
            printf("%d", celotnaPot[i]);
        printf("\n");
        return;
    }

    obiskano[zacetnoVozlisce] = 1;
    celotnaPot[stClenov] = zacetnoVozlisce;

    for (int i = 0; i < stVozlisc; i++)
    {
        // če obstaja povezava
        if (matrikaObiskanosti[zacetnoVozlisce][i] == 1)
            pot(stVozlisc, i, koncnoVozlisce, matrikaObiskanosti, obiskano, celotnaPot, stClenov + 1);
    }
    obiskano[zacetnoVozlisce] = 0;
}

int main()
{
    int stVozlisc;
    scanf("%d", &stVozlisc);

    /*
    Povezava od vozlišča i do vozlišča j obstaja natanko tedaj, ko je element matrike v vrstici z indeksom
    i in stolpcu z indeksom j enak 1. 
    */
    int** matrikaSosednosti = (int** ) calloc(stVozlisc, sizeof(int*));

    int* obiskano = (int *) calloc(stVozlisc, sizeof(int));

    int* celotnaPot = (int *) calloc(stVozlisc, sizeof(int));

    for (int i = 0; i < stVozlisc; i++)
    {
        matrikaSosednosti[i] = (int* ) calloc(stVozlisc, sizeof(int));
        for (int j = 0; j < stVozlisc; j++)
            scanf("%d", &matrikaSosednosti[i][j]);
    }

    int zacetnoVozlisce;
    int koncnoVozlisce;

    scanf("%d %d", &zacetnoVozlisce, &koncnoVozlisce);

    pot(stVozlisc, zacetnoVozlisce, koncnoVozlisce, matrikaSosednosti, obiskano, celotnaPot, 0);

    return 0;
}