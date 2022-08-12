/*
Izpiše vsa padajoča zaporedja števil med (1, k] katerih vsota = <n>
@stClenov: uporabljen del tabele
@result: izpis členov
@cleni: hranijo posamezne vrednost

Naredimo neko tabelo, kamor shranimo perspektivne člene. Podobno kot prej.
Hranimo direktno kateri člen smo dodali zadnjega v tabelo. Ni potrebe po 2D.

*/

#include <stdio.h>
#include <stdlib.h>

void izpisiClene(int *t, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            printf(" + ");
        printf("%d", t[i]); // izpišemo število
    }
    printf("\n");
}

long nacini(int ciljnaVsota, int k, int *cleni, int stClenov)
{
    if (ciljnaVsota <= 0 || k <= 0) { 
        // ko pridemo do rešitve moramo izpisati
        if (ciljnaVsota == 0) {
            // vsoto smo zgradili do konca, zato lahko njene člene izpišemo
            izpisiClene(cleni, stClenov);
            return 1;
        }
        return 0;
    }

    // število načinov, kjer v tem koraku vključimo <k>
    cleni[stClenov] = k;
    long vsebujeK = nacini(ciljnaVsota - k, k, cleni, stClenov + 1);
    // člen smo uporabili, tabelo imamo večjo za 1 --> 2. klic rekurzije nato dobi stClenov za 1 več

    // število členov, kjer število <k> izpustimo iz seštevka (lahko, da smo ga dodali korak prej)
    long brezK = nacini(ciljnaVsota, k - 1, cleni, stClenov);
    // stClenov upošteva kot neuporaben k;  cleni[stClenov] = k je v bistvu garbage, ker nismo povečali število členov

    return (vsebujeK + brezK);
}

int main()
{
    int ciljnaVSota, k;
    scanf("%d %d", &ciljnaVSota, &k);

    int *cleni = (int *) calloc(ciljnaVSota, sizeof(int));

    nacini(ciljnaVSota, k, cleni, 0);
    // naša tabela ne bo vedno uporabljena do konca --> do katerega mesta se nahajajo uporabni dele tabele, do kje ima naša tabela vrednost
    // na začetku je ta vrednost 0, nato ustrezno povečujemo
    // printf("%ld\n", stNacinov);

    return 0;
}

/*
Ne moremo izpisati kar na podlagi sprehoda - nekatere opcije tudi niso prave (določena drevesa so "suha").
Hraniti moramo delne rešitve --> če se rešitev izkaže za pravilno --> izpišemo
*/

/*
Na začetku štartamo s tabelo, kjer ni nič notri. 
Ko 1. kličemo načini, bomo na mestu ... 0.
Na mestu k vpišemo 5:
    - v 1. opciji k povečamo za 1
Funkcija načini dobi število členov, ki bo 1 - veljavna 5 in nato zapiše na to mesto 1, 2, ..
    - v 2. opciji smo tudi zapisali 5 ampak nam število členov ostane na 0 --> vsi klici bodo jemali kot da je ta tabela prazna
*/