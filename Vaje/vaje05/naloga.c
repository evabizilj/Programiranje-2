#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Z zanko se premikamo od začetnega do končnega kazalca in seštevamo elemente. 
Če povečamo kazalec za 1, se avtomatsko poveča za velikost tipa, na katerega kaže.
*/

/*
S kazalcem <p> se sprehodimo od pomnilniškega naslova <zac> do
pomnilniškega naslova <kon> in sproti seštevamo vrednosti *p, torej
vrednosti v posameznih celicah, na katere kaže kazalec p
*/

int vsota(int* zac, int* kon) {
    int vsota = 0;
    int *p = zac;
    while (p <= kon) {
        vsota += *p;
        p++; // premik na naslednjo celico tabele (tj. za sizeof(int) bajtov naprej)
    }
    return vsota;
}

/*
Imamo tabelo t. Pointer na tabelo je enako kot pointer na prvi element.
Indeks ni neposredno povezan z našo tabelo, hrani na katero mesto hrani kazalec na kazalec - ta kaže na neko mesto v tabeli.

V primeru, da je indeks - 1, potem moramo v njega napisati mesto kamor kaže kazalec na kazalec.
- t .... želimo razliko kamor kažeta pointerja

2. primer
V indeksu je npr. vrednost 7, potem moramo kazalec predstaviti.
Spreminjamo *kazalec kamor kaže kazalec = naslov kamor kaže t + indeks elementov kasneje.

Zakaj ne **:
ker smo želeli spreminjati kamor kaže kazalec, ne pa njegove vrednosti
*/

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
    if (*indeks == - 1)
        /* indeks celice s pomnilniškim naslovom <*kazalec> (tj. razliko med
           pomnilniškima naslovoma <*kazalec> in <t>) vpišemo v
           spremenljivko <*indeks>
        */
        *indeks = *kazalec - t;
    else
        // v spremenljivko <*kazalec> vpišemo pomnilniški naslov celice z indeksom <*indeks>
        *kazalec = t + *indeks;
}

void frekvenceCrk(char* niz, int** frekvence) {
    int *pojavitve = (int *) calloc(26, sizeof(int));
    // pojavitve[i]: skupno število pojavitev znakov ('A' + i) in ('a' + i)

    //char *ch = niz;  // character je kazalec na ch
    char znak;
    while (*niz != '\0') {
        if (isalpha(*niz)) {
            znak = tolower(*niz);
            pojavitve[znak - 'a']++;
        }
        niz++;
    }
    // kazalec na začetek tabele pogostosti vpišemo v spremenljivko *frekvence
    *frekvence = pojavitve;
}

void kvadrat(int *x) {
	*x = *x * *x;
}

int main() {
    int x = 10;
    int *p = &x;
    printf("%d %p %d %p\n", x, &x, p, *p);
    
    int *t = malloc(10 * sizeof(int));
    t[4] = 8;
    printf("%d %d %d %d\n", t[4], *(t + 4), t, t + 4);

    int a = 2;
	int *pa = &a;
	
	printf("a = %d\n", a);
	kvadrat(&a);
	printf("a^2 = %d\n", a);
	kvadrat(pa);
	printf("a^4 = %d\n", a);

    int tabela[] = {3, 6, 1, 9, 7, 2, 8, 5, 4};

    printf("%d\n", vsota(tabela, tabela));
    printf("%d\n", vsota(tabela, tabela + 8));

    int indeks = -1;
    int* kazalec = t;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%d\n", indeks);

    indeks = -1;
    kazalec = t + 5;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%d\n", indeks);

    indeks = -1;
    kazalec = t + 9;
    indeksInKazalec(t, &indeks, &kazalec);
    printf("%d\n", indeks);

    char* NIZ = "A quick brown fox jumps over the lazy dog.";

    int* frekvence;
    frekvenceCrk(NIZ, &frekvence);
    for (int c = 'A';  c <= 'Z';  c++) {
        if (frekvence[c - 'A'] > 0) {
            printf("%c -> %d\n", c, frekvence[c - 'A']);
        }
    }

    free(frekvence);

    exit(0);

    return 0;
}

/*

TESTIRANJE
Testni primeri so programi, ki testirajo funkcije. 

Izvajanje testov
    • podobno kot do sedaj
    • prevedemo vsak testni primer posebej in ga zaženemo
    • prevedemo razred naloga (v katerem prej v funkciji main napišete svoj lasten test)

1. export name=naloga; make; make test
2. naredimo lasten test v main; gcc naloga.c ... ; ./naloga
3. gcc testxx.c ... ; ./testxx

*/

