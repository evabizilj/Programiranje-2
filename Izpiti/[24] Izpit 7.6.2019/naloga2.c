#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce 
{
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* zgradi(int* t) 
{
    if (*t <= 0) 
        return NULL;
    Vozlisce* v = malloc(sizeof(Vozlisce));
    v->podatek = *t;
    v->naslednje = zgradi(t + 1);
    return v;
}

void izpisi(Vozlisce* zacetek)
{
    printf("[");
    for (Vozlisce* p = zacetek;  p != NULL;  p = p->naslednje) 
    {
        if (p != zacetek) 
            printf(", ");
        printf("%d", p->podatek);
    }
    printf("]\n");
}

void pocisti(Vozlisce* zacetek) 
{
    if (zacetek != NULL) 
    {
        pocisti(zacetek->naslednje);
        free(zacetek);
    }
}

Vozlisce* obrni(Vozlisce* zacetek)
{
    Vozlisce* prejsnje = NULL;
    Vozlisce* trenutno = zacetek;
    Vozlisce* naslednji = NULL;

    while (trenutno != NULL)
    {
        naslednji = trenutno->naslednje;
        trenutno->naslednje = prejsnje;
        prejsnje = trenutno;
        trenutno = naslednji;
    }
    zacetek = prejsnje;
    return zacetek;
}

void obdelaj(Vozlisce* seznam) 
{
    izpisi(seznam);
    seznam = obrni(seznam);
    izpisi(seznam);
    pocisti(seznam);
}

int main() 
{
    Vozlisce* seznam = zgradi((int[]) {1000, 116, 819, 330, 558, 729, 600, 712, 545, 530, 246, 207, 679, 244, 348, -1});
    obdelaj(seznam);
    return 0;
}


