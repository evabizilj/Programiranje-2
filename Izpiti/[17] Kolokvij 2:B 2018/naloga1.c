#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče
    Vozlisce* naslednje; // kazalec na naslednje vozlišče (NULL, če ga ni)
};

int razdalja(Vozlisce* p, Vozlisce* q)
{
    int stKorakov = 0;

    while (p != NULL && p < q)
    {
        stKorakov++;
        p = p->naslednje;
    }

    return stKorakov;
}

Vozlisce* ustvariSeznam(int stElementov) {
    if (stElementov == 0) {
        return NULL;
    }
    Vozlisce* prvo = malloc(sizeof(Vozlisce));
    prvo->naslednje = NULL;

    Vozlisce* prejsnje = prvo;
    for (int i = 1;  i < stElementov;  i++) {
        Vozlisce* trenutno = malloc(sizeof(Vozlisce));
        trenutno->naslednje = NULL;
        prejsnje->naslednje = trenutno;
        prejsnje = trenutno;
    }
    return prvo;
}

Vozlisce* naprej(Vozlisce* v, int stKorakov) {
    if (stKorakov == 0) {
        return v;
    }
    return naprej(v->naslednje, stKorakov - 1);
}

void pocistiSeznamRek(Vozlisce* v) {
    if (v != NULL) {
        pocistiSeznamRek(v->naslednje);
        free(v);
    }
}

void pocistiSeznam(Vozlisce* v) {
    if (v != NULL) {
        Vozlisce* w = v->naslednje;
        v->naslednje = NULL;
        pocistiSeznamRek(w);
    }
}

int main() {
    Vozlisce* v = ustvariSeznam(1000);
    Vozlisce* p = naprej(v, 128);
    Vozlisce* q = naprej(v, 972);
    printf("%d\n", razdalja(p, q));

    pocistiSeznam(v);
    exit(0);
    return 0;
}

