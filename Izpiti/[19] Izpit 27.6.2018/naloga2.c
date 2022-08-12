#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* n;
    struct _Vozlisce* nn;
} Vozlisce;

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element);


void izpisi(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    while (p != NULL) {
        if (p != zacetek) {
            printf(" -> ");
        }
        printf("%d", p->podatek);
        p = p->n;
    }
    printf(" | ");

    Vozlisce* pp = zacetek;
    while (pp != NULL) {
        if (pp != zacetek) {
            printf(" ->-> ");
        }
        printf("%d", pp->podatek);
        pp = pp->nn;
    }
    printf(" | ");
    if (zacetek != NULL) {
        Vozlisce* pp = zacetek->n;
        while (pp != NULL) {
            if (pp != zacetek->n) {
                printf(" ->-> ");
            }
            printf("%d", pp->podatek);
            pp = pp->nn;
        }
    }
    printf("\n");
}

Vozlisce* zgradiSeznam() {
    Vozlisce* v001 = malloc(sizeof(Vozlisce));
    Vozlisce* v002 = malloc(sizeof(Vozlisce));
    Vozlisce* v003 = malloc(sizeof(Vozlisce));
    Vozlisce* v004 = malloc(sizeof(Vozlisce));
    v001->podatek = 10;
    v002->podatek = 20;
    v003->podatek = 30;
    v004->podatek = 40;
    v001->n = v002;
    v002->n = v003;
    v003->n = v004;
    v004->n = NULL;
    v001->nn = v003;
    v002->nn = v004;
    v003->nn = NULL;
    v004->nn = NULL;
    return v001;
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->n);
        free(zacetek);
    }
}

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element) 
{
    if (zacetek == NULL) 
    {
		zacetek = (Vozlisce* ) malloc(sizeof(Vozlisce));
		zacetek->podatek = element;
		zacetek->n = NULL;
		zacetek->nn = NULL;
		return zacetek;

	} else if (element <= zacetek->podatek) 
    {
		Vozlisce *novo = (Vozlisce* ) malloc(sizeof(Vozlisce));
		novo->podatek = zacetek->podatek;
		novo->n = zacetek->n;
		novo->nn = zacetek->nn;
		
		zacetek->podatek = element;
		zacetek->n = novo;
		zacetek->nn = novo->n;	
		return zacetek;

	} else if (zacetek->n == NULL) 
    {
		Vozlisce *novo = malloc(sizeof(Vozlisce));
		novo->podatek = element;
		novo->n = NULL;
		novo->nn = NULL;
		zacetek->n = novo;
		return zacetek;
	}
	
	Vozlisce *novo = vstaviUrejeno(zacetek->n, element);
    zacetek->nn = novo->n;
    
    return zacetek;
}

int main() {
    Vozlisce* zacetek = zgradiSeznam();

    printf("PREJ:   ");
    izpisi(zacetek);

    printf("VSTAVI: 25\n");
    zacetek = vstaviUrejeno(zacetek, 25);

    printf("POTEM:  ");
    izpisi(zacetek);

    pocisti(zacetek);
    exit(0);
    return 0;
}

/*

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct _Vozlisce {
    int podatek;
    struct _Vozlisce* n;
    struct _Vozlisce* nn;
} Vozlisce;

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element);


void izpisi(Vozlisce* zacetek) {
    Vozlisce* p = zacetek;
    while (p != NULL) {
        if (p != zacetek) {
            printf(" -> ");
        }
        printf("%d", p->podatek);
        p = p->n;
    }
    printf(" | ");

    Vozlisce* pp = zacetek;
    while (pp != NULL) {
        if (pp != zacetek) {
            printf(" ->-> ");
        }
        printf("%d", pp->podatek);
        pp = pp->nn;
    }
    printf(" | ");
    if (zacetek != NULL) {
        Vozlisce* pp = zacetek->n;
        while (pp != NULL) {
            if (pp != zacetek->n) {
                printf(" ->-> ");
            }
            printf("%d", pp->podatek);
            pp = pp->nn;
        }
    }
    printf("\n");
}

Vozlisce* zgradiSeznam() {
     Vozlisce* v001 = malloc(sizeof(Vozlisce));
    Vozlisce* v002 = malloc(sizeof(Vozlisce));
    Vozlisce* v003 = malloc(sizeof(Vozlisce));
    Vozlisce* v004 = malloc(sizeof(Vozlisce));
    v001->podatek = 10;
    v002->podatek = 20;
    v003->podatek = 30;
    v004->podatek = 40;
    v001->n = v002;
    v002->n = v003;
    v003->n = v004;
    v004->n = NULL;
    v001->nn = v003;
    v002->nn = v004;
    v003->nn = NULL;
    v004->nn = NULL;
    return v001;
}

void pocisti(Vozlisce* zacetek) {
    if (zacetek != NULL) {
        pocisti(zacetek->n);
        free(zacetek);
    }
}

Vozlisce* vstaviUrejeno(Vozlisce* zacetek, int element){
    Vozlisce* trenutno = zacetek;
    // zacetek
    if (zacetek->podatek > element)
    {
        Vozlisce* novo = (Vozlisce*) malloc(sizeof(Vozlisce));
        novo->podatek = element;
        novo->n = trenutno;
        novo->nn = trenutno->n;

        return novo;
    }

    // konec
    while (trenutno != NULL)
    {
        if (trenutno->n->podatek < element && trenutno->nn == NULL)
        {
            Vozlisce* konec = (Vozlisce*) malloc(sizeof(Vozlisce));
            konec->podatek = element;

            trenutno->nn = konec;

            Vozlisce* temp = trenutno->n; 
            temp->n = konec;
            return zacetek;
        }

        //vmesni
        if (trenutno->n->podatek < element && trenutno->nn->podatek > element)
        {
            //kreiranje noda
            Vozlisce* vmesni = (Vozlisce*) malloc(sizeof(Vozlisce));
            vmesni->podatek = element; //25
            vmesni->n = trenutno->nn; //kazalec na 30
            Vozlisce* temp = trenutno->nn; //kazalec na 30
            vmesni->nn = temp->n; //kazalec na 40

            trenutno->nn = vmesni;

            //prevezanje
            Vozlisce* temp2 = trenutno->n; //20ka
            temp2->n = vmesni;
            temp2->nn = vmesni->n;

            return zacetek;
        }
        trenutno = trenutno->n;
    }
} 

int main() {
    Vozlisce* zacetek = zgradiSeznam();

    printf("PREJ:   ");
    izpisi(zacetek);

    printf("VSTAVI: 25\n");
    zacetek = vstaviUrejeno(zacetek, 25);

    printf("POTEM:  ");
    izpisi(zacetek);

    pocisti(zacetek);
    exit(0);
    return 0;
}







*/
