#include <stdio.h>
#include <stdlib.h>

void skoki(int stPloscic, int* ploscice, int ploscice1, int ploscice2, int pot, int index)
{
    // smo znotraj ploscic
    if (index < stPloscic && index >= 0)
    {
        // obiskali smo ploščico
        ploscice[index] = 1;

        if (pot > 0)
        {
            // gremo v vse možne smeri
            skoki(stPloscic, ploscice, ploscice1, ploscice2, pot - 1, index + ploscice1);
            skoki(stPloscic, ploscice, ploscice1, ploscice2, pot - 1, index + ploscice2);
            skoki(stPloscic, ploscice, ploscice1, ploscice2, pot - 1, index - ploscice1);
            skoki(stPloscic, ploscice, ploscice1, ploscice2, pot - 1, index - ploscice2);
        }
    }
}

int main()
{
    int stPloscic;
    int ploscice1;
    int ploscice2;
    int pot;

    scanf("%d %d %d %d", &stPloscic, &ploscice1, &ploscice2, &pot);

    int* ploscice = (int* ) calloc(stPloscic, sizeof(int));

    skoki(stPloscic, ploscice, ploscice1, ploscice2, pot, 0);
    
    int skupnaPot = 0;
    for (int i = 0; i < stPloscic; i++)
        // ploščico smo obiskali, pot povečamo
        if (ploscice[i] == 1)
            skupnaPot++;
    
    printf("%d\n", skupnaPot);

    return 0;
}