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

Vozlisce* zdruzi(Vozlisce** a, Vozlisce** b)
{
    if (*a == NULL)
        *a = *b;
    else
    {
        Vozlisce* trenutno = *a;
        while (trenutno->naslednje != NULL)
            trenutno = trenutno->naslednje;
        trenutno->naslednje = *b;
    }
    *b = NULL;
    return *a;
}

Vozlisce* izbrisiEnake(Vozlisce* zacetek)
{
    Vozlisce* tmp;
    Vozlisce* trenutno = zacetek;

    if (zacetek == NULL)
        return zacetek;

    while (trenutno->naslednje != NULL)
    {
        if (trenutno->podatek == trenutno->naslednje->podatek)
        {
            tmp = trenutno->naslednje->naslednje;
            free(trenutno->naslednje);
            trenutno->naslednje = tmp;
        }
        else
            trenutno = trenutno->naslednje; 
    }
    return zacetek;
}


int main() {
    int array1[] = {1, 2};
    int array2[] = {2, 3, 4, 5};


    Vozlisce* a = ustvari(array1, 2);
    testiraj(a);
    Vozlisce* b = ustvari(array2, 4);
    testiraj(b);
    //Vozlisce* b = pobrisiElement(a, 2);
    Vozlisce* c = zdruzi(&a, &b);
    Vozlisce* rezultat = izbrisiEnake(c);
    testiraj(rezultat);

    return 0;
}
