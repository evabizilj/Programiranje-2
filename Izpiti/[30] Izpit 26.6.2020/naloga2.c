#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>

typedef struct Vozlisce {
    int podatek; // podatek, ki ga hrani vozlišče
    struct Vozlisce* naslednje; // kazalec na naslednje vozlišče (NULL, če ga ni)
} Vozlisce;

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

void testiraj(Vozlisce* v) 
{
    printf("%s\n", vNiz(v));
}

Vozlisce* tocno(Vozlisce* zac, int i)
{
    int index = 0;
    Vozlisce* trenutno = zac;
    while (trenutno != NULL)
    {
        if (i == index)
            return trenutno;
        index++;
        trenutno = trenutno->naslednje; 
    }
}

Vozlisce* izloci(Vozlisce* zac, Vozlisce* v)
{
    Vozlisce* trenutno = zac;

    if (zac == v)
        zac = zac->naslednje;

    while (trenutno != NULL)
    {
        int flag = 0;
        //vmesni elementi && zadnji element
        if (trenutno->naslednje == v)
        {
            trenutno->naslednje = trenutno->naslednje->naslednje;
            flag = 1;
        }

        if (flag == 0)
            trenutno = trenutno->naslednje;
    }
    free(trenutno);
    return zac;
}

int main(){
    int array[] = {1,2,3,4,5,6,7};
    Vozlisce* a = ustvari(array, 7);
    testiraj(a);
    //Vozlisce* b = malloc(sizeof(Vozlisce));
    Vozlisce* b = tocno(a, 6);
    Vozlisce* c = izloci(a, b);
    free(b);
    testiraj(c);
    return 0;
}