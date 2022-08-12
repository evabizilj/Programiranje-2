
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Vozlisce Vozlisce;

struct Vozlisce {
    int podatek;
    Vozlisce* naslednje;
};

Vozlisce* izloci(Vozlisce* zacetek)
{
    Vozlisce* trenutno = zacetek;
    Vozlisce* prejsnje = zacetek;

    int counter = 0;
    int k = trenutno->podatek;

    while (trenutno != NULL) 
    {

        if (k == counter)
        {
            if (trenutno->naslednje == NULL)
                break;
            prejsnje->naslednje = trenutno->naslednje;
            trenutno = trenutno->naslednje;
            k = trenutno->podatek;
            counter = 0; 
        }
        else
        {
            prejsnje = trenutno;
            trenutno = trenutno->naslednje;
            counter++;
        }
    
    }
    return zacetek;
}


Vozlisce* zgradi(int* t) {
    if (*t <= 0) {
        return NULL;
    }
    Vozlisce* v = malloc(sizeof(Vozlisce));
    v->podatek = *t;
    v->naslednje = zgradi(t + 1);
    return v;
}

void izpisi(Vozlisce* zacetek) {
    printf("[");
    for (Vozlisce* p = zacetek;  p != NULL;  p = p->naslednje) {
        if (p != zacetek) {
            printf(", ");
        }
        printf("%d", p->podatek);
    }
    printf("]\n");
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->naslednje);
        free(zacetek);
    }
}


int main() {
    Vozlisce* seznam = zgradi((int[]) {6, 7, 10, 17, 8, 12, 7, 12, 7, 9, 7, 12, 13, 14, 13, -1});
    izpisi(seznam);
    izloci(seznam);
    izpisi(seznam);
    pocisti(seznam);
    exit(0);
    return 0;
}
