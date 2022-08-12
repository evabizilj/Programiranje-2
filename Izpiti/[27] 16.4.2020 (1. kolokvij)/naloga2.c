
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/*

NE DELA

    int dolzina; // len vsebuje število elementov brez zaključne 0
    ...
    int kopija[dolzina];
    ... preis v tabelo kopija
    t[i] = &kopija[0];

DELA

    int dolzina; // len vsebuje število elementov brez zaključne 0
    ...
    int *tmp;
    tmp = (int*) malloc ((len + 1) * sizeof (int));
    ...
    t[i] = tmp;

    zelo veliko tabelo tabelo
    zelo kratke sekundarne tabele

    t[0] ----> 5 3 7 0
           ˆ 
    t[1] ---->

    t[0] ----> 5' 3' 7' 0'

Moramo iti po podani tabeli.
Za vsak kazalec moramo v njej pogledati, če še kateri kazalec v tej tabeli kaže na isti naslov, 
in če --> skopiramo tabelo na katero kaže trenutni kazalec in si assignamo to tabelo dvojniku, ki smo ga našli.

Nov kazalec = nov naslov
Novo z mallocom nardimo in potem sam pointer dvojnika nastavimo, da kaze na to kopijo.

Naredimo identicno tabelo z mallocom, ki bo imela svoj unikaten naslov in 
moramo nastavit, da kaze ta pointer nanjo.

Dolzino te tabele, ki ji delamo kopijo dobimo?
Lahko damo 1000 (max length).
Lahko pa gremo enkrat po dolžini dokler ne pridemo do 0 pa potem samo dolzina++ vsakič.
Pa še ++ ko pridemo do 0.
*/


/*
Kazalec t kaže na začetek primarne tabele, ki vsebuje kazalce na začetke sekundarnih tabel. 
Primarna tabela lahko vsebuje skupine kazalcev, ki kažejo na isto sekundarno tabelo. 
Funkcija naj vsebino primarne tabele spremeni tako, da bo vsak kazalec v taki skupini 
kazal na ločeno kopijo sekundarne tabele.
Primarna tabela se konča s kazalcem NULL, vsaka sekundarna tabela pa s številom 0. 

*/

void kopirajTabela(int* target, int* source)
{
    int i = 0; 
    while (source[i] != 0)
    {
        target[i] = source[i];
        i++;
    }
}


void pretvori(int** t)
{
    int i = 0;
    while (t[i] != NULL)
    {
        int* sekundarnaTabela = t[i];
        int* kopija = (int* ) calloc(1000, sizeof(int));

        kopirajTabela(kopija, sekundarnaTabela);

        t[i] = kopija;
        i++;
    }
}


void izpisi(int** t, int n) {
    for (int i = 0;  i < n;  i++) {
        int* p = t[i];
        while (*p != 0) {
            printf("%d ", *p);
            p++;
        }
        printf("0\n");
    }
    for (int i = 0;  i < n;  i++) {
        for (int j = 0;  j < n;  j++) {
            printf("%d", t[i] == t[j]);
        }
        printf("\n");
    }
}

int main() {
    // koda za ro"cno testiranje (po "zelji)
    int t1[] = {0};
    int* t2 = t1;
    int* t3 = t2;
    int* t4 = t2;

    int* t[] = {t1, t2, t3, t4, NULL};

    pretvori(t);
    int n = sizeof(t) / sizeof(t[0]) - 1;
    izpisi(t, n);

    exit(0);
    return 0;
}

