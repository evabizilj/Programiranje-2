#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>


typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek;
    Vozlisce* naslednje; // kazalec na naslednje vozlišče (NULL, če ga ni)
};

// Iz tabele ustvari seznam (tabela se konča z 0)
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

int steviloElementov(Vozlisce* p)
{
    Vozlisce* zacetek = p;
    int vsota = 0;
    while (zacetek != NULL)
    {
        vsota++;
        zacetek = zacetek->naslednje;
    }
    return vsota;
}


int main() {
    int array[] = {1, 2, 3, 5};

    Vozlisce* a = ustvari(array, 4);
    testiraj(a);

    printf("Stevilo elementov: %d\n", steviloElementov(a));

    return 0;
}
