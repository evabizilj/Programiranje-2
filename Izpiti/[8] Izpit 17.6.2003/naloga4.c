#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče (prioriteta)
    Vozlisce* naslednje; // kazalec na naslednje vozlišče (NULL, če ga ni)
};

Vozlisce* ustvari(int* t, int n) {
	if (n <= 0)
		return NULL;
	Vozlisce* zacetek = (Vozlisce* ) malloc(sizeof(Vozlisce));
	zacetek->podatek = *t;
	zacetek->naslednje = ustvari(t + 1, n - 1);
	return zacetek;
}

char NIZ[1000];
char* vNiz(Vozlisce* zacetek)
{
    char* pNiz = NIZ;
    *pNiz = '[';
    pNiz++;

    Vozlisce* trenutno = zacetek;
    while (trenutno != NULL)
    {
        if (trenutno != zacetek)
            pNiz += sprintf(pNiz, ", ");
        pNiz += sprintf(pNiz, "%d", trenutno->podatek);
        trenutno = trenutno->naslednje;
    }
    sprintf(pNiz, "]");
    return NIZ;
}

void testiraj(Vozlisce* v) {
    printf("%s\n", vNiz(v));
}

Vozlisce* vstaviNaZacetek(Vozlisce* zacetek, int element)
{
    Vozlisce* novo = (Vozlisce* ) malloc(sizeof(Vozlisce));
    novo->podatek = element;
    novo->naslednje = zacetek;
    return novo;
}

Vozlisce* vstavi(Vozlisce* zacetek, int element)
{
    if (zacetek == NULL || element < zacetek->podatek)
        return vstaviNaZacetek(zacetek, element);
    zacetek->naslednje = vstavi(zacetek->naslednje, element);
    return zacetek;
}

int main() {
    int array[] = {1, 2, 7, 10};

    Vozlisce* a = ustvari(array, 4);
    Vozlisce* b = vstavi(a, 3);
    testiraj(b);
    return 0;
}
