#include <stdio.h>
#include <stdlib.h>

typedef struct Vozlisce
{
    int podatek;
    struct Vozlisce* naslednje;
} Vozlisce;

Vozlisce* prepisi(int* t)
{
    int i = 0; 
    if (t[i] == 0)
        return NULL;
    
    // zacetek
    Vozlisce* zacetek = (Vozlisce *) malloc(sizeof(Vozlisce));
    zacetek->podatek = t[i];
    zacetek->naslednje = NULL;

    Vozlisce* trenutno = zacetek;

    i++;

    while (t[i] != 0)
    {
        Vozlisce* novo = (Vozlisce *) malloc(sizeof(Vozlisce));
        novo->podatek = t[i];
        novo->naslednje = NULL;
        trenutno->naslednje = novo;
        trenutno = trenutno->naslednje;
        i++;
    }

    return zacetek;

}


int main()
{
    int tab[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};


    Vozlisce* trenutno = prepisi(tab);
    while (trenutno != NULL)
    {
        printf("%d ", trenutno->podatek);
        trenutno = trenutno->naslednje;
    }
    printf("\n");
}