#include <stdio.h>
#include <stdlib.h>

typedef struct Vozlisce Vozlisce;
struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče
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

Vozlisce* obrni(Vozlisce* zacetek)
{
    Vozlisce* prejsnje = NULL;
    Vozlisce* trenutno = zacetek;
    Vozlisce* naslednje = NULL;

    while (trenutno != NULL)
    {
        naslednje = trenutno->naslednje;
        trenutno->naslednje = prejsnje;
        prejsnje = trenutno;
        trenutno = naslednje;
    }
    zacetek = prejsnje;
    return zacetek;
}

int main() {
    int array[] = {1, 2, 3, 5};

    Vozlisce* a = ustvari(array, 4);
    testiraj(a);
    Vozlisce* c = obrni(a);
    testiraj(c);

    
    return 0;
}